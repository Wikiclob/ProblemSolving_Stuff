#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
#define BE(x) x.begin(),x.end()
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<string,string> ss;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

ifstream input("kittens.in");
ofstream output("output.out");

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    input.tie(NULL);
    int tmp1,tmp2,tmp3;
    int V,E,R,C,X;

    input >> V >> E >> R >> C >> X;

    vi sizes(V);
    vi serverLatencies(E);
    int nbConnection;
    vector<vector<ii> > cacheLatencies(E);
    vector<vector<ii> > EndpointLatencies(C);
    vector<vector<ii> > requestsVideos(E);
    vector<vector<ii> > requestsEndPoints(V);
    vector<map<int,long long> > best_choice(C);



    vi cacheRestSize(C,X);

    for(int i=0;i<V;i++)
        input >> sizes[i];

    for(int i=0;i<E;i++){
        input >> serverLatencies[i] >> nbConnection;
        for(int j=0;j<nbConnection;j++){
            input >> tmp1 >> tmp2;
            EndpointLatencies[tmp1].push_back(ii(i,tmp2));
            cacheLatencies[i].push_back(ii(tmp1,tmp2));
        }
    }

    for(int i=0;i<R;i++){
        input >> tmp1 >> tmp2 >> tmp3;
        requestsVideos[tmp2].push_back(ii(tmp1,tmp3));
        requestsEndPoints[tmp1].push_back(ii(tmp2,tmp3));
    }

    vector<vector<bool> > visitedCE(E,vector<bool>(C,false));
    vector<vector<bool> > visitedCV(C,vector<bool>(V,false));

    int min_,i_,j_;
    double rat_;
    int ii_,jj_;
    vvi result(C);

    while(true){
        min_ = oo;
        for(int i=0;i<E;i++){
            for(int j=0;j<cacheLatencies[i].size();j++){
                int v = cacheLatencies[i][j].f;
                int lat = cacheLatencies[i][j].s;
                if(min_>lat && !visitedCE[i][v]){
                    min_ = lat;
                    i_ = i;
                    j_ = v;
                }
            }
        }
        if(min_== oo)
            break;
        visitedCE[i_][j_] = true;
        rat_ = -oo;
        for(int i=0;i<requestsVideos[i_].size();i++){
            if((rat_<requestsVideos[i_][i].s / sizes[requestsVideos[i_][i].f]) && (cacheRestSize[j_] >= sizes[requestsVideos[i_][i].f]) && !visitedCV[j_][requestsVideos[i_][i].f]){
                rat_ = requestsVideos[i_][i].s / sizes[i];
                ii_ = requestsVideos[i_][i].f;
            }
        }
        if(rat_ == -oo)
            break;
        result[j_].push_back(ii_);
        cacheRestSize[j_]-= sizes[ii_];
        visitedCV[j_][ii_] = true;
    }

    //videosId.resize(V);

    /*for(int i=0;i<V;i++){
        videosId[i] = i;
    }*/

    /*for(int i=0;i<C;i++){
        int cache = i;
        for(int j=0;j<EndpointLatencies[i].size();j++){
            int endPoint = EndpointLatencies[i][j].f;
            for(int k=0;k<requestsVideos[EndpointLatencies[i][j].f].size();k++){

            }
        }
    }

    for(int i=0;i<V;i++){
        if(sizes[i] <= X){
            for(int j=0;j<C;j++){
                if(cacheRestSize[j] >= sizes[i]){
                    solution[j].push_back(videosId[i]);
                    cacheRestSize[j]-= sizes[i];
                }
            }
        }
    }
    */
    int nbUsed = 0;
    for(int i=0;i<result.size();i++){
        if(result[i].size()!=0)
            nbUsed++;
    }

    output << nbUsed << endl;

    for(int i=0;i<result.size();i++){
        if(result[i].size()!=0){
            output << i;
            for(int j=0; j < result[i].size();j++){
                output << " " << result[i][j];
            }
            output << endl;
        }
    }

    return 0;
}
