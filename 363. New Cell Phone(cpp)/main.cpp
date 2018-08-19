#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)

using namespace std;

bool equal_string(string a,string b){
    if(a.length()!=b.length())
        return false;
    string w1="",w2="";
    for(int i=0;i<a.length() || i<b.length();i++){
        if(i<a.length())
            w1+=(a.at(i)>=65 && a.at(i)<=90)?a.at(i)+32:a.at(i);
        if(i<b.length())
            w2+=(b.at(i)>=65 && b.at(i)<=90)?b.at(i)+32:b.at(i);
        if(w1!=w2)
            return false;
    }
    return true;
}

int main()
{
    int N,modif,pos;
    string firstN,lastN,number;
    vector<string> List;
    vector<string> numP;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> firstN >> lastN >> number;
        List.push_back(firstN+" "+lastN);
        numP.push_back(number);
    }
    cin >> modif;
    for(int i=0;i<modif;i++){
        cin >> firstN >> lastN >> number;
        for(int j=0;j<List.size();j++){
            if(equal_string(firstN+" "+lastN,List[j])){
                List[j]=firstN+" "+lastN;
                numP[j]=number;
                break;
            }
        }
    }
    for(int i=0;i<List.size();i++){
        cout<< List[i] << " " << numP[i] << endl;
    }
    return 0;
}
