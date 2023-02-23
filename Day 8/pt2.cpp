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
    int top, left, right, bottom;

    input >> tmp;
    range = tmp.size();
    sum = 0;
    
    int hiden[range][range] = {1};

    grid.resize(range, std::vector<int>(range, 0));

    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++)
            grid[i][j] = (int) (tmp[j] - '0');
        input >> tmp;
    }
    

    for (int i = 1; i < range-1; i++){
        for (int j = 1; j < range-1; j++){
            top = 0;
            left = 0;
            right = 0;
            bottom = 0;
            for (int x = 1; x < range; x++){
                if(i+x == range)
                    break;
                right++;
                if(grid[i][j] <= grid[i+x][j]){
                    break;
                }      
            }
            for (int x = 1; x < range; x++){
                if(i-x == -1)
                    break;
                left++;
                if(grid[i][j] <= grid[i-x][j]){
                    break;
                }      
            }
            for (int x = 1; x < range; x++){
                if(j+x == range)
                    break;
                bottom++;   
                if(grid[i][j] <= grid[i][j+x]){
                    break;
                }      
            }
            for (int x = 1; x < range; x++){
                if(j-x == -1)
                    break;
                top++;
                if(grid[i][j] <= grid[i][j-x]){
                    break;
                }      
            }
            hiden[i][j] = top * bottom * right * left;
            std::cout << hiden[i][j] << " ";
            if(top * bottom * right * left > sum)
                sum = top * bottom * right * left;
        }
        std::cout << std::endl;
    }
    std::cout << sum << std::endl;
}
