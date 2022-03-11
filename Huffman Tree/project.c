//Aleyna Elif Özkan 
//1801042652

#include <stdio.h>
#include <stdlib.h>

#define MAXCODE 20

typedef struct trees{
  char item;
  unsigned freq;
  char code[MAXCODE];
  struct trees *next,*left,*right;
}tree;


tree *findFrequency(char *filename);
int search(tree *head, char x);
void bubbleSort(tree *start);
void swap(tree *a, tree *b);
tree *createTree(tree* head);
void printList(tree *head);
void deleteFirstNode(tree *head);
void NodeInsertatEnd(tree *head,tree *Z);
tree *CopyList(tree *head);
void CodeNULL(tree *node);
void makeCodes(tree* root, int i);
void printCode(tree *root);
int isLeaf(tree* root);


int main(){
tree *head=(tree*)malloc(sizeof(tree));

	head=findFrequency("reference.txt");
	//creating a linked list for frequencies
	tree *headCopy=(tree*)malloc(sizeof(tree));
	//copied the linked list because I used the original one to create tree
	headCopy=CopyList(head);

	tree *root=(tree*)malloc(sizeof(tree));
	root=createTree(head);
	//makeCodes(root,0);

	return 0;
}


tree *findFrequency(char *filename){
FILE *fp;
char c;
int i,j,min;

fp=fopen(filename,"r");
	if(fp==NULL)
		printf("Error!!\n");

tree *first=(tree*)malloc(sizeof(tree));
tree *helper=(tree*)malloc(sizeof(tree));

	c=fgetc(fp);

	first->item=c;
	first->freq=1;
	first->next=NULL;
//assign the first char to the linked list
//it's freq is 1

	helper=first;

	while(!feof(fp)){
		//ten read the file till the end
		c=fgetc(fp);
		if(search(first,c)==0 && !feof(fp)){
			//if it is not added to the linked list before,add it
			tree *new=(tree*)malloc(sizeof(tree));
			new->item=c;
			new->freq=1;
			helper->next=new;
			new->next=NULL;
			helper=new;
		}
		
	}

	fclose(fp);
	return first;
}


int search(tree *head, char x){ 
//helper function to find if given char exits in linked list 
    tree *current = head;  // Initialize current

    while (current != NULL){ 
        if (current->item == x){
        	current->freq++; 
        	//if it exists, then increse freq
            return 1; 
        }
        current = current->next; 
    } 
    return 0; 
} 


void bubbleSort(tree *start){ 
// Bubble sort the given linked list using freq
	int swapped, i; 
	tree *ptr1; 
	tree *lptr = NULL;  

	do{ 
		swapped = 0; 
		ptr1 = start; 

		while (ptr1->next != lptr){ 
			if (ptr1->freq > ptr1->next->freq){ 
				swap(ptr1, ptr1->next); 
				swapped = 1; 
			} 
			ptr1 = ptr1->next; 
		} 
		lptr = ptr1; 
	} 
	while (swapped); 
} 


void swap(tree *a, tree *b){ 
//helper function to swap data of two nodes a and b
int temp;
char k;

	temp = a->freq; 
	k=a->item;

	a->freq = b->freq;
	a->item = b->item;

	b->freq = temp;
	b->item = k; 
} 


