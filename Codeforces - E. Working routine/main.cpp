#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int oo=1e9;
const int MAX=1010;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int M[MAX][MAX];
int n,m;

void swap_c(int a,int b,int x,int y){
    M[a][b]=M[a][b]+M[x][y];
    M[x][y]=M[a][b]-M[x][y];
    M[a][b]=M[a][b]-M[x][y];
}

void swap_mem(int a,int b,int x,int y,int _size){
    int tmp[MAX];
    memcpy(tmp,M[a]+b,_size*sizeof(int));
    memcpy(M[a]+b,M[x]+y,_size*sizeof(int));
    memcpy(M[x]+y,tmp,_size*sizeof(int));
}

void swap_m(int a,int b,int x,int y,int nn,int mm){
    for(int i=a;i<a+nn;i++){
        swap_mem(i,b,i-a+x,y,mm);
    }
}

void print_res(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << M[i][j];
            if(j!=(m-1))
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int q;
    int a,b,x,y,nn,mm;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> M[i][j];
        }
    }
    while(q--){
        cin >> a >> b >> x >> y >> nn >> mm;
        swap_m(a-1,b-1,x-1,y-1,nn,mm);
    }
    print_res();
    return 0;
}
