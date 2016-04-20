import csv
import time
import sys

def access_db(name, ext = ".csv"):
    print "\nAccessing {0} database...".format(name)
    ifile = open(name + ext, "rb")
    reader = csv.reader(ifile)

    # Read in the input.
    try:
        data = readCSV(reader)
    except:
        print "Unexpected error:", sys.exc_info()[0]
        raise

    # Only print out the first 10 entries of the
    # database if the database has more than 10 entries.


    # Accessing DB main memu
    while(True):
        print("\nPossible actions:")
        print("0. Print the first n entries.")
        print("1. View an entry.")
        print("2. Append a new entry to the end.")
        print("3. Modify an entry.")
        print("4. Sort the database based on a criteria.")
        print("5. Go back to the main menu.\n")

        option = raw_input("> ")
        if (option == "1"):
            key = raw_input("Please enter the name of the key: ")
            try:
                view_entry(key, data)
            except KeyError:
                print "No key found."
                print "You mean these entries?"
                view_entries_by_number(key, data)
        elif (option == "0"):
            n = raw_input("Please enter the number of desired entries: ")
            print_entries(data, n)
        elif (option == "2"):
            append_entry(data)
        elif (option == "3"):
            key = raw_input("Please enter the name of the key: ")
            try:
                modify_entry(key,data)
            except KeyError:
                print "No key found."
                view_entries_by_number(key, data)
        elif (option == "4"):
            # Print out the mapping of the criterias first.
            crit = raw_input("Please enter the criteria: ")
            sort_db(data, crit)
        elif (option == "5"):
            print "Going back to the main menu...\n"
            # Any change to the directory must be save.
            change = True
            if (change):
                # Write the current database to csv file.
                with open(name + ext, 'wb') as csvfile:
                    csvWriter = csv.writer(csvfile)
                    
                    for key in data:
                        entry = key

                        for item in data[key]:
                            entry = entry + ' ' + item
                        csvWriter.writerow(entry.split())

                # Finish writing changes

            time.sleep(2)
            break;
        else:
            print "\nInvalid choice! Please pick again!\n"
            time.sleep(3)
        print

    return

def print_entries(database, n = 5):
    if len(database) == 0:
        print "The database is empty."
        return

    c = 0;
    for key, value in database.iteritems():
        if (c > n or c > len(database)):
            break
        else:
            print key + " " + " ".join(database[key])


""" This function reads in the csv file.
    Check for bad input. If bad input is detected,
    print out corrupted database.
"""
def readCSV(reader):
    data = dict()
    for row in reader:
        data[row[0]] = []
        for i in range(1, len(row)):
            data[row[0]].append(row[i].strip())

    return data

def view_entry(key, database):
    if len(database) == 0:
        print "The database is empty."
        return

    data_entry = database[key]
    print "\n" + key
    print "Read & Understand the problem: " + data_entry[0]
    print "Solve the problem on paper: " + data_entry[1]
    print "Write pseudocode: " + data_entry[2]
    print "Translate pseudocode into real code & perform testing locally: " + data_entry[3]
    print "Test code online: " + data_entry[4]
    print "Review and read editorial: " + data_entry[5]
    sys.stdout.write("Problem category: ")
    for i in range(6, len(data_entry)):
        if i < len(data_entry) - 1:
            sys.stdout.write(data_entry[i] + ", ")
        else:
            sys.stdout.write(data_entry[i])
    return

def view_entries_by_number(number, database, listAll = False, n = 2):
    c = 0
    keys = []

    # TODO: Think up a better way to query a search string in the entry.
    # Hint: Using regular expression.
    for key in database:
        if (number in key):
            c += 1
            keys.append(key)

    print "You mean these entries?"
    if (listAll):
        for key in keys:
            print key + " ".join(database[key])
    else:
        for i in range(n):
            print keys[i] + " " + " ".join(database[keys[i]])
            if i == n - 1 and len(keys) - n != 0:
                print "There are {} more entries.".format(len(keys) - n)
    return

def append_entry(database):
    in_str = raw_input("Input the entry info:\n")

    # Use regex to verify if the input entry is a good entry.
    entry = in_str.split(",")
    for item in entry:
        item.strip()
    
    print 
    if entry[0] not in database:
        database[entry[0]] = []

        for i in range(1, len(entry)):
            database[entry[0]].append(entry[i])
    else:
        print "Entry exists."

    return

def modify_entry(key, database):
    return

def sort_db(database, crit = "problem_code"):
    return

