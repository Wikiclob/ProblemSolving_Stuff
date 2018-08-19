#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ch1,ch2;
    cin >> ch1 >> ch2;
    for(int i=0;i<ch1.length();i++)
        if(ch1.at(i)<='Z' && ch1.at(i)>='A')
            ch1[i]=ch1[i]+32;
    for(int i=0;i<ch2.length();i++)
        if(ch2.at(i)<='Z' && ch2.at(i)>='A')
            ch2[i]=ch2[i]+32;
    if(ch1.compare(ch2)<0)
        cout << -1 << endl;
    else if(ch1.compare(ch2)>0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
