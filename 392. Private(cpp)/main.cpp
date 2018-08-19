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

int letter_to_int(char c){
    return (c>=97)?c-'a'+1:((c>=65)?c-'A'+1:c-'0'+1);
}

bool verif_private(string name){
    int point=name.find(".");
    int nbName=point;
    int nbExt=name.length()-nbName-1;
    int countN=0,countE=0;
    if(nbName>nbExt*26)
        return false;
    else if(nbName*26<nbExt)
        return false;
    else{
        for(int i=0;i<nbName;i++)
            countN+=letter_to_int(name.at(i));
        for(int i=nbName+1;i<name.length();i++)
            countE+=letter_to_int(name.at(i));
        return countN==countE;
    }
}

int main()
{
    int N;
    string name;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> name;
        if(!verif_private(name))
            cout << name << endl;
    }
    return 0;
}
