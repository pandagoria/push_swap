#!/usr/bin/env python3

import random
import sys

def main():
    number = sys.argv[1]
    numbers = random.sample(range(-100, 900), int(number))
    random.shuffle(numbers)
    for j in numbers:
        print(j, end=' ')
    print("\n");

main()
