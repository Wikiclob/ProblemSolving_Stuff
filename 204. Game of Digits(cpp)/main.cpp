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

ll calcul_substr(short int suite[],int taille){
    int i,j,k,maxV;
    int res=0;
    bool c_verif;
    bool verif[10];
    for(i=0;i<taille;i++){
        if(suite[i]==0){
            res++;
            //cout << i << "]=0" << endl;
            memset(verif,false,sizeof(bool)*10);
            verif[suite[i]]=true;
            maxV=0;
            for(j=i-1;j>=0 && i-j<=9;j--){
                if(verif[suite[j]])
                    break;
                else{
                    verif[suite[j]]=true;
                    if(suite[j]>maxV)
                        maxV=suite[j];
                }
                c_verif=true;
                for(k=1;k<=maxV;k++){
                    //cout << "maxV= " << maxV <<" verif= " << verif[k] << " k= " << k <<endl;
                    if(!verif[k]){
                        c_verif=false;
                        break;
                    }
                }
                if(c_verif){
                    //cout << j << " => " << i << endl;
                    res++;
                }
            }
            memset(verif,false,sizeof(bool)*10);
            verif[suite[i]]=true;
            maxV=0;
            for(j=i+1;j<taille && j-i<=9;j++){
                if(verif[suite[j]])
                    break;
                else{
                    verif[suite[j]]=true;
                    if(suite[j]>maxV)
                        maxV=suite[j];
                }
                c_verif=true;
                for(k=1;k<=maxV;k++)
                    if(!verif[k]){
                        c_verif=false;
                        break;
                    }
                if(c_verif){
                    //cout << i << " => " << j << endl;
                    res++;
                }
            }
        }

    }
    return res;
}

int main()
{
    int N,i,j,k;
    ll res;
    bool verif;
    cin >> N;
    char suite[100001];
    short int serie[100000];
    for(i=0;i<N;i++){
        fflush(stdin);
        scanf("%s",suite);
        verif=false;
        for(j=0;j<strlen(suite);j++){
            serie[j]=suite[j]-48;
            if(!verif && serie[j]==0)
                verif=true;
        }
        if(verif)
            res=calcul_substr(serie,strlen(suite));
        else
            res=0;
        cout << res << "\n";
    }
    return 0;
}
