#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

bool verif;
int N;
void verif_possible(int p,int nb){
    verif=true;
    for(int i=0;i<p;i++){
        if((nb-1)%p!=0){
            verif=false;
            break;
        }
        else
            nb-=((nb-1)/p+1);
    }
    if(nb%p!=0)
        verif=false;
}

int main()
{
    while(true){
        scanf("%d",&N);
        if(N<0)
            break;
        for(int i=5;i>1;i--){
            verif_possible(i,N);
            if(verif){
                printf("%d coconuts, %d people and 1 monkey\n",N,i);
                break;
            }
        }
        if(!verif)
            printf("%d coconuts, no solution\n",N);

    }
    return 0;
}
