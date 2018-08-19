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
    int letter1[26];
    int letter2[26];
    int N;
    char c;
    int nb;
    char ch1[10001];
    char ch2[10001];
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        memset(letter1,0,sizeof(int)*26);
        memset(letter2,0,sizeof(int)*26);
        nb=0;
        scanf("%s",ch1);
        scanf("%s",ch2);
        for(int j=0;j<strlen(ch1);j++){
            letter1[ch1[j]-97]++;
        }
        for(int j=0;j<strlen(ch2);j++){
            letter2[ch2[j]-97]++;
        }
        for(int j=0;j<26;j++){
            nb+=abs(letter1[j]-letter2[j]);
        }
        printf("%d\n",nb);
    }
    return 0;
}
