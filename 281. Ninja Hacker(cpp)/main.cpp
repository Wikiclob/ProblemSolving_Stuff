#include <bits/stdc++.h>//all
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
    /*int N,n;
    string ch;
    char tmp[100],test;
    int count_c[26];
    scanf("%d",&N);fflush(stdin);
    for(int i=0;i<N;i++){
        memset(count_c,0,sizeof(int)*26);
        cin >> ch;
        bool verif=true;
        scanf("%d",&n);fflush(stdin);
        for(int k=0;k<n;k++){
            scanf("%s",tmp);
            test=tmp[strlen(tmp)-2];
            tmp[strlen(tmp)-2]='\0';
            count_c[test-97]=atoi(tmp);
        }
        for(int k=0;k<26;k++){
            if(count_c[k]!=0){
                if(count(tmp,tmp+strlen(tmp),k+97)<count_c[k]){
                    cout << "-1\n";
                    verif=false;
                    break;
                }
            }
        }
        if(verif){
            int T2[26]=0;
            for(int k=0;k<strlen(tmp);k++){
                if(T2[tmp[k]])
            }
        }
    }*/
    string ch="15";
    int x=atoi(ch.c_str());
    cout << x << endl;
    return 0;
}
