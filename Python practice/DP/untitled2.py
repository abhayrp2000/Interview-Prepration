#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 09:24:12 2020

@author: akashkumar
"""

9, 3

27, 9


50, 20

75, 65

def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
    
def lcm(a, b):
    return int((a*b) / gcd(a,b))
gcd(45, 17)
lcm(24, 12)
    


