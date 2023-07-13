#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
void mapMake()
{
int numRows;
int numColumns;
//easy= 8*8 contains 10 potholes
//medium=9*9 contains 30 potholes
//hard=10*10 contains  50 potholes
int numPot;
int area; //map size
int pots[numPot]; //array of positions of potholes
char diff[100];
int map[numRows][numColumns];

while(true)
{
printf("What difficulty would you like to play?\n Choose from: easy, medium, or hard.\n");
scanf("%s",diff);
	for(int i=0; i<strlen(diff);i++)
{
		diff[i]=toupper(diff[i]);
}
	if(strcmp(diff, "EASY")
{
		printf("You have chosen %s\n",diff);
		numRows=8;
		numColumns=8;
		numPot=10;
		return;
}
	else if(strcmp(diff, "MEDIUM")
{
		printf("You have chosen %s\n",diff);
		numRows=9;
		numColumns=9;
		numPot=30;
		return;
}
	else if(strcmp(diff, "HARD")
{
		printf("You have chosen %s\n",diff);
		numRows=10;
		numColumns=10;
		numPot=50;
		return;
}
	else
{
printf("You have have entered: %s\n", diff, "\nWhich is not an accepted difficulty. Please try again, and choose from the list given.\n");
}
area=numRows*numColumns;
}
//Great! difficulty chose, #potholes created, area made, and we know the values of rows and columns now. We can move on with these values.
//first for loop makes an array of positions of potholes
for(int i=0;i<=numPot;i++)
{
	pots[i]=rand(1,area); //randomizes postions of potholes, witin the values of the map.
	for(int j=0; j<i; j++)
	{
	if(pots[i]==npots[j])
		pots[i]=rand(1,area); //don't want two potholes in same spot if we can avoid it! It is okay, but we want minimal amount as possible.
	}
}
//this for loop makes the map
int spotVal=0;
for(int i=0;i<=numColumns;i++)
{
	for(int j=0;j<=numRows;j++)
	{
		spotVal++; // holds "value" of spot, 1 up to area value.
		for(int k=0;k<numPot;k++)
		{
			if(pots[k]==spotVal)
				map[j][i]=1;
			else
				map[j][i]=0;
		}
	}
}
}
//##########################################################################################
bool check_guess(int guess) {
    int safe_spaces[13] = {1, 2, 3, 4, 5, 7, 8, 10, 11, 12, 13, 14, 15};
    for (int i = 0; i < 13; i++) {
        if (safe_spaces[i] == guess) {
            return true;
        }
    }
    return false;
}
//##########################################################################################

void print_map(int guess1) {
    printf("Map:\n");
    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < numRows; j++) {
            if (map[i][j]==1||map[i][j]==0) 
                printf("X ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
    printf("\n");
}
//##########################################################################################
int main() {
    int guess;
    int score = 0;
    int spaces_left = area-numPots;
	int potsLeft=numPots;
	int potsAroundGuess=0;
    bool already_guessed = false;

    do {
        printf("Enter guess: ");
        scanf("%d", guess);

        if (check_guess(guess)) {
            if (already_guessed) {
                printf("Already guessed. Try again.\n");
                continue;
            }

            already_guessed = true;
            score += 200;
            spaces_left--;

            printf("Guess: %d\n", guess);
			printf("\nPotholes in the radius of your guess:  %d\n", potsAroundGuess);
            printf("\nScore: %d\n", score);
			printf("\n\nPotholes left: %d", potsLeft);
            printf("\nSafe spaces left: %d", spaces_left);
        }
        else {
            already_guessed = false;
        }
    } while (check_guess(guess));

    printf("You hit a pothole. Game over!\n");
    printf("Score: %d\n", score);
	printf("\nPotholes left: %d\n",potsLeft);

    return 0;
}