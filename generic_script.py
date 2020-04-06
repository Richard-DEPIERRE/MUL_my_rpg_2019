#!/usr/bin/env python3

import sys
import math

g = open(sys.argv[1][0: len(sys.argv[1]) - 4] + "txt", "w+")
f = open(sys.argv[1], 'r')
numbers = ""
data1 = []
data2 = []
data3 = []
data4 = []
data5 = []

for i in range(5) :
    l = f.readline()

for i in range(145 - 5) :
    numbers += f.readline()

numbers = numbers.split(',')

for i in numbers :
    data1.append(int(i))

for i in range(149 - 145) :
    f.readline()

numbers = ""

for i in range(289 - 159) :
    numbers += f.readline()

numbers = numbers.split(',')

# for i in numbers :
#     data2.append(int(i))

for i in range(293 - 289) :
    l = f.readline()

numbers = ""

for i in range(433 - 293) :
    numbers += f.readline()

numbers = numbers.split(',')

# for i in numbers :
#     data3.append(int(i))

for i in range(437 - 433) :
    f.readline()

numbers = ""

for i in range(577 - 437) :
    numbers += f.readline()

numbers = numbers.split(',')

# for i in numbers :
#     data4.append(int(i))

for i in range(591 - 577) :
    f.readline()

numbers = ""

for i in range (721 - 581) :
    numbers += f.readline()

numbers = numbers.split(',')

for i in range(len(numbers)) :
    g.write(numbers[i])
    if (i + 1 in range(len(numbers))) :
        g.write(":")

f.close()
g.close()