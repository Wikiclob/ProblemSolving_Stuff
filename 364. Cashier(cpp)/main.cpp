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
    int flous;
    map<int,int> caisse;
    while(true){
        cin >> flous;
        if(flous==0)
            break;
        if(caisse.insert(pair<int,int>(flous,1)).second==false)
            caisse[flous]++;
    }
    for(map<int,int>::iterator it=caisse.begin();it!=caisse.end();it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
