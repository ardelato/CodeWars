# Purpose

I created this repository to work on Codewars problems in my own environment. Through more and more challeneges I started adding more components such an **instructions.md**, markdown file to know what the challenge is asking for.

Then I began to create my own test case files but that got tedious so I repurposed a testing framework I used for my C programming class that my professor `Kurt Mammen` gave us to test our programs. 

Making and creating each challenge folder also became tedious. 
1. I had to create a new folder with the challenge name.
2. Create the following files:
   * solution.c - holds the function to implement
   * instructions.md - holds the challenge instructions
3. Copy over testCases.c & unitTest.h to the new challenge folder - *testing framework files*
4. Populate instructions.md with the actual instructions
   
So I ended up looking to the Codewars API and used `python` to automate that process for me.

---


## To Do
- [ ] Macro, or some other automation to insert `{test##,"test##"},` into the run tests array after a new test function is created
- [ ] Fix programming environment to test with gdb

