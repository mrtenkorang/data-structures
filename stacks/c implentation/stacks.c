#include <stdio.h>
#include <stdlib.h>

struct People{
	char firstLetter;
	int age;
	struct People* next;
};

struct People* createPerson(char firstLetter, int age){
	struct People* person = (struct People*)malloc(sizeof(struct People));

	person->firstLetter = firstLetter;
	person->age = age;
	person->next = NULL;
	return person;
}


struct People* Push(struct People* head,char firstLetter, int age){
	struct People* temp = createPerson(firstLetter,age);

	temp->next = head;
	head = temp;

	return head;
}

void Top(struct People* head){
	printf("%c %d\n",head->firstLetter, head->age);
}

struct People* Pop(struct People* head){
	struct People* temp = head;
	head = temp->next;
	free(temp);
	return head;
}

int main(){
	struct People* head;

	head = Push(head,'T',22);
	head = Push(head,'F',26);
	head = Push(head,'D',22);
	head = Pop(head);
	Top(head);

}