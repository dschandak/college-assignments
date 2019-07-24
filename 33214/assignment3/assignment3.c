#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define NUM_THREADS 6

struct mat
{
	int q,p,k,l,m,n,arr[5][5],brr[5][5];
};
int c[5][5];
void * multiply(void* arg);
int main() 
{
int res;
time_t t;
pthread_t a_thread[5][5];
void * thread_result;
int lots_of_threads,i,j;
int r1,c1,r2,c2,y,z,arr1[5][5],arr2[5][5];
struct mat M;
printf("enter no of row and column for matrix 1::");
scanf("%d%d",&r1,&c1);
printf("enter no of row and column for matrix 2::");
scanf("%d%d",&r2,&c2);
if(c1==r2)
{
	printf("enter element for matrix 1::\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d x %d :: ",i+1,j+1);
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("enter element for matrix 2::\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d x %d :: ",i+1,j+1);
			scanf("%d",&arr2[i][j]);
		}
	}
} 
else printf("invalid values for number of rows and columns");

printf("The matrices are::\n\n");
printf("matrix 1::\n\n");
for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("\t%d",arr1[i][j]);
		}
		printf("\n\n");
	}
printf("\n\nmatrix 2::\n\n");
for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("\t%d",arr2[i][j]);
		}
		printf("\n\n");
	}

t=time(NULL);

for(i=0;i<r1;i++)
{
	for(j=0;j<c2;j++)
	{
		struct mat M={i,j,r1,c1,r2,c2,NULL,NULL};
		for(y=0;y<r1;y++)
	{
		for(z=0;z<c1;z++)
		{
			M.arr[y][z]=arr1[y][z];
		}
	}
		for(y=0;y<r2;y++)
	{
		for(z=0;z<c2;z++)
		{
			M.brr[y][z]=arr2[y][z];
		}
	}
		struct mat * p=&M;
		res = pthread_create(&(a_thread[i][j]), NULL, multiply,p);
		if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
		}	
		
	}
}

for(i=0;i<M.k;i++)
{
	for(j=0;j<M.n;j++)
	{	
		res = pthread_join(a_thread[i][j], &thread_result);	
	}
}

for(y=0;y<r2;y++)
	{
		for(z=0;z<c1;z++)
		{
			printf("%d\t",c[y][z]);
		}
		printf("\n\n");
	}

printf("All done\n");
t=time(NULL)-t;
printf("%ld",t);
//normal method
t=time(NULL);
int mul[5][5];
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            mul[i][j]=0;
            for(int k=0;k<c2;k++)
            {
                mul[i][j]=mul[i][j]+arr1[i][k]*arr2[k][j];
            }
        }
    }
 
    printf("The resultant matrix formed on multiplying the two matrices\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
    t=time(NULL)-t;
printf("%ld",t);

exit(EXIT_SUCCESS);

}
void * multiply(void* arg) 
{
struct mat * N =arg;
int x=0,i,j;
for(i=0;i<N->l;i++)
{
	x += N->arr[N->p][i] * N->brr[i][N->q];
}
c[N->p][N->q]=x;

//rand_num=1+(int)(9.0*rand()/(RAND_MAX+1.0));
//sleep(rand_num);
pthread_exit(NULL);
}



