#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 11:12:34 2020

@author: akashkumar
"""

import re
s = "A man, a plan, a canal: Panama"
a = "".join(re.split("[^a-zA-Z]*", s)).lower()
r = a[::-1]
j = len(a)-1
arr = list(a)
for i in range(int(len(a)/2)):
    if arr[i] != arr[j]:
        print(False)
    j -= 1
print(True)


s = "4193 with words"
a = int("".join(re.split("[^-1-9]*", s)))

string = "geeksforgeeks" 
string.count("geeks")

int(s)