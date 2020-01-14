/*
 * Modified C unit testing frameworkd developed by Kurt Mammen for CPE 357
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <float.h>

#include "unitTest.h"

#define TEST_ALL -1
#define REGULAR -2 
#define SPECIAL -3

// Write all tests here
// static void test##(){}
static void test01(){
   int n = 2;

   int matrix_a[2][2] = {{1, 2},
                        {1, 2}};
   int matrix_b[2][2] = {{2, 3},
                        {2, 3}};
   int expected[2][2] = {{3, 5},
                        {3, 5}};
   int (*returned)[n] = matrix_addition(n,matrix_a,matrix_b);

   for(size_t y=0; y < n; y++) {
      for(size_t x=0; x < n; x++) {
         printf("Returned[%d][%d]: %d, Expected[%d][%d]: %d\n",y,x,returned[y][x],y,x,expected[y][x]);
         TEST_UNSIGNED(returned[y][x],expected[y][x]);
      }
   } 
}

static void test02(){
   int n = 1;

   int matrix_a[1][1] = {{1}};
    int matrix_b[1][1] = {{2}};
    int expected[1][1] = {{3}};
   int (*returned)[n] = matrix_addition(n,matrix_a,matrix_b);

   for(size_t y=0; y < n; y++) {
      for(size_t x=0; x < n; x++) {
         printf("Returned[%d][%d]: %d, Expected[%d][%d]: %d\n",y,x,returned[y][x],y,x,expected[y][x]);
         TEST_UNSIGNED(returned[y][x],expected[y][x]);
      }
   } 
}

static void test03(){
   int n = 3;

   int matrix_a[3][3] = {{1, 2, 3},
                          {3, 2, 1},
                          {1, 1, 1}};
   int matrix_b[3][3] = {{2, 2, 1},
                          {3, 2, 3},
                          {1, 1, 3}};
   int expected[3][3] = {{3, 4, 4},
                          {6, 4, 4},
                          {2, 2, 4}};

   int (*returned)[n] = matrix_addition(n,matrix_a,matrix_b);

   for(size_t y=0; y < n; y++) {
      for(size_t x=0; x < n; x++) {
         printf("Returned[%d][%d]: %d, Expected[%d][%d]: %d\n",y,x,returned[y][x],y,x,expected[y][x]);
         TEST_UNSIGNED(returned[y][x],expected[y][x]);
      }
   } 
}

static void test04(){
   int n = 3;

   int matrix_a[3][3] = {{0, 0, 3},
                          {1, 3, 2},
                          {4, 6, 9}};
   int matrix_b[3][3] = {{1, 2, 0},
                          {3, 2, 4},
                          {3, 2, 0}};
   int expected[3][3] = {{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};

   int (*returned)[n] = matrix_addition(n,matrix_a,matrix_b);

   for(size_t y=0; y < n; y++) {
      for(size_t x=0; x < n; x++) {
         printf("Returned[%d][%d]: %d, Expected[%d][%d]: %d\n",y,x,returned[y][x],y,x,expected[y][x]);
         TEST_UNSIGNED(returned[y][x],expected[y][x]);
      }
   } 
}

/* Prototype for all test functions. This allows the creation of an array of
 * function pointers which makes the testing code shorter and more clear. It
 * also makes it easier/faster to add new tests - NICE!
 */
typedef void (*TestFunc)();

typedef struct
{
   TestFunc fn;
   char *fnName;
} Test;

static void testAll(Test* tests)
{
   int i;

   for (i = 0; tests[i].fn != NULL; i++)
   {
      printf("Running regular %s\n", tests[i].fnName);

      /* Call the test function via function pointer in the array */
      tests[i].fn();
      printf("\t Passed regular %s\n\n", tests[i].fnName);
   }
}

static void findAndCall(Test* tests, const char *type, char *fnName)
{
   int i;

   for (i = 0; tests[i].fn != NULL; i++)
   {
      if (0 == strcmp(tests[i].fnName, fnName))
      {
         /* Found it, call the function via function pointer... */
         printf("Running %s %s\n", type, fnName);
         tests[i].fn();
         return;
      }
   }

   fprintf(stderr, "ERROR %s %s: Function not found\n", type, fnName);
   exit(EXIT_FAILURE);
}

