#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<char>> ship(9);
    std::vector<char> trash;
    std::string tmp;
    int amount=0;
    int from=0;
    int to=0;
    std::ifstream stack ("stack.txt");

    if(stack){
        int count=0;
        while (getline(stack, tmp)){
            for(int i=0; i<ship.size(); i++){
                if(isalpha(tmp[4*i+1])){
                    ship[i].push_back(tmp[4*i+1]);
                }
            }
            if(isdigit(tmp[1]))
                break;
        }

        for (int a=0; a<ship.size(); a++){
            std::reverse(ship[a].begin(), ship[a].end());
        }


        while (stack >> tmp >> amount >> tmp >> from >> tmp >> to){
            from-=1;
            to-=1;
            for(int j=0; j<amount; j++){
                trash.push_back(ship[from].back());
                ship[from].pop_back();
            }
            for(int j=0; j<amount; j++){
                ship[to].push_back(trash.back());
                trash.pop_back();
            }
            for (auto a : ship){
                for(auto b : a)
                    std::cout << b;
                std::cout  << std::endl;
            }
            std::cout  << std::endl;
        }
        for(auto a : ship)
            std::cout<<a.back();
    }


    else{
        std::cout << "ERROR!";
        exit(1);
    }
}
