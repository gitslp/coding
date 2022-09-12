#include <iostream>
#include "../include/Myclass.h"
#include "../include/cout.h"

int main (int argc, char ** argv)
{
    //Myclass window(125,80);     // 254,80 en taille de police 12  
    Myclass test(12);
    factory *pa = factory::create();
    singleton *single1 = singleton::create();
    singleton *single2 = singleton::create();   // single1 et single2 sont la meme instance
    single1->rien();
    single2->rien();
 
    //SegmentDeDroite droite(1,2);

    test.SetStat(13);
    test.GetStat();
    B b(1,2);
    //Myclass::objstatpub=20;
    test.GetStat();
    Myclass::GetStatPub();      // fonction statique pas besoin d'objet pour etre appellee


    std::cout << "coucoue" << std::endl;
    //std::cout << "\x1B[2J\x1B[H";
   
    //window.Loop(1000);



    
    return EXIT_SUCCESS;  
}
