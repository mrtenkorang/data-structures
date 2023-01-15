#include <stdlib.h>
#include <stdio.h>

// creates a skeleto for the data
struct nodeTree{
	int data;
	struct nodeTree* left;
	struct nodeTree* right;
};

// Assigns the data to a memory location
struct nodeTree* create(int data){
	struct nodeTree* newNode = (struct nodeTree*)malloc(sizeof(struct nodeTree*));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Adds the data to the tree
struct nodeTree* insert(struct nodeTree* root, int data){
	if (root == NULL){
		root = create(data);
	}else if (data <= root->data){
		root->left = insert(root->left,data);
	}else{
		root->right = insert(root->right,data);
	}
	return root;
}

// searches for the data
bool search(struct nodeTree* root, int data){
	if (root == NULL){
		return false;
	}else if (data == root->data){
		return true;
	}else if (data <= root->data){
		return search(root->left,data);
	}else{
		return search(root->right,data);
	}
}
// find the minimum  number using recursion
int findMin(struct nodeTree* root){
	if (root == NULL){
		printf("Empty tree, find operation failed...");
	}
	if (root->left == NULL){
		return root->data;
	}
	return findMin(root->left);
}
//find the maximum number using recursion
int findMax(struct nodeTree* root){
	if (root == NULL){
		printf("Empty tree, find operation failed...");
	}
	if (root->right == NULL){
		return root->data;
	}
	return findMax(root->right);
}


int main(){
	struct nodeTree* root;
	int number, min, max;

	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 3);
	root = insert(root, 60);
	root = insert(root, 15);
	root = insert(root, 12);

	min = findMin(root);
	printf("The minimum value is %d\n",min);

	max = findMax(root);
	printf("The minimum value is %d\n",max);

	printf("enter a number to search: ");
	scanf("%d",&number);

	if (search(root,number) == true){
		printf("Number found!\n");
	}else{
		printf("Number not found!\n");
	}
}
