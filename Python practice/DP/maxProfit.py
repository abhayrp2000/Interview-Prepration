#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug  7 22:45:22 2020

@author: akashkumar
"""

def maxProfit(prices):
    if len(prices)==0:
        return 0
    buyprice=prices[0]
    profit=[0]*len(prices)
    for i in range(1,len(prices)):
        buyprice=min(buyprice,prices[i])
        maxprofit=max(profit[i-1],prices[i]-buyprice)
        profit[i]=maxprofit
    return profit[-1]
maxProfit([7,1,5,3,6,4])

