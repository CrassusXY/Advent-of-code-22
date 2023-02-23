#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define range 4

int main() {
    bool flag=false, ans = false;
    int chuj = 0;
    std::string tmp;
    std::ifstream input ("input.txt");

    if(input){
        input >> tmp;
        for(int i = 0; i<tmp.size()-range; i++){
            for (int j = 0; j < range-1; j++){
                for (int x = 1; x < range-j; x++){
                    if(tmp[i+j] == tmp[i+j+x]){
                        j=0;
                        ans = false;
                        flag = true;
                        break;
                    }
                    else{
                        flag = false;
                        ans = true;
                    } 
                }
                if(flag)
                    break;
            }
            if(ans){
                std::cout << "first place: " << i+range << std::endl;
                break;
            }
                
        }
    }


    else{
        std::cout << "ERROR!";
        exit(1);
    }
}
