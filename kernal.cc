#include "kernal.h"

Kernal::Kernal(std::vector<std::vector<float>> k){
    size=k.size();
    std::vector<float> temp;
    // std::cout<<"made things"<<std::endl;
    for(int i = 0;i<k.size();i++){
        std::vector<float> temp={};
        for(int j = 0;j<k[i].size();j++){
            temp.push_back(k[i][j]);
        }
        kernal.push_back(temp);
    }
}
Kernal::~Kernal(){
    return;
}
int Kernal::getSize(){
    return size;
}
float Kernal::get(int x,int y){
    return kernal[x][y];
}
