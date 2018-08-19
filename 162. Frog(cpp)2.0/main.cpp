#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double dist_a_to_b(pair<int,int> a,pair<int,int> b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

int main()
{
    int N,maxD,nbWood,x,y;
    pair <int,int> dep=make_pair(25,0);
    pair <int,int> arr=make_pair(25,50);
    int dij[52][52];
    vector <pair<int,int> > Points;
    scanf("%d",&N);
     for(int i=0;i<N;i++){
        memset(dij,-1,sizeof(int)*50*2500);
        Points.clear();
        Points.push_back(dep);
        dij[0][0]=0;
        scanf("%d%d",&maxD,&nbWood);
        for(int j=0;j<nbWood;j++){
            scanf("%d%d",&x,&y);
            Points.push_back(make_pair(x,y));
            dij[0][j+1]=0;
        }
        Points.push_back(arr);
        dij[0][nbWood+1]=0;
        for(int j=0;j<52;j++){
            for(int k=0;k<52;k++){
                if(dij[j][k]!=-1){
                    for(int l=0;l<52;l++){
                        if(k!=l){
                            if(dij[j][l]!=-1){
                                if(dist_a_to_b(V[l],V[k])<=maxD)
                            }
                        }
                    }
                }
            }
        }
     }
    return 0;
}
