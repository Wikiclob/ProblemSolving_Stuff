#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    string ch;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ch;
        if(ch.length()>10)
            cout << ch.at(0) << ch.length()-2 << ch.at(ch.length()-1) << endl;
        else
            cout << ch << endl;
    }
    return 0;
}
