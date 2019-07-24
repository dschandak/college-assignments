#!/bin/sh

echo "FILE OPERATIONS"

while [ 1 -eq 1 ]
do
echo " 1::create  2::display  3::append"
read ch

case $ch in

1)  echo "enter file name"
	read fil
	echo " press ctrl+d after writing"
	cat > $fil     ;;
	
2)  cat $fil       ;;

3)	echo " press ctrl+d after writing" 
	cat >> $fil
esac

done	
   
