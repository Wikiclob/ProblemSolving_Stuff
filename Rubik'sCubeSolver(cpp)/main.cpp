#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
#include <fstream>
#include <time.h>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;


enum COLOR{red=0,yellow=1,green=2,orange=3,blue=4,black=5,white=6};
enum MOVES{R=0,Rr=1,L=2,Lr=3,U=4,Ur=5,D=6,Dr=7,F=8,Fr=9,B=10,Br=11,VIDE=12};

struct face{
    COLOR square[3][3];
};

struct cube{
    face Right;
    face Left;
    face Up;
    face Down;
    face Front;
    face Back;
};

typedef pair< pair<cube,int>,MOVES> STATE;

struct ARBRE{
    STATE debut;
    ARBRE* last;
    vector<ARBRE*> next;
};

ifstream input("input.in");
ofstream output("output.out");
ARBRE arbre_moves;
stack<ARBRE *> recursive;

void init_face(COLOR col, face *f){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            (*f).square[i][j]=col;
        }
    }
}

void init_cube(cube *c){
    init_face(black,&(*c).Down);
    init_face(red,&(*c).Left);
    init_face(yellow,&(*c).Up);
    init_face(green,&(*c).Front);
    init_face(orange,&(*c).Right);
    init_face(blue,&(*c).Back);
}

COLOR center_face(face f){
    return f.square[1][1];
}

string retour_color(COLOR c){
    switch(c){
    case black:     return "black";break;
    case red:       return "red";break;
    case yellow:    return "yellow";break;
    case green:     return "green";break;
    case orange:    return "orange";break;
    case blue:      return "blue";break;
    case white:     return "white";break;
    }
}

string retour_moves(MOVES m){
    switch(m){
    case R: return "R";
    case Rr: return "Rr";
    case L: return "L";
    case Lr: return "Lr";
    case U: return "U";
    case Ur: return "Ur";
    case D: return "D";
    case Dr: return "Dr";
    case F: return "F";
    case Fr: return "Fr";
    case B: return "B";
    case Br: return "Br";
    case VIDE: return "vide";
    }
}

void affiche_cube(cube c){
    int i,j;
    cout << "DOWN FACE:" << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "\t" << retour_color(c.Down.square[i][j]);
        }
        cout << "\n";
    }
    cout << "FRONT FACE:" << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "\t" << retour_color(c.Front.square[i][j]);
        }
        cout << "\n";
    }
    cout << "RIGHT FACE:" << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "\t" << retour_color(c.Right.square[i][j]);
        }
        cout << "\n";
    }
    cout << "BACK FACE:" << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "\t" << retour_color(c.Back.square[i][j]);
        }
        cout << "\n";
    }
    cout << "LEFT FACE:" << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "\t" << retour_color(c.Left.square[i][j]);
        }
        cout << "\n";
    }
    cout << "UP FACE:" << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << "\t" << retour_color(c.Up.square[i][j]);
        }
        cout << "\n";
    }
}

void reverse_face_normal(face *f){
    COLOR tmpC=(*f).square[0][0];
    (*f).square[0][0]=(*f).square[2][0];
    (*f).square[2][0]=(*f).square[2][2];
    (*f).square[2][2]=(*f).square[0][2];
    (*f).square[0][2]=tmpC;
    tmpC=(*f).square[0][1];
    (*f).square[0][1]=(*f).square[1][0];
    (*f).square[1][0]=(*f).square[2][1];
    (*f).square[2][1]=(*f).square[1][2];
    (*f).square[1][2]=tmpC;
}

void reverse_face_reverse(face *f){
    COLOR tmpC=(*f).square[0][0];
    (*f).square[0][0]=(*f).square[0][2];
    (*f).square[0][2]=(*f).square[2][2];
    (*f).square[2][2]=(*f).square[2][0];
    (*f).square[2][0]=tmpC;
    tmpC=(*f).square[0][1];
    (*f).square[0][1]=(*f).square[1][2];
    (*f).square[1][2]=(*f).square[2][1];
    (*f).square[2][1]=(*f).square[1][0];
    (*f).square[1][0]=tmpC;
}

