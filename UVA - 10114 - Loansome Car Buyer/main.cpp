#include <bits/stdc++.h>

using namespace std;

int main()
{
    int duration,nbDep,firstW,secondW,nbW,currW;
    double monthPay,loan,percent,ownedL,CarPrice,oldPercent;
    bool stop=false;
    int month;
    while(cin >> duration){
        cin >> monthPay >> loan >> nbDep;
        ownedL=loan;
        month=0;
        stop=false;
        CarPrice=loan+monthPay;
        currW=0;
        firstW=0,secondW=0;
        for(int i=0;i<nbDep;i++){
            cin >> secondW >> percent;
            if(!stop){
                if(i==0)
                    oldPercent=percent;
                while(currW<=secondW){
                    if(currW==0)
                        CarPrice*=(1-oldPercent);
                    else{
                        ownedL-=monthPay;
                        if(currW<secondW){
                            CarPrice*=(1-oldPercent);
                        }
                        else{
                            CarPrice*=(1-percent);
                            oldPercent=percent;
                        }
                    }
                    cout << "CarPrice: " << CarPrice << " ownedL: " << ownedL << endl;
                    if(CarPrice>ownedL){
                        month=currW;
                        stop=true;
                    }
                    currW++;
                }
            }
        }
        if(CarPrice>=ownedL){
            while(currW<duration){
                CarPrice*=(1-oldPercent);
                ownedL-=loan;
                if(CarPrice<ownedL){
                    month=currW;
                    break;
                }
                cout << "CarPrice: " << CarPrice << " ownedL: " << ownedL << endl;
                currW++;
            }
        }
        if(month==1)
            cout << month << " month" << endl;
        else
            cout << month << " months" << endl;
    }
    return 0;
}
