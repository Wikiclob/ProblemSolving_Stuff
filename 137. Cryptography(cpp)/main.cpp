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
#define MIN_INT (-2147483648)

using namespace std;

string crypt_word(string word,int jump){
    string retour="";
    int pos,m;
    for(int i=0;i<word.length();i++){
        pos=word.at(i)-(word.at(i)>=97?97:65);
        m=(pos+jump%26)%26;
        retour.push_back(m+(word.at(i)>=97?65:97));
    }
    return retour;
}

int main()
{
    int N,nb,m;
    string crypt,word;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nb >> m;
        for(int j=0;j<nb;j++){
            cin >> word;
            if(j==0)
                crypt=crypt_word(word,m);
            else
                crypt+=" "+crypt_word(word,m);
        }
        cout << crypt << endl;
    }
    return 0;
}
