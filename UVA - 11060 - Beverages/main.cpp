#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int MAX=110;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

int n;
vvi graphe;
vector<string> vertices;
vector<string> res;
bool visited[MAX];
vector<int> indegree;

ofstream output("output.out");

void topologicalSortUtil(int v){
    visited[v]=true;
    for(int i=0;i<graphe[v].size();i++){
        if(!visited[graphe[v][i]]){
            topologicalSortUtil(graphe[v][i]);
        }
    }
    res.push_back(vertices[v]);
}

void topologicalSort(){
    res.clear();
    memset(visited,false,sizeof visited);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topologicalSortUtil(i);
        }
    }
}

void topologicalSortUtil2(int v){
    visited[v]=true;
    for(int i=0;i<n;i++){
        if(indegree[i]==0 && !visited[i]){
            res.push_back(vertices[i]);
            for(int j=0;j<graphe[i].size();j++){
                indegree[graphe[i][j]]--;
            }
            topologicalSortUtil2(i);
        }
    }
}

void topologicalSort2(){
    res.clear();
    memset(visited,false,sizeof visited);
    topologicalSortUtil2(MAX-1);
}

void afficheTopologicalSort(){
    for(int i=res.size()-1;i>=0;i--){
        cout << res[i];
        if(i!=0)
            cout << " ";
    }
    cout << endl;
}

void afficheTopologicalSort2(){
    for(int i=0;i<res.size();i++){
        //output << res[i];
        cout << res[i];
        if(i!=(res.size()-1)){
            //output << " ";
            cout << " ";
        }
    }
    //output << "." << endl;
    cout << "." << endl;
}

int main()
{
    int m;
    int caseCount=0;
    int i1,i2;
    string s1,s2;
    bool found1,found2;
    string tmp;
    while(cin >> n){
        caseCount++;
        vertices.clear();
        graphe.clear();
        indegree.clear();
        for(int i=0;i<n;i++){
            cin >> tmp;
            vertices.push_back(tmp);
            indegree.push_back(0);
        }
        graphe.resize(n);
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> s1 >> s2;
            found1=found2=false;
            for(int j=0;j<n;j++){
                if(!found1 && vertices[j]==s1){
                    i1=j;
                    found1=true;
                }
                if(!found2 && vertices[j]==s2){
                    i2=j;
                    found2=true;
                }
                if(found1 && found2){
                    graphe[i1].push_back(i2);
                    indegree[i2]++;
                    break;
                }

            }
        }
        topologicalSort2();
        //output << "Case #" << caseCount << ": Dilbert should drink beverages in this order: " ;
        cout << "Case #" << caseCount << ": Dilbert should drink beverages in this order: " ;
        afficheTopologicalSort2();
        //output << endl;
        cout << endl;

    }
    return 0;
}
