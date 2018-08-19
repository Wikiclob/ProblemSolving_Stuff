#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int TC;
    long long A, O;
    long long TEMP;
    long long ans;
    scanf("%d", &TC);
    while(TC--){
        cin >> A >> O;
        cin >> ans;
        for(int i = 0; i < A; i++){
            cin >> TEMP;
            ans &= TEMP;
        }

        for(int i = 0; i < O; i++){
            cin >> TEMP;
            ans |= TEMP;
        }
        cout << ans << endl;
    }
    return 0;
}
