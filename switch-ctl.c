/********************************************************

  switch-ctl.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
  char ch;
  char msg[100];

  printf("type A or B: ");
  scanf("%c",&ch);

  switch(ch){
  case 'A' : 
    strcpy(msg ,"A is selected !\n");
    break;
  case 'B' : 
    strcpy(msg,"B is selected !\n");
    break;
  default :
    strcpy(msg,"I don't know what you typed !!\n");
    break;
  }

  printf("%s",msg);

  exit(0);
}
