#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%i",&T);
    for(int i=0;i<T;i++){
        int nbWords,enWord=-1;
        //cout << "testT " << i << endl;
        scanf("%i",&nbWords);
        string line[nbWords],swapW;
        for(int j=0;j<nbWords;j++){
            cin >> line[j];
            //cout << "test " << j << endl;
            if(line[j].at(0)!='#')
                enWord=j;
        }
        //cout << "test" << endl;
        if(enWord==-1){
            for(int j=0;j<nbWords-1;j++)
                cout << line[j]+" ";
            cout << line[nbWords-1] << endl;
        }
        else if(enWord==0){
            for(int j=1;j<nbWords;j++)
                cout << line[j]+" ";
            cout << line[enWord] << endl;
        }
        else if(enWord==nbWords-1){
            cout << line[enWord];
            for(int j=0;j<nbWords-1;j++)
                cout << " "+line[j];
            cout << endl;
        }
        else{
            for(int j=enWord+1;j<nbWords;j++)
                cout << line[j]+" ";
            cout << line[enWord];
            for(int j=0;j<enWord;j++)
                cout << " "+line[j];
            cout << endl;
        }
    }
    return 0;
}
