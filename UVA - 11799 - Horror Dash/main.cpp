#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,maxN,speed;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        maxN=0;
        while(n--){
            cin >> speed;
            maxN=max(maxN,speed);
        }
        cout << "Case " << i << ": " << maxN << endl;
    }
    return 0;
}