tree *createTree(tree *head){
int i=0;

tree *helper=(tree*)malloc(sizeof(tree));
	helper=head;
//sort the linked list
	bubbleSort(head);
	printList(head);
	printf("\n\n\n");

	while(helper!=NULL){
		//leaf
		helper->left=NULL;
		helper->right=NULL;
		helper=helper->next;				
	}	
	helper=head;

//creating first tree node
	tree *Z=(tree*)malloc(sizeof(tree));
	tree *finalTree=(tree*)malloc(sizeof(tree));
	tree *finalTreeHelper=(tree*)malloc(sizeof(tree));


	finalTree->left=helper;
	finalTree->right=helper->next;
	finalTree->item='%';
	finalTree->freq=helper->freq+helper->next->freq;
	finalTree->next=NULL;

	Z->freq=finalTree->freq;
	Z->item=finalTree->item;
	Z->left=helper;
	Z->right=helper->next;
	Z->next=NULL;

	CodeNULL(finalTree);
	finalTreeHelper=finalTree;
	helper=helper->next->next;
	
//delete the head node of the linked list
	deleteFirstNode(head);
	head=head->next;
	deleteFirstNode(head);
	head=head->next;
	
//add the sum of freq in linked list
	NodeInsertatEnd(head,Z);
	bubbleSort(head);
	helper=head;


	printList(head);
	printf("\n\n\n");

	while(helper->next->next!=NULL){
//same things till the last 2 nodes
		tree *finalTreeNew=(tree*)malloc(sizeof(tree));
		tree *Z=(tree*)malloc(sizeof(tree));

		finalTreeNew->left=helper;
		finalTreeNew->right=helper->next;
		finalTreeNew->item='%';
		finalTreeNew->freq=helper->freq+helper->next->freq;
		finalTreeNew->next=NULL;

		Z->freq=finalTreeNew->freq;
		Z->item=finalTreeNew->item;
		Z->left=helper;
		Z->right=helper->next;
		Z->next=NULL;

		CodeNULL(finalTreeNew);

		finalTreeHelper->next=finalTreeNew;
		finalTreeHelper=finalTreeNew;

		helper=helper->next->next;

		deleteFirstNode(head);
		head=head->next;
		deleteFirstNode(head);
		head=head->next;
		

		NodeInsertatEnd(head,Z);
		bubbleSort(head);
		helper=head;

		printList(head);
		printf("\n\n\n");

	}
//the last 2 nodes creates the root

	tree *treeRoot=(tree*)malloc(sizeof(tree));
	treeRoot->left=helper;
	treeRoot->right=helper->next;
	treeRoot->item='%';
	treeRoot->freq=helper->freq+helper->next->freq;
	CodeNULL(treeRoot);
	
	printf("%d\n",treeRoot->freq);
		return treeRoot;

	
}

void printList(tree *head){
tree *helper=(tree*)malloc(sizeof(tree));
	helper=head;
//helper func to print linked list
	while(helper!=NULL){
		printf("%c   ",helper->item );
		printf("%d\n",helper->freq );
		helper=helper->next;
	}
}

void deleteFirstNode(tree *head){
// Clears the memory occupied by first node

    tree *toDelete;

    toDelete = head;
    head = head->next;

    free(toDelete);

}
void NodeInsertatEnd(tree *head,tree *Z){
//helper to add nodes to the linked list 
	tree *helper=(tree*)malloc(sizeof(tree));
	helper=head;

while(helper->next!=NULL)
	helper=helper->next;

if(helper->next==NULL)
	helper->next=Z;

}


tree *CopyList(tree *head){

	tree *current = head;	// used to iterate over original list
	tree *newList = NULL; // head of the new list
	tree *tail = NULL;	// point to last node in new list

	while (current != NULL){
		// special case for the first new Node
		if (newList == NULL){

			newList = (tree*)malloc(sizeof(tree));
			newList->item = current->item;
			newList->freq = current->freq;
			newList->next = NULL;
			tail = newList;
		}
		else
		{
			tail->next = (tree*)malloc(sizeof(tree));
			tail = tail->next;
			tail->item = current->item;
			tail->freq = current->freq;
			tail->next = NULL;
		}
		current = current->next;
	}

	return newList;
}
void CodeNULL(tree *node){
	for(int i=0;i<MAXCODE;i++)
		node->code[i]='\0';
}
void makeCodes(tree* root, int i){
	//not working 
if (root->left){ 

		root->code[i]=0; 
		makeCodes(root->left,i+1); 
	} 

	if (root->right) { 

		root->code[i]= 1; 
		makeCodes(root->right, i+1); 
	} 

	if (isLeaf(root)){ 

		printf("%c: ", root->item); 
		printCode(root);
		i=0;
	} 
}

void printCode(tree *root){  
	for (int i = 0; i < MAXCODE; ++i) 
		printf("%s", root->code); 

	printf("\n"); 
} 

int isLeaf(tree* root){ 

	return !(root->left) && !(root->right); 
} 