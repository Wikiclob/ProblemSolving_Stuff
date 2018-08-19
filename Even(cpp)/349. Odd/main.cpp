#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    string rep=(x%2==0)?"Even":"Odd";
    cout << rep << endl;
    return 0;
}
