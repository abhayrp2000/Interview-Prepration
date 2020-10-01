#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug  7 23:30:32 2020

@author: akashkumar
"""

nums = [-2,1]
temp = [0 for _ in range(len(nums))]
temp[0] = nums[0]
for i in range(1, len(nums)):
    temp[i] = max(nums[i], temp[i-1] + nums[i])

