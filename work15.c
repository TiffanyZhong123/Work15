#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
int main(){
  srand(time(NULL));
  printf("Before forking!\n");
  int a = fork();
  //child 1
  if(a == 0){
    printf("PID of child process1: %d\n", getpid());
    int randint = rand()%16 + 5;
    sleep(randint);
    printf("Child %d has woken up!\n",getpid());
    return randint;
  }
  else{
    int b = fork();
    //child 2
    if(b == 0){
    printf("PID of child process2: %d\n", getpid());
    int randint = rand()%16 + 5;
    sleep(randint);
    printf("Child %d has woken up!\n",getpid());
    return randint;
  }
    else{
      //parent
      int status;
      int x = wait(&status);
      printf("PID of completed child process:%d\n",x);
      printf("Child slept for %d seconds.\n", WEXITSTATUS(status));
      printf("Parent process is completed.\n");
      return 0;
    }
  }
  return 0;
}
