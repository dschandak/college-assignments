#!/bin/sh

if [ $# -ne 2 ] ; then

 echo "give first number"
 read a
 echo "give second number"
 read b
 
 sh mal.sh $a $b 
 exit 0
 
fi 

 echo "$1+$2" | bc

 echo `expr $1 + $2`
