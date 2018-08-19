#include <bits/stdc++.h>

using namespace std;

const int oo=1e9;

int main()
{
    int participant,budg,hotels,weeks,price,beds;
    int minV;
    while(cin >> participant){
        minV=oo;
        cin >> budg >> hotels >> weeks;
        for(int i=0;i<hotels;i++){
            cin >> price;
            for(int j=0;j<weeks;j++){
                cin >> beds;
                if(beds>=participant){
                    if(price*participant<=budg){
                        if(price*participant<minV){
                            minV=price*participant;
                        }
                    }
                }
            }
        }
        if(minV==oo)
            cout << "stay home" << endl;
        else
            cout << minV << endl;
    }
    return 0;
}
