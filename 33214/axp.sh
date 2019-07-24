#!/bin/sh

echo "enter a"
read a
echo "enter b"
read b

while [ 1 -eq 1 ]
do
echo "1:-ADD  2:-SUB 3:-MULTIPLY  4:-DIVIDE"
read ch

case $ch in 
1) z=`expr $a + $b` ;;

2) z=`expr $a - $b` ;;
 
3) z=`expr $a \* $b` ;;

4) z=`expr $a / $b` ;;
esac

echo " $z "

done