void move_cube(cube *c,MOVES m){
    face tmp;
    init_face(white,&tmp);
    switch(m){
        case Rr:
            tmp.square[0][2]=c->Front.square[0][2];
            tmp.square[1][2]=c->Front.square[1][2];
            tmp.square[2][2]=c->Front.square[2][2];
            c->Front.square[0][2]=c->Up.square[0][2];
            c->Front.square[1][2]=c->Up.square[1][2];
            c->Front.square[2][2]=c->Up.square[2][2];
            c->Up.square[0][2]=c->Back.square[0][2];
            c->Up.square[1][2]=c->Back.square[1][2];
            c->Up.square[2][2]=c->Back.square[2][2];
            c->Back.square[2][2]=c->Down.square[0][0];
            c->Back.square[1][2]=c->Down.square[1][0];
            c->Back.square[0][2]=c->Down.square[2][0];
            c->Down.square[0][0]=tmp.square[2][2];
            c->Down.square[1][0]=tmp.square[1][2];
            c->Down.square[2][0]=tmp.square[0][2];

            reverse_face_reverse(&(c->Right));
            break;
        case R:
            tmp.square[0][2]=c->Front.square[0][2];
            tmp.square[1][2]=c->Front.square[1][2];
            tmp.square[2][2]=c->Front.square[2][2];
            c->Front.square[0][2]=c->Down.square[2][0];
            c->Front.square[1][2]=c->Down.square[1][0];
            c->Front.square[2][2]=c->Down.square[0][0];
            c->Down.square[0][2]=c->Back.square[2][2];
            c->Down.square[1][2]=c->Back.square[1][2];
            c->Down.square[2][2]=c->Back.square[0][2];
            c->Back.square[0][2]=c->Up.square[0][2];
            c->Back.square[1][2]=c->Up.square[1][2];
            c->Back.square[2][2]=c->Up.square[2][2];
            c->Up.square[0][2]=tmp.square[0][2];
            c->Up.square[1][2]=tmp.square[1][2];
            c->Up.square[2][2]=tmp.square[2][2];

            reverse_face_normal(&(c->Right));
            break;
        case Lr:
            tmp.square[0][0]=c->Front.square[0][0];
            tmp.square[1][0]=c->Front.square[1][0];
            tmp.square[2][0]=c->Front.square[2][0];
            c->Front.square[0][0]=c->Down.square[2][2];
            c->Front.square[1][0]=c->Down.square[1][2];
            c->Front.square[2][0]=c->Down.square[0][2];
            c->Down.square[0][2]=c->Back.square[2][0];
            c->Down.square[1][2]=c->Back.square[1][0];
            c->Down.square[2][2]=c->Back.square[0][0];
            c->Back.square[0][0]=c->Up.square[0][0];
            c->Back.square[1][0]=c->Up.square[1][0];
            c->Back.square[2][0]=c->Up.square[2][0];
            c->Up.square[0][0]=tmp.square[0][0];
            c->Up.square[1][0]=tmp.square[1][0];
            c->Up.square[2][0]=tmp.square[2][0];

            reverse_face_reverse(&(c->Left));
            break;
        case L:
            tmp.square[0][0]=c->Front.square[0][0];
            tmp.square[1][0]=c->Front.square[1][0];
            tmp.square[2][0]=c->Front.square[2][0];
            c->Front.square[0][0]=c->Up.square[0][0];
            c->Front.square[1][0]=c->Up.square[1][0];
            c->Front.square[2][0]=c->Up.square[2][0];
            c->Up.square[0][0]=c->Back.square[0][0];
            c->Up.square[1][0]=c->Back.square[1][0];
            c->Up.square[2][0]=c->Back.square[2][0];
            c->Back.square[0][0]=c->Down.square[2][2];
            c->Back.square[1][0]=c->Down.square[1][2];
            c->Back.square[2][0]=c->Down.square[0][2];
            c->Down.square[0][2]=tmp.square[2][0];
            c->Down.square[1][2]=tmp.square[1][0];
            c->Down.square[2][2]=tmp.square[0][0];

            reverse_face_normal(&(c->Left));
            break;
        case U:
            tmp.square[0][0]=c->Front.square[0][0];
            tmp.square[0][1]=c->Front.square[0][1];
            tmp.square[0][2]=c->Front.square[0][2];
            c->Front.square[0][0]=c->Right.square[2][0];
            c->Front.square[0][1]=c->Right.square[1][0];
            c->Front.square[0][2]=c->Right.square[0][0];
            c->Right.square[0][0]=c->Back.square[2][0];
            c->Right.square[1][0]=c->Back.square[2][1];
            c->Right.square[2][0]=c->Back.square[2][2];
            c->Back.square[2][0]=c->Left.square[2][2];
            c->Back.square[2][1]=c->Left.square[1][2];
            c->Back.square[2][2]=c->Left.square[0][2];
            c->Left.square[0][2]=tmp.square[0][0];
            c->Left.square[1][2]=tmp.square[0][1];
            c->Left.square[2][2]=tmp.square[0][2];

            reverse_face_normal(&(c->Up));
            break;
        case Ur:
            tmp.square[0][0]=c->Front.square[0][0];
            tmp.square[0][1]=c->Front.square[0][1];
            tmp.square[0][2]=c->Front.square[0][2];
            c->Front.square[0][0]=c->Left.square[0][2];
            c->Front.square[0][1]=c->Left.square[1][2];
            c->Front.square[0][2]=c->Left.square[2][2];
            c->Left.square[0][2]=c->Back.square[2][2];
            c->Left.square[1][2]=c->Back.square[2][1];
            c->Left.square[2][2]=c->Back.square[2][0];
            c->Back.square[2][0]=c->Right.square[0][0];
            c->Back.square[2][1]=c->Right.square[1][0];
            c->Back.square[2][2]=c->Right.square[2][0];
            c->Right.square[0][0]=tmp.square[0][2];
            c->Right.square[1][0]=tmp.square[0][1];
            c->Right.square[2][0]=tmp.square[0][0];

            reverse_face_reverse(&(c->Up));
            break;
        case Dr:
            tmp.square[2][0]=c->Front.square[2][0];
            tmp.square[2][1]=c->Front.square[2][1];
            tmp.square[2][2]=c->Front.square[2][2];
            c->Front.square[2][0]=c->Right.square[2][2];
            c->Front.square[2][1]=c->Right.square[1][2];
            c->Front.square[2][2]=c->Right.square[0][2];
            c->Right.square[0][2]=c->Back.square[0][0];
            c->Right.square[1][2]=c->Back.square[0][1];
            c->Right.square[2][2]=c->Back.square[0][2];
            c->Back.square[0][0]=c->Left.square[2][0];
            c->Back.square[0][1]=c->Left.square[1][0];
            c->Back.square[0][2]=c->Left.square[0][0];
            c->Left.square[0][0]=tmp.square[2][0];
            c->Left.square[1][0]=tmp.square[2][1];
            c->Left.square[2][0]=tmp.square[2][2];

            reverse_face_reverse(&(c->Down));
            break;
        case D:
            tmp.square[2][0]=c->Front.square[2][0];
            tmp.square[2][1]=c->Front.square[2][1];
            tmp.square[2][2]=c->Front.square[2][2];
            c->Front.square[2][0]=c->Left.square[0][0];
            c->Front.square[2][1]=c->Left.square[1][0];
            c->Front.square[2][2]=c->Left.square[2][0];
            c->Left.square[0][0]=c->Back.square[0][2];
            c->Left.square[1][0]=c->Back.square[0][1];
            c->Left.square[2][0]=c->Back.square[0][0];
            c->Back.square[0][0]=c->Right.square[0][2];
            c->Back.square[0][1]=c->Right.square[1][2];
            c->Back.square[0][2]=c->Right.square[2][2];
            c->Right.square[0][2]=tmp.square[2][2];
            c->Right.square[1][2]=tmp.square[2][1];
            c->Right.square[2][2]=tmp.square[2][0];

            reverse_face_normal(&(c->Down));
            break;
        case Fr:
            tmp.square[2][0]=c->Up.square[2][0];
            tmp.square[2][1]=c->Up.square[2][1];
            tmp.square[2][2]=c->Up.square[2][2];
            c->Up.square[2][0]=c->Right.square[2][0];
            c->Up.square[2][1]=c->Right.square[2][1];
            c->Up.square[2][2]=c->Right.square[2][2];
            c->Right.square[2][0]=c->Down.square[2][0];
            c->Right.square[2][1]=c->Down.square[2][1];
            c->Right.square[2][2]=c->Down.square[2][2];
            c->Down.square[2][0]=c->Left.square[2][0];
            c->Down.square[2][1]=c->Left.square[2][1];
            c->Down.square[2][2]=c->Left.square[2][2];
            c->Left.square[2][0]=tmp.square[2][0];
            c->Left.square[2][1]=tmp.square[2][1];
            c->Left.square[2][2]=tmp.square[2][2];

            reverse_face_reverse(&(c->Front));
            break;
        case F:
            tmp.square[2][0]=c->Up.square[2][0];
            tmp.square[2][1]=c->Up.square[2][1];
            tmp.square[2][2]=c->Up.square[2][2];
            c->Up.square[2][0]=c->Left.square[2][0];
            c->Up.square[2][1]=c->Left.square[2][1];
            c->Up.square[2][2]=c->Left.square[2][2];
            c->Left.square[2][0]=c->Down.square[2][0];
            c->Left.square[2][1]=c->Down.square[2][1];
            c->Left.square[2][2]=c->Down.square[2][2];
            c->Down.square[2][0]=c->Right.square[2][0];
            c->Down.square[2][1]=c->Right.square[2][1];
            c->Down.square[2][2]=c->Right.square[2][2];
            c->Right.square[2][0]=tmp.square[2][0];
            c->Right.square[2][1]=tmp.square[2][1];
            c->Right.square[2][2]=tmp.square[2][2];

            /**same face normal**/
            reverse_face_normal(&(c->Front));
            break;
        case Br:
            tmp.square[0][0]=c->Up.square[0][0];
            tmp.square[0][1]=c->Up.square[0][1];
            tmp.square[0][2]=c->Up.square[0][2];
            c->Up.square[0][0]=c->Left.square[0][0];
            c->Up.square[0][1]=c->Left.square[0][1];
            c->Up.square[0][2]=c->Left.square[0][2];
            c->Left.square[0][0]=c->Down.square[0][0];
            c->Left.square[0][1]=c->Down.square[0][1];
            c->Left.square[0][2]=c->Down.square[0][2];
            c->Down.square[0][0]=c->Right.square[0][0];
            c->Down.square[0][1]=c->Right.square[0][1];
            c->Down.square[0][2]=c->Right.square[0][2];
            c->Right.square[0][0]=tmp.square[0][0];
            c->Right.square[0][1]=tmp.square[0][1];
            c->Right.square[0][2]=tmp.square[0][2];

            reverse_face_reverse(&(c->Back));
            break;
        case B:
            tmp.square[0][0]=c->Up.square[0][0];
            tmp.square[0][1]=c->Up.square[0][1];
            tmp.square[0][2]=c->Up.square[0][2];
            c->Up.square[0][0]=c->Right.square[0][0];
            c->Up.square[0][1]=c->Right.square[0][1];
            c->Up.square[0][2]=c->Right.square[0][2];
            c->Right.square[0][0]=c->Down.square[0][0];
            c->Right.square[0][1]=c->Down.square[0][1];
            c->Right.square[0][2]=c->Down.square[0][2];
            c->Down.square[0][0]=c->Left.square[0][0];
            c->Down.square[0][1]=c->Left.square[0][1];
            c->Down.square[0][2]=c->Left.square[0][2];
            c->Left.square[0][0]=tmp.square[0][0];
            c->Left.square[0][1]=tmp.square[0][1];
            c->Left.square[0][2]=tmp.square[0][2];

            reverse_face_normal(&(c->Back));
            break;
    }
}

