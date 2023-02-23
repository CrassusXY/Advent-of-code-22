#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::string tmp;
    int count = 0;
    int highest[3] = {0};
    std::ifstream calories ("calories.txt");


    if(calories){
        while (getline(calories, tmp)){
            try{
                count += stoi(tmp);
            }

            catch(std::invalid_argument){
                if(count > highest[0]){
                    highest[2] = highest[1];
                    highest[1] = highest[0];
                    highest[0] = count;
                }
                else if (count > highest[1])
                {
                    highest[2] = highest[1];
                    highest[1] = count;
                }
                else if (count > highest[2])
                {
                    highest[2] = count;
                }
                count = 0;
            }

        }
        calories.close();
        std::cout << "Most calories carried by elf is: " << highest[0] << std::endl;
        std::cout << "Second most calories carried by elf is: " << highest[1] << std::endl;
        std::cout << "Third most calories carried by elf is: " << highest[2] << std::endl;
        std::cout << "Summary calories carried by top3 elf is: " << highest[0]+highest[1]+highest[2] << std::endl;
    }

    else{
        std::cout << "ERROR!";
        exit(1);
    }
}