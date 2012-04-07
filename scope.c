/********************************************************

  scope.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

void increment(){
  static int  i = 10;
  int j = 10;

  printf("static i = %d\n", i);
  printf("auto j = %d\n", j);
  i += 10;
  j += 10;
}

void main(int argc,char** argv){
  int i;
  for (i = 0;i < 3;i++){
    increment();
  }
}
