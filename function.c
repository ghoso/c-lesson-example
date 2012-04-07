/********************************************************

  function.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>

/* プロトタイプ宣言 */
/* int get_loop_num(); */
/* void show_output(int) */

int get_loop_num()
{
  char num_str[3];

  printf("type number of loop[1-100]: ");
  fgets(num_str,sizeof(num_str),stdin);
  
  int num = atoi(num_str);
  return num;
}

void show_output(int num){
  printf("Count start !!\n");
  int i = 0;
  while (i < num){
    sleep(1);
    printf("%i\n",i+1);
    i++; 
  }  
  printf("Count done !!\n");
}


int main(int argc, char** argv){
 
  int lnum = get_loop_num();
  show_output(lnum);
 
  exit(0);
}
