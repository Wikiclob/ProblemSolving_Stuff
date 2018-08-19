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
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

map<string,string> regularExpressions;

bool notOperator(string s){
    return s!= ";" && s!= "(" && s!=")" && s!="|";
}

string firstExpression(string s){
    if(s.size()==0) return "";
    string result = "";
    for(int i=0;i<s.size();i++){
        string value = (notOperator(string("")+s[i]))?regularExpressions[string("")+s[i]]:"";
        if(value.size()!=0){
            result += "("+firstExpression(value)+")";
        }
        else{
            result += string("")+s[i];
        }
    }
    return result;
}

//stack<string> toDo;

void reverseStack(stack<string>& Stack)
{
   string item;
   stack<string> tmpStack;

   while (!Stack.empty())
   {
      item = Stack.top();
      Stack.pop();
      tmpStack.push(item);
   }

   //while (tmpStack.isEmptyStack() == false)
   //{
   //   item = tmpStack.top();
   //   tmpStack.pop();
   //   stack.push(item);
   //   cout << item;
   //}

   Stack = tmpStack;
   return;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    ifstream input("input.in");
    //input.tie(NULL);
    ofstream output("output.out");

    string tmp;
    //int lastOuNumber = 1;
    while(input >> tmp){
        int equalPos = tmp.find("=");
        string expression = tmp.substr(equalPos+1);
        regularExpressions[string("")+tmp[equalPos-1]] = expression;
        for(int i=0;i<expression.size();i++){
            string tmp1 = string("")+expression[i];
            if(notOperator(tmp1) && !(regularExpressions.find(tmp1) != regularExpressions.end())){
                regularExpressions[tmp1] = "";
            }
        }
    }

    for(map<string,string>::iterator it = regularExpressions.begin(); it!=regularExpressions.end();it++){
        stack<string> Stack;
        string tmp = it->s;
        int numberNow = 0;
        int now = 1;
        string res = "";
        if(tmp.size()!=0){
            Stack.push(string("")+tmp[0]);
            for(int i=1;i<tmp.size();i++){
                Stack.push(string("")+tmp[i]);
            }
            tmp = "";
            while(!Stack.empty()){
                tmp += Stack.top();
                Stack.pop();
            }
            reverse(BE(tmp));
            regularExpressions[it->f] = tmp;
        }
    }

    string M = regularExpressions["M"];

    string res = firstExpression(M);
    res = "S;" + res + ";E";
    cout << "res: " << res << endl;

    stack<string> myStack;
    vector<string> result;
    vector<pair<string,vector<string> > > saved;
    int open = 0;
    //int lastParenthese = 0;
    string myOp = "";
    bool nothingDone = true;

    for(int i=0;i<res.size();i++){
        if(res[i] == '('){
            nothingDone = false;
            open++;
        };
        if(res[i]!=')'){
            myStack.push(string("")+res[i]);
        }
        else{
            open--;
            string now = "";
            while(!myStack.empty()){

                string tmp = myStack.top();
                myStack.pop();
                if(tmp!="("){
                    now += tmp;
                }
                else{
                    break;
                }
            }
            reverse(BE(now));
            //cout << "combin: " << now << endl;
            if(now[now.size()-1]==';'){
                for(int j=0;j<result.size();j++){
                    result[j] = now+result[j];
                }
            }
            else if(now[now.size()-1]=='|'){
                result.push_back(now.substr(0,now.size()-1));
            }
            else{
                result.push_back(now);
            }

            if(!myStack.empty() && !open){
                while(!myStack.empty()){
                    string op = myStack.top();
                    myStack.pop();
                    if(op==";"){
                        for(int j=0;j<result.size();j++){
                            result[j] = myStack.top()+op+result[j];
                        }
                    }
                    else{
                        result.push_back(myStack.top());
                    }
                    myStack.pop();
                }
            }
            if(!open){
                saved.push_back(pair<string,vector<string> >(myOp,result));
                result.clear();
                if(i<res.size()-1){
                    myOp = string("")+res[i+1];
                    i++;
                }
            }

        }
    }

    if(!nothingDone){
        bool entered = false;

        if(!myStack.empty()){
            entered = true;
            string now = string("")+myStack.top();
            myStack.pop();
            result.push_back(now);
            while(!myStack.empty()){
                string tmp1,tmp2;
                tmp1 = string("")+myStack.top();
                myStack.pop();
                tmp2 = string("")+myStack.top();
                myStack.pop();

                if(tmp1==";"){
                    for(int j=0;j<result.size();j++){
                        result[j] = tmp2+tmp1+result[j];
                    }
                }
                else{
                    int sizeT = result.size();
                    for(int i=0;i<sizeT;i++){
                        result.push_back(tmp2+tmp1+result[i].substr(0,result[i].size()-1));
                    }
                }

            }
        }

        if(entered){
            saved.push_back(pair<string,vector<string> >(myOp,result));
        }
    }
    else{
        reverseStack(myStack);
        result.push_back(myStack.top());
        myStack.pop();
        while(!myStack.empty()){
            string tmp1,tmp2;
            tmp1 = myStack.top();
            myStack.pop();
            tmp2 = myStack.top();
            myStack.pop();
            if(tmp1==";"){
                for(int j=0;j<result.size();j++){
                    result[j] = result[j] + tmp1 + tmp2;
                }
            }
            else if(tmp1 == "|"){
                int sizeT = result.size();
                for(int i=0;i<sizeT;i++){
                   result.push_back(result[i].substr(0,result[i].size()-1) + tmp2);
                }
            }
        }
        saved.push_back(pair<string,vector<string> >("",result));
    }


    while(saved.size()>1){
        if(saved[1].f == "|"){
            for(int i=0;i<saved[0].s.size();i++){
                saved[1].s.push_back(saved[0].s[i]);
            }
            saved.erase(saved.begin());
        }
        else{
            vector<string> temp;
            for(int i=0;i<saved[1].s.size();i++){
                for(int j=0;j<saved[0].s.size();j++){
                    temp.push_back(saved[0].s[j] + ";"+ saved[1].s[i]);
                }
            }
            saved[1].s = temp;
            saved.erase(saved.begin());
        }
    }

    vector<string> toPrint = saved[0].s;

    string json = "[";

    for(int i=0;i<toPrint.size();i++){
        for(int j=1;j<toPrint[i].size();j+=2){
            string object = "{\"from\":\"";
            object += toPrint[i][j-1];
            object += "\",\"to\":\"";
            object += toPrint[i][j+1];
            object += "\"}";
            json += object + ",";
        }
    }
    json[json.size()-1] = ']';

    cout << json << endl;
    output << json << endl;

    //cout << saved.size() << endl;
    cout << "--begin saved" << endl;
    for(int i=0;i<toPrint.size();i++){
        cout << toPrint[i] << endl;
     }
    cout << "--end saved" << endl;

    /*for(map<string,string>::iterator it = regularExpressions.begin(); it!=regularExpressions.end();it++){
        cout << it->f << " := " << it->s << endl;
    }*/
    return 0;
}
