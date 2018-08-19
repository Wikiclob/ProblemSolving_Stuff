#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;


priority_queue <ii, vector<ii>, greater<ii> > pq;

int main(){
    pq.push({6,8});
    pq.push({1,4});
    pq.push({3,7});

    cout << pq.top().first << endl;
    return 0;
}
