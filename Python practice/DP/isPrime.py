#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug  9 13:16:10 2020

@author: akashkumar
"""

def isPrime(n):
    i = 2
    if n<=1:
        return 0
    while(i <= n/2):
        if n % i == 0:
            return 0
        i += 1
    print(n)
    return 1

count = 0
for i in range(30):
    count += isPrime(i)
    
## DP
    
n = 20
dp = [True] * n
counter = 0
if n<=1:
    print(0)
for i in range(2, n):
    if dp[i] == True:
        counter += 1
        for j in range(i,n,i):
            dp[j]=False
        
s = "leEeetcode"
def check(s):
    i = 0
    while(i < len(s) - 1):
        if (s[i+1] == s[i].upper() and s[i] == s[i+1].lower()) or (s[i+1] == s[i].lower() and s[i] == s[i+1].upper()):
            s = s[:i] + s[i+2:] 
            i += 2
        i+=1
    return s
for i in range(int(len(s)/2)):
    s = check(s)
