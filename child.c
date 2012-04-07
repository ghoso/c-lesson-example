/********************************************************

  child.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CHILD_NUM 10

int main(void){
  pid_t result_pid;
  int i;

  for(i = 0;i < CHILD_NUM;i++){
    result_pid = fork();
    
    switch(result_pid){
    /* 子プロセス */
    case 0:
      fprintf(stdout,"child process.\tpid = %d.\tmy ppid = %d\n",getpid(),getppid());
      sleep(i*3);
      break;
    /* fork失敗 */
    case -1:
      fprintf(stderr,"fork failed.\n");
      break;
    default:
      break;
    }
    /* 親プロセス */
    if(result_pid == 0){
      return 0;
    }
  }

  /* 親プロセスが子プロセスの終了を待つ */
  if(result_pid != 0){
    int status;
    int child_pid;
    i = 0;
    printf("parent process\n");
    while(i < CHILD_NUM){
      child_pid = waitpid(-1,&status,WNOHANG);
      if(child_pid > 0){
	i++;
	fprintf(stdout,"PID %d done\n",child_pid);
      }else{
	fprintf(stdout,"No child exited\n");
      }
      sleep(1);
    }
  }
  return 0;
}
