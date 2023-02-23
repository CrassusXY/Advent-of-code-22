#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    int score = 0;
    char oponent, you;
    std::ifstream guide ("guide.txt");

    if(guide){
        while (guide >> oponent >> you){
            if(you == 'X'){
                score += 1;
                if(oponent == 'A')
                    score += 3;
                else if(oponent == 'C')
                    score += 6;
            }
                
            else if(you == 'Y'){
                score += 2;
                if(oponent == 'B')
                    score += 3;
                else if(oponent == 'A')
                    score += 6;
            }
                
            else if(you == 'Z'){
                score += 3;
                if(oponent == 'C')
                    score += 3;
                else if(oponent == 'B')
                    score += 6;
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