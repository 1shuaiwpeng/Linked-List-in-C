#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "Input.h"

int main(void)
{
	char cmd;
	Stdnt * Head, * Std;
	int i;
	Head=NULL;
	cmd=getchar();
	in_clear();	
	while(cmd != 'q') {
		switch(cmd)
		{
			case 'c':
				if (Head==NULL)			/* avoid recall 								 * the creatList								 * more than one								 */
					Head=creatList();
				else
					printf("List exists!\n");
				break;
			case 'i':
				insert(Head);
				break;
			case 'a':
				add(Head);
				break;
			case 'd':
				delete(Head);
				break;
			case 'f':
				Std=find(Head);
				if (Std==NULL)
					printf("No record");
				else
					printf("Num=%ld, score= %.2f\n",Std->num, Std->score);
				break;
			case 'r':
				delete_list(Head);
				Head=NULL;
				break;
			case 'p':
				print_list(Head);
				break;
			case '\n':
				break;	
			default:
				printf("invalid command!\n");
				break;
		}
		
		printf("Please input next command:");
		cmd=getchar();
		in_clear();
	}

	return 0;
}
