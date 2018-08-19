#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N,nbT,trai;
    string ecran="";
    bool verif=true;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nbT;
        verif=true;

        for(int j=0;j<nbT;j++){
            cin >> trai;
            if(trai>1)
                verif=false;
        }
        if(verif)
            cout << "not ambiguous" << endl;
        else
            cout << "ambiguous" << endl;
    }
    return 0;
}
