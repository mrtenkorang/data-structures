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

struct Employee* createEmployee(int age, double salary){
	struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

	newEmployee->age = age;
	newEmployee->salary = salary;
	newEmployee->next = NULL;
	return newEmployee;
}


struct Employee* enQueue(struct Employee* head, int age, double salary){
	struct Employee* emp = createEmployee(age,salary);
	struct Employee* temp = head;

	if (head == NULL){
		head = emp;
		return head;
	}
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = emp;
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
	head = enQueue(head,22, 20000);
	head = enQueue(head,23, 30000);
	head = enQueue(head,24, 40000);
	head = enQueue(head,25, 50000);

	front(head);
	printf("%d\n",isEmpty(head));
	//Print(head);
}