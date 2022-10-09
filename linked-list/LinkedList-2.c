#include <stdio.h>
#include <stdlib.h>


struct Car{
	int id;
	int price;
	int quantity;
	struct Car* next;
};

Car* Insert(Car* head, int id, int price, int quantity){
	Car* temp = (Car*)malloc(sizeof(struct Car));
	temp->id = id;
	temp->price = price;
	temp->quantity = quantity;
	head = temp;

	return head;
}

int count = 0;

void Print(Car* head){
	count++;
	while (head != NULL){
		printf("Car %d:\n\tDetails:\n\tID = %d\n\tPrice = %d\n\tQuantity = %d",count,head->id,head->price,head->quantity);
		head = head->next;
	}
	printf("\n");
}


int main(){
	struct Car* head;
	int n,i,id,price,quantity;
	printf("How many cars do you want to add?: ");
	scanf("%d",&n);

	for (int i = 0; i < n; i++){
		printf("Enter car id,price and quantity: ");
		scanf("%d %d %d",&id, &price, &quantity);	
		head = Insert(head,id,price,quantity);
		printf(head)
	}
	


	return 0;
}