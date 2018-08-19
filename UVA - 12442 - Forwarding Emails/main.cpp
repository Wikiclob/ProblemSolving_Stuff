#include <bits/stdc++.h>

using namespace std;

const int MAX = 50001;

int T[MAX];
int length[MAX];
bool visited[MAX];
int n;

int dfs(int i){
    int sum=0;
    visited[i]=true;
    if(T[i]!=-1 && !visited[T[i]])
        sum+=1+dfs(T[i]);
    visited[i]=false;
    return length[i]=sum;
}

int soluce(){
    int max_t=0;
    int ans;
    for(int i=1;i<=n;i++){
        if(length[i]==-1)
            dfs(i);
        if(length[i]>max_t){
            max_t=length[i];
            ans=i;
        }
    }
    return ans;
}

int main()
{
    int t,tmp;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        memset(T,-1,sizeof T);
        memset(length,-1,sizeof length);
        memset(visited,false,sizeof visited);
        for(int j=0;j<n;j++){
            cin >> tmp;
            cin >> T[tmp];
        }
        cout << "Case " << i << ": " << soluce() << endl;
    }
    return 0;
}
