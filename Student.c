#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "Input.h"


int List_exist(Stdnt * Head)
{
	int exist;
	if (Head == NULL){
		printf("List doesn't exist!\n");
		return 0;
	}
	else
		return 1;
}

Stdnt * creatStd(void)
{
	Stdnt * Std;
	Std=(Stdnt *) malloc (sizeof(Stdnt));
	if (Std==NULL) {
		printf(" Out of space!!!");
	}
	else {
		printf(" Please input the student's information:\n");
		scanf("%ld,%f",&Std->num, &Std->score);
		in_clear();
	}

	return Std;
}



/* Creat the list and return the pointer as the Header of the list. The first
 * element contains nothing.
 */
Stdnt * creatList(void)
{
	Stdnt * Std;
	Std=(Stdnt *) malloc (sizeof(Stdnt));

	
	if (Std != NULL) 
		Std->next=NULL;
	
	return Std;
}


void add(Stdnt * Head)
{
	Stdnt * p;
	if (List_exist(Head)){
		p=Head;
		while(p->next != NULL)
			p=p->next;

		p->next=creatStd();
		p->next->next=NULL;
	}
}

void insert(Stdnt * Head)
{
	int i,m;
	Stdnt * Std, * tmp;
	if (List_exist(Head)){
		Std=Head;
		char buf;	
		printf("Please input the insert position (after):");
		scanf("%d",&m);
		in_clear();
		for (i=0;i<m;i++){
			if (Std->next == NULL) {
				printf(" index %d out of the range of the list!\n", m);
				return;
			}
		
			Std=Std->next;		
		}	
	
		tmp=creatStd();
		tmp->next=Std->next;
		Std->next=tmp;
	}
}


Stdnt * find_pre(Stdnt * Head, long num)
{	
	Stdnt * Std;
	if(List_exist(Head)) {
		Std=Head;
		while((Std->next != NULL ) && (Std->next->num != num))
			Std=Std->next;
	
		return Std;
	}
	else
		return NULL;
}


void delete(Stdnt * Head)
{
	
	Stdnt * Std,* tmp;
	long num;
	if (List_exist(Head)) {
		printf("Please input the num you want to delete: ");
		scanf("%ld",&num);
		in_clear();
		Std=find_pre(Head,num);
		if (Std->next != NULL) {
			tmp=Std->next;
			Std->next=tmp->next;
			free(tmp);		/* Note: the space of the delete
						 * element should be free */
		}
	}

}


Stdnt * find(Stdnt * Head)
{
	Stdnt * Std;
	long num;
	if (List_exist(Head)) {
		printf("Please input the num you want to find: ");
		scanf("%ld", &num);
		in_clear();

		Std=find_pre(Head,num);
	
		if(Std->next != NULL)
			Std=Std->next;
	
		return Std;
	}
}

void delete_list(Stdnt * Head)
{
	Stdnt * Std,* tmp;
	if (List_exist(Head)){
		Std=Head;
		tmp=Std->next;
		while(tmp != NULL) {
			free(Std);
			Std=tmp;
			tmp=tmp->next;
		}
		free(Std);
	}

}



void print_list(Stdnt * Head)
{
	Stdnt * Std;

	if (List_exist(Head)) {	
		Std=Head->next;
		if (Std !=NULL) {
			printf("Num\tScore\n");
			while(Std != NULL) {
				printf("%ld\t%.2f\n",Std->num,Std->score);
				Std=Std->next;
			}
		}	
		else {
			printf(" The list is empty!\n ");
		}
	}
}
