#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  8 12:19:54 2020

@author: akashkumar
"""

def count(arr):
    n = len(arr)
    count = 0
    m = arr[0]
    for i in range(1, n):
        if arr[i] < m:
            count += 1
    return count



nums = [5,2,6,1]
n = len(nums)
ans = []
for i in range(n-1):
    ans.append(count(nums[i:n]))
ans.append(0)
        


nums = [5,2,6,1]
m = nums[0]
n = len(nums)
for i in range(1, n):
    if nums[i] < m:
        print(nums[i])


n = len(nums)
ans = []
for i in range(n-1):
    arr = nums[i:n]
    k = len(arr)
    count = 0
    m = arr[0]
    for i in range(1, k):
        if arr[i] < m:
            count += 1
    ans.append(count)
ans.append(0)
