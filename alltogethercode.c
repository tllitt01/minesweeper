#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int numRows;
int numColumns;
//easy= 8*8 contains 10 potholes
//medium=9*9 contains 30 potholes
//hard=10*10 contains  50 potholes
int numPot;
int *pots; //array of positions of potholes
char diff[100];
int **map;
bool checking=true;
int **mapUpdated;
int map2Val=0;
 bool already_guessed = false;


void mapMake()
{
while(true)
{
printf("\n	What difficulty would you like to play?\n Choose from: easy, medium, or hard.\n");
scanf("%s",diff);
	for(int i=0; i<strlen(diff);i++)
{
		diff[i]=toupper(diff[i]);
}
	if(strcmp(diff, "EASY")==0)
{
		printf("	You have chosen: %s\n",diff);
		numRows=8;
		numColumns=8;
		numPot=10;
		break;
}
	else if(strcmp(diff, "MEDIUM")==0)
{
		printf("	You have chosen: %s\n",diff);
		numRows=9;
		numColumns=9;
		numPot=30;
		break;
}
	else if(strcmp(diff, "HARD")==0)
{
		printf("	You have chosen: %s\n",diff);
		numRows=10;
		numColumns=10;
		numPot=50;
		break;
}
	else
{
printf("	You have have entered: %s", diff);
printf(" Which is not an accepted difficulty. Please try again, and choose from the list given.\n");
}

}
map = (int**)malloc(numColumns * sizeof(int*));
mapUpdated = (int**)malloc(numColumns * sizeof(int*));

for (int i = 0; i < numColumns; i++)
	{
    map[i] = (int*)malloc(numRows * sizeof(int));
    mapUpdated[i] = (int*)malloc(numRows * sizeof(int));
	}
pots=(int*)malloc(numPot*sizeof(int));
//Great! difficulty chose, #potholes created, area made, and we know the values of rows and columns now. We can move on with these values.
//first for loop makes an array of positions of potholes
for(int i=0;i<numPot;i++)
{
	pots[i]=rand()%(numRows*numColumns)+1; //randomizes postions of potholes, witin the values of the map.
	for(int j=0; j<i; j++)
	{
		//printf("%d",pots[i]);
		//printf(" ");
	if(pots[i]==pots[j])
		pots[i]=rand()%(numRows*numColumns)+1; //don't want two potholes in same spot if we can avoid it! It is okay, but we want minimal amount as possible.
	}
}
//this for loop makes the map
int spotVal=0;
for(int i=0;i<numColumns;i++)
{
	for(int j=0;j<numRows;j++)
	{
		spotVal++; // holds "value" of spot, 1 up to area value.
		for(int k=0;k<numPot;k++)
		{
		
			if(pots[k]==spotVal)
			{
				map[j][i]=1;
				mapUpdated[j][i]=1;
				break;
			}
			else
			{
				map[j][i]=9;
				mapUpdated[j][i]=9;
			}
			
		}
		//printf("%d",mapUpdated[j][i]);
			//printf(" ");
	}
}
}
//##########################################################################################

void check_guess_update_map(int guess) {
    int spotVal2=0;
	bool check;
	
for(int i=0;i<numColumns;i++)
{
	for(int j=0;j<numRows;j++)
	{
		spotVal2++; // holds "value" of spot, 1 up to area value.
		if(spotVal2==guess)
		{
			if(map[j][i]==1)
			{
				checking=false;
				already_guessed = false;				// false means you hit a pothole.
				return;
			}
			else if(mapUpdated[j][i]!=9)
				already_guessed = true;
			else
				already_guessed=false;
			int minRow;
			    if(j - 1 >= 0) 
					minRow =j-1;
				else
					minRow=0;
            int maxRow;
				if(j + 1 < numRows) 
					maxRow =j + 1 ;
				else
					maxRow =	numRows - 1;
            int minCol;
				if(i - 1 >= 0) 
					minCol =i - 1 ;
				else
					minCol =0;
            int maxCol;
				if(i + 1 < numColumns) 
					maxCol =i + 1; 
				else
					maxCol =numColumns - 1;
				
                for (int row = minRow; row <= maxRow; row++)
				{
                    for (int col = minCol; col <= maxCol; col++)
					{
                        if (row == j && col == i)
                            continue; // skip the center spot
					if(map[row][col]!=9)
                        map2Val += map[row][col];
                    }
                }
                    
                
			//map2Val=mapUpdated[j-1][i-1]+mapUpdated[j-1][i]+mapUpdated[j-1][i+1]+mapUpdated[j][i-1]+mapUpdated[j][i+1]+mapUpdated[j+1][i-1]+mapUpdated[j+1][i]+mapUpdated[j+1][i+1];
			mapUpdated[j][i]=map2Val;
		}
				
		
	}
    checking=true;
}
}
//##########################################################################################

