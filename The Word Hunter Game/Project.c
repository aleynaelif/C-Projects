#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
char random_letters(int i);
void print_table(char table [DICT_SIZE][DICT_SIZE]);
int upper(char *dict[DICT_SIZE],int whichword);


int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);
	//print_coord(coord);
	
	srand(time(NULL));

char table[DICT_SIZE][DICT_SIZE];
char x1[DICT_SIZE],y1[DICT_SIZE],x2[DICT_SIZE],y2[DICT_SIZE];
int i,j,k=0,t,flag=0,x,y,g,whichword=20,lenght_word,flag1=0,is_it_true=0,is_it_reverse,score=0;
char word[DICT_SIZE];
int cord[2];
int lenght[DICT_SIZE];

//random letters
	for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			table[i][j]=random_letters(i);
		}
	}
//replacinng random letters with meaningful words
	
	for(i = 0 ; i < DICT_SIZE ; i++) {
		x1[i]=coord[i][0];
		y1[i]=coord[i][1];
		x2[i]=coord[i][2];
		y2[i]=coord[i][3];
//if word is horizontal ->
			if(y1[i]==y2[i] && x1[i]!=x2[i] && x2[i]>x1[i]){
				for(j=x1[i];j<=x2[i];j++){
					table[y1[i]][j]=dict[i][k];
					k++;	
				}
				k=0;
			}
/*//if word is horizontal <-
			if(y1[i]==y2[i] && x1[i]!=x2[i] && x2[i]<x1[i]){
				for(j=x1[i];j>=x1[i];j--){
					table[y1[i]][j]=dict[i][k];
					k++;	
				}
				k=0;
			}*/
//if word is vertical
			if(y1[i]!=y2[i] && x1[i]==x2[i]){
				for(j=y1[i];j<=y2[i];j++){
					table[j][x1[i]]=dict[i][k];
					k++;	
				}
				k=0;
			}
//if word is diagonal
			if(y1[i]!=y2[i] && x1[i]!=x2[i]){
				for(j=y1[i], t=x1[i] ;j<=y2[i] && t<=x2[i]; j++ && t++){
					table[j][t]=dict[i][k];
					k++;
				}
				k=0;
			}
	}
//printing the table
		print_table(table);

//do{
//it is not working but do while the score is not equal to 15
//it works when you do this once. But for multiple times it does not works correctly.
//taking input from the user
	printf("\nEnter the word:");
	scanf("%s",word);
	if(word[0]=='e' && word[1]=='x' && word[2]=='i' && word[3]=='t'){
		printf("Goodbye!\n");
//if the word is exit than leaving the game
	}
// if it is not taking the coordinates

	else{

		printf("\nEnter the row coordinate:");
			scanf("%d",&cord[0]);
			y=cord[0];
		printf("\nEnter the column coordinate:");
			scanf("%d",&cord[1]);
			x=cord[1];
		
			
//finding the lenght of the each word

		for(j=0;j<DICT_SIZE;j++){
			for(i=0;dict[j][i]!='\0';i++){
			lenght[j]=i;
			}
		}
		for(j=0;j<DICT_SIZE;j++){
			while(word[k]==dict[j][k]){
				if (word[k]!='\0'|| dict[j][k]!='\0'){
						k++;
						whichword=j;
						}
				else
				break;
				
}
			if (word[k]=='\0' && whichword!=20)
				flag=1;
			}	

//if the word is in the  dict than flag=1 , after that we can check the directions


if(flag==0)
	printf("You typed the wrong word!\n");
else if(flag==1){
printf("You have the right word! \n");

	for(i=0;i<=lenght[whichword];i++){
		if(word[i]!='\0'){
//if the word is written west to east and last or first coordinate is given
			if(y==x1[whichword] && x==y1[whichword])
				is_it_reverse=0;
			else if(y==x2[whichword] && x==y1[whichword]){
				is_it_reverse=1;
				y=y-lenght[whichword]+1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				if(word[i]==table[x][y+i]){
					flag1++;
					}
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;

						}
				
			}
			
//if the word is written north to south and last or first coordinate is given
			
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y2[whichword] && y==x1[whichword]){
				is_it_reverse=1;
				x=x-lenght[whichword]+1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				if(word[i]==table[x+i][y]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
				}
			}
//if the word is  written north-west to south-east and last or first coordinate is given
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y2[whichword] && y==x2[whichword] && x1[whichword]< x2[whichword] && y1[whichword] <y2[whichword]){
				is_it_reverse=1;
				x=x-lenght[whichword]+1;
				y=y-lenght[whichword]+1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				 if(word[i]==table[x+i][y+i]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
				}
			}
//if the word is written south-west to north-east and last or first coordinate is  given
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y2[whichword] && y==x2[whichword] && x1[whichword]< x2[whichword] && y1[whichword] >y2[whichword]){
				is_it_reverse=1;
				x=x-lenght[whichword]+1;
				y=y+lenght[whichword]-1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				 if(word[i]==table[x-i][y+i]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
				}
			}
//if the word is written south to north and last or first coordinate is given
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y2[whichword] && y==x1[whichword]){
				is_it_reverse=1;
				x=x+lenght[whichword]-1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				if(word[i]==table[x-i][y]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
					}
			}
//if the word is written south-east to noert-west and last or first coordinate is given
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y2[whichword] && y==x1[whichword] && x1[whichword]> x2[whichword] && y1[whichword]>y2[whichword]){
				is_it_reverse=1;
				x=x+lenght[whichword]-1;
				y=y+lenght[whichword]-1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				if(word[i]==table[x-i][y-i]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
				}
			}
//if the word is written east to west and last or first coordinate is given
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y1[whichword] && y==x1[whichword]){
				is_it_reverse=1;
				y=y+lenght[whichword]-1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				if(word[i]==table[x][y-i]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
				}
			}
//if the word is written north-east to south-west and the last or first coordinate is given
			if(x==y1[whichword] && y==x1[whichword])
				is_it_reverse=0;
			else if(x==y2[whichword] && y==x2[whichword] && x2[whichword]<x1[whichword] && y1[whichword]<y2[whichword]){
				is_it_reverse=1;
				x=x-lenght[whichword]+1;
				y=y+lenght[whichword]-1;
				is_it_reverse=0;
			}
			
			
			if(is_it_reverse==0){
				if(word[i]==table[x+i][y-i]){
					flag1++;
						if(flag1==lenght[whichword]){
							upper(dict,whichword);
							score=score+1;
						}
				}
			}
			
			
		}
	}
if(score!=0)
	printf("You guessed the coordinates correctly!\n");
else
	printf("Coordinates are wrong!\n");
	}
}
//}while(score!=DICT_SIZE);
	if (score==DICT_SIZE)
	printf("You win!\n");
		
	return 0;
}

char random_letters(int i){
char result;
char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	result=letters[(rand()+i)%26];
	return result;

}

void print_table(char table [DICT_SIZE][DICT_SIZE]){
int i,j;
	for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			printf("%c ",table[i][j]);
		}
		printf("\n");
	}
}
//upper function 

int upper(char *dict[DICT_SIZE], int whichword){
int i,score;
	for(i=0;dict[whichword][i]!='\0';i++){
		if(dict[whichword][i]>='a' && dict[whichword][i]<='z'){
			dict[whichword][i]=dict[whichword][i]-32;
		}
	
	}
	
}

