#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
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
    int N,S,val,sum;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> val >> S;
        sum=val*(val+1)/2;
        if(sum==S)
            cout << "Possible" << endl;
        else if(sum<S || sum%2!=S%2 || sum-4<S || 2-sum>S)
            cout << "Impossible" <<endl;
        else
            cout << "Possible" << endl;
    }
    return 0;
}