void print_map(int guess)
 {
	 int numbr=0;
    printf("\nPlaces you have guessed will show as the number of potholes in their radius.\nMap:\n    ");
	for(int k=1; k<=numColumns;k++)
	{
		printf("%d ",k);
	}
	printf("\n\n");
    for (int i = 0; i < numColumns; i++) 
	{
		printf("%d   ",i+1);
        for (int j = 0; j < numRows; j++) 
		{
			numbr++;
            //if (numbr==guess)
				//printf(". ");
			if((mapUpdated[j][i]==1&&map[j][i]==1)||(mapUpdated[j][i]==9&&map[j][i]==9 ))
                printf("X "); 
			else 
                printf("%d ",mapUpdated[j][i]);
            
        }
        printf("\n");
    }
    printf("\n");
}
//##########################################################################################
int main() {
    int guess;
    int score = 0;
    int spaces_left;
	char play[50];
	bool playAgain=true;
	//int potsLeft=numPot;
   while(playAgain)
   {
	   score=0;
	printf("\n	Welcome to the driving course! Do your best to avoid the potholes!\n	If you want to stop at any point, please type 0 when it asks you to make a guess.\n");
	mapMake();
	spaces_left = (numRows*numColumns)-numPot;
    do {
        printf("	Enter guess: ");
        scanf("%d", &guess);
		if(guess>numRows*numColumns)
		{
			printf("	Please make sure your guess is within the bounds of the map.\n");
			continue;
		}
		if(guess==0)
			return 0;
		check_guess_update_map(guess);
		
        if (checking) {
            if (already_guessed)
				{
                printf("	Already guessed. Try again.\n");
                continue;
				}

            score += 200;
            spaces_left--;

           // printf("	Guess: %d\n", guess);
			if(spaces_left==0)
			{
				printf("	Congrats! You won the game. You have avoided all of the potholes and safely passed the driving test.\n");
				printf("Would you like to play again? Type Y if you would like to play again, or anything else if you would like to quit: ");
				scanf("%s",play);
				play[0]=toupper(play[0]);
				if(strcmp(play, "Y")==0)
				{
				playAgain=true;
				}
				else 
				{
					playAgain=false;
					return 0;
				}
	
			}
			if(guess==0)
			return 0;
			printf("\n	Potholes in the radius of your guess:  %d\n", map2Val);
            printf("\n	Score: %d\n", score);
			//printf("\n\nPotholes left: %d", potsLeft);
            printf("\n	Safe spaces left: %d", spaces_left);
			print_map(guess);
			map2Val=0;
        }
        
    } while (checking);

    printf("	You hit a pothole. Game over!\n");
    printf("	Score: %d\n", score);
	printf("Would you like to play again? Type Y if you would like to play again, or anything else if you would like to quit: ");
				scanf("%s",play);
				play[0]=toupper(play[0]);
				if(strcmp(play, "Y")==0)
				{
				playAgain=true;
				}
				else 
				{
					playAgain=false;
					return;
				}
	//printf("\nPotholes left: %d\n",potsLeft);
}
   
	free(map);
	return 0;
}
