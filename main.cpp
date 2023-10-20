#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

unsigned int find2(const  int & val,const vector< int> & tab){
    unsigned int i=0;
    while( i < tab.size() && tab[i] !=  val){
        i=i+1;
    }
    return i;
}

vector< int> generer(vector< int> tab,const unsigned int & m,const unsigned int & taille){
    tab.resize(taille);
    for(unsigned int i=0 ; i < taille-1 ; i=i+1){
        unsigned int n=rand()%m+1;
        while( find2(n,tab) != taille ){
             n=rand()%m+1;
        }
        tab[i]=n;
    }
    return tab;
}

vector< int> genereTabInt(const unsigned int & n,const unsigned int & m,vector< int> tab){
    tab.resize(n);
    int v;
    for(unsigned int i=0 ; i < n-1 ; i=i+1 ){
        v=rand()%m+1;
        if(find2(v,tab) == n){
             tab[i]=v;
        }
    }
    return tab;
}
void affiche(vector< int> tableau){
    for(size_t i=0 ; i < tableau.size() ;i=i+1 ){
        cout << tableau[i] << " " ;
    }
}
unsigned int trouvercaractere(const char & carc,const string & chaine,const unsigned int & debut){
    unsigned int i=debut;
    for( ; i < chaine.size();i=i+1 ){
        if(chaine[i] == carc){
             return i ;
        }
    }
    return i ;
}
unsigned int compteur(const char & carc,const string & chaine){
    unsigned int comp=0;
    for( unsigned int i=0; i < chaine.size();i=i+1 ){
        if(chaine[i] == carc){
             comp=comp+1;
        }
    }
    return comp ;
}
bool isupper(const char & car){
    if(toupper(car) == car){
        return true;
    }else{
        return false;
    }
}
void test(){
    assert(isupper('A'));
    cout << "tout va bien" <<endl;
}
string cryptage( string  mot){
    char crypter;
    string nouveau;
    crypter=++mot[0];
    nouveau=crypter;
    for(unsigned int i=1 ; i< mot.size();++i){
        crypter=++mot[i];
        nouveau=nouveau + crypter;
    }
    return nouveau;
}

string dessin(string trait,unsigned int taille){
    for(unsigned int n=0;n < taille ; ++n){
        trait[n]='#';
    }
    return trait;
}
vector<int> joueur( vector<int> tabl){
   ;
    for(size_t i=0;i< tabl.size();++i){
        cout << "saisir le nombre pour ton " << i << " pion" << endl;
        cin >> tabl[i];
    }
    return tabl;
}
vector<int> pion(const vector<int> & tab,const vector<int> & combi){
    vector<int> nv (4);
    for(size_t i=0;i< tab.size();++i){
        if(tab[i] == combi[i]){
             nv[i]=1;
        }else if(find2(tab[i],combi) != tab.size()){
             nv[i]=2;
        }else{
             nv[i]=0;
        }
    }
    return nv;
}
vector<int> ordi( vector<int> tabl){
    ;
    for(size_t  i=0;i< tabl.size();++i){
        tabl[i]=rand()%6+0;
    }
    return tabl;
}


int main()
{
    cout << "Hello World!" << endl;
    vector<int> combinaison {1, 3, 4, 5};
    unsigned int compteur=0;
    vector<int> gagner {1,1,1,1};
    vector<int> tab(4);
    tab=joueur(tab);
    for(;;){
    vector<int> nv= pion(tab,combinaison);
    affiche(nv);
    cout << endl;
    compteur=compteur+1;
    if(compteur == 12 || nv == gagner ) break;
    cout << "resaisir une autre combinaison" << endl;
    tab=joueur(tab);
    affiche(tab);
    cout << endl;
    }
    cout << "bien joue !" << endl;

    return 0;
}
