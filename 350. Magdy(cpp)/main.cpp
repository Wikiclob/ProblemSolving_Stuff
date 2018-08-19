#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    string rep=(x<1)?"Don't be lazy, it takes only few minutes, you can do it.":(x==1)?"Good Job":"You Rocks Man";
    cout << rep << endl;
    return 0;
}
