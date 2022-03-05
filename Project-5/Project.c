#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

struct person{
	char name [SIZE];
	char surname [SIZE];
	char musical_Work [SIZE];
	int age;
	struct person *next;
}; 

typedef struct person *top;
top tepe=NULL;

typedef struct person *helper;
helper tepe1=NULL;


int menu();
void addNode(char name[SIZE], char surname [SIZE], char creation [SIZE], int age);
void print_stack();
void deleteNode(top temp);
void Sort_Alphabetically();
struct person Sort_Increasingly();


int main(){
	top temp;
	helper helper;
	int ch,age;
	char name[SIZE],surname[SIZE],creation[SIZE];

	ch=menu();

	while(ch!=5){
		switch(ch){
			case 1:
				printf("Name:");
				scanf(" %[^\n]s",name);

				printf("Surname:");
				scanf(" %[^\n]s",surname);

				printf("Creation:");
				scanf(" %[^\n]s",creation);

				printf("Age:");
				scanf("%d",&age);

				addNode(name,surname,creation,age);
				print_stack(temp);

					break;
			case 2:

					deleteNode(temp);
					print_stack(temp);

					break;
			case 3: 

				Sort_Alphabetically();
				print_stack(temp);

					break;

			case 4:

				Sort_Increasingly();
				print_stack(helper);

					 break;
		}
		ch=menu();
	}
	return 0;
}

int menu(){
	int ch;
		printf("*****MENU*****\n");
	printf("\t1- Add a Person to the Stack\n");
	printf("\t2- Pop a Person from the Stack\n");
	printf("\t3- Sort Alphabetical Order\n");
	printf("\t4- Sort Age in Increasing Order\n");
	printf("\t5- Exit menu\n*************\n");
	printf("Choice:");
	scanf("%d",&ch);
		return ch;

}


void addNode(char name[SIZE], char surname [SIZE], char creation [SIZE], int age){
	int value, count;
	struct person *temp;
	temp=(top)malloc(sizeof(top)*20);
	if(tepe==NULL) {
		strcpy(temp->name,name);
		strcpy(temp->surname,surname);
		strcpy(temp->musical_Work,creation);
		temp->age=age;

		tepe=temp;
		tepe->next=NULL;
	}

	else if(tepe!=NULL){

		strcpy(temp->name,name);
		strcpy(temp->surname,surname);
		strcpy(temp->musical_Work,creation);
		temp->age=age;

		printf("%d\n", temp->age);
		temp->next=tepe;
		tepe=temp;
			}

}

void print_stack(top temp){
	int a=1;
	if(tepe==NULL)
		printf("Stack boştur!\n");
	else{
		temp=tepe;
		printf("--------------------\n");
		while(temp!=NULL){
			printf("\n%d) %s\n",a,temp->name);
			printf("%s\n",temp->surname);
			printf("%s\n",temp->musical_Work);
			printf("%d\n",temp->age);
			printf("--------------------\n");
			temp=temp->next;
			a++;
		}
	}
}
void deleteNode(top temp){

	int age;
	char name[SIZE],surname [SIZE],creation [SIZE];

	if(tepe==NULL){
		printf("Stack is empty!\n");
	}
	else {
		temp=tepe;
		age=temp->age;
		strcpy(temp->name,name);
		strcpy(temp->surname,surname);
		strcpy(temp->musical_Work,creation);
		tepe=tepe->next;
		free(temp);
	}

}

void Sort_Alphabetically(){




}
struct person Sort_Increasingly(){
	int currAge;
	char currName[SIZE],currSurname[SIZE],currCreation[SIZE];
		top temp;
	struct person *helper;
	helper=(top)malloc(sizeof(top)*20);

		if(tepe!=NULL) {
			currAge=temp->age;
			strcpy(currName,temp->name);
			strcpy(currSurname,temp->surname);
			strcpy(currCreation,temp->musical_Work);

			strcpy(helper->name,temp->name);
			strcpy(helper->surname,temp->surname);
			strcpy(helper->musical_Work,temp->musical_Work);
			helper->age=temp->age;

			while(tepe1!=NULL && helper->age>currAge){
					deleteNode(helper);
					addNode(helper->name,helper->surname,helper->musical_Work,helper->age);
					
				}
					strcpy(helper->name,currName);
					strcpy(helper->surname,currSurname);
					strcpy(helper->musical_Work,currCreation);
					helper->age=currAge;
		}
		return *helper;
}


