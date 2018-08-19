#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,tree,nb,canP;
    long long days;
    vector <int> V;
    cin >> N;
    for(int i=0;i<N;i++){
        V.clear();
        canP=0;
        cin >> days;
        cin >> nb;
        for(int j=0;j<nb;j++){
            cin >> tree;
            V.push_back(tree);
        }
        sort(V.begin(),V.end(),greater<int>());
        int k=0,l=V.size()-2;
        while(k<V.size()){
            //cout << V.at(j) << " ";
            if(days>=V.at(k) && (days-1)>=(V.at(l)+V.at(l+1))){
                canP+=2;
                days-=2;
                l-=2;
                V.erase(l);
                V.erase(l+1);
            }
            else if(days >=V.at(k)){
                canP++;
                days--;
                k++;
            }
        }
        //cout << endl;
        cout << canP << endl;
    }
    return 0;
}
