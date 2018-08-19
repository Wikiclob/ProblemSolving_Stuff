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

bool isPrime(int n) {
    if (n == 2) return true ;
    else if (n < 2 || n % 2 == 0) return false ;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)  return false;

    return true;
    }

int sum_digit(int n){
    int retour=0;
    while(n>0){
        retour+=n%10;
        n/=10;
    }
    return retour;
}

bool visited[10001];

int main()
{
    memset(visited,false,sizeof(bool)*10001);
    int N,deb,fin,res,minR=10001,maxR=-1;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&deb,&fin);
        res=0;
        for(int j=deb;j<=fin;j++){
            if(j>=minR && j<=maxR){
                if(visited[j])
                    res++;
            }
            else if(isPrime(j) && isPrime(sum_digit(j))){
                visited[j]=true;
                res++;
            }
        }
        minR=min(minR,deb);
        maxR=max(maxR,fin);
        printf("%d\n",res);
    }
    return 0;
}
