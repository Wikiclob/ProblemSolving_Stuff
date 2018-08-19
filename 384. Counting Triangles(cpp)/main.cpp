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
    int N,np,ntri;
    vector <pair<short int,short int> > Points;
    pair<short int,short int> pt,v1,v2;
    cin >> N;
    for(int l=1;l<=N;l++){
        cin >> np;
        ntri=0;
        Points.clear();
        for(int i=0;i<np;i++){
            cin >> pt.first >> pt.second;
            Points.push_back(pt);
        }
        for(int i=0;i<np-2;i++){
            for(int j=i+1;j<np-1;j++){
                for(int k=j+1;k<np;k++){
                    v1.first=Points[i].first-Points[j].first;
                    v1.second=Points[i].second-Points[j].second;
                    v2.first=Points[j].first-Points[k].first;
                    v2.second=Points[j].second-Points[k].second;
                    ntri+=(v1.first*v2.second==v1.second*v2.first?0:1);
                }
            }
        }
        cout << "Test case #" << l << ": " << ntri << " triangle(s) can be formed." << endl;

    }
    return 0;
}
