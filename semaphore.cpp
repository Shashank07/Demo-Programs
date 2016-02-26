#include<unistd.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

sem_t sema;

void *ThreadFunc(void *args)
 {
	while (1)
	 {
	         sem_wait(&sema);
       		 cout<<"Within the thread!\n";
       		 sem_post(&sema);
  		 sleep(3);
   	 }
}

int main()
{
    
    // initialize semaphore, only to be used with threads in this process, set value to 1
    sem_init(&sema, 0, 1);
    
    pthread_t mythread;
    cout<<"Starting thread, semaphore Variable is unlocked.\n";

    pthread_create(&mythread, NULL, &ThreadFunc, NULL);
    char a;
    cout<<"Enter any character to lock the semaphore and pause the execution :\n";
    cin>>a;

    sem_wait(&sema);

    cout<<"Semaphore Variable is locked.\n";
    cout<<"Now enter any character to  unlock the semaphore :";
    cin>>a; 
    cout<<"Semaphore Variable is unlocked,and the threads execution continues\n";
    sem_post(&sema);
    
    sleep(7);
    cout<<"Now program will be stopped by the main thread!!\n";
    sleep(1);

    return 0;
}
