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
#define MAX_INT (999999)
#define MIN_INT (-999999)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

float dist_pts(ii a,ii b){
    return sqrt(pow(b.first-a.first,2)+pow(b.second-a.second,2));
}



int main()
{
    int N,maxD,nbWood,x,y,i,j,k;
    vii points;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d",&maxD,&nbWood);
        int M[nbWood+2];
        bool visited[nbWood+2];
        memset(M,-1,sizeof(int)*(nbWood+2));
        memset(visited,false,sizeof(bool)*(nbWood+2));
        points.clear();
        points.push_back(ii(25,0));
        points.push_back(ii(25,50));
        for(int j=0;j<nbWood;j++){
            scanf("%d%d",&x,&y);
            points.push_back(ii(x,y));
        }
        M[0]=0;
        bool verif=true;
        int cc=0;
        while(verif){
            verif=false;
            for(j=0;j<nbWood+2;j++){
                if(M[j]!=-1){
                    for(k=0;k<nbWood+2;k++){
                        if(j!=k){
                            if(M[k]==-1){
                                if(dist_pts(points[j],points[k])<=maxD){
                                    M[k]=M[j]+1;
                                    verif=true;
                                }
                            }
                            else{
                                if(dist_pts(points[j],points[k])<=maxD){
                                    if(M[k]>M[j]+1){
                                        M[k]=M[j]+1;
                                        verif=true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(M[1]!=-1){
            cout << M[1] << "\n";
        }
        else
            cout << "Impossible\n";
    }
    return 0;
}
