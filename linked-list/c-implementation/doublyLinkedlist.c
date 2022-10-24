#include <stdio.h>
#include <stdlib.h>

struct Employee{
	struct Employee* prev;
	int age;
	int salary;
	struct Employee* next;
};

// create a new employee node
struct Employee* createEmployee(int age,int salary){
	struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

	newEmployee->prev = NULL;
	newEmployee->age = age;
	newEmployee->salary = salary;
	newEmployee->next = NULL;

	return newEmployee;
}

// insert into the list
struct Employee* insertAtHead(struct Employee* headPointer,int age,int salary){
	struct Employee* temp = createEmployee(age,salary);

	if (headPointer == NULL){
		headPointer = temp;
		return headPointer;
	}
	temp->next = headPointer;
	headPointer->prev = temp;
	headPointer = temp;
	return headPointer;
}

// delete from the list --- by value or by position


struct Employee* insertAtTail(struct Employee* headPointer,int age,int salary){
	struct Employee* temp = createEmployee(age,salary);
	struct Employee* temp1 = headPointer;

	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;
	return headPointer;
}



struct Employee* insertByPosition(struct Employee* headPointer, int age,int salary,int p){
	struct Employee* temp = createEmployee(age,salary);
	struct Employee* temp1 = headPointer;
	int i;

	for (int i = 0; i < p-2; i++){
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp1->next = temp;
	return headPointer;

}
	


void Print(struct Employee* p){
	if (p == NULL){
		return;
	}
	printf("%d  %d\n", p->age, p->salary);
	Print(p->next);
}


int main(){
	struct Employee* head = NULL;

	head = insertAtHead(head,24,6000);
  	head = insertAtHead(head,25,7000);
  	head = insertAtHead(head,21,3000);
  	head = insertAtHead(head,22,5000);
  	head = insertAtHead(head,26,9000);
  	head = insertAtHead(head,28,8000);
  
  	head = insertAtTail(head,30,10000);
  	head = insertAtTail(head,35,15000);
  	head = insertAtTail(head,37,20000);
  
	head = insertByPosition(head, 40, 150000,2);

	Print(head);

	return 0;
}