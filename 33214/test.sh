a=a.txt
echo "enter word key search"
read b
while test 1 -eq 1 
do
echo "enter what to search :: 1-roll  2-name  3-surname 4-city"
read c
 if test $c -eq 1;then
      grep $b $a|cut -f1 -d "|"
 elif test $c -eq 3;then     
      grep $b $a|cut -f2 -d "|"    
 elif test $c -eq 2;then     
      grep $b $a|cut -f3 -d "|"  
 elif test $c -eq 2;then     
      grep $b $a|cut -f4 -d "|"       
 fi    
done
