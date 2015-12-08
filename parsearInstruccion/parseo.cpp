#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<sstream>

using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(){
        cout<<"\n"<<"Enter statement: ";
        string m;
        getline(cin,m);

        string temp;
        vector <string> cds;
        stringstream s (m);
        while(s>> temp){
            cds.push_back(temp);
            cout<<"\n"<<temp;
        }
    return 0;
}
