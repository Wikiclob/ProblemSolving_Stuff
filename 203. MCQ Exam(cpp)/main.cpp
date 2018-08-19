#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int chance[4],N,maxChance;
    string rep,ecran;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> rep;
        memset(chance,0,sizeof(int)*4);
        maxChance=0;
        ecran="";
        for(int j=0;j<rep.size();j++){
            chance[rep[j]-65]++;
            if(maxChance<chance[rep[j]-65])
                maxChance=chance[rep[j]-65];
        }
        for(char c='A';c<='D';c++){
            if(chance[c-65]==maxChance){
                ecran+=c;
            }
        }
        cout << maxChance << " "+ecran << endl;
    }
    return 0;
}
