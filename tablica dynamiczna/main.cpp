#include <iostream>
#include <string>
#include "duza_liczba.hpp"

using namespace std; 

int main()
{

    Duza_liczba A("543");
    Duza_liczba B(1); 
    Duza_liczba C(32);

    //B.print();

    C = A ;

    C.print();




    return 0;
}