MOVES retour_move(int m){
    switch(m){
        case 0: return R;
        case 1: return Rr;
        case 2: return L;
        case 3: return Lr;
        case 4: return U;
        case 5: return Ur;
        case 6: return D;
        case 7: return Dr;
        case 8: return F;
        case 9: return Fr;
        case 10: return B;
        case 11: return Br;
    }
}

MOVES get_inverse(MOVES m){
    switch(m){
        case Rr:
            return R;
        case R:
            return Rr;
        case Lr:
            return L;
        case L:
            return Lr;
        case U:
            return Ur;
        case Ur:
            return U;
        case Dr:
            return D;
        case D:
            return Dr;
        case Fr:
            return F;
        case F:
            return Fr;
        case Br:
            return B;
        case B:
            return Br;
    }
}

void flush_cube(cube *c){
    int N=rand()%50;
    cout << N << endl;
    for(int i=0;i<N;i++){
        move_cube(c,retour_move(rand()%12));
    }
}
int test=0;

bool is_cross(face f){
    return f.square[1][1]==f.square[1][0]
       && f.square[1][1]==f.square[1][2]
       && f.square[1][1]==f.square[0][1]
       && f.square[1][1]==f.square[2][1];
}

bool has_cross(cube c){
    return is_cross(c.Back)
    || is_cross(c.Down)
    || is_cross(c.Front)
    || is_cross(c.Left)
    || is_cross(c.Right)
    || is_cross(c.Up);
}

