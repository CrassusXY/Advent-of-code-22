#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    int score = 0;
    int matchflag = 0;
    std::string tmp;
    char match;
    std::ifstream rucksacks ("rucksacks.txt");

    if(rucksacks){
        while (rucksacks >> tmp){
            for (int i = 0; i < tmp.size()/2; i++){
                for (int j = tmp.size()/2; j < tmp.size(); j++){
                    if(tmp[i] == tmp [j]){
                        match = tmp[i];
                        matchflag = 1;
                    }
                }
            }
            if(matchflag){
                if(islower(match))
                    score += (int)match-96;
                else
                    score += (int)match-38;
                matchflag = 0;
            }
            
        }
        rucksacks.close();
        std::cout << "Your score is: " << score << std::endl;
    }

    else{
        std::cout << "ERROR!";
        exit(1);
    }
}