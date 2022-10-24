#include <stdio.h>
#include <stdlib.h>


// create a struct to hold all the elements you want in the list
struct Salary{
	double amount;
	struct Salary* next;// this point to the next salary struct
};

// Pass the address of the head node to the insert function and the user 
// entered value
Salary* Insert(Salary* head,int x){
	//Dynamically allocate memory to hold a pointer to the salary structure 
	struct Salary* temp = (Salary*)malloc(sizeof(struct Salary));

	temp->amount = x;// initialize the amount section of the salary section 

	temp->next = head;// set the next amount to the head node which is either null
						// or the address of the first node

	head = temp;// give the allocated address(which is the first node) to the
				// head node
	return head;
}

struct Salary* anotherInsert(struct Salary* head, double x){
	struct Salary* temp = (struct Salary*)malloc(sizeof(struct Salary));
	temp->amount = x;
	temp->next = NULL;
	if (head == NULL){
		head = temp;
	}else{
		struct Salary* temp1 = head;
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp; 
	}
	return head;
}

void reverseWithRecursion(struct Salary* p){
	if (p->next == NULL){
		head = p;	
		return;
	}
	reverseWithRecursion(p->next);
	struct Salary* temp = p->next;
	temp->next = p;
	p->next = NULL;

}


void Print(Salary* head){
	//struct Salary* temp = head;
	printf("The salaries are:");
	while (head != NULL){
		printf(" %.2lf,",head->amount);// print the amount
		head = head->next; // move to the next amount
	}
	printf("\n");
}
void recursivePrint(struct Salary* head){
	if (head == NULL){
		return;
	}
	printf("%.0lf\n",head->amount);
	recursivePrint(head->next);
}

int main(){
	struct Salary* head = NULL;

	head = anotherInsert(head,2);
	head = anotherInsert(head,3);
	head = anotherInsert(head,4);
	head = anotherInsert(head,5);
	head = anotherInsert(head,6);
	head = anotherInsert(head,7);

	reverseWithRecursion(head);

	/*int n,i;
	double x;
	printf("How many salaries do you want to add?: ");
	scanf("%d",&n);

	for (int i = 0; i < n; i++){
		printf("Enter the salary: ");
		scanf("%lf",&x);
		head = Insert(head,x);
		//Print(head);
	}*/
	recursivePrint(head);

	return 0;
}

