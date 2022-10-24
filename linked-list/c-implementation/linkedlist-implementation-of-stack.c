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

struct Employee* push(struct Employee* head, int age, double salary){
	struct Employee* current = createEmployee(age,salary);

	if (head == NULL){
		head = current;
		return head;
	}
	current->next = head;
	head = current;
}

void Print(struct Employee* head){
	//struct Salary* temp = head;
	printf("The numbers are:");
	while (head != NULL){
		printf(" %d %.1lf",head->age, head->salary);// print the amount
		head = head->next; // move to the next amount
	}
	printf("\n");
}


int main(){
	struct Employee* head;

	head = push(22,20000);
	Print(head);

}