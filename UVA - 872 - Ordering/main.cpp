#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
const int MAX=26;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

vvi graphe;

class Graph{
    vector<int> vert; // list of vertex
    vector<int> indegree;

private:
    void allTopologicalSortUtil(vector<int>& res,bool visited[]){
        bool flag=false;

        for(int i=0;i<vert.size();i++){
            if(indegree[vert[i]] && !visited[vert[i]]){
                for(int j=0;j<graphe[vert[i]].size();j++){
                    indegree[graphe[vert[i]][j]]--;
                }

                res.push_back(vert[i]);
                visited[vert[i]]=true;
                allTopologicalSortUtil(res, visited);

                visited[vert[i]]=false;

                for(int j=0;j<graphe[vert[i]].size()-1;j++){
                    indegree[graphe[vert[i]][j]]++;
                }

                flag = true;
            }
        }

        if(!flag){
            for(int i=0;i<res.size();i++){
                cout << (char)(res[i]+'A') << " ";
            }
            cout << endl;
        }
    }

public:
    bool existVertex(char c){
        for(int i=0;i<vert.size();i++){
            if(vert[i]==(c-'A'))
                return true;
        }
        return false;
    }

    void addVertex(char c){
        vert.push_back(c-'A');
    }

    void addEdge(char c1,char c2){
        graphe[c1-'A'].push_back(c2-'A');
        indegree[c2-'A']++;
    }

    void clearGraph(){
        graphe.clear();
        graphe.resize(26);
        vert.clear();
        indegree.clear();
        indegree.resize(26);
    }



    void allTopologicalSorts(){
        bool visited[26];
        memset(visited, false, sizeof visited);

        vector<int> res;
        allTopologicalSortUtil(res,visited);
    }
};

int main()
{
    int t;
    Graph G;

    char c,c1,c2;
    cin >> t;
    getchar();
    while(t--){
        getchar();
        G.clearGraph();
        while(true){
            c=getchar();
            if(c=='\n')
                break;

            if(c!=' '){
                G.addVertex(c);
                cout << "test1: " << c << endl;
            }
        }
        while(true){
            c1=getchar();
            if(c1=='\n')
                break;
            if(c1!=' '){
                cout << "test2(c1): " << c1 << endl;
                getchar();
                c2=getchar();
                cout << "test2(c2): " << c2 << endl;
                G.addEdge(c1,c2);
            }
        }
        G.allTopologicalSorts();
    }
    return 0;
}
