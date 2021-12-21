#!/usr/bin/env python3

import random

def main():
    numbers = random.sample(range(-100, 900), 100)
    random.shuffle(numbers)
    for j in numbers:
        print(j, end=' ')
    print("\n");

main()
