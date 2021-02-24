#!/usr/bin/env python

from ctypes import *

def check_so(soname):
    try:
        lib = CDLL(soname)
        print("INFO: Found so as", lib)
        print("O retorno do produto: ", lib.soma(3, 2))
        return True
    except OSError as ex:
        print("WARNING:", ex)
        return False


if __name__ == "__main__":
    
    j = check_so("./libsoma.so")
    if not j:
        print("Error: Could not test")
    else:
        print("Success: J %s  \n" % j)
