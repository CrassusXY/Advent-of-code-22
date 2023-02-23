#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    int score = 0;
    int start[2], stop[2];
    std::string tmp, tmpA, tmpB;
    std::ifstream pairs ("pairs.txt");

    if(pairs){
        while (pairs >> tmp){
            tmpA = tmp.substr(0, tmp.find(","));
            tmpB = tmp.substr(tmp.find(",") + 1, tmp.size());

            start[0] = stoi(tmpA.substr(0, tmpA.find("-")));
            start[1] = stoi(tmpB.substr(0, tmpB.find("-")));

            stop[0] = stoi(tmpA.substr(tmpA.find("-") + 1, tmpA.size()));
            stop[1] = stoi(tmpB.substr(tmpB.find("-") + 1, tmpB.size()));

            if(stop[0] >= start[1] && start[0] <= stop[1])
                score++;
                
        }
        std::cout << "Final score is: " << score << std::endl;
    }

    else{
        std::cout << "ERROR!";
        exit(1);
    }
}