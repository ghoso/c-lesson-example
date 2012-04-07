/********************************************************

  count_char.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>

main(int argc,char **argv)
{
    char ch;
    int count = 0;
    
    while ((ch = getchar()) != EOF){
			if (ch != ' ' && ch != '\n' && ch != '\t'){ 
				count++;
			} 
    }

    printf("Num of character = %d\n",count);

}
