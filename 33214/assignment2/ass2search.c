#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle itself 
        if (arr[mid] == x)  return mid; 
  
        // If element is smaller than mid, then it can only be present 
        // in left subarray 
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); 
  
        // Else the element can only be present in right subarray 
        return binarySearch(arr, mid+1, r, x); 
   } 
  
   // We reach here when element is not present in array 
   return -1; 
} 

int main(int argc, char *argv[])
{
	int i,n,x;
	int arr[15];
	char str[15];
	
	printf("executed\n");
    printf("\n");

     printf("\n");
	printf("\nInsert number to be searched::");
	scanf("%d",&x);
	strcpy(str,*argv);
	for(i=0;str[i]!='\0';i++)
	{
		arr[i]=str[i] - '0';
	}
	n=i;

	int result=binarySearch(arr,0,n,x);	
	  printf("\n");
	printf("found at %d\n",result);

}
