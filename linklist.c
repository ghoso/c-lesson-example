/********************************************************

  linklist.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <malloc.h>

typedef struct _cell_t
{
  struct _cell_t *next;
  int data;
}cell_t;

extern int setList(cell_t *p, int data);
extern int deleteList(cell_t* p);
extern void allDeleteList(cell_t *p);

cell_t g_cell;//セルの先頭（このセルにはデータを入れない）

int main(int argc, char** argv)
{
  g_cell.next = NULL;//先頭のセルの初期化
  setList(&g_cell, 0);
  setList(g_cell.next, 1);
  setList(g_cell.next, 2);
  setList(g_cell.next, 3);
  cell_t *cp = NULL;
  int i = 0;
  for (cp = g_cell.next;cp != NULL;cp = cp->next,i++){
    printf("%dth cell data = %d\n",i,cp->data);
  }
  /* deleteList(&g_cell); */
  allDeleteList(&g_cell);
  
  return(0);
}

/* 
   int setList(cell_t* p, int data)
   新規セルの挿入
 　*p 挿入したいセルのポインタ（この直後にセルを挿入する）
 　data データ
 　返却値 -1の時はデータのセットができなかった時、正常時は0を返す
*/
int
setList(cell_t* p, int data)
{
  cell_t *tmp;
  tmp = (cell_t*)malloc(sizeof(cell_t));
  if(tmp == NULL)
    {
      return(-1);
    }
  
  tmp->next = p->next;
  tmp->data = data;
  p->next = tmp;
  return(0);
}


/* 
   int deleteList(cell_t* p)
   引数で受け取ったセルの次のポインタのデータを削除
   *p 削除したいセルを指しているポインタ
   返却値 -1:エラー 0:正常終了
*/
int
deleteList(cell_t* p)
{
  cell_t *tmp;
  if(p->next == NULL)
    {
      return(-1);
    }
  tmp = p->next;
  p->next = tmp->next;
  free(tmp);
  return(0);
}

/*
 void allDeleteList(cell_t *p)
   データの全削除
   *p 先頭のセルのポインタ
*/
void
allDeleteList(cell_t *p)
{
  cell_t *tmp;
  while (p->next != NULL)
    {
      tmp = p->next;
      p->next = tmp->next;
      free(tmp);
    }
}
