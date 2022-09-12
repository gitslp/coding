#ifndef MYCLASS_H

#define MYCLASS_H
#include <iostream>

class Myclass;                  // delcaration anticipie sinon c'est le serpent qui se mord la queue...

class amie
{
    private:
    public:
    void fonction_amie(Myclass &);
};


class Myclass
{
    private:
    static int objstat;
    static const int objstat2=5;
    int maxx;
    int maxy;
    char *buffer=NULL;              // Toujours mettre NULL !!!!!
    const int numnational=0;
    mutable int tata;
    volatile int juju;
    //Myclass();                      // on definit un constructeur private sans arg pour interdire 
                                    // toute instanciation de la classe.

    public:
    static int objstatpub;          // peut etre utilise de n'importe sans objet 
    Myclass();
    Myclass(const int&,const int&);
    Myclass(int id) : numnational(id){std::cout << "coucou" << std::endl;};
    ~Myclass();
    void BufDraw();
    void Loop(unsigned long);
    void BufInit(const char&); 
    void DrawPixel(int,int,char='+');
    void DrawLine (int,int,int,int,char='+');
    void DrawRect(int,int,int,int,char='+');
    void DrawRectFill(int,int,int,int,char='+');
    void DrawCircle(int,int,int);
    void toto() const;
    void SetValeur(int _maxx) { maxx = _maxx;}          // =
    void SetValeur2(int maxx)  { this->maxx = maxx;}    // =
    void SetValeur3(int maxx)  { (*this).maxx = maxx;}  // =
    // est parfois utile pour inserer un objet lui meme dans une liste...
    void SetStat(int);
    void GetStat();
    static int GetStatPub();

    friend void amie::fonction_amie(Myclass &);       // fonction_amie uniquement et pas toutes les fonction de la classe grain fin
    //friend class amie;                   class amie dans son entier gros grain
                                        // C'EST L'UN OU L'AUTRE !
                                        // le domaine de protection n'a aucune importance
                                        // la declaration de la classe amie doit se faire AVANT la classe accedee


};

class factory
{
    private:
        factory() {};
    public:
    static factory *create();
};

class singleton
{
    private:
        singleton() {};
        static singleton leSeulEtLUnique;
    public:
        static singleton *create();
        void rien();
};

class Point {
    private:
        int abscisse, ordonee;
        
    public:
        Point(int x=0, int y=0) {
            abscisse = x;
            ordonee = y;
        }
};

class SegmentDeDroite {
    private:
        Point premier, second;
    public:
        SegmentDeDroite(int , int, int,int );
};
//---------------------- COMPOSITION -----------------------
class A{
    private:
        int valeur;
    public:
    A(int x) { valeur = x; }
    ~A() { std::cout << "destruction de A:" << valeur << std::endl;}
};

class B{
    private:
    A un;
    A deux;       
    public:
    // il faut initialiser les composant avant le compose !
        B(int x,int y) : un(x),deux(y) {};  // un sera initialise avant deux pour suivre
        // le meme ordre que la definition ! Car c'est elle qui compte
        ~B() { std::cout << " destruction de B" << std::endl;}

};

// int main() {
//  B b(1,2);
//}
//---L'objet B contient deux objets A---------------------------


#endif