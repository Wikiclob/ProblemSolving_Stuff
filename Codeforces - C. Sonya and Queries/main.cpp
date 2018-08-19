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

struct Node
{
  ll nb;
  Node *left;
  Node *right;

  Node(){
    nb=0;
    left=nullptr;//0
    right=nullptr;//1
  }
};
typedef struct Node Node;

class Tree{
public:
    Node* source;

    Tree(){
        source = new Node();
        source->left = new Node();
        source->right = new Node();
    }

    void afficheArbre(Node *n){
        if(n!=nullptr){
            cout << n->nb << " ";
            afficheArbre(n->left);
            afficheArbre(n->right);
        }
    }

    void addOne(Node *n){
        if(n!=nullptr){
            n->nb++;
            addOne(n->left);
        }
    }

    void removeOne(Node *n){
        if(n!=nullptr){
            n->nb--;
            removeOne(n->left);
        }
    }

    void _add(string x){
        Node* tmp;
        Node* last=source;
        int counter=x.size()-1;
        while(counter>=0){
            if((x[counter]-48)%2==0){
                tmp=last->left;
                if(tmp==nullptr){
                    last->left=new Node();
                    last->left->nb=last->nb;
                    tmp=last->left;
                }
            }
            else{
                tmp=last->right;
                if(tmp==nullptr){
                    last->right=new Node();
                    tmp=last->right;
                }
            }
            counter--;
            last=tmp;
        }
        addOne(tmp);
    }

    void _remove(string x){
        Node* tmp=source;
        int counter=x.size()-1;
        while(counter>=0){
            if((x[counter]-48)%2==0){
                tmp=tmp->left;
            }
            else{
                tmp=tmp->right;
            }
            counter--;
        }
        removeOne(tmp);
    }

    void _value(string x){
        Node* tmp;
        Node* last=source;
        int counter=x.size()-1;
        while(counter>=0){
            if((x[counter]-48)==0){
                tmp=last->left;
                if(tmp==nullptr){
                    last->left=new Node();
                    last->left->nb=last->nb;
                    tmp=last->left;
                }
            }
            else{
                tmp=last->right;
                if(tmp==nullptr){
                    last->right=new Node();
                    tmp=last->right;
                }
            }

            counter--;
            last=tmp;
        }
        while((tmp->left)!=nullptr){
            tmp=tmp->left;
        }
        cout << tmp->nb << endl;
    }
};
typedef struct Tree Tree;



int main()
{
    std::ios::sync_with_stdio(false);
    Tree *T=new Tree();
    int n;
    char request;
    string tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> request >> tmp;
        switch(request){
            case '+': T->_add(tmp); break;
            case '-': T->_remove(tmp); break;
            case '?': T->_value(tmp); break;
        }
    }
    return 0;
}
