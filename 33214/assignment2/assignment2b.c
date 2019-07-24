#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
       
void quicksort(int number[15],int first,int last){
   int i, j, pivot, temp;
   char * arg[15];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}              
       
int main()
       {
           int arr[15],arr1[15],i,j,temp,n;
      
           char str[15];
           int * te;
           pid_t pid,epid;
           
	 	   printf("enter no. of elements in array::");
	 	   scanf("%d",&n);	
	 	   printf("please enter the no. in array::");
	 	   for(i=0;i<n;i++)
	 	   {
	 	   		scanf("%d",&arr[i]);	
	 	   }
           quicksort(arr,0,n-1);
	 	   
           pid = fork();
           if (pid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

          if(pid>0) {            /* Parent writes argv[1] to pipe */
               printf("\n");
              printf("\n\nsorted array of parent is :: ");	
               for(i=0;i<n;i++)
			  {
			  	printf("%d\t",arr[i]);
			  }	
			  
			  wait(NULL);
			  
           }

           else
           {
              sleep(2);
           	  for(i=0;i<n;i++)
			  {
			        str[i]=arr[i]+'0'; 
			  }
			  str[i]='\0';		
              char * const arg[]={str};

			  int ret = execv("./search",arg);
           } 
           
          
       }

