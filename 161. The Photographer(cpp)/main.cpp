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
    int i,j,k;
    char tmp;
    bool change;
    char number[101];
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        fflush(stdin);
        scanf("%s",number);
        change=false;
        for(j=strlen(number)-2;j>=0;j--){
            if(number[j]<number[j+1]){
                change=true;
                for(k=strlen(number)-1;k>j;k--){
                    if(number[k]>number[j]){
                        tmp=number[j];
                        number[j]=number[k];
                        number[k]=tmp;
                        sort(number+j+1,number+strlen(number));
                        printf("%s\n",number);
                        break;
                    }
                }
                break;
            }
        }
        if(!change)
            printf("DONE\n");
    }
    return 0;
}
