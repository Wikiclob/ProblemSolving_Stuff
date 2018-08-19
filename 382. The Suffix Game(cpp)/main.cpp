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
    int N;
    string w1,w2,tmp,save1,save2;
    int cmp,diff;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        cin >> save1 >> save2;
        if(save1.size()<save2.size()){
            w1=save2;
            w2=save1;
        }
        else{
            w1=save1;
            w2=save2;
        }
        diff=w1.size()-w2.size();
        cmp=0;
        for(int j=w2.size()-1;j>=1;j--){
            if(w1.at(j+diff)==w2.at(j))
                cmp++;
            else
                break;
        }
        cout << "Game #" << i << ":\n";
        cout << "   The input words are " << save1 << " and " << save2 << ".\n";
        cout << "   The words entered in the notebook are " << save1.substr(0,save1.size()-cmp)
             << " and " << save2.substr(0,save2.size()-cmp) << ".\n";
    }
    return 0;
}
