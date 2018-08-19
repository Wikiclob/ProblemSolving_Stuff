#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int N;
    char star[40];
    cin >> N;
    memset(star,32,N-1);
    memset(star+N-1,'*',1);
    memset(star+N,'\0',1);
    for(int i=0;i<N;i++){

        printf("%s\n",star+i);
        memset(star+N+i*2,'*',2);
        memset(star+N+i*2+2,'\0',1);
    }
    return 0;
}
