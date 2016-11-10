#!/usr/bin/python3
#Kenneth Adair
#Taken from an example from Chris Brown's "Linux systems programming" course on Pluralsight.
import os

fout = os.open("foo", os.O_WRONLY | os.O_CREAT, 0o644)

os.write(fout, bytes("hello world", "utf-8"))
os.close(fout)
