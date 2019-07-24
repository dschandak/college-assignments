#!/bin/sh

echo "***ADDRESS BOOK***"

while [ 1 -eq 1 ]
do
echo " 1::create  2::display  3::append 4::delete 5::modify 6::exit"
read ch

case $ch in

1)  echo "enter name of address book"
	read fl_name
    touch $fl_name   ;;

2)  cat $fl_name       ;;

3)  echo "enter name"
	read nam
	echo "enter address"
	read add
	echo " | " $nam " | " $add " | " | cat >> $fl_name    
	sort $fl_name | tee f1_name
	mv f1_name $fl_name ;;

	

	
4)  echo "insert name of record to delete"
	read del_name
	grep -v $del_name $fl_name | tee temp.txt
	mv temp.txt $fl_name ;;     

5)  echo "name of record to modify"
	read up_name 
	up_add=`grep $up_name $fl_name | cut -f3 -d "|"`
	echo "enter new address"
	read new_add
	sed "s/$up_add/$new_add/" $fl_name | tee f1_name
	mv f1_name $fl_name ;;    
	
6) exit ;;	


esac

done	
   

