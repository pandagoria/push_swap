#!/bin/sh

i=0
while [ $i -le 20 ] ;
do ../push_swap $(./generator.py) | wc -l
i=$(($i + 1)) ;
done
