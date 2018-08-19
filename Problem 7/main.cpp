#include <iostream>
#include <vector>
#include <set>

#define INF 999999999999LL
using namespace std;
int n, m;
long long mp[110][110];
long long d[110][110];

int tx[] = {1,-1,0,0};
int ty[] = {0,0,-1,1};

set<pair<long long, pair<int, int> > > active;

bool inBounds(pair<int, int> point){
    return point.first >= 0 && point.first < n && point.second >= 0 && point.second < m;
}

long long dijkstra(){
    active.insert(make_pair(mp[0][0], make_pair(0,0)));
    while(!active.empty()){
        pair<int, int> curr = active.begin()->second;
        if(curr.first == n-1 && curr.second == m-1) return d[curr.first][curr.second];
        active.erase(active.begin());
        for(int k = 0; k < 4; k++){
            int adjY = curr.first+ty[k];
            int adjX = curr.second+tx[k];
            if(inBounds(make_pair(adjY, adjX))){
                long long oldValue = d[adjY][adjX];
                long long newValue = mp[adjY][adjX] + d[curr.first][curr.second];
                if(oldValue > newValue){
                    active.erase(make_pair(oldValue, make_pair(adjY, adjX)));
                    d[adjY][adjX] = newValue;
                    active.insert(make_pair(d[adjY][adjX], make_pair(adjY, adjX)));
                }
            }
        }
    }
}

void init(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] = INF;

    active.clear();
}


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mp[i][j];

        init();
        d[0][0] = mp[0][0];
        cout << dijkstra() << endl;
    }
    return 0;
}
