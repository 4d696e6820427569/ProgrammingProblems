#!/usr/bin/env python


""" This program helps me track the number of problems I have solved.

    Each entry of the database is mapped with:
        Problem code name -> The time duration for each step of the deliberating practice
        process

    The deliberating practice process:
        1. Read and understand the problem statement.
        2. Solve the problem on paper.
        3. Write pseudocode.
        4. Translate pseudocode into real code.
        5. Perform testing locally.
        6. Test the code online.
        7. Debugging code.
        8. Review and read the editorial.

    The program is designed as a center consisting of external databases.
    Each database is a set of solved problems from online site such as TopCoder, UVA, etc
    At the initialization step, the program search for files ending with '.db' in the current
    directory.

"""


# Importing libaries and modules
import time
import datetime
import anydbm
import glob
import os
import csv
import AccessDB

def main():
    # Defining some default stuffs.
    MAX_NUM_ACTIONS = 3

    DB_REL_DIR = "./"
    DB_EXT = ".csv"

    os.system('clear')
    print "Welcome to CP Tracker!"


    while(True):

        # List out the current databases.
        db_listing(DB_REL_DIR, DB_EXT)

        # List out the possible actions the user can make.
        print "\nPossible actions:"
        print "1. Create a new database."
        print "2. Import an external database."
        print "3. Access a database."
        print "4. List all the databases."
        print "5. Configure global variables."
        print "Enter q to quit.\n"

        option = raw_input("> ")
        if (option == "1"):
            name = raw_input("DB Name: ")
            create_db(name, DB_EXT)
        elif (option == "2"):
            continue
            break
        elif (option == "3"):
            name = raw_input("DB name that you want to access (without the .csv): ")
            AccessDB.access_db(name, DB_EXT)
        elif (option == "q"):
            break
        elif (option == "4"):
            db_listing()
        elif (option == "5"):
            config_global()
        else:
            print "\nInvalid choice! Please pick again!\n"
            time.sleep(2)


    return

def create_db(name, ext = ".csv", directory = "./"):
    for file in os.listdir(directory):
        if file == (name + ext):
            print "The database's name exists."
            answer = raw_input("Do you want to overwrite the existed database? (y/n)")
            if (answer == "n"):
                return

    ofile = open(name + ext, "wb")
    ofile.close()
    return


def db_listing(directory = "./", ext = ".csv"):

    print "Listing the databases in the current directory...\n"
    time.sleep(1)

    db_lists = list()
    for file in os.listdir(directory):
        if file.endswith(ext):
            print(file)
            db_lists.append(file)

    if (len(db_lists) == 0):
        print "There's no found database in the current directory.\n"
    else:
        print

    return

def config_global():
    return

if __name__ == "__main__":
    main()
