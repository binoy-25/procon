#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int fact(int n)
{
  int f=1;
  for(int i=1;i<=n;i++)
    f=f*i;
return f;
      
int main()
{  int n,r,nf,rf,nrf
  printf("Enter n;");
scanf("%d",&n);
  printf("Enter r;");
scanf("%d",&r);
nf=fact(n);
rf=fact(r);
nrf=fact(n-r);
  key_t key=ftok("shmfile",65);
  int shmid=shmget(key,1024,0666|IPC_CREAT);
  char* str=(char*)shmat(shmid,NULL,0);
sprintf(str,"%d%d%d%d%d",n,r,nf,rf,nrf);
printf("Written %d%d%d%d%d",n,r,nf,rf,nrf);
shmdt(str);
return 0;
}
