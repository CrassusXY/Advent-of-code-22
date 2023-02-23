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
    int sum = 0;
    std::ifstream input ("input.txt");

    while(input >> tmp){
        if(tmp == "addx"){
            input >> num;
            //std::cout << tmp << " " << num << std::endl;
            cycle++;
            if(cycle == ser ){
                std::cout << "Signal: " << cycle << " * " << x << " = " << cycle*x << std::endl;
                sum = sum + cycle*x ;
                ser += 40;
            }
            
            cycle++;
            if(cycle == ser){
                std::cout << "Signal: " << cycle << " * " << x << " = " << cycle*x << std::endl;
                sum = sum + cycle*x ;
                ser += 40;
            }
            x += num;
        }
        else{
            cycle++;
            if(cycle == ser){
                std::cout << "NSignal: " << cycle << " * " << x << " = " << cycle*x << std::endl;
                sum = sum + cycle*x ;
                ser += 40;
            }
            //std::cout << tmp << std::endl;
        }
            
    }
    std::cout << sum << std::endl;
}