static void runTests(Test *tests, const char *type, char *fnName)
{
   if (fnName == NULL)
      testAll(tests);
   else
      findAndCall(tests, type, fnName);

   /* Free the tests (allocated in initTests) */
   free(tests);
}

static char* checkArgs(int argc, char *argv[], int *testType)
{
   char *testName;

   if (argc == 1)
   {
      *testType = REGULAR;      
      testName = NULL;
   }
   else if (argc == 2)
   {
      *testType = REGULAR; 
      testName = argv[1];
   }
   else if (argc == 3)
   {
      if (0 != strcmp(argv[1], "-special"))
      {
         fprintf(stderr, "Invalid option '%s'\n", argv[1]);
         exit(EXIT_FAILURE);
      }
      
      *testType = SPECIAL;
      testName = argv[2];
   }
   else
   {
      fprintf(stderr, "Usage: %s [testName | -special testName]\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   return testName;
}

Test* initTests(Test tests[], int size)
{
   Test *dynamicMemory = malloc(size);

   if (dynamicMemory == NULL)
   {
      fprintf(stderr, "FAILURE in %s at %d: ", __FILE__, __LINE__);
      perror(NULL);
      exit(EXIT_FAILURE);
   }

   return memcpy(dynamicMemory, tests, size);
}

/* Allocates, initializes, and returns the array of regular test functions.
 * Regular test functions are those that are expected to pass or report failure
 * BUT NOT terminate the test driver.
 *
 * By default, the test driver runs ALL of the regular tests. Alternatively, you
 * can run one at a time by simply specifying its name when you invoke the
 * test driver.
 *
 * See alTests for tests that you always want to run individually.
 *
 * NOTE: The last structure in the array must have NULL values as this indicates
 *    the array's end.
 *
 * IMPORTANT SUBTLETY: You can only use sizeof to obtain an array's size in
 *    the scope where the array is declared, otherwise you will just get
 *    the size of the pointer to the array.
 */
Test* initRegularTests()
{
   Test local[] = {
      {test01,"test01"},
      {test02,"test02"},
      {test03,"test03"},
      {test04,"test04"},
      {NULL, NULL}

   };

   /* See IMPORTANT SUBTLETY above regarding the use of sizeof on arrays */
   return initTests(local, sizeof(local));
}

/* Allocates, initializes, and returns the array of special test functions.
 * Special test functions are those that you want to run individually for one
 * reason or another. For example, a test to see if a function asserts failure
 * when it is supposed to. Or, a test intended to measure CPU or memory
 * performance using tools like the Unix time command or Valgrind - for
 * tests like these you only want to run the single test and then observe the
 * results.
 *
 * See initRegularTests for tests that can together.
 *
 * NOTE: The last structure in the array must have NULL values as this indicates
 *    the array's end.
 *
 * IMPORTANT SUBTLETY: You can only use sizeof to obtain an array's size in
 *    the scope where the array is declared, otherwise you will just get
 *    the size of the pointer to the array.
 */
Test* initSpecialTests()
{
   Test local[] = {
      //Syntax {funcName,"String"}
      {NULL, NULL}
   };

   /* See IMPORTANT SUBTLETY above regarding the use of sizeof on arrays */
   return initTests(local, sizeof(local)); 
}

/* Test driver
 *
 * Usage: testCases [functionName | -special functionName]
 *
 * When no option is specified ALL of the regular tests are run.
 * When "functionName" is specified that single regular test is run.
 * When "-special functionName" is specified that single special test is run.
 */
int main(int argc, char *argv[])
{
   char *testName;
   int testType;

   /* Make stdout unbuffered so that test output is synchronous on signals */
   setbuf(stdout, NULL);

   /* Get the test name type */
   testName = checkArgs(argc, argv, &testType);
 
   /* Run the test(s)... */
   if (testType == REGULAR)
      runTests(initRegularTests(), "regular", testName);
   else
      runTests(initSpecialTests(), "special", testName);
   
   return 0;
}
