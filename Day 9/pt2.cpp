#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#define len 9

int main() {
    std::set<std::pair<int, int>> chuj;
    std::string tmp;
    bool dot = false;
    int num=0;

    int tail[len+1][2] = {0};
    int x=0, y=0;

    std::ifstream input ("input.txt");

    while(input >> tmp >> num){
        std::cout << "==" << tmp << " " << num << "==" << std::endl;
        for(int i=0; i<num; i++){
            //rusz glowom
            if(tmp == "U")
                tail[0][0]++;
            else if(tmp == "D")
                tail[0][0]--;
            else if(tmp == "L")
                tail[0][1]--;
            else if(tmp == "R")
                tail[0][1]++;

            for(int n=1; n <= len; n++){
                //oblicz odleglosc
                x = abs(tail[n-1][0]-tail[n][0]);
                y = abs(tail[n-1][1]-tail[n][1]);

                //pion poziom
                if(x == 2 && y == 0){
                    if(tail[n-1][0] > tail[n][0])
                        tail[n][0]++;
                    else
                        tail[n][0]--;
                }
                else if(x == 0 && y == 2){
                    if(tail[n-1][1] > tail[n][1])
                        tail[n][1]++;
                    else
                        tail[n][1]--;
                }

                //skosy
                else if(x == 2 && y == 1){
                    if(tail[n-1][0] > tail[n][0])
                        tail[n][0]++;
                    else
                        tail[n][0]--;

                    if(tail[n-1][1] > tail[n][1])
                        tail[n][1]++;
                    else
                        tail[n][1]--;
                }

                else if(x == 1 && y == 2){
                    if(tail[n-1][1] > tail[n][1])
                        tail[n][1]++;
                    else
                        tail[n][1]--;

                    if(tail[n-1][0] > tail[n][0])
                        tail[n][0]++;
                    else
                        tail[n][0]--;
                }

                else if(x == 2 && y == 2){
                    if(tail[n-1][1] > tail[n][1])
                        tail[n][1]++;
                    else
                        tail[n][1]--;

                    if(tail[n-1][0] > tail[n][0])
                        tail[n][0]++;
                    else
                        tail[n][0]--;
                }
            }
            chuj.insert(std::pair<int, int>(tail[len][0], tail[len][1]));
        }
        // for (int a = 10; a >= -5; a--){
            //     for (int b = -5; b < 10; b++){
            //         dot = true;
            //         for(int n=1; n <= len; n++){
            //             if(tail[0][0] == a && tail[0][1] == b){
            //                 std::cout << "H";
            //                 dot = false;
            //                 break;
            //             } 
            //             else if(tail[n][0] == a && tail[n][1] == b){
            //                 std::cout << n;
            //                 dot = false;
            //                 break;
            //             }
            //         }
            //         if(dot)
            //             std::cout << ".";
            //     }
            //     std::cout << std::endl;
            // }
            // std::cout << std::endl;
    }
    std::cout << chuj.size() << std::endl;
}
