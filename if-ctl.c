/********************************************************

  if-ctl.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

int main(int argc, char** argv){
  char ch;

  /* if */
  printf("type Y or N: ");
  scanf("%c",&ch);
  if (ch == 'Y'){
    printf("Y typed !\n");
  }else if (ch == 'N'){
    printf("N typed !\n");
  }else{
    printf("I don't know what you typed\n");
  }

}
