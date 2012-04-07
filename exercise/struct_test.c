/********************************************************

  struct_test.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

struct point {
  int x;
  int y;
};

struct point s_func(int x,int y){
  struct point lp;
  
  lp.x = x;
  lp.y = y;

  return lp;
}

main()
{
  struct point p;

  p = s_func(3,12);
  printf("x = %d y = %d\n",p.x,p.y);

}
