#include <iostream>
#define fc(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
    int n,i;
    cin >> n;
    fc(i,n)
        cout << i+1 << " ";
    cout << endl;
    return 0;
}
