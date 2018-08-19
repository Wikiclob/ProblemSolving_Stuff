#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
#define MAXSTR (MAX+1)
#define woo while(1)
#define f1(i,n) for(i=0;i<n;i++)
#define f2(i,n) for(i=0;i<=n;i++)
#define psi(s,v) printf(s);scanf("%d",&v);
#define pss(s,v) fflush(stdin);printf(s);scanf("%[^\n]s",v);
#define psf(s,v) printf(s);scanf("%f",&v);
#define DUMPINT(varname) fprintf(stderr, "%s = %i\n", #varname, varname);
#define DUMPSTR(varname) fprintf(stderr, "%s = %s\n", #varname, varname);
#define DUMPFLOAT(varname) fprintf(stderr, "%s = %f\n", #varname, varname);
#define DUMPCHAR(varname) fprintf(stderr, "%s = %c\n", #varname, varname);

typedef int boolean;

typedef struct Matiere{
    char nom[MAXSTR];
    float note;
    float coefficient;
} Matiere;

typedef struct Etudiant{
    char nom[MAXSTR];
    float moyenne;
    char cin[MAXSTR];
    int age;
} Etudiant;

int longueurChaine(char * T){
    if(*T != '\0') return 1+longueurChaine(T+1);
}

void test(){
    int a;
    printf("adresse p: %p\n",&a);
    printf("adresse x: %x\n",&a);
    printf("adresse d: %d\n",&a);
}

void calcul(int a, int b, int* T){
    *T = a+b;
    if(b){
        *(T+1) = a/b;
        *(T+2) = a%b;
    }
    *(T+3) = a*b;

    *(T+4) = a-b;
}

void testMemoryScan(){
    int a;
    printf("%p\n",&a);
    printf("%x\n",&a);
    while(1){
        scanf("%d",&a);
    }
}

void ex1(){
    int a,b,somme,div,mul,rest,sus;
    int* T = NULL;
    T = malloc(sizeof(int)*5);

    scanf("%d%d",&a,&b);
    calcul(a,b,T);
    printf("%d + %d = %d\n",a,b,*T);
    printf("%d / %d = %d\n",a,b,*(T+1));
    printf("%d %c %d = %d\n",a,'%',b,*(T+2));
    printf("%d * %d = %d\n",a,b,*(T+3));
    printf("%d - %d = %d\n",a,b,*(T+4));

    free(T);
}

void exStructTest(){
    Matiere T[MAX];
    int n,i;
    float moy=0.0f,coeff=0.0f;
    while(1){
        psi("saisir nombre matieres: ",n);
        if(n) break;
    }
    f1(i,n){
        fflush(stdin);
        pss("saisir matiere: ",T[i].nom);
        psf("saisir coefficient: ",T[i].coefficient);
        psf("saisir note: ",T[i].note);
        moy+= T[i].note * T[i].coefficient;
        coeff += T[i].coefficient;
    }
    printf("la moyenne est: %.2f\n",((coeff)?moy/coeff:0.0f));
}

void exMalloc(){
    int i,n=0,choix;
    Etudiant* students = (Etudiant*)malloc(sizeof(Etudiant));
    woo{
        system("cls");
        woo{
            printf("------- MENU -------\n");
            printf("1- ajouter un etudiant\n");
            printf("2- supprimer un etudiant\n");
            printf("3- afficher liste des etudiants\n");
            printf("4- quitter\n");
            psi("choix: ",choix);
            system("cls");
            if(choix && choix<5)
                break;
        }
        if(choix==4)
            break;
        switch(choix){
        case 1:
            if(sizeof(students)<n+1)
                students = (Etudiant*)realloc(students,2*sizeof(students));
            pss("saisir nom: ",students[n].nom);
            while(strlen(students[n].cin)!=8){
                pss("saisir cin: ",students[n].cin);
            }
            psi("saisir age: ",students[n].age);
            psf("saisir moyenne: ",students[n].moyenne);
            n++;
            break;
        case 2:
            if(n){
                woo{
                    f1(i,n){
                        printf("%d - %s\n",i+1,students[i].nom);
                    }
                    printf("%d pour quitter\n",n+1);
                    psi("choix: ",choix);
                    if(choix && choix<=n+1)
                        break;
                }
                if(choix == n+1)
                    break;
                for(i=choix+1;i<n;i++)
                    students[i-1] = students[i];
                if(n-1<(sizeof(students)/2))
                    students = (Etudiant*) realloc(students,sizeof(students)/2);
                n--;
            }
            else{
                fflush(stdin);
                printf("pas d'etudiant dans la liste.\n");
                printf("appuyer sur une touche pour continuer...");
                getchar();
            }
            break;
        case 3:
            f1(i,n){
                printf("%d - %s\n",i+1,students[i].nom);
            }
            fflush(stdin);
            printf("appuyer sur une touche pour continuer...");
            getchar();
            break;
        }
    }
}

void exLongueur(){
    char *T =(char*) malloc(sizeof(char)*MAXSTR);
    pss("donnez une chaine de charactere: ",T);
    printf("la taille est: %d\n",longueurChaine(T));
    free(T);
}

boolean palindrome(char *T){
    int i;
    for(i=0;i<strlen(T)/2;i++)
        if(*(T+i)!=*(T+strlen(T)-i-1))
            return FALSE;
    return TRUE;
}

void ex14(){
    int i,n;
    char *A = (char*) malloc(sizeof(char)*MAXSTR);
    char *B = (char*) malloc(sizeof(char)*MAXSTR);
    pss("saisir A: ",A);
    pss("saisir B: ",B);
    n = strlen(B);
    for(i=n;i<=strlen(A)+n;i++){
        *(B+i) = *(A+i-n);
    }
    //*(B+n+strlen(A))= '\0';
    printf("la chaine concat est: %s\n",B);
    free(A);
    free(B);
}

char * initString(int size){
    return (char*) malloc(sizeof(char)*size);
}

void ex15(){
    char *T = (char*) malloc(sizeof(char)*MAXSTR);
    pss("saisir chaine: ",T);
    printf("la chaine %s un palindrome\n",(palindrome(T)?"est":"n'est pas"));
    free(T);
}

boolean isSubstr(char* A,char* B){
    int i,whereFound;
    int count = 0;
    boolean foundFirst = FALSE;
    boolean foundSecond = FALSE;

    for(i=0;i<strlen(A);i++){
        //DUMPINT(i);
        if(*(A+i) == *(B+count)){
            if(!foundFirst){
                foundFirst=TRUE;
            }
            else{
                if(!foundSecond){
                    foundSecond=TRUE;
                    whereFound = i;
                }
            }
            count++;
        }
        else{
            count=0;
            if(foundSecond){
                i=whereFound+1;
                count = 1;
                foundSecond = FALSE;
            }
            else{
                foundFirst = foundSecond = FALSE;
            }
        }
        //DUMPINT(foundFirst);
        //DUMPINT(foundSecond);
        //DUMPINT(count);
        if(count == strlen(B))
            return TRUE;
    }
    return FALSE;
}

void ex16(){
    char *A = initString(MAXSTR);
    char *B = initString(MAXSTR);
    pss("saisir str: ",A);
    pss("saisir substr: ",B);
    printf("'%s' %s un substr de '%s'\n",B,(isSubstr(A,B)?"est":"n'est pas"),A);

}
