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

int main()
{
    int N,i,x,y,ccI;
    char ch[100001];
    scanf("%d",&N);
    while(N--){
        x=0;y=0;ccI=0;
        scanf("%s",ch);
        for(i=0;i<strlen(ch);i++)
            switch(ch[i]){
                case 'L': x--;break;
                case 'R': x++;break;
                case 'U': y++;break;
                case 'D': y--;break;
                case '?': ccI++;break;
            }
        printf("%d %d %d %d\n",x-ccI,y-ccI,x+ccI,y+ccI);
    }
    return 0;
}
