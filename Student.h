#ifndef STUDENT_H
#define STUDENT_H

#include <stdlib.h>

#define Len sizeof(struct Student)

struct Student
{
	long num;
	float score;
	struct Student * next;
};

typedef struct Student Stdnt;

extern Stdnt * creatList(void);	/* creat the linked list */
extern void add (Stdnt *);	/* add one element at the end of the list */
extern void insert(Stdnt *);	/* insert one element behind the m-th el
					 * element
					 */
extern void delete(Stdnt *);	/* delete the element num */
extern int is_empty(Stdnt *);	/* check if the list is empty */
extern int is_last(Stdnt *);	/* check if m-th is the last element */
extern Stdnt * find(Stdnt *);	/* find the element with num */
extern Stdnt * find_pre(Stdnt *, long num);/* find the element pointer before
					 * element num */ 
extern void delete_list(Stdnt *);	/* delete the list */
extern Stdnt * creatStd(void);
extern void print_list(Stdnt *);	/* print all the element */
extern int List_exist(Stdnt *);	

#endif
