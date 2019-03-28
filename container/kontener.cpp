#include "kontener.hpp"

Kontener::Kontener(int size)
{
    size_ = size;
    tablica_ = new char[size];
}

Kontener::Kontener(char znak, int size)
{
    size_ = size;
    tablica_= new char[size_];
    for(int i=0; i < size_; i++)
    {
        tablica_[i] = znak;
    }
}
// dekonstruktor
Kontener::~Kontener()
{
    delete [] tablica_;
}
// konstruktor kopiujący ! wskaźnik powinien wskazywać na nową tablice 
Kontener::Kontener(const Kontener &other)
{
    size_ = other.size_;
    tablica_= new char [size_];

    for(int i=0; i < size_;i++)
    {
        tablica_[i] = other.tablica_[i];
    }
}
// operator =
Kontener& Kontener:: operator=(const Kontener &other)
{
    if(this != &other)
    {
        delete [] tablica_;
        size_ = other.size_;
        tablica_=new char [size_];

        for(int i=0 ; i < size_; i++)
            tablica_[i] = other.tablica_[i];
    }

    return *this;
}
