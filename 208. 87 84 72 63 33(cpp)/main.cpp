#include <iostream>

using namespace std;

int main()
{
    string affiche="";
    int T[]={45,8+48,6+48,3+48,9+48,1+48,2+48,3+48,9+48,7+48};
    for(int i=0;i<10;i++)
        if(i!=9)
            cout << T[i] << " ";
        else
            cout << T[i] << endl;
    return 0;
}