void prepare_tree_solution(){
    while(!recursive.empty()){
        ARBRE* tmp=recursive.top();
        recursive.pop();
        STATE c=(*tmp).debut;
        if(c.first.second<8){
            for(int i=0;i<12;i++){
                if((*tmp).last==nullptr
                   ||(
                      retour_move(i)!=get_inverse((*((*tmp).last)).debut.second)
                      && !((*((*tmp).last)).last!=nullptr && ((*((*tmp).last)).debut.second==(*((*((*tmp).last)).last)).debut.second ) && (*((*tmp).last)).debut.second==retour_move(i))
                   )
                   ){

                    move_cube(&(c.first.first),retour_move(i));
                    ARBRE r;
                    r.debut=make_pair(make_pair(c.first.first,c.first.second+1),retour_move(i));
                    //printf("test: %d\n",c.first.second);
                    //if(c.first.second==21)
                    //    getchar();
                    r.next.clear();
                    r.last=tmp;
                    (*tmp).next.push_back(&r);
                    recursive.push(&r);
                    if(has_cross(c.first.first)){
                        cout << "HAS CROSS: nb of moves: "<< c.first.second << endl;
                        ARBRE* tmpA=(*tmp).last;
                        cout << "Algo: " << retour_moves((*tmp).debut.second);
                        while(tmpA!=nullptr){
                            if((*tmpA).debut.second!=VIDE)
                            cout << retour_moves((*tmpA).debut.second);
                            tmpA=(*tmpA).last;
                        }
                        getchar();
                    }
                    move_cube(&(c.first.first),get_inverse(retour_move(i)));

                    prepare_tree_solution();
                }
                //else
                //    printf("%d - NOPE\n",++test);
            }
        }
    }

}

void read_tree_solution(){

}

string find_solution(cube c){

}

int main()
{
    srand (time(NULL));
    cube c;
    init_cube(&c);
    flush_cube(&c);
    affiche_cube(c);
    arbre_moves.debut.first.first=c;
    arbre_moves.debut.first.second=0;
    arbre_moves.debut.second=VIDE;
    arbre_moves.next.clear();
    arbre_moves.last=nullptr;
    recursive.push(&arbre_moves);

    prepare_tree_solution();

    return 0;
}
