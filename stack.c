#include<stdio.h>
#define max 4
int arr[max],top=-1;
void push(int);
int pop(void);
void display();
int  main(){
	int a,item;
	do{
		printf("1.push\n2.pop\n3.display\n0.exit");
 		scanf("%d",&a);
		switch(a){
			case 1:
				printf("Enter the element to be pushed\n");
				scanf("%d",&item);
				push(item);
				printf("Element pushed");
				break;
			case 2:
				item=pop();
				if(item==-888){
					printf("stack is empty\n");						
				}
				else
					printf("poped element is %d\n",item);
				break;
			case 3:
				display();
				break;	
	
	
		}
	}while(a!=0);
	return 0;
}




void push(int x){
	if (top==max-1)
		printf("Stack is full\n");
	else{
		top=top+1;
		arr[top]=x;
	
	}
}



int  pop(){
	int b;
	if(top==-1){
		b=-888;
	}	
	else{
		b=arr[top];
		top=top-1;
	}
	return b;
}


void display(){
	if(top==-1){
		printf("Stack is empty\n");
	}	
	else{
		for(int i=top;i>=0;i--){
			printf("%d",arr[i]);
		}
	}
	
}
