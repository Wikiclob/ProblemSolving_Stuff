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

using namespace std;

int main()
{
    int N,min1=MAX_INT,min2=MAX_INT,i1=-1,i2=-1,dist;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> dist;
        if(min1>dist && i1!=i){
            min2=min1;
            i2=i1;
            min1=dist;
            i1=i;
        }
        else if(min2>dist && i2!=i){
            min2=dist;
            i2=i;
        }
    }
    cout << min1 << " " << min2 << endl;
    return 0;
}
