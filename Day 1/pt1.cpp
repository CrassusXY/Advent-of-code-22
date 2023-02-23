#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::string tmp;
    int count = 0;
    int highest = 0;
    std::ifstream calories ("calories.txt");


    if(calories){
        while (getline(calories, tmp)){
            try{
                count += stoi(tmp);
            }

            catch(std::invalid_argument){
                if(count > highest)
                    highest = count;
                count = 0;
            }

        }
        calories.close();
        std::cout << "Most calories carried by elf is :" << highest << std::endl;
    }

    else{
        std::cout << "ERROR!";
        exit(1);
    }
}