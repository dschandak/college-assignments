#!/bin/sh

echo "***RESULT***"

while [ 1 -eq 1 ]
do
echo " 1::create    2::display    3::append   4::delete   5::modify   6::show result   7::exit"
read ch

case $ch in

1)  echo "enter name of address book"
	read fl_name
    touch $fl_name   ;;

2)  cat $fl_name       ;;

3)  echo "enter roll no."
    read roll
	echo "enter name"
	read nam
	echo "enter mark1"
	read m1
	echo "enter mark2"
	read m2
	echo "enter mark3"
	read m3
	echo " | " $roll " | " $nam "|"$m1"|"$m2"|"$m3"|" | cat >> $fl_name    
	sort $fl_name | tee f1_name
	mv f1_name $fl_name ;;

	

	
4)  echo "insert name of record to delete"
	read del_roll
	grep -v $del_roll $fl_name | tee temp.txt
	mv temp.txt $fl_name ;;     

5)  echo "name of record to modify"
	read up_roll 
	
	echo "edit:: 1. name  2. mark1  3. mark2  4. mark3" 
	read ch1
	case ch1 in
	1)
			up_name=`grep $up_roll $fl_name | cut -f3 -d "|"`
			echo "enter new name"
			read new_name
			sed "s/$up_name/$new_name/" $fl_name | tee f1_name
			mv f1_name $fl_name ;;  
			
	1)
			up_m1=`grep $up_roll $fl_name | cut -f4 -d "|"`
			echo "enter new address"
			read new_m1
			sed "s/$up_m1/$new_m1/" $fl_name | tee f1_name
			mv f1_name $fl_name ;;  		  
	
	1)
			up_m2=`grep $up_roll $fl_name | cut -f5 -d "|"`
			echo "enter new address"
			read new_m2
			sed "s/$up_2/$new_2/" $fl_name | tee f1_name
			mv f1_name $fl_name ;;  
			
	1)
			up_m3=`grep $up_roll $fl_name | cut -f6 -d "|"`
			echo "enter new address"
			read new_m3
			sed "s/$up_m3/$new_m3/" $fl_name | tee f1_name
			mv f1_name $fl_name ;;  
			esac
							;;

6)    echo "enter roll no. "
	  read res_roll
	  up_m1=`grep $res_roll $fl_name | cut -f4 -d "|"`
	  up_m2=`grep $res_roll $fl_name | cut -f5 -d "|"`					
	  up_m3=`grep $res_roll $fl_name | cut -f6 -d "|"`
	  
	  avg1=`expr $up_m1 + $up_m2 + $up_m3`
	  avg=`expr $avg1 / 3`
	  
	  if [ avg  ]
	  
	  
	  							
7) exit ;;	


esac

done	
   

