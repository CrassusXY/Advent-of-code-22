#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<long>> monke = {{89, 73, 66, 57, 64, 80}, {83, 78, 81, 55, 81, 59, 69}, {76, 91, 58, 85}, 
    {71, 72, 74, 76, 68}, {98, 85, 84}, {78}, {86, 70, 60, 88, 88, 78, 74, 83}, {81, 58}};
    long monkeyIntrest[8] = {0};

    for(int round = 0; round < 10000; round++){
        for(int i = 0; i < monke.size(); i++){
            std::cout << "Monke " << i << ": ";
            for(int j = 0; j < monke[i].size(); j++){
                std::cout << monke[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        //Monkey0
        monkeyIntrest[0] += monke[0].size();
        for (int x = 0; x < monke[0].size(); x++){
            monke[0][x] = (monke[0][x]*3)%9699690;
            if(monke[0][x]%13 == 0){
                monke[6].push_back(monke[0][x]);
            }
            else{
                monke[2].push_back(monke[0][x]);
            }
        }
        monke[0].clear();
        
        //Monkey1
        monkeyIntrest[1] += monke[1].size();
        for (int x = 0; x < monke[1].size(); x++){
            monke[1][x] = (monke[1][x] + 1)%9699690;
            if(monke[1][x]%3 == 0){
                monke[7].push_back(monke[1][x]);
            }
            else{
                monke[4].push_back(monke[1][x]);
            }
        }
        monke[1].clear();
        
        //Monkey2
        monkeyIntrest[2] += monke[2].size();
        for (int x = 0; x < monke[2].size(); x++){
            monke[2][x] = (monke[2][x] * 13)%9699690;
            if(monke[2][x]%7 == 0){
                monke[1].push_back(monke[2][x]);
            }
            else{
                monke[4].push_back(monke[2][x]);
            }
        }
        monke[2].clear();

        //Monkey3
        monkeyIntrest[3] += monke[3].size();
        for (int x = 0; x < monke[3].size(); x++){
            monke[3][x] = (monke[3][x] * monke[3][x])%9699690;
            if(monke[3][x]%2 == 0){
                monke[6].push_back(monke[3][x]);
            }
            else{
                monke[0].push_back(monke[3][x]);
            }
        }
        monke[3].clear();

        //Monkey4
        monkeyIntrest[4] += monke[4].size();
        for (int x = 0; x < monke[4].size(); x++){
            monke[4][x] = (monke[4][x] + 7)%9699690;
            if(monke[4][x]%19 == 0){
                monke[5].push_back(monke[4][x]);
            }
            else{
                monke[7].push_back(monke[4][x]);
            }
        }
        monke[4].clear();

        //Monkey5
        monkeyIntrest[5] += monke[5].size();
        for (int x = 0; x < monke[5].size(); x++){
            monke[5][x] = (monke[5][x] + 8)%9699690;
            if(monke[5][x]%5 == 0){
                monke[3].push_back(monke[5][x]);
            }
            else{
                monke[0].push_back(monke[5][x]);
            }
        }
        monke[5].clear();

        //Monkey6
        monkeyIntrest[6] += monke[6].size();
        for (int x = 0; x < monke[6].size(); x++){
            monke[6][x] = (monke[6][x] + 4)%9699690;
            if(monke[6][x]%11 == 0){
                monke[1].push_back(monke[6][x]);
            }
            else{
                monke[2].push_back(monke[6][x]);
            }
        }
        monke[6].clear();

        //Monkey7
        monkeyIntrest[7] += monke[7].size();
        for (int x = 0; x < monke[7].size(); x++){
            monke[7][x] = (monke[7][x] + 5)%9699690;
            if(monke[7][x]%17 == 0){
                monke[3].push_back(monke[7][x]);
            }
            else{
                monke[5].push_back(monke[7][x]);
            }
        }
        monke[7].clear();
    }

    
    for(int i = 0; i < monke.size(); i++){
        std::cout << "Monke " << i << " inspected items " << monkeyIntrest[i] << " times.";
        std::cout << std::endl;
    }

    std::sort(std::begin(monkeyIntrest), std::end(monkeyIntrest));
    std::cout << "Monkey business: " << monkeyIntrest[6]*monkeyIntrest[7] << std::endl;


    // for(int i = 0; i < monke.size(); i++){
    //     std::cout << "Monke " << i << ": ";
    //     for(int j = 0; j < monke[i].size(); j++){
    //         std::cout << monke[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}
