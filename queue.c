#include <stdio.h>
#define SIZE 3
int queue[SIZE], head=-1, rear=-1;

int isFull(){
	if(rear==SIZE-1)
		return 1;
	return 0;
}

int isEmpty(){
	if(head==-1 && rear==-1)
		return 1;
	return 0;
}

void enqueue(int item){
	if(!isFull()){
		if(isEmpty()){
			head++;
			rear++;
			queue[rear]=item;

		}
		else{
			rear++;
			queue[rear]=item;
		}
	}
	else{
		printf("Queue overflow!\n");
	}
}

void dequeue(){
	if(!isEmpty()){
		if(head==rear){
			head=-1;
			rear=-1;
			return;
		}
		head++;
	}
	else{
		printf("Queue underflow!\n");
	}
}

void display(){
	if(isEmpty()){
		printf("Queue underflow!\n");
		return;
	}
	printf("Display start\n");
	for(int i=head; i<=rear; i++){
		printf("%d ", queue[i]);
	}
	printf("\nDisplay end\n");


}

void status(){
	printf("head is %d and rear is %d\n",head, rear);
}

int main(){
	
	while(1){
		int choice;
		printf("1-Enqueue\n2-Dequeue\n3-Display\n4-Status\n");
		scanf("%d",&choice);

		if(choice==1){
			int item;
			scanf("%d", &item);
			enqueue(item);
		}
		else if(choice==2){
			dequeue();
		}
		else if(choice==3){
			display();
		}
		else if(choice==4){
			status();
		}
		else{
			break;
		}
	}

}