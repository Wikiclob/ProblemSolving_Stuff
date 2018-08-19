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
    int N;
    int nbW,nbC,cc,minNb,countC;
    cin >> N;
    for(int i=1;i<=N;i++){
        countC=0;
        cin >> nbW >> nbC;
        minNb=nbW/2+nbW%2;
        for(int j=0;j<nbC;j++){
            cin >> cc;
            countC+=(cc>=minNb?1:0);
        }
        cout << "Case " << i << ": " << countC << endl;
    }
    return 0;
}
