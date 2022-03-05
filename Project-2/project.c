#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define PI 3
#define red 0
#define yellow  1
#define blue 2
#define black 3
#define white 4



double CreateBody (int shape);											
int SetColor(int color);
double LoadMoves (int shape,double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_lenght, int attack_power);


int main(){

int shape,color,paint,attack_power;
double move_lenght,size_of_body;


shape=CIRCULAR;
color=798;
																
	size_of_body=CreateBody(shape);												
	color=SetColor(color);
	move_lenght=LoadMoves(shape,size_of_body);
	attack_power=SetAttackPower(0,150);
	ShowPokemon(shape,size_of_body,color,move_lenght,attack_power);
}


double CreateBody (int shape){											
double area,edge,edge1;

	if (shape== SQUARE){
		printf("Please enter the lenght of the edge:\n");
		scanf("%lf",&edge);
			area=edge*edge;								//calculates the area of the square pokemon
				return area;
	}
	else if (shape==RECTANGULAR){
		printf("Please enter the lenght of the long edge:\n");
		scanf("%lf",&edge);
		printf("Please enter the lenght of the short edge:\n");
		scanf("%lf",&edge1);
			area=edge1*edge;							//calculates the area of the rectangular pokemon
				return area;
	}
	else if (shape==CIRCULAR){
		printf("Please enter the lenght of the radius:\n");
		scanf("%lf",&edge);
			area=PI*edge*edge;							//calculates the area of the circular pokemon
				return area;
	}
	else{
		printf("Please enter 1, 2, 3 only. ");
			return 0;
	}
}




int SetColor(int color){											
int modulo;

	if(0<=color<=1000){
		modulo=color % 5;								//calculates the modulo of the color code
			return modulo;
	}
	else if(color>1000){
		return 1;
	}
	else{
		printf("Please enter a positive integer.\n");
	}

}



double LoadMoves (int shape,double body_size){
double lenght;

	if (shape==SQUARE){
		lenght=sqrt(body_size);								//calculates the edge of the square using the area
			lenght=lenght*4;							//finding the move of the square pokemon
				return lenght;
	}
	else if (shape ==RECTANGULAR){
		lenght=body_size/5;								//calculates the longh edge of the rectangular pokemon using the area
			lenght=(2*lenght)+10; 							//finding the move of the rectangular pokemon
				return lenght;
	}
	else if (shape==CIRCULAR){
		lenght=body_size/PI;								//calculates the radius of the circular pokemon using the area
			lenght=sqrt(lenght);
				lenght=lenght*2*PI;						//finding the move of the circular pokemon
					return lenght;
	}



}




int SetAttackPower (int lower_bound, int upper_bound){
int diff,random,result;

		diff=upper_bound-lower_bound;
	srand(time(NULL));
		result=rand()%(diff+1)+lower_bound;						// finding the random attack power using rand function
					return(result);
}



void ShowPokemon(int shape, double body_size, int color, double move_lenght, int attack_power){

int i,j,lenght;

	if(shape==SQUARE){
		lenght=sqrt(body_size);
			for (i=1;i<=lenght;i++){
				for(j=1;j<=lenght;j++){
					printf("X ");						//printing the square pokemon using X's
				}
					printf("\n");
			}
	}
	else if(shape==RECTANGULAR){
		lenght=body_size/5;								//assuming the short edge is 5 and calculating the long edge 
			for (i=1;i<=5;i++){
				for(j=1;j<=lenght;j++){
					printf("X ");						//prints the rectangular pokemon using X's 
				}
					printf("\n");
			}
	}
	else if(shape==CIRCULAR){
		lenght=body_size/PI;
			lenght=sqrt(lenght); 							//calculating the radius using the area

int i, j, k;
int tmp_n = 0;
       tmp_n = lenght;
       lenght = (lenght / 2) + 1;

        for (i = 1; i <= lenght; i++){
		for (j = 0; j < (lenght - i); j++)
			if( tmp_n % 2 == 0 ){
			
                        	if(i == 1 && j == (lenght-i-1))
                            		printf("   ");						//prints top X's spaces for even numbers 
                        	else
                            		printf("      ");					//prints the upper left spaces before X's for even numbers
                        }
                        else
                        	printf("      ");						//prints the upper left spaces before X's for odd numbers
                        	
                for (j = 1; j <= i; j++)
			if (j == 1) 
                    		printf("X");							//prints the upper left X's
                    	else{
                        	if (tmp_n % 2 == 0){
                            		if (j == 2) 
                            			printf("     ");				//prints the inside tabs for even numbers
                            		else 
                            			printf("           ");
                        	}
                        else 
                        	printf("           ");						//prints inside tabs for odd numbers
                        }
                        
                       
                for (k = 1; k < i; k++)
                    if (k == i-1) 
                    	printf("X");								//prints the upper right X's 
                    else 
                    	printf(" ");							
                printf("\n");
	}





            for (i = lenght-1; i >= 1; i--){
                for (j = 0; j < (lenght - i); j++)
                    if ( tmp_n % 2 == 0 ){
                    
                        if (i == 1 && j == (lenght - i - 1))
                            printf("   ");							//prints the lower X's spaces for even numbers
                        else
                            printf("      ");							//prints the lower tabs before X's for even numbers
                    }
                    else
                        printf("      ");							//prints lower tabs before X's for odd numbers
                        
                for (j = 1; j <= i; j++)
                    if (j == 1) 
                    	printf("X");								//prints the lower left X's
                    else {
                        if (tmp_n % 2 == 0){
                        
                            if (j == 2) 
                            	printf("     ");						//prints the inside tabs for even numbers
                            else 
                            	printf("           ");
                        }
                        else 
                        	printf("           ");						//prints the inside tabs for odd numbers
                    }
                for (k = 1; k < i; k++)
                    if (k == i-1) 
                    	printf("X"); 								//prints the lower right X's
                    else 
                    	printf(" ");
                printf("\n");
            }
            printf("\n");
}


												//prinnting the shape of the pokemon
	if(shape==SQUARE){
		printf("\nName: Square Pokémon\n");
	}
	else if(shape==RECTANGULAR){
		printf("\nName: Rectangular Pokémon\n");
	}
	else if(shape==CIRCULAR){
		printf("\nName: Circular Pokémon\n");
	}

												//printing the color of the pokemon
printf("Size:%0.3lf\n",body_size);


	if(color==red){
		printf("Color: Red\n");
	}	
	if(color==yellow){
		printf("Color: Yellow\n");
	}
	if(color==blue){
		printf("Color: Blue\n");
	}
	if(color==black){
		printf("Color: Black\n");
	}
	if(color==white){
		printf("Color: White\n");
	}



printf("Move:%0.3f\n",move_lenght);								//printing the move of the pokemon
printf("Attack Power: %d\n", attack_power);							//printing the attack power of the pokemon

}


