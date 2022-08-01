#!/usr/bin/python3
import sys 
from itertools import cycle

def encrypt(var, key, byteorder=sys.byteorder):
        while len(key) < len(var):
                key += key

        key, var = key[:len(var)], var[:len(key)]
        int_var = int.from_bytes(var, byteorder)
        int_key = int.from_bytes(key, byteorder)
        int_enc = int_var ^ int_key
        return int_enc.to_bytes(len(var), byteorder)

   
key = bytes(sys.argv[1], 'utf-8')
data = sys.stdin.buffer.read()

sys.stdout.buffer.write(encrypt(data, key))

