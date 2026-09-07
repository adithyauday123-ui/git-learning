#include<stdio.h>
#include<stdlib.h>


struct Node{
	int data;
	struct Node *next;
};
struct Node * head = NULL;


void insert();
void display();
void deletenode();




int main() {
 int choice;
 while (1) {
 printf("\n--- LINKED LIST MENU ---\n");
 printf("1. Insert\n");
 printf("2. Display\n");
 printf("3. Delete\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1: insert();
 break;
 case 2:
 display();
 break;
 case 3:
 deletenode();
 break;
 case 4:
 exit(0);
 default:
 printf("Invalid choice\n");
 } }
 return 0;
 }



void insert (){
int value;
struct Node *newNode;
newNode=(struct Node *)malloc(sizeof(struct Node));
printf("Enter value : ");
scanf("%d",&value);
newNode->data = value;
newNode->next = head;
head = newNode;
printf("Node inserted \n");
}


void display(){
	struct Node *temp = head;
	if(head==NULL){
		printf("List is empty");
		return;
	}
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
}


void deletenode(){
	struct Node *temp;
	if (head == NULL){
		printf("List is empty");
		return;
	}
	temp=head;
	head=head->next; 
	free(temp);
	printf("Node deleted \n");
}

