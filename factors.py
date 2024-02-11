#!/usr/bin/python3
"""factorize module"""
import sys

def factor(value):
    """print simple factor of integer number as n=p*q"""
    ref = 2

    while value % ref and value > ref:
        ref += 1

    print("{:.0f}={:.0f}*{:.0f}".format(value, value / ref, ref))

if len(sys.argv) != 2:
    print("no file to open")
    exit()

try:
    with open(sys.argv[1]) as file:
        line = file.readline()

        while line != "":
            value = int(line.split('\n')[0])
            factor(value)
            line = file.readline()

except Exception as e:
    print("Error to open file: {}".format(sys.argv[1]))
    print(e)
