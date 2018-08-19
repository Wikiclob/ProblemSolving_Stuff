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

int main()
{
    int N;
    bool pal,first;
    int i,j,k,cmp,verif;
    char S[100001];
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        fflush(stdin);
        scanf("%s",S);
        pal=false;
        first=true;
        j=strlen(S)-1;
        cmp=0;
        if(j==0)
            pal=true;
        verif=strlen(S)/2;
        while(!pal && verif<=j && first){
            if(S[0]!=S[j]){
                cmp++;
                j--;
            }
            else{
                cmp++;
                pal=true;
                for(k=0;k<cmp;k++){
                    if(S[k]!=S[j+k]){
                        pal=false;
                        break;
                    }
                }
                if(pal){
                    first=false;
                }
                else
                    j--;
            }
        }
        if(pal)
            printf("Case %d: YES\n",i);
        else
            printf("Case %d: NO\n",i);
    }
    return 0;
}
