#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char decrypt[27];
    string crypt;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin.ignore();
        getline(cin,crypt);
        fflush(stdin);
        scanf("%s",decrypt);
        printf("%i ",i+1);
        for(int j=0;j<crypt.size();j++){
            if(crypt[j]!=' ')
                cout << decrypt[(int)crypt[j]-65];
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
