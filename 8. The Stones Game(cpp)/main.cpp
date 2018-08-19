#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%i",&T);
    for(int i=0;i<T;i++){
        int N,M,X,a1,a2;
        scanf("%i%i%i",&N,&M,&X);
        a1=N%M;
        a2=X%M;
        if(a1==a2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
