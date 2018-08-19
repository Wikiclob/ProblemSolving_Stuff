#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iterator>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    int N;
    string word;
    string sentence;
    int a,b;
    bool first,verif;
    vector<string> tokens;
    bool poss[26];
    cin >> N;cin.ignore();
    for(int i=0;i<N;i++){
        memset(poss,false,sizeof(bool)*26);
        first=true;
        tokens.clear();
        getline(cin,sentence);
        istringstream iss(sentence);
        copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(tokens));
        cin >> word;cin.ignore();
        for(int j=0;j<tokens.size();j++){
            if(tokens[j].length()==word.length()){
                first=true;
                verif=true;
                for(int k=0;k<word.length();k++){
                    if(first){
                        if(tokens[j][0]<word[0]){
                            a=('z'-word[0])+1+tokens[j][0]-'a';
                        }
                        else{
                            a=tokens[j][0]-word[0];
                        }
                        first=false;
                    }
                    else{
                        if(tokens[j][k]<word[k]){
                            b=('z'-word[k])+1+tokens[j][k]-'a';
                        }
                        else{
                            b=tokens[j][k]-word[k];
                        }
                        if(b!=a){
                            verif=false;
                            break;
                        }
                    }
                }
                if(verif){
                    poss[a]=true;
                }
            }
        }
        for(int j=0;j<26;j++)
            if(poss[j])
                printf("%c",j+97);
        printf("\n");
    }
    return 0;
}
