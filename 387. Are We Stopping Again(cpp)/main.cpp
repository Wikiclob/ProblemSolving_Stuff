#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)

using namespace std;

int mini(int a,int b)
{
    int min=(a<b)?a:b;
    return min;
}
int pgcd(int a, int b)
{
    int pgcd=min(a,b);
	while (pgcd>=1)
    {
		if(a%pgcd==0 && b%pgcd==0)
            break;
		pgcd--;
	}
    return pgcd;
}
int ppcm(int a, int b)
{
    int ppcm=(a*b)/pgcd(a,b);
    return ppcm;
}

int main()
{
    int N,total,gas,food,stop,pcm;
    cin >> N;
    while(N--){
        cin >> total >> gas >> food;
        stop=total/gas-(total%gas==0?1:0);
        stop+=total/food-(total%food==0?1:0);
        pcm=ppcm(food,gas);
        stop-=total/pcm-(total%pcm==0?1:0);
        cout << total << " " << gas << " " << food << endl;
        cout << stop << endl;
    }
    return 0;
}
