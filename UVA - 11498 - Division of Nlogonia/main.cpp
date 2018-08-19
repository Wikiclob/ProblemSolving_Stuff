#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,coordX,coordY;
    int divX,divY;
    while(true){
        cin >> k;
        if(!k)
            break;
        cin >> divX >> divY;
        while(k--){
            cin >> coordX >> coordY;
            if(coordX==divX || coordY == divY)
                cout << "divisa" << endl;
            else if(coordX>divX && coordY > divY)
                cout << "NE" << endl;
            else if(coordX < divX && coordY > divY)
                cout << "NO" << endl;
            else if(coordX < divX && coordY < divY)
                cout << "SO" << endl;
            else
                cout << "SE" << endl;
        }
    }
    return 0;
}
