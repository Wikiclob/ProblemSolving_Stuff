#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long S,N,sum=0,prod;
    cin >> N >> S;
    for(long long i=0;i<N;i++){
        cin >> prod;
        sum+=prod;
    }
    if(sum<=S)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
