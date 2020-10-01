#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 10:41:49 2020

@author: akashkumar
"""

from collections import defaultdict

arr = [3, 34, 4, 12, 5, 2]
s = 9
d = defaultdict(lambda : 0)
for i in range(len(arr)):
    if arr[i] in d:
        print((s-arr[i], arr[i]))
        break
    else:
        d[s - arr[i]] += 1


 
