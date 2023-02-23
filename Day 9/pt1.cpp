#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <set>

int main() {
    std::set<std::pair<int, int>> chuj;
    std::string tmp;
    int num=0;

    int head[2] = {0};
    int tail[2] = {0};
    int x=0, y=0;

    std::ifstream input ("input.txt");

    while(input >> tmp >> num){
        for(int i=0; i<num; i++){
            //rusz glowom
            if(tmp == "U")
                head[0]++;
            else if(tmp == "D")
                head[0]--;
            else if(tmp == "L")
                head[1]--;
            else if(tmp == "R")
                head[1]++;

            //oblicz odleglosc
            x = abs(head[0]-tail[0]);
            y = abs(head[1]-tail[1]);

            //pion poziom
            if(x == 2 && y == 0){
                if(tmp == "U")
                    tail[0]++;
                else
                    tail[0]--;
            }
            else if(x == 0 && y == 2){
                if(tmp == "R")
                    tail[1]++;
                else
                    tail[1]--;
            }

            //skosy
            else if(x == 2 && y == 1){
                if(tmp == "U")
                    tail[0]++;
                else
                    tail[0]--;

                if(head[1] > tail[1])
                    tail[1]++;
                else
                    tail[1]--;
            }

            else if(x == 1 && y == 2){
                if(tmp == "R")
                    tail[1]++;
                else
                    tail[1]--;

                if(head[0] > tail[0])
                    tail[0]++;
                else
                    tail[0]--;
            }
            chuj.insert(std::pair<int, int>(tail[0], tail[1]));
        }
    }
    std::cout << chuj.size() << std::endl;
}
