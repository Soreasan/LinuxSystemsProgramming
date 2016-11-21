#! /usr/bin/python3
# Kenneth Adair
# This example is taken from the Linux Systems Programming course
# Add up sizes of all files in the current directory

# imports the os module which we need to interact with files and stuff
import os
# total will be used to track the size of the files in the current directory
total = 0

#This FOR loop goes through every file in the current directory
for file in os.listdir("."):
	# statinfo gets the stats about each file
	statinfo = os.stat(file)
	total = total + statinfo.st_size

print("total is", total)
