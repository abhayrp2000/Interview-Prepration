#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 09:41:33 2020

@author: akashkumar
"""

def ugly(n):
    arr = [0]
    arr[0] = 1
    i = 1
    while(i < n):
        if i%2 == 0:
            arr.append(i)
        elif i%3 == 0:
            arr.append(i)
            
            
        elif i%5 == 0:
            arr.append(i)
        i += 1
    print(arr)
    
ugly(15)