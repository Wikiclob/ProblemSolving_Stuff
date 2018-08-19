#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

//ofstream output("output.out");

int main()
{
    int N,nb,i,j;
    double calcul,tmp;
    scanf("%d",&N);
    cout << fixed;
    for(i=0;i<N;i++){
        scanf("%d",&nb);
        if(nb==1)
            //printf("%.3f\n",0.0);
            cout << setprecision(3) << 0.0 << "\n";
        else if(nb==2)
            //printf("%.3f\n",4.0);
            cout << setprecision(3) << 4.0 << "\n";
        else{
            tmp=0;
            calcul=nb/2;
            calcul+=2+(nb-3)/2;
            calcul+=1+(nb-3)/2;
            calcul+=(nb-2)/2;
            calcul+=(nb-1)*2;
            for(j=3;j<nb;j++)
                tmp+=sqrt(2*pow(j-2,2));
            calcul+=2*tmp+sqrt(2*pow(nb-2,2));
            //printf("%.3f\n",calcul);
            cout << setprecision(3) << calcul << "\n";
        }
    }
    return 0;
}
