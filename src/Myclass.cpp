#include <iostream>
#include <math.h>
#include "../include/Myclass.h"

Myclass::Myclass()
{
    maxx = 80;
    maxy = 25;
    buffer = new char [maxx*maxy] {0};
    BufInit(' ');
    BufDraw();
}

Myclass::Myclass(const int &maxx,const int &maxy)
{
    this->maxx = maxx;
    this->maxy = maxy;
    
    buffer = new char [maxx*maxy] {0};
    BufInit(' ');
    BufDraw();
}

Myclass::~Myclass()
{
    delete [] buffer;
}

void Myclass::BufInit(const char &ch)
{
    for (int y=0; y<maxy ; y++)
    {
        for(int x=0; x<maxx ; x++)
            buffer[x+maxx*y]=ch ;
    }    
}

void Myclass::BufDraw()
{
    std::cout << "\x1B[H";          // revient en haut a gauche uniquement
    for (int y=0; y<maxy ; y++)
    {
        for(int x=0; x<maxx ; x++)
            std::cout << buffer[x+maxx*y];
        std::cout << std::endl;
    }    
}

void Myclass::Loop(unsigned long nbr)
{
    for (unsigned long i=0;i<nbr;i++)
    {
        DrawRect(10,10,50,50,'*');
        DrawRectFill(60,10,80,50,'*');
        DrawCircle(110,25,25);
        DrawPixel(254,79);
        DrawLine(0,0,100,10,'+');
        BufDraw();
    }
}

void Myclass::DrawRect(int x1, int y1, int x2, int y2,char caracter)
{
    if (x1>=0 & x1<maxx & y1>=0 & y1<maxy & x2>=0 & x2<maxx & y2>=0 & y2<maxy )
    {
        for(int x=x1;x<=x2;x++) 
    {
        DrawPixel(x,y1);
        DrawPixel(x,y2);
    }
    for(int y=y1;y<=y2;y++)
    {
        DrawPixel(x1,y);
        DrawPixel(x2,y);
    }
    }
}

void Myclass::DrawRectFill(int x1, int y1, int x2, int y2,char caracter)
{
    if (x1>=0 & x1<maxx & y1>=0 & y1<maxy & x2>=0 & x2<maxx & y2>=0 & y2<maxy )
    {
        for(int x=x1;x<=x2;x++) 
            for(int y=y1;y<=y2;y++)
            {
                DrawPixel(x,y);
            }
    }
    
}

void Myclass::DrawCircle(int x, int y, int radius)
{
    int _y;
    int _x;
    float angle;
    for (int i=0;i<2400;i++)
    {
        angle = (float)i/100*M_1_PI;
        _y =(int)(float)radius*sin(angle); 
        _x =(int)(float)radius*2*cos(angle);
        DrawPixel(x+_x,y+_y);
    }
}

void Myclass::DrawPixel(int x,int y, char caracter)
{
    if (x<maxx & x>=0 & y<maxy & y>=0) buffer[x+y*maxx]=caracter;           
}

void Myclass::DrawLine(int x0,int y0,int x1,int y1,char caracter)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0)
    {
        yi--;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = y0;

    for (int x=x0;x<x1;x++)
        {
            DrawPixel(x, y,'+');
            if (D > 0)
            {
                y = y + yi;
                D = D + (2 * (dy - dx));
            }
            else
            {
                D = D + 2*dy;
            }
        }
}


void Myclass::toto() const
{
    tata++;
}

int Myclass::objstat(12);       // initialisation d'un attribut static

void Myclass::SetStat(int _objstat)
{
    objstat = _objstat; // this ne peut pas etre utilise puisqu'il ny a pas de contexte d'objet.
}

void Myclass::GetStat()
{
    std::cout << "Stat = " << objstat << std::endl;
}

int Myclass::GetStatPub()
{
    return 1;
}

factory *factory::create()
{
    return new factory;
}

// singleton
singleton singleton::leSeulEtLUnique;

singleton *singleton::create()
{
    return &leSeulEtLUnique;
}

void singleton::rien()
{
    std::cout << this << std::endl;
}

void amie::fonction_amie(Myclass &ptr)
{
    ptr.maxx;           // PEUT ACCEDER A UN ATTRIBUT D'UNE AUTRE CLASSE CAR AMI
}

SegmentDeDroite::SegmentDeDroite(int x1,int y1,int x2,int y2):second(x2,y2),premier(x1,y1)
{
    
}