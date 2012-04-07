/********************************************************

  file-write.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

void main(){
  char *buffer = "追加したよ!!\n";
  FILE *fp;
  fp = fopen("test.dat", "a");

  // ファイルオープン失敗か？
  if ( !fp ){
    printf("ファイルオープンエラー\n");
    return;
  }

  // 文字を書き込む
  if ( EOF == fputs(buffer, fp) )
    printf("ファイル書き込みエラー\n");

  // ファイルクローズ
  fclose(fp);
  printf("test.datに追加しました。\n");
}
