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

int main()
{
    int N,nb;
    ll toy,best;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nb;
        best=0;
        for(int j=0;j<nb;j++){
            cin >> toy;
            best=max(best,toy);
        }
        cout << best << endl;
    }
    return 0;
}
