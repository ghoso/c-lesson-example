/********************************************************

  for-ctl.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  char num_str[3];

  printf("type number of loop[1-100]: ");
  fgets(num_str,sizeof(num_str),stdin);
  
  int num = atoi(num_str);

  printf("Count start !!\n");
  int i;
  for (i = 0;i < num;i++){
    sleep(1);
    printf("%i\n",i+1);
  }  
  printf("Count done !!\n");

  exit(0);
}
