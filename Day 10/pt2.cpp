#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>


int main() {
    std::string tmp;
    int num=0;
    
    int cycle = 0;
    int x = 1;
    int ser = 20;
    std::string crt;
    std::string sprite = "###.....................................";
    std::ifstream input ("input.txt");


    while(input >> tmp){
        if(tmp == "addx"){
            input >> num;
            cycle++;
            std::cout << sprite[cycle%40-1];
            if(cycle%40 == 0)
                std::cout << std::endl;
            // std::cout << "SPRITE: " << cycle << std::endl;
            // std::cout << sprite << std::endl << std::endl;

            cycle++;
            std::cout << sprite[cycle%40-1];
            if(cycle%40 == 0)
                std::cout << std::endl;

            x += num;
            sprite = "........................................";
            sprite[x] = '#';
            sprite[x-1] = '#';
            sprite[x+1] = '#';
            // std::cout << "SPRITE: " << cycle << std::endl;
            // std::cout << sprite << std::endl << std::endl;
        }
        else{
            cycle++;
            // std::cout << "SPRITE: " << cycle << std::endl;
            // std::cout << sprite << std::endl << std::endl;
            std::cout << sprite[cycle%40-1];
            if(cycle%40 == 0)
                std::cout << std::endl;
        }
            
    }
}
