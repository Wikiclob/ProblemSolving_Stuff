#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void printTransactions(double m, int k, int d, vector <string> name, vector <int> owned, vector < vector <double> > prices) {
    //Enter your code here
    vector<double> estimation(k);
    vector<double> moy(k);
    vector<pair<double,double> > round(k);
    vector<double> maxFluctuation(k);
    double tmp;
    double minf,maxf;
    double money=m;
    for(int i=0;i<k;i++){
        minf=prices[i][0];
        maxf=prices[i][0];
        for(int j=1;j<5;j++){
            estimation[i]+=prices[i][j]-prices[i][j-1];
            if(prices[i][j]>maxf)
                maxf=prices[i][j];
            if(prices[i][j]<minf)
                minf=prices[i][j];
        }
        maxFluctuation[i]=maxf-minf;
        moy[i]=estimation[i]/4;
        tmp=moy[i]*10;
        //tmp=round(tmp);
        tmp/=10;
        round[i]={tmp,-tmp};
        //if(estimation[i]<tmp && estimation[i]>-tmp)
        //    cout << name[i] << " SELL 0\n";
    }
    vector<pair<int,int> > buy;
    vector<double> diff;
    vector<int> buyOrSell(k);//1 buy -1 sell 0 nothing
    for(int i=0;i<k;i++){
        if(estimation[i]<round[i].second){
            buyOrSell[i]=1;
            buy.push_back({i,0});
            diff.push_back(round[i].second-estimation[i]+((maxFluctuation[i]/2)-round[i].first));
        }
        else if(estimation[i]>round[i].first){
            buyOrSell[i]=-1;
        }
        else{
            buyOrSell[i]=0;
        }
    }
    bool exit=false;
    int maxBuy=0;
    for(int i=0;i<buy.size();i++){
        maxBuy=0;
        for(int k=0;k<buy.size();k++){
            if(diff[k]>diff[maxBuy] && prices[buy[k].first][4]<=money)
                maxBuy=k;
        }
        if(prices[maxBuy][4]<=money){
            buy[k].second=floor(money/prices[maxBuy][4]);
            money-=buy[k].second;
        }
        else{
            exit=true;
            break;
        }
    }
    int countB=0;
    for(int i=0;i<k;i++){
        if(buyOrSell[i]==-1){
            cout << name[i] << " SELL " << owned[i] << "\n";
        }
        else if(buyOrSell[i]==1){
            if(buy[countB].second>0){
                cout << name[i] << " BUY " << buy[countB].second << "\n";
            }
            countB++;
        }
    }



}
int main(void) {
    double _m;
    cin >> _m;

    int _k;
    cin >> _k;

    int _d;
    cin >> _d;

    vector<string> _name;
    vector<int> _owned;
    vector < vector <double> > _prices;

    string _name_item;
    int _owned_item;
    double _prices_item_item;

    for(int _i=0; _i<_k; _i++) {
        cin >> _name_item;
        _name.push_back(_name_item);

        cin >> _owned_item;
        _owned.push_back(_owned_item);

        vector <double> _prices_item;
        for(int _j = 0; _j<5; _j++) {
            cin >> _prices_item_item;
            _prices_item.push_back(_prices_item_item);
        }
        _prices.push_back(_prices_item);

    }

    printTransactions(_m, _k, _d, _name, _owned, _prices);

    return 0;
}
