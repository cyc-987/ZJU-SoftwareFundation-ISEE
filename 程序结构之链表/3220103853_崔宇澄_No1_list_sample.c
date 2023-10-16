#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>

#define MaxLength 10

typedef struct LIST
{
	char name[MaxLength];
	int length;
	struct LIST *next;
}LIST;


void print_list(LIST *p) /* Print all the node of the list. */
{
	if(p == NULL) return;
	while(p != NULL){
		printf("%s\n",p->name);
		p = p->next;
	}
}


LIST * insert_node(LIST *head, char x[MaxLength], int k)
{
	LIST *p = head;
	LIST *temp = NULL;
	
	LIST *nodeTobeInsert = (LIST*)malloc(sizeof(LIST*));
	strcpy(nodeTobeInsert->name, x);
	nodeTobeInsert->length = strlen(x);
	nodeTobeInsert->next = NULL;

	if(k == 0){
		head = nodeTobeInsert;
		head->next = p;
	}else{
		int i = 1;
		while(p->next != NULL) {
			if(i == k) break;
			p = p->next;
			i++;
		}

		if(i < k) return NULL;
		else{
			temp = p->next;
			p->next = nodeTobeInsert;
			nodeTobeInsert->next = temp;
		}

	}

	return(head);
}

int delete_node(LIST *head, int i)
{
	LIST *p = head;
	LIST *temp = NULL;
	if(head == NULL) return 0;
	
	if(i == 0){
		temp = head;
		head = head->next;
		//free(temp);
	}else{
		int k = 1;
		while(p->next != NULL){
			if(i == k) break;
			else{
				k++;
				p = p->next;
			}
		}

		if(k < i) return -1;
		else{
			temp = p->next;
			p->next = temp->next;
			//free(temp);
		}
	}

	return 0;
}

int main()
{
	int i, choice;
	char x[MaxLength], element, listname;
	LIST a, b, c, l, *p, *head; 
	
	strcpy(a.name, "Zhou");  a.length = 4;
	strcpy(b.name, "Xing");  b.length = 4;
	strcpy(c.name, "Chi");   c.length = 3;
	
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	
	/*
	LIST *a, *b, *c, *p, *head; 
	
	a = (LIST *)malloc(sizeof(LIST));
	strcpy(a->name, "Zhou");

	b = (LIST *)malloc(sizeof(LIST));
	strcpy(b->name, "Xing");

	c = (LIST *)malloc(sizeof(LIST));
	strcpy(c->name, "Chi"); 
	
	head = a;
	a->next = b;
	b->next = c;
	c->next = NULL;
	p = head;
	*/

	printf("Welcome to use this programe!\nNow the exist list is:\n");
	print_list(p);

	printf("Please chose the function:\n1.Insert a node in the linklist.\n2.Delete a node in the link list.\n3.Print link list.\n4.Quit the programe.\n");
	
	scanf("%d", &choice);
	switch(choice)
	{
		case 4:{
					printf("Thanks to use!Good bye!");
					break;
			   }
		case 1:{
					printf("Input where the node you want to Insert:");
					scanf("%d", &i);

					printf("Input the node you want to Insert:");
					scanf(" %s", &x);
					
					head = insert_node(head, x, i);
					print_list(head);
					
					break;
				}
		case 2:{
					printf("Input where the node you want to Delete:");
					scanf("%d", &i);

					delete_node(head, i);
					print_list(head);
					break;
				}
		case 3:{
					print_list(head);
					
					break;

			   }
	}
} 
