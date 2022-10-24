	#include <stdio.h>
#include <stdlib.h>

struct Salary{
	double amount;
	struct Salary* next;// this point to the next salary struct
};

struct Salary* head;

void insertAt(int x,int p){
	struct Salary * temp1 = (Salary*)malloc(sizeof(struct Salary));/*Allocate 
	 a block of memory a temporary variable that points to the salary structure*/
	temp1->amount = x;// set the amount section to the passed parameter
	temp1->next = head;// set the next section to the head node
	// check if the selected position is 1
	if (p == 1){
		temp1->next = head;// set the next section to the head node
		head = temp1;// set the head node to the alocated memory
		return;// stop
	}
	// if p is not 1, set another temp variable to hold the value of the head node
	Salary* temp2 = head;
	/* loop to get to the desired position, we subtract 2 from the p because initally
	the list begins at the head node which is not part of the list and so when we 
	2 we can land at the desired location*/
	for (int i = 0; i < p-2; i++){
		temp2 = temp2->next;// move through the list
	}
	temp1->next = temp2->next;/* set the link section of the newly created node
	to the value in the link section of the node that the new one will replace 
	at the existing node's position*/
	temp2->next = temp1;/*Set the link section of the existing node to the address of
	the newly created node*/
}

void deleteByPosition(int p){
	struct Salary* temp1 = head;// create a pointer the the head node as usual
	// check if the position to be deleted is the head node
	if (p == 1){
		head = temp1->next;// det the nest section of the second node to be the head node
		free(temp1);// after free up the temp variable used
		return;// stop
	}
	int i;
	// loop through the list to get the desired position
	for (i = 0; i < p-2; i++){
		temp1 = temp1->next;// set the stop at position to the temp variable
	}
	struct Salary* temp2 = temp1->next;/* set temp2 to point to the next section of the
	stopped position*/
	temp1->next = temp2->next;/* set the next section at the stopped position to the 
	next section of the next position*/
	free(temp2);// free up the temp variable used
}

void deleteByValue(int value){
	struct Salary *temp = head;// point a temp variable to the head node
	struct Salary *prev = NULL;// a variable to keep track od the previous addresses
	// check if temp is null, that si if you are at the end of the list
	while (temp != NULL){
		// check if the amount field of the node is equal to the value passed
		if (temp->amount == value){
			// check if prev is null, that is you are the first node
			if (prev == NULL){
				head = temp->next;// set the head node to the next node
				free(temp);// free the temp variable
				return;// stop
			}
			prev->next = temp->next;/*Set the next field of the prev node to the 
			value of the next field of the temp variable*/
			free(temp);// free the temp variable
			return;// stop
		}
		prev = temp;// set the prev address to temp
		temp = temp->next;// move on in the list
	}
	
}

void insertAtEnd(int x){
	struct Salary *temp = (Salary*)malloc(sizeof(struct Salary));
	struct Salary *current,*prev;

	current = head;// point the current variable to the head node
	prev = NULL; // point the prev variable to null

	// check if current is null to signal the end of the list
	while(current != NULL){
		prev = current;// give the value in the current variable to the prev variable
		current = current->next; // move to the next node
	}
	temp->amount = x; // set the amount field to the passed parameter
	temp->next = prev->next; //set the next field to the prev next field
	prev->next = temp;// set the next field of next to the created node
}

void Reverse(){
	struct Salary *current,*prev, *next;
	current = head;
	prev = NULL;

	while (current != NULL){
		next = current->next;// move to the next node and store in next
		current->next = prev; // set the current.next to the prev node
		prev = current;// give current to prev
		current = next;// give next to current
	}
	head = prev;// give prev to head
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

void Print(){
	//struct Salary* temp = head;
	printf("The numbers are:");
	while (head != NULL){
		printf(" %.1lf,",head->amount);// print the amount
		head = head->next; // move to the next amount
	}
	printf("\n");
}

int main(){
	insertAt(4,1);
	insertAt(5,1);
	insertAt(6,2);
	insertAt(9,3);
	insertAt(12,4);
	insertAt(14,5);
	insertAt(18,3);
	insertAt(15,1);	
	deleteByValue(15);
	deleteByPosition(3);
	insertAtEnd(90);
	//Reverse();
	reverseWithRecursion(head);
	Print();


	//int p;
	//printf("Enter a position to delete: ");
	//scanf("%d",&p);

	//Delete(p);
	//Print();
	return 0;
}



