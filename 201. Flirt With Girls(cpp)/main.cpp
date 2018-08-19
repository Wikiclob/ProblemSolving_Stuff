#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int N,dist,nb,x,y,flirt;
    float pow1, pow2,racine;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nb >> dist;
        flirt=0;
        for(int j=0;j<nb;j++){
            cin >> x >> y;
            pow1=pow(x,2);
            pow2=pow(y,2);
            racine=sqrt(pow1+pow2);
            if(racine<=dist)
                flirt++;
        }
        cout << flirt << endl;
    }
    return 0;
}
