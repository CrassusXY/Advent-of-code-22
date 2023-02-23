#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    int score = 0;
    char oponent, you;
    std::ifstream guide ("guide.txt");

    //X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win.
    //(1 for Rock, 2 for Paper, and 3 for Scissors)
    if(guide){
        while (guide >> oponent >> you){
            if(you == 'X'){
                if(oponent == 'A')
                    score += 3;
                else if(oponent == 'B')
                    score += 1;
                else if(oponent == 'C')
                    score += 2;
            }
                
            else if(you == 'Y'){
                score += 3;
                if(oponent == 'A')
                    score += 1;
                else if(oponent == 'B')
                    score += 2;
                else if(oponent == 'C')
                    score += 3;
            }
                
            else if(you == 'Z'){
                score += 6;
                if(oponent == 'A')
                    score += 2;
                else if(oponent == 'B')
                    score += 3;
                else if(oponent == 'C')
                    score += 1;
            }
                
        }
        guide.close();
        std::cout << "Your score is: " << score << std::endl;
    }

    else{
        std::cout << "ERROR!";
        exit(1);
    }
}