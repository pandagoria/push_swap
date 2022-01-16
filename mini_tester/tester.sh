#!/bin/sh

num=100
echo "20 тестов для $num случайных чисел"
cd ../
make &> /dev/null
i=0
echo "___________________________________________"
while [ $i -le 20 ] ;
do ./push_swap $(mini_tester/generator.py $num) | wc -l
i=$(($i + 1)) ;
done
echo "____________________________________________"
make fclean &> /dev/null
