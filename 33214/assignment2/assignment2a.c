#include <sys/types.h>
       #include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>
       
void quicksort(int number[15],int first,int last){
   int i, j, pivot, temp;

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
           pid_t pid,epid;
           
	 	   printf("enter no. of elements in array::");
	 	   scanf("%d",&n);	
	 	   printf("please enter the no. in array::");
	 	   for(i=0;i<n;i++)
	 	   {
	 	   		scanf("%d",&arr[i]);	
	 	   }
	 	   for(i=0;i<n;i++)
	 	   {
	 	   		arr1[i]=arr[i];	
	 	   }
			
           pid = fork();
           if (pid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (pid == 0) 
           {    /* Child reads from pipe */
              epid=getpid();
              printf("\nthe pid of child is :: %d",epid);
			  printf("\nThis is child program!!!");
			 // printf("old parent pid:: %d",getppid());
			  sleep(1);
			 
			  //array sorting
			  for(i=0;i<n;i++)
			  {
			  	for(j=0;j<n-1;j++)
			  	{
			  		if(arr[j]>arr[j+1])
			  		   {  
			  		   		temp=arr[j]; 
							arr[j]=arr[j+1];
							arr[j+1]=temp;
					   }			  		      
			  	}
			  }  
			  printf("\n\nsorted array of child is ::\t ");
			  for(i=0;i<n;i++)
			  {
			  	printf("%d\t",arr[i]);
			  }	
           } 
           
           else {            /* Parent writes argv[1] to pipe */
             sleep(10);
               epid=getpid();
              printf("\n\nthe pid of parent is :: %d",epid);
			  printf("\n\nThis is parent program!!!");	
			  wait(NULL);
			  quicksort(arr1,0,n-1);
			  printf("\n\nsorted array of parent is ::\t ");
			  for(i=0;i<n;i++)
			  {
			  	printf("%d\t",arr1[i]);
			  }	
           }
       }

