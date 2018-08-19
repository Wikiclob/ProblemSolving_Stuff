#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); } // divide bef multiply!

int main()
{
    int N;
    int pgcd=1;
    int nb,nb2;
    bool reset=true;
    while(true){
        if(reset){
            scanf("%d",&nb);
            pgcd=nb;
            reset=false;
            if(nb==0)
                break;
        }
        else{
            scanf("%d",&nb2);
            if(nb2==0){
                reset=true;
                printf("%d\n",pgcd);
            }
            else{
                if(pgcd==nb){
                    pgcd=max(pgcd,nb2)-min(pgcd,nb2);
                }
                else{
                    pgcd=gcd(pgcd,nb2-nb);
                }
            }
        }
    }
    return 0;
}
