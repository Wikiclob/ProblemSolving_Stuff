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
    int N,Kpal;
    int Npair;
    int Nimpair;
    int lettre[26];
    char s[100001];
    int Nchar=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&Kpal);
        Nchar=0;
        memset(lettre,0,sizeof(int)*26);
        Npair=0;Nimpair=0;
        getchar();
        while((s[Nchar]=getchar())!='\n' && s[Nchar]!=EOF){
            lettre[s[Nchar]-97]++;
            Nchar++;
        }
        s[Nchar]='\0';
        for(int j=0;j<26;j++){
            Npair+=lettre[j]/2;
            Nimpair+=lettre[j]%2;
        }
        if(Nimpair>Kpal || strlen(s)<Kpal)
            printf("NO\n");
        else{
            printf("YES\n");
        }
    }
    return 0;
}
