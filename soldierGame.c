/* Copyright Liam O'Brien December 2019 
   A C game that focuses primarily on algorithmic pointer structuring
   
*/
//#include <stdio.h>
//#include <stdlib.h>

typedef struct node
{
int val;
struct node *prev, *next;
}soldier;

//soldier* head = NULL;


soldier* create_soldier(int sequence);
soldier* create_reverse_circle(int n);
soldier* reaarange_circle(soldier* head);
void display(soldier* head);
int kill(soldier* head, int n, int k);
void addSoldierEnd(int item, soldier** head);
void addSoldierBeg(int item, soldier** head);
int n, k = 0;
char c[50] = "";
char b[50] = "";

int main()
{
	int temp = 0;
	int i = 0;
	soldier* head = NULL;
	printf("How many soldiers are trapped? \n");
	fflush(stdin);
	fgets(c, 50, stdin);
	n = atoi(c);
	printf("Which soldier would you like to start off killing: (Enter a number between 1 and %d) \n", n);
	fflush(stdin);
	fgets(b, 50, stdin);
	k = atoi(b);
//	printf("%d", k);
	printf("\n");
	head = create_reverse_circle(n);
		display(head);
		printf("\n");
	head = reaarange_circle(head);
		display(head);
	temp = kill(head, n, k);
	printf("\n\nSoldier %d is the last one alive.", temp);
	
	return 0;
}



soldier* create_soldier(int sequence)
{
	soldier* temp;
	temp = (soldier *) malloc(sizeof(soldier));
	temp->val=sequence;
	temp->prev=NULL;
	temp->next=NULL;
//	printf("%d", sequence);
	return temp;
}




soldier* create_reverse_circle(int n)
{
	soldier* head = NULL;
	int i = 0;
	for(i = n; i > 0; i--)
	{
		addSoldierEnd(i, &head);
	}
	return head;
}



soldier* reaarange_circle(soldier* head)
{
	
	soldier* temp = head;
	soldier* temp2 = NULL;
	
	while (temp != NULL && temp->next != head)
	{
		
		temp2 = temp->next;
		temp->next=temp->prev;
		temp->prev=temp2;
		temp=temp2;
		
	}
	temp2 = temp->next;
	temp->next=temp->prev;
	temp->prev=temp2;
	
	return temp;
}




void display(soldier* head)
{
	soldier* temp = head;
	
	while (temp != NULL && temp->next != head)
	{
		
		printf("%d ", temp->val);
		temp=temp->next;
		
	}
	printf("%d ", temp->val);
}



int kill(soldier* head, int n, int k)
{
	int i = 1;
	soldier* temp = head;
	soldier* current = NULL;
	printf("\n\nThe order the soldiers were killed in was: ");
	while(n > 1)
	{		
		while(i<k)
		{				
			temp=temp->next;
			i++;
		}
		current = temp;
		printf("%d ", temp->val);
		current->prev->next = current->next;
		current->next->prev = current->prev;
		temp = temp->next;
		free(current);
		current = NULL;
		i = 1;
		n--;
	}
	
	
	return temp->val;
}


void addSoldierEnd(int item, soldier** head)
{
	soldier *t;
	soldier* temp = create_soldier(item);
	temp->next=NULL;
	if(*head==NULL)
	{
		 *head=temp;
	     temp->prev = *head;
	     temp->next=*head;
	  //   printf("%d\n", temp->val);
    }
	else
	{
 	      t=*head;
	      while(t->next!=*head)
            t=t->next;

	      t->next=temp;
          temp->prev = t;
          temp->next=*head;
         // printf("%d\n", temp->val);
          (*head)->prev=temp;
	}

}

void addSoldierBeg(int item, soldier** head)
{

	soldier* temp = create_soldier(item);
	temp->prev = NULL;
	temp->next=*head;

	if(*head!=NULL)
        (*head)->prev=temp;

    *head = temp;
}
