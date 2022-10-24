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
		
	}
}

int main(){

}