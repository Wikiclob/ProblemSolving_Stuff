#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int N;
vector<vector<ii>> adjList;


int dfs(int u, int parent){
    int m = 0;
    for(ii &v:adjList[u]){
        if(v.first != parent){
            if(v.second == 0)
                v.second = dfs(v.first, u);
            m = max(m, v.second);
        }
    }
    return 1 + m;
}

int main(){
    int TC;
    int U, V;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        adjList.assign(N+1, vector<ii>());
        int nEdge = N-1;
        while(nEdge--){
            scanf("%d %d", &U, &V);
            adjList[U].push_back({V,0});
            adjList[V].push_back({U,0});
        }

        if(N == 1) printf("0\n");
        else{
            int depth = 0;
            for(int i = 1; i <= N; i++){
                if(adjList[i].size() == 1)
                depth = max(depth, dfs(i, -1));
            }
            printf("%d\n", N-depth);
        }
    }
    return 0;
}
