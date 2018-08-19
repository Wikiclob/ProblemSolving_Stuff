#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;

vvi graphe;
vector<char> vertices;
vector<int> indegree;
bool out;
int t;
int verif;
bool beginR;

//ofstream output("output.out");

bool cycle;
void cycleDetectUtil(bool visited[],int v){
    if(visited[v]){
        cycle=true;
        return;
    }
    for(int i=0;i<graphe[v].size();i++){
        visited[v]=true;
        cycleDetectUtil(visited,graphe[v][i]);
        visited[v]=false;
    }

}

bool cycleDetect(){
    cycle=false;
    for(int i=0;i<vertices.size();i++){
        bool visited[26];
        memset(visited,false,sizeof visited);
        cycleDetectUtil(visited,i);
        if(cycle)
            return true;
    }
    return false;
}



void topologicalSort(bool visited[],vi &res){
    bool flag=false;
    for(int i=0;i<vertices.size();i++){
        if(indegree[i]==0 && !visited[i]){
            visited[i]=true;
            res.push_back(i);
            for(int j=0;j<graphe[i].size();j++){
                indegree[graphe[i][j]]--;
            }
            topologicalSort(visited,res);

            visited[i]=false;
            res.erase(res.end() - 1);
            for(int j=0;j<graphe[i].size();j++){
                indegree[graphe[i][j]]++;
            }

            flag=true;
        }
    }
    if(!flag && res.size()!=0){
        out=true;
        if(t!=(verif-1) || !beginR){
            //output << endl;
            cout << endl;
        }
        beginR=false;
        for(int i=0;i<res.size();i++){
            //output << vertices[res[i]];
            cout << vertices[res[i]];
            if(i!=(res.size()-1)){
                //output << " ";
                cout << " ";
            }
        }
    }
}

int main()
{
    char c,c1,c2;
    bool found1,found2;
    int i1,i2;
    cin >> t;
    verif=t;
    getchar();
    beginR=true;
    while(t--){
        getchar();
        graphe.clear();
        graphe.resize(26);
        vertices.clear();
        indegree.clear();
        while(true){
            c=getchar();
            if(c=='\n')
                break;

            if(c!=' '){
                vertices.push_back(c);
                indegree.push_back(0);
            }
        }

        while(true){
            c1=getchar();
            if(c1=='\n')
                break;
            if(c1!=' '){
                getchar();
                c2=getchar();
                found1=found2=false;
                for(int i=0;i<vertices.size();i++){
                    if(vertices[i]==c1){
                        found1=true;
                        i1=i;
                    }
                    if(vertices[i]==c2){
                        found2=true;
                        i2=i;
                    }
                    if(found1 && found2)
                        break;
                }
                graphe[i1].push_back(i2);
                indegree[i2]++;
            }

        }
        out=false;
        vector<int> res;
        bool cyclD=cycleDetect();
        if(!cyclD)
            topologicalSort(new bool[26],res);
        if(!out || cyclD){
            if(t!=(verif-1)){
                //output << endl;
                cout << endl;
            }
            //output << "NO";
            cout << "NO";
        }

        //output << endl;
        cout << endl;

    }
    return 0;
}
