#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int main() {
    int score = 0;
    bool matchflag = false;
    std::string tmpA, tmpB, tmpC;
    std::vector<char> matchlist;
    char match;
    std::ifstream rucksacks ("rucksacks.txt");

    if(rucksacks){
        while (rucksacks >> tmpA >> tmpB >> tmpC){
            
            //check for all possible matches between first and second string
            for (int i = 0; i < tmpA.size(); i++){
                for (int  j = 0; j < tmpB.size(); j++){
                    if(tmpA[i] == tmpB[j]){
                        matchlist.push_back(tmpA[i]);//push all matches to vector
                        break;
                    }   
                }
            }

            //check all matches between vector AB and third string
            for (int k = 0; k < matchlist.size(); k++){
                for (int l = 0; l < tmpC.size(); l++){
                    if(matchlist[k] == tmpC[l]){//if matches, set flag and break
                        matchflag = true;
                        match = tmpC[l];
                        break;
                    }
                }
                if(matchflag)
                    break;
            }
            matchlist.clear();//clear vector for future usage 


            //counting score if matche occures
            if(matchflag){
                if(islower(match))
                    score += (int)match-96;
                else
                    score += (int)match-38;
                matchflag = !matchflag;
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
