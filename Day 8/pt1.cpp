#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> grid;
    std::string tmp;
    std::ifstream input ("input.txt");
    int range=0;
    int sum=0;

    input >> tmp;
    range = tmp.size();
    sum = 4*range - 4;
    
    int hiden[range][range] = {0};

    grid.resize(range, std::vector<int>(range, 0));

    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++)
            grid[i][j] = (int) (tmp[j] - '0');
        input >> tmp;
    }
    

    for (int i = 1; i < range-1; i++){
        for (int j = 1; j < range-1; j++){
            for (int x = 1; x < range; x++){
                if(i+x == range)
                    break;
                else if(grid[i][j] <= grid[i+x][j]){
                    hiden[i][j]++;
                    break;
                }      
            }
            for (int x = 1; x < range; x++){
                if(i-x == -1)
                    break;
                if(grid[i][j] <= grid[i-x][j]){
                    hiden[i][j]++;
                    break;
                }      
            }
            for (int x = 1; x < range; x++){
                if(j+x == range)
                    break;
                    
                if(grid[i][j] <= grid[i][j+x]){
                    hiden[i][j]++;
                    break;
                }      
            }
            for (int x = 1; x < range; x++){
                if(j-x == -1)
                    break;
                if(grid[i][j] <= grid[i][j-x]){
                    hiden[i][j]++;
                    break;
                }      
            }
            std::cout << hiden[i][j] << " ";
            if(hiden[i][j]<4)
                sum++;
        }
        std::cout << std::endl;
    }
    std::cout <<"Sum = " << sum << std::endl;
}
