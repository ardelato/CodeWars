import requests
import os
import errno
import sys
from shutil import copy

exampleString = "Example:\n\turl: https://www.codewars.com/kata/printer-errors\n\turl-ending: printer-errors\n\t$ python challengeSetup.py printer-errors\n"

if len(sys.argv) != 2:
    print("USESAGE: python challengeSetup.py url-ending")
    print(exampleString)

else:
    resp = requests.get('https://www.codewars.com/api/v1/code-challenges/' + sys.argv[1])

    if resp.status_code != 200:
        # This means something went wrong.
        print ("ERROR")
        exit()

    dic = resp.json()

    problemName = dic.get('name')
    problemDIR = './' + problemName
    problemCredit = dic.get('createdBy').get('username')
    problemDesription = dic.get('description')

    # Make directory in current folder
    try:
        print("Making Directory %s\n" % problemDIR)
        os.makedirs(problemDIR)
        print("Finished Making Directory %s \n" % problemDIR)
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

    # Copy testCases.c and unitTest.h
    try:
        print("Copying Test Case Template")
        copy('testCases.c',problemDIR)
        print("Done Copying Test Case Template\n")

        print("Copying Unit Test Header")
        copy('unitTest.h',problemDIR)
        print("Done Copying Unit Test Header\n")
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

    # Change Directory
    try:
        os.chdir(problemDIR)
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

    # Create Solutions file
    print("Creating Solutions File")
    sFile = open('solution.c','w')
    sFile.close
    print("Finished Creating Solutions File\n")

    # Open & Create Instructions Markdown file
    print("Creating Instructions Markdown File")
    mdFile = open('instructions.md','w')
    mdFile.write('# ' + problemName + '\n\n') # Make Header
    mdFile.write('#### *Created by user:* `' + problemCredit + '`\n---\n') # Credit User
    mdFile.write(problemDesription) # Write Problem Description
    mdFile.close
    print("Finished Creating Instructions Markdown File\n")