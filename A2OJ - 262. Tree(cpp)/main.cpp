#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
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

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int k;

typedef struct node{
    int value;
    node* left;
    node* right;
    node* parent;
} node;

typedef struct tree{
    node* head;
} tree;

tree T;

void generate_tree(){
    queue<node> q;
    node head;
    head.value = -1;
    q.push(head);
    T.head = &head;
    for(int i=0;i<k-1;i++){
        int sizeLevel = ipow(2,i);
        for(int j=0;j<sizeLevel;j++){
            node n = q.front();
            q.pop();
            node left,right;
            left.value = -1;
            right.value = -1;
            left.parent = &n;
            right.parent = &n;
            n.left = &left;
            n.right = &right;
            q.push(left);
            q.push(right);
        }
    }
}

void create(int house){
    cout << "test 1" << endl;
    node n = *T.head;
    bool placed = false;
    int level=1;
    while(!placed){

        if(level<k){
            if((*n.left).value==-1){
                n = *n.left;
                level++;
            }
            else if(n.value==-1){
                n.value = house;
                placed = true;
            }
            else if((*n.right).value==-1){
                n = *n.right;
                level++;
            }
            else{
                n = *n.parent;
                level--;
            }
        }
        else{
            n.value=house;
            placed = true;
        }
    }
}

void print_tree(){
    queue<node> q;
    q.push(*T.head);
    while(!q.empty()){
        for(int i=0;i<k;i++){
            int sizeLevel = ipow(2,i);
            for(int j=0;j<sizeLevel;j++){
                node n = q.front();
                q.pop();
                if(j!=0){
                    cout << " " << n.value;
                }
                else{
                    cout << n.value;
                }
                q.push(*n.left);
                q.push(*n.right);
            }
            cout << endl;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,tmp;
    cin >> t;
    while(t--){
        cin >> k;
        ll n = ipow(2,k)-1;
        cout << "n: " << n << endl;
        generate_tree();
        //cout << "test" << endl;
        for(int i=0;i<n;i++){
            cout << "test2" << endl;
            cin >> tmp;
            cout << "test3" << endl;
            //create(tmp);
        }
        print_tree();
    }
    return 0;
}
