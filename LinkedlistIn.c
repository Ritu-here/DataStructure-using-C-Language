#include<stdio.h>
#include<stdlib.h>
struct slist
{
	int data;
	struct slist *next;
}
*head = NULL;
typedef struct slist node;

void create()
{
	node *temp, *temp1;
	temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	printf("\nEnter the value you want to insert as data");
	scanf("%d",&temp->data);
	if(head==NULL)
		head=temp;
	else
	{
		temp1=head;
		while(temp1->next!= NULL)
			temp1=temp1->next;
		temp1->next=temp;
	}
}

void display()
{
	node *temp;
	temp = head;
	if(temp == NULL)
		printf("No node is here to display");
	else
		while(temp!= NULL)
		{
			printf("\n %d",temp->data);
			temp=temp->next;
		}
}

void insertAtFirstPos()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	printf("Enter the value you want to insert");
	scanf("%d",temp->data);
	
	temp->next=head;
	head=temp;
	printf("\n Insertion at 1st position is successfully done!");
}

void insertAtLastPos()
{
	node *temp,*temp1;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter the you want to insert in it");
	scanf("%d",temp->data);
	temp->next=NULL;
	temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;
	temp1->next=temp;
	printf("Node successfully inserted at last position");
}

void count()
{
	node *temp;int count=0;
	temp=head;
	while(temp!= NULL)
	{
		count++;
		temp=temp->next;
	}
	printf("Total no. of node=%d",count);
}

void insertAtAnyPosition()
{
	int pos, count=0;
	node *temp,*temp1; int i;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	printf("\n Enter position number At which position you want to insert your data");
	scanf("%d",&pos);
	if(pos<1 || pos>count++)
		printf("Invalid Position");
	else
	{
		temp=(node*)malloc(sizeof(node));
		printf("/n Enter value for new node");
		scanf("%d",&temp->data);
		if(pos==1)
		{
			temp->next=head;
		
		head=temp;
		printf("Insertion done at position 1st");
		}
		else
		{
			temp1=head;
			for(i=1;i<pos-1;i++)
				temp1=temp1->next;
			temp->next=temp1->next;
			temp->next=temp;
		}
		printf("\n Insertion at your given position is done");
	
	}
	
}

int main()
{
	 int choice;
	 while(1)
	 {
	 	printf("\n 1-> Create List \n 2-> Display List \n 3-> Insert at First position \n 4->Insert at last position \n5-> Insert at any position \n6-> count number of nodes \n7->Exit");
	 	scanf("%d",&choice);
	 	if(choice == 1)
	 		create();
	 	else if(choice == 2)
	 		display();
	 	else if(choice == 3)
	 		insertAtFirstPos();
	 	else if(choice == 4)
	 		insertAtLastPos();
	 	else if(choice == 5)
	 		insertAtAnyPosition();
	 	else if(choice == 6)
	 		count();
	 	else if(choice == 7)
	 		break;
	 	else
	 		printf("\n Wrong Choice");
	 		
	 		
	 		
	 		
	 }
	 return 0;
}
