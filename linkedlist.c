#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void insertBeginning();
void display();
//void insertEnd();

int main(void)
{
	int n;
while(1){
	printf("Enter the choice\n");
	printf("1.Insert at beggining\n");
	printf("2.Insert at end\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	printf("Please enter your choice : ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			insertBeginning();
			break;
		case 2:
//			insertEnd();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid choice \n");
	}
}
return(0);
}


void insertBeginning()
{
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the data : ");
	scanf("%d",&newNode->data);
	newNode->next = head;
	head = newNode;
}



void display()
{
	struct Node *temp;
	if (head == NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	temp = head;
	printf("\n\nLinked list : ");
	while(temp != NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("\n\n");

}
