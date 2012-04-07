/********************************************************

  file-read.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

#define BUFFER_SIZE 512

void main(int argc,char **argv){
  char buffer[BUFFER_SIZE];
  FILE *fp;

  fp = fopen("test.dat", "r");

  if (!fp){
    printf("ファイルオープンエラー\n");
    return;
  }

  // １行ずつ読み込んで表示する
  while( fgets(buffer, BUFFER_SIZE, fp) ){
    printf("%s", buffer);
  }

  // ファイルクローズ
  fclose(fp);
}
