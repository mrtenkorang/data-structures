/*
In a queue data structure, insertion is done at the bottom while deletion is done from the 
front of the structure. this is so because in a queue whatever goes in first comes out first like 
it os experienced in real life
*/

#include <stdio.h>
#include <stdlib.h>

struct Employee{
	int age;
	double salary;
	struct Employee* next;
};

struct Employee* head = NULL;
struct Employee* temp = NULL;

struct Employee* createEmployee(int age, double salary){
	struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

	newEmployee->age = age;
	newEmployee->salary = salary;
	newEmployee->next = NULL;
	return newEmployee;
}

// The temp variable stores the address of the recently added node to make insertion of other nodes 
// easier ans faster 
struct Employee* enQueue(int age, double salary){
	struct Employee* emp = createEmployee(age,salary);
	if (head == NULL){
		head = emp;
		temp = emp;
		return head;
	}
	temp->next = emp;
	temp = emp;
	return head;	
}

struct Employee* deQueue(struct Employee* head){
	struct Employee* temp = head;
	if (head == NULL){
		return 0;
	}
	head = temp->next;
	free(temp);
	return head;
}

void Print(struct Employee* head){
	if (head == NULL){
		return;
	}
	printf("%d  %.1lf\n",head->age, head->salary);
	Print(head->next);
}

void front(struct Employee* head){
	printf("%d  %.1lf\n", head->age, head->salary);
}
int isEmpty(struct Employee* head){
	int check = 0;
	if (head == NULL){
		check = 1;
	}
	return check;
}

int main(){
	struct Employee* head;
	head = enQueue(22, 20000);
	head = enQueue(23, 30000);
	head = enQueue(24, 40000);
	head = enQueue(25, 50000);

	head = deQueue(head);

	front(head);
	printf("%d\n",isEmpty(head));
	//Print(head);
}