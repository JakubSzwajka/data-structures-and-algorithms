#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Kontener
{

public:
    Kontener(int size_=200);
    Kontener(T znak, int size_);
    // konstruktor kopiujący
    Kontener(const Kontener &other);

    // standard 11 "noexcept"--> 
    virtual ~Kontener() /* noexcept */;
    Kontener& operator=(const Kontener &other);
    
    int size()const{return size_;}

    // przeciazony operator tablicowy MUSI BYC PRZECIAZONY WKLASIE
    T &operator[](int i)
    {
        return tablica_[i];
    }
    T &operator[](int i) const
    {
        return tablica_[i];
    }

private:
    int size_;
    T *tablica_;
};

template <typename T>
Kontener<T>::Kontener(int size)
{
    size_ = size;
    tablica_ = new T[size];
}
template <typename T>
Kontener<T>::Kontener(T znak, int size)
{
    size_ = size;
    tablica_ = new T[size_];
    for (int i = 0; i < size_; i++)
    {
        tablica_[i] = znak;
    }
}
// dekonstruktor
template <typename T>
Kontener<T>::~Kontener()
{
    delete[] tablica_;
}
// konstruktor kopiujący ! wskaźnik powinien wskazywać na nową tablice
template <typename T>
Kontener<T>::Kontener(const Kontener<T> &other)
{
    size_ = other.size_;
    tablica_ = new T[size_];

    for (int i = 0; i < size_; i++)
    {
        tablica_[i] = other.tablica_[i];
    }
}
// operator =
template <typename T>
Kontener<T> &Kontener<T>::operator=(const Kontener &other)
{
    if (this != &other)
    {
        delete[] tablica_;
        size_ = other.size_;
        tablica_ = new T[size_];

        for (int i = 0; i < size_; i++)
            tablica_[i] = other.tablica_[i];
    }

    return *this;
}
template <typename T>
ostream& operator << (ostream & exit ,const Kontener<T> &print)
{
    for(int i = 0 ; i < print.size() ; i ++)
    {
        cout << print[i] << " " ;
    }
    return cout;
}
