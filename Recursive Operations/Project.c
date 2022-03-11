#include<stdio.h>

int divisior(int num1,int num2);
int common(int num1,int num2);
void sorting(int elements[], int left, int medium, int right);
void rec(int elements[], int left, int right);
void formula(int num);
int digit_number(int num);
int power(int number,int digit);
int check (int number,int digit,int answer);
int checking(char str[],int h);


int main(){

int choice;
int num1,num2,ans;
int i,lenght;
int num;
int number,answer=0,digit,res;
char str[100];
int h=0;



printf("\n1. Finding GCD\n");
printf("2. Sorting the numbers\n");
printf("3. Using the formula\n");
printf("4. Checking if the digits of numbers fits the formula or not\n");
printf("5. Finding the first capital letter in the string\n");
printf("Type another number to exit\n");
printf("	Choice:");

	scanf("%d",&choice);
	printf("\n");

	switch(choice){

		case 1:
			printf("Enter a number:");
				scanf("%d",&num1);
			printf("Enter a number:");
				scanf("%d",&num2);
		
					ans=common(num1,num2);

			printf("Gretest common divisior is %d\n",ans );

			//divisior(num1,num2);
		break;


		case 2:
		
			printf("Enter the lenght of the list:");
				scanf("%d",&lenght);
			
			int elements[100];

			for (i = 0; i < lenght; ++i){
				printf("Enter the %d. element:",i+1);
					scanf("%d",&elements[i]);
		    	}
			for(i=0;i<lenght;i++)
			    printf("%d ",elements[i] );
				printf("\n");
		     
			 	rec(elements, 0, lenght - 1);
		  
			 for(i=0;i<lenght;i++)
			    printf("%d ",elements[i] );
				printf("\n");

				break;


		case 3:
		
			printf("Enter the number:");
				scanf("%d",&num);
		
				formula(num);
			printf("\n");
		break;



		case 4:
		
			printf("Enter a number:");
			scanf("%d",&number);
				digit=digit_number(number);
			
				res=check(number,digit,answer);

			if(number==res){
			 	printf("%d = %d\n",number,res );
					printf("EQUAL\n");
			}
			else if (number!=res ){
				printf("%d != %d\n",number,res );
					printf("NOT EQUAL\n");
			}
		break;

		case 5:
		
			printf("Please enter the string that you want to find the first upper letter:");
			scanf("%s",str);
		
				checking(str,h);

		break;

		default:

			printf("Exiting...\n");
		break;

	}
}




int divisior(int num1,int num2){

int i,k=0,gcd=1,multip1[100],multip2[100];

	printf("The divisiors of %d are: ",num1 );
	for(i=2;num1!=1;i++){

		if(num1%i==0){
			num1=num1/i;
			multip1[i-2]=i;
				printf("%d  ",multip1[i-2]);
					i--;
		
		}
	}

	printf("\n");

	printf("The divisiors of %d are: ",num2 );

	for(i=2;num2!=1;i++){

		if(num2%i==0){
			num2=num2/i;
			multip2[i-2]=i;
				printf("%d  ",multip2[i-2]);
					i--;
		
		}
	}


	printf("\n");

}

// first part
int common(int num1,int num2){

	if(num2!=0)
		return common (num2,num1%num2);
	else 
		return num1;

}

void rec(int elements[], int left, int right){
int medium;

    if (left < right){
     
        medium = left+(right-left)/2;
   
        rec(elements, left, medium);
        rec(elements, medium+1, right);
        sorting(elements, left, medium, right);
    }
}
//second part
void sorting(int elements[], int left, int medium, int right){

int i, j, k, n1 ,n2;

    n1= medium - left + 1;
    n2 =  right - medium;
  
int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = elements[left + i];
    for (j = 0; j < n2; j++)
        R[j] = elements[medium + 1+ j];
  
	    i = 0; 
	    j = 0;
	    k = left;
 
    while (i < n1 && j < n2){
    
        if (L[i] <= R[j]){
            elements[k] = L[i];
            i++;
        }
        
        else{
            elements[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1){
    
        elements[k] = L[i];
        i++;
        k++;
    }
    
     while (j < n2){
        elements[k] = R[j];
        j++;
        k++;
    }
}
//third part
void formula(int num){

	if(num%2==0){
		printf("%d ",num);
		num=num/2;
			if(num>0)
				formula(num);
	

	}
	
	else if(num%2==1){
		printf("%d ",num);
			if(num>1){
				num=(3*num)+1;
				formula(num);
			}
	}
}
//fourth part
int digit_number (int number){
int i=0;
	while(number>0){
		i++;
		number=number/10;
	}
		return i;
}

int check(int number,int digit,int answer){
int temp,res;

	if(number>0){
		
		temp=number%10;
		answer=power(temp,digit)+answer;
		number=number/10;
	
		check(number,digit,answer);
	}
	
	  if(number<=0)
		return answer;

}


int power(int number,int digit){

if(digit!=0){

	return(number*power(number,digit-1));
}
else
	return 1;

}
//fifth part
int checking(char str[],int h){

	if(str[h]!='\0')
	{
		if(str[h]>= 'A' && str[h]<= 'Z'){
			printf("First upper letter is: %c\n",str[h]);
		}


		else {
			h++;
			checking(str,h);
		}
	}
	else if(str[h]=='\0')
		printf("There is no upper letter in this string!\n");
}

