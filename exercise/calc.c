/********************************************************

  calc.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
/* a + b */
int add(int a,int b)
{
    int ret = 0;
    
    ret = a + b;
    return ret;
}

/* a - b */
int sub(int a, int b)
{
    int ret = 0;
    
    ret = a - b;
    return ret;
}

/* a * b */
int multi(int a, int b)
{
    int ret = 0;
    
    ret = a * b;
    return ret;
}

/* a / b */
float divide(int a, int b)
{
    int ret = 0.0;

    if (b == 0){
	perror("Can't divide by 0");
    }
    
    ret = a/b;
    return ret;
}

main()
{
    int result = 0;
    double result_d = 0.0;

    result = add(100,100);
    printf("100 + 100 = %d\n",result);
    result = sub(100,50);
    printf("100 - 50 = %d\n",result);
    result = multi(10,30);
    printf("10 * 30 = %d\n",result);
    result_d = divide(100,100);
    printf("100 / 100 = %f\n",result_d);
}
