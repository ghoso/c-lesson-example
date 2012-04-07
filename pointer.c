/********************************************************

  pointer.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

int main(int argc,char** argv){
  char str[15] = "こんにちは";
  int i = 0;

  while(str[i] != '\0'){
    putc(str[i],stdout);
    i++;
  }
  putc('\n',stdout);
}
