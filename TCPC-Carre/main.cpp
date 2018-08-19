#include <bits/stdc++.h>

using namespace std;

double maxRes;
double maxSide;
int L,W,nb;

double binary_search_res(){
    int tmpL,tmpW;
    double first=0.0001;
    double last=maxRes;
    double res;
    while(floor(first*10000)!=floor(last*10000)){
        res=(first+last)/2;
        tmpL=floor(L/sqrt(res));
        tmpW=floor(W/sqrt(res));
        if(tmpL*tmpW>=nb)
            first=res;
        else
            last=res;
    }
    return res;
}

double solve(){
    maxRes=(L*W)/(1.0*nb);
    maxSide=sqrt(maxRes);
    int nL=floor(L/maxSide),nW=floor(W/maxSide);
    if(nL*nW>nb)
        return maxRes;
    else{
        return binary_search_res();
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&nb,&L,&W);
        printf("%.4f\n",solve());
    }
    return 0;
}
