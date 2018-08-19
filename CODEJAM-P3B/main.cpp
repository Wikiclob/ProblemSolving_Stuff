#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265

using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

vector<pair<string,string> > V;


typedef struct Node{
    string ch1;
    string ch2;
    vector<int> connections;
    vector<int> relation;// 1 for nom 2 for prenom 3 for both
    bool desactivated;
};

vector<Node> Graph;
int maxFake;

void add(Node n){
    for(int i=0;i<Graph.size();i++){
        if(Graph[i].ch1==n.ch1 || Graph[i].ch2==n.ch2){
            Graph[i].connections.push_back(Graph.size());
            n.connections.push_back(i);
            if(Graph[i].ch1==n.ch1 && Graph[i].ch2==n.ch2){
                Graph[i].relation.push_back(3);
                n.relation.push_back(3);
            }
            else if(Graph[i].ch1==n.ch1){
                Graph[i].relation.push_back(1);
                n.relation.push_back(1);
            }
            else{
                Graph[i].relation.push_back(2);
                n.relation.push_back(2);
            }
        }
    }
    Graph.push_back(n);
}

void desactivate(int i){
    Graph[i].desactivated=true;
}

void activate(int i){
    Graph[i].desactivated=false;
}

void initializeActivated(){
    for(int i=0;i<Graph.size();i++){
        Graph[i].desactivated=false;
    }
}

bool isDesactivated(int i){
    return Graph[i].desactivated;
}

int connections(int i){
    return Graph[i].relation.size();
}

bool maybeFake(int i){
    bool verif1=false;
    bool verif2=false;
    for(int j=0;j<Graph[i].connections.size();j++){
        if(!isDesactivated(Graph[i].connections[j])){
            if(!verif1){
                if(Graph[i].relation[j]==1 || Graph[i].relation[j]==3)
                    verif1=true;
            }
            if(!verif2){
                if(Graph[i].relation[j]==2 || Graph[i].relation[j]==3)
                    verif2=true;
            }
            if(verif1 && verif2)
                return true;
        }
    }
    return false;
}

void initializeMaxFake(){
    maxFake=0;
}

vector<int> MaxTab;

void countMaxFake(){
    int countMax=1;
    int firstInd=-1;
    stack<int> fake;
    int react=-1;
    do{
        countMax=0;
        //cout << "size: " << Graph.size() << " first ind: " << firstInd << endl;
        for(int i=0;i<Graph.size();i++){
            //cout << "infini? " << i << endl;
            if(maybeFake(i) && react!=i){
                desactivate(i);
                fake.push(i);
                countMax++;
            }
        }
        MaxTab.push_back(countMax);
        if(fake.size()>0){
            activate(firstInd);
            react=firstInd;
            firstInd=fake.top();
            fake.pop();
        }

    }
    while(fake.size()>0);
}

int main()
{
    ifstream input("C-small-practice.in");
    ofstream output("C-small-practice.out");
    int N;
    int nb;
    string name1,name2;
    input >> N;
    for(int i=1;i<=N;i++){
        input >> nb;
        initializeMaxFake();
        Graph.clear();
        MaxTab.clear();
        for(int j=0;j<nb;j++){
            input >> name1 >> name2;
            Node n;
            n.ch1=name1.substr(0,name1.size());
            n.ch2=name2.substr(0,name2.size());
            add(n);
        }
        //cout << "test " << i << endl;
        countMaxFake();
        int maxF=0;
        for(int j=0;j<MaxTab.size();j++){
            if(MaxTab[j]>maxF)
                maxF=MaxTab[j];
        }
        cout << maxF << endl;
        output << "Case #" << i << ": ";
        output << maxF << "\n";
    }
    return 0;
}
