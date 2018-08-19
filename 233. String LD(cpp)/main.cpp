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
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    int nb;
    int minT;
    vector<string> mots;
    string word;
    bool verif=false;
    do{
        cin >> nb;cin.ignore();
        if(nb==0)
            break;
        //cout << "verif nb: " << nb << endl;
        //scanf("%d",&nb);
        minT=MAX_INT;
        verif=false;
        mots.clear();
        for(int i=0;i<nb;i++){
            cin >> word;
            //cout << "verif mot: " << word << endl;
            mots.push_back(word);
            //cout << "verif mot2: " << mots[mots.size()-1] << endl;
            minT=min(minT,(int)word.length());
            //cout << "verif minT: " << minT << endl;
        }
        for(int k=0;k<minT;k++){
            for(int i=0;i<nb-1;i++){
                for(int j=i+1;j<nb;j++){
                    if(mots[i].length()==mots[j].length()){
                        verif=true;
                        for(int l=k;l<mots[i].length();l++){
                            if(mots[i][l]!=mots[j][l]){
                                verif=false;
                                break;
                            }
                        }
                        if(verif)
                            break;

                    }
                }
                if(verif)
                    break;
            }
            if(verif){
                cout << k-1 << endl;
                break;
            }
        }
        if(!verif)
            cout << minT-1 << endl;
    }
    while(true);
    return 0;
}
