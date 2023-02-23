#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
int chuj;

struct plik{
    plik(std::string name_, int siz_){
        name = name_;
        siz = siz_;
    }
    int siz=0;
    std::string name;
};


class dir{
    public:
    std::string name;
    dir *parent;
    std::vector<plik> filelist;
    std::vector<dir> dirlist;
    dir(std::string name_, dir *parent_){
        name = name_;
        parent = parent_;
    }
    dir(){
        name = "top";
        parent = NULL;
    }
    int get_size(int pivot);
};

int dir::get_size(int pivot = 0){
    int sum=0;
    int tmp=0;

    for(dir b:dirlist){
        tmp = b.get_size();
        if(tmp < 100000){
            std::cout << "Dir " << b.name << ", size: " << tmp << std::endl;
            chuj += tmp;
        }
        sum += tmp;
    }

    for(plik a:filelist)
        sum += a.siz;
    
    return sum;
}


// $ cd /
// $ ls
// 150961 cmnwnpwb
// 28669 hhcp.jzd
// dir jssbn
// dir lfrctthp
// 133395 lfrctthp.tlv
// dir ltwmz
// dir nmzntmcf
// dir vhj
// 256180 wbs.vmh
// 257693 zsntdzf
// $ cd jssbn
// $ ls

int main() {
    std::ifstream input ("input.txt");
    bool addfile = false;
    std::string tmp, tmpA, tmpB;
    int siz = 0;
    dir top;
    dir *current;
    current = &top;

    while(input >> tmp >> tmpA){
        if(tmp == "$"){
            addfile = false;
            if(tmpA == "cd"){
                input >> tmpB;
                if(tmpB == "/"){
                    current = &top;
                }
                else if(tmpB == ".."){
                    current = current->parent;
                }
                    
                else{
                    for(int x=0; x < current->dirlist.size(); x++)
                        if(current->dirlist[x].name == tmpB)
                            current = &current->dirlist[x];        
                }
            }
        }
        else{
            if(isdigit(tmp[0]))
                current->filelist.push_back(plik(tmpA, stoi(tmp)));
            else
                current->dirlist.push_back(dir(tmpA, current));
        }
    }

    std::cout << "Total size: " << top.get_size() << std::endl;
    std::cout << "Answer: " << chuj << std::endl; 
}
