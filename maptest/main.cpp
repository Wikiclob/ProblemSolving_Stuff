#include <iostream>
#include <set>



using namespace std;

int main(){
    set<pair<int, pair<int, int>>> s;
    s.insert(make_pair(1, make_pair(3, 2)));
    s.insert(make_pair(6, make_pair(1, 8)));
    s.insert({2, {5, 2}});
    s.erase({6,{1,8}});
    for(auto x:s){
        cout << x.first << endl;
    }
    return 0;
}
