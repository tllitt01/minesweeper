//
//  minesweeper_ui.cpp
//  
//
//  Created by Taylor Little on 7/4/23.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int check_guess(int guess) {
    int safe_spaces[13] = {1, 2,3, 4, 5, 7, 8, 10, 11, 12, 13, 14, 15};
    int check;
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
    int old_guesses[13] = {};
    
    do {
        printf("Enter guess: ");
        scanf("%d", &guess);
        check = check_guess(guess);
    }
    while (check == 1);
    
    return 0;

}



                


