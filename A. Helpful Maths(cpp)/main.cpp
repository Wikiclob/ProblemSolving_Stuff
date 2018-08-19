#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    char ch[101];
    vector <int> sum;
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i+=2){
        sum.push_back(ch[i]-48);
    }
    sort(sum.begin(),sum.end());
    for(int i=0;i<sum.size();i++){
        cout << sum.at(i);
        if(i<sum.size()-1)
            cout << "+";
    }
    putchar('\n');
    return 0;
}
