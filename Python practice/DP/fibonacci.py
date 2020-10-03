#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 10:32:33 2020

@author: akashkumar
"""

def fib(n):
    arr = [0, 1]
    for i in range(2, n):
        arr.append(arr[i-1] + arr[i-2])
    print(arr)
        
fib(9)
