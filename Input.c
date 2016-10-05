#include <stdio.h>

#include "Input.h"

/* clear the garbage from the scanf or other input command */

void in_clear(void)
{
	char c;
	while(1){
		c=getchar();
		if ((c=='\n') || (c==-1))
			break;
	}	
	return ;
}
