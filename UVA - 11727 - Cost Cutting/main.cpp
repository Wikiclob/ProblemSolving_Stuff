#include <bits/stdc++.h>

using namespace std;

int mid(int a,int b,int c){
    return a+b+c-max(a,max(b,c))-min(a,min(b,c));
}

int main()
{
    int t;
    int a,b,c;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> a >> b >> c;
        cout << "Case " << i << ": " << mid(a,b,c) << endl;
    }
    return 0;
}
