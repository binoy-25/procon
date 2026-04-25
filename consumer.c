#include<stdio.h>
#include<sys.ipc.h>
#include<sys.shm.h>
int main()
{
key_t key=ftok("shmfile",65);
int shmid=shmget(key,1024,0666);
char* str=(char* str)shmat(shmid,NULL,0);
int n,r,nf,rf,nrf;
sscanf(str,"%d%d%d%d%d",&n,&r,&nf,&rf,&nrf);
printf("\nConsumer\n");
printf(""%d%d%d%d%d",n,r,nf,rf,nrf);
  shmdt(str);
shmctl(shmid,IPC_RMID,NULL);
return 0;
}
