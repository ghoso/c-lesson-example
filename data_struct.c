/********************************************************

  data_struct.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
  /* array */
  int ac[10];


  ac[0] = 10;
  ac[1] = 20;
  ac[2] = 30;

  int ac_total = ac[0] + ac[1] + ac[2];
  printf("Total = %i\n",ac_total);
  exit(0);
    
}
