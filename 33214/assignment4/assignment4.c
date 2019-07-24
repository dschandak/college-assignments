#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
void *prod(void *arg);
void *cons(void *arg);
int count;
#define WORK_SIZE 1024

int res,p,c;
int arr[10];
sem_t full,empty;
pthread_mutex_t work_mutex; /* protects both work_area and time_to_exit */

int main() {
int i;
res = pthread_mutex_init(&work_mutex, NULL);
if (res != 0) {
perror("Mutex initialization failed");
exit(EXIT_FAILURE);
}
pthread_t p_thread[10],c_thread[10];
void *thread_result;
res = sem_init(&empty, 0, 10);
if (res != 0) {
perror("Semaphore initialization failed");
exit(EXIT_FAILURE);
}
res = sem_init(&full, 0, 0);
if (res != 0) {
perror("Semaphore initialization failed");
exit(EXIT_FAILURE);
}
printf("please insert no. of producers :: ");
scanf("%d",&p);
printf("please insert no. of consumers :: ");
scanf("%d",&c);
printf("xdfvzxdc");
for(i=0;i<p;i++)
{
    int * z=&i;
	res = pthread_create(&p_thread[i], NULL,prod,z );
	if (res != 0) {
	perror("Thread creation failed");
	exit(EXIT_FAILURE);
	}
}

for(i=0;i<c;i++)
{	
	int * z=&i;
	res = pthread_create(&c_thread[i], NULL,cons,z);
	if (res != 0) {
	perror("Thread creation failed");
	exit(EXIT_FAILURE);
	}
}


printf("\nWaiting for thread to finish...\n");

for(i=0;i<p;i++)
{	
	res = pthread_join(p_thread[i], &thread_result);
	if (res != 0) {
	perror("Thread join failed");
	exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
}

for(i=0;i<c;i++)
{
	res = pthread_join(c_thread[i], &thread_result);
	if (res != 0) {
	perror("Thread join failed");
	exit(EXIT_FAILURE);
	}

}
	printf("Thread joined\n");
	sem_destroy(&full);
	sem_destroy(&empty);

exit(EXIT_SUCCESS);
}
void *prod(void *arg)
{
	int pro = *(int *)arg;
	int i=rand()%7;
	int j;
	while(1){
	sleep(rand()%7);
	sem_wait(&empty);
    pthread_mutex_lock(&work_mutex);
	printf("\n\nproducer no %d added :: %d",pro,i);
	arr[count]=i;
	count++;
	printf("\n\nbuffer is:: ");
	for(j=0;j<count;j++)
	{
		printf("\t%d",arr[j]);
	}
	pthread_mutex_unlock(&work_mutex);
	sem_post(&full);
	}
	pthread_exit(NULL);
}
void *cons(void *arg) 
{
	int con = *(int *)arg;
	int j;
	while(1)
	{
	sleep(rand()%8);
	sem_wait(&full);
	pthread_mutex_lock(&work_mutex);
	printf("\n\nconsumer no. %d removes :: %d",con,arr[count-1]);
	arr[count-1]=0;
	count--;
	printf("\n\nBuffer is:: ");
	for(j=0;j<count;j++)
	{
		printf("\t%d",arr[j]);
	}
	pthread_mutex_unlock(&work_mutex);
	sem_post(&empty);
	}
	pthread_exit(NULL);
}
