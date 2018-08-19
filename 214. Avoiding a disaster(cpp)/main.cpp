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
#define HALFDAY_IN_MIN (720)

using namespace std;

int calcul_min(string h){
    int hour=atoi(h.substr(0,2).c_str());
    int minute=atoi(h.substr(3,2).c_str());
    return (hour*60+minute);
}

pair<int,int> min_diff(int h1, int h2){
    if(h1==h2)
        return make_pair(0,0);
    pair<int,int> res;
    res.first=abs(h1-h2);
    res.second=HALFDAY_IN_MIN-abs(h1-h2);
    return res;
}

bool verif_can_do_it(int h1,int h2, int h3){//h1 et h2 sont les faux et h3 la vrai
    //cout << h1 << " " << h2 << " " << h3 << endl;
    pair<int,int> diff=min_diff(h1,h2);
    //cout << diff.first << " " << diff.second << endl;
    int add,sub;
    if(diff.first%2==0){
        add=h1+diff.first/2;
        if(add>HALFDAY_IN_MIN+59)
            add-=HALFDAY_IN_MIN;
        //cout << "[first diff]add: "<< add << endl;
        if(add==h3)
            return true;
        sub=h1-diff.first/2;
        if(sub<60)
            sub+=HALFDAY_IN_MIN;
        //cout << "[first diff]sub: "<< sub << endl;
        if(sub==h3)
            return true;
    }
    if(diff.second%2==0){
        add=h1+diff.second/2;
        if(add>HALFDAY_IN_MIN+59)
            add-=HALFDAY_IN_MIN;
        //cout << "[second diff]add: "<< add << endl;
        if(add==h3)
            return true;
        sub=h1-diff.second/2;
        if(sub<60)
            sub+=HALFDAY_IN_MIN;
        //cout << "[second diff]sub: "<< sub << endl;
        if(sub==h3)
            return true;
    }
    return false;
}

int main()
{
    string H[3];
    int HM[3];
    int N,theOne;
    bool verif;
    cin >> N;
    for(int i=0;i<N;i++){
        verif=false;
        cin >> H[0] >> H[1] >> H[2];
        HM[0]=calcul_min(H[0]);
        HM[1]=calcul_min(H[1]);
        HM[2]=calcul_min(H[2]);
        for(int j=0;j<3;j++){
            //cout << "test " << j << ": " << HM[j] << " " << HM[(j+1)%3] << " " << HM[(j+2)%3] << endl;
            if(verif_can_do_it(HM[j],HM[(j+1)%3],HM[(j+2)%3])){
                if(!verif){
                    verif=true;
                    theOne=(j+2)%3;
                }
                else{
                    verif=false;
                    break;
                }
            }
        }
        if(!verif)
            cout << "Look at the sun" << endl;
        else
            cout << "The correct time is " << H[theOne] << endl;
    }
    return 0;
}
