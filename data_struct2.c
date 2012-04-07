/********************************************************

  data_struct2.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  /* 構造体 */
  struct record{
    int id;
    char name[10];
  };

int main(int argc,char** argv){
  struct record user_master;

  user_master.id = 1;
  strcpy(user_master.name,"Yamada Taro");
  printf("struct user_master: ID=%i Name=%s\n",user_master.id,user_master.name);

  exit(0);
}
