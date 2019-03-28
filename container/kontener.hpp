#include <iostream>
#include <string>

using namespace std;

class Kontener
{

public:
    Kontener(int size_=200);
    Kontener(char znak, int size_);
    // konstruktor kopiujący
    Kontener(const Kontener &other);

    // standard 11 "noexcept"--> 
    virtual ~Kontener() noexcept;
    Kontener& operator=(const Kontener &other);

    int size()const{return size_;}

    // przeciazony operator tablicowy MUSI BYC PRZECIAZONY WKLASIE
    char & operator[](int i){
        return tablica_[i];
    }
    char & operator[](int i) const{
        return tablica_[i];
    }

private:
    int size_;
    char *tablica_;
};

