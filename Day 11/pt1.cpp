#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> monke = {{79, 98}, {54, 65, 75, 74}, {79, 60, 97}, {74}};
    int monkeyIntrest[4] = {0};

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
            monke[0][x] = (monke[0][x]*19)/3;
            if(monke[0][x]%23 == 0){
                monke[2].push_back(monke[0][x]);
            }
            else{
                monke[3].push_back(monke[0][x]);
            }
        }
        monke[0].clear();
        
        //Monkey1
        monkeyIntrest[1] += monke[1].size();
        for (int x = 0; x < monke[1].size(); x++){
            monke[1][x] = (monke[1][x] + 6)/3;
            if(monke[1][x]%19 == 0){
                monke[2].push_back(monke[1][x]);
            }
            else{
                monke[0].push_back(monke[1][x]);
            }
        }
        monke[1].clear();
        
        //Monkey2
        monkeyIntrest[2] += monke[2].size();
        for (int x = 0; x < monke[2].size(); x++){
            monke[2][x] = (monke[2][x] * monke[2][x])/3;
            if(monke[2][x]%13 == 0){
                monke[1].push_back(monke[2][x]);
            }
            else{
                monke[3].push_back(monke[2][x]);
            }
        }
        monke[2].clear();

        //Monkey3
        monkeyIntrest[3] += monke[3].size();
        for (int x = 0; x < monke[3].size(); x++){
            monke[3][x] = (monke[3][x] + 3)/3;
            if(monke[3][x]%17 == 0){
                monke[0].push_back(monke[3][x]);
            }
            else{
                monke[1].push_back(monke[3][x]);
            }
        }
        monke[3].clear();
    }

    std::sort(std::begin(monkeyIntrest), std::end(monkeyIntrest));
    for(int i = 0; i < monke.size(); i++){
        std::cout << "Monke " << i << " inspected items " << monkeyIntrest[i] << " times.";
        std::cout << std::endl;
    }

    
    std::cout << "Monkey business: " << monkeyIntrest[2]*monkeyIntrest[3] << std::endl;


    // for(int i = 0; i < monke.size(); i++){
    //     std::cout << "Monke " << i << ": ";
    //     for(int j = 0; j < monke[i].size(); j++){
    //         std::cout << monke[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}
