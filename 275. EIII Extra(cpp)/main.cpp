#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    long long nb;
    cin >> N;
    while(N--){
        cin >> nb;
        if(nb%3==0)
            cout << (nb/3)*20 << "\n";
        else
            cout << (nb/3+1)*20 << "\n";
    }
    return 0;
}
