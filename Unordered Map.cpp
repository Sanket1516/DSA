#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char,int>map;

    string s = "Tirumalapuram";
    for(auto i : s){
        if(map.find(i) != map.end()){
            map[i]++;
        }
        else{
            map[i] = 1;
        }
    }
    return 0;
}