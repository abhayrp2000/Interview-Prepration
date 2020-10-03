#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 00:16:25 2020

@author: akashkumar
"""

from collections import defaultdict
s = "akash"
d = defaultdict(lambda: 0)
l = list(s)
for i in l:
    d[i] += 1
ans = []
for key, val in d:
    if val == 1:

l.index('k')



s = "leetcode"
d = defaultdict(lambda: 0)
l = list(s)
for i in l:
    d[i] += 1
for key, val in d.items():
    if val == 1:
        print(l.index(key))
return -1




len(s)

import collections
count = collections.Counter(s)
for idx,ch in enumerate(s):
    print(ch, count[ch])
    
import collections
    
s = "anagram"
l = list(s)
c = collections.Counter(s)
d = defaultdict(lambda:0)
for idx,ch in enumerate(s):
    print(count[ch])
    d[ch] = count[ch]
    
    
str(,)
    
    