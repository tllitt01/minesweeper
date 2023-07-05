//
//  minesweeper_ui.cpp
//
//
//  Created by Taylor Little on 7/4/23.
//

#include <stdio.h>
#include <string.h>


using namespace std;

bool check_guess(int guess) {
    int safe_spaces[13] = {1, 2,3, 4, 5, 7, 8, 10, 11, 12, 13, 14, 15};
    for (int i; i < 13; i++) {
        if (safe_spaces[i] == guess) {
            return true;
        }
    }
    return 0;
}

int main() {
    
    int check;
    int guess;
    int score = 0;
    int spaces_left = 13;
    
    do {
        printf("Enter guess: ");
        scanf("%d", &guess);
        check = check_guess(guess);
        if (check == 1) {
            score = score + 200;
            spaces_left = spaces_left - 1;
            printf("Guess: %d\n", guess);
            printf("Score: %d\n", score);
            printf("Safe spaces left: %d\n", spaces_left);
            
        }

    }
    while (check == 1);
    
    printf("You hit a pothole. Gameover!\n");
    printf("Score: %d\n", score);
    
    return 0;
    

}



                



