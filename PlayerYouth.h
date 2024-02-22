#ifndef _YOUTH_
#define _YOUTH_

#include "PlayerBase.h"
#include <vector>
#include <string>
#include <cstdlib>  // Add this for 'srand' and 'rand'
#include <ctime>    // Add this for 'time'
#include <iostream> // Add this for 'cout' and 'cin'

using namespace std; // Add this to avoid unresolved 'cout' and 'cin'

template <typename T>
class PlayerYouth : public PlayerBase<T>
{
private:
    int age;

public:
    PlayerYouth();
    PlayerYouth(std::string _name, int _age);
    //PlayerYouth(const PlayerYouth &p);

    void SetAge(int _age);

    void AddOneCard();
    void AddAttackCards(int cards);

    PlayerYouth<T> &operator=(const PlayerYouth<T> &p);

    ~PlayerYouth(){};
};

template <typename T>
PlayerYouth<T>::PlayerYouth()
{
    SetAge();
}

template <typename T>
PlayerYouth<T>::PlayerYouth(std::string _name, int _age)
{
    // Set the name and age using the base class constructor
    this->SetName(_name);
    this->SetAge(_age);
}

template <typename T>
void PlayerYouth<T>::SetAge(int _age)
{
    if (_age < 4)
    {
        _age = 4;
    }
    else if (_age > 18)
    {
        _age = 18;
    }

    // Set the age member
    this->age = _age;
}

template <typename T>
void PlayerYouth<T>::AddOneCard()
{
 
    T x = static_cast<T>(rand() % (age / 2 + 1));
    PlayerBase<T>::attackCards.push_back(x);
}

template <typename T>
void PlayerYouth<T>::AddAttackCards(int cards)
{
    PlayerBase<T>::attackCards.clear();
    
    for (int i = 0; i < cards; i++)
    {
        T x = static_cast<T>(rand() % (age / 2 + 1));
        PlayerBase<T>::attackCards.push_back(x);
    }

    cout<<"The attack cards are"<<endl;
    for(int hasan : PlayerBase<T>::attackCards){
        cout<<hasan<<endl;
    }
}

template <typename T>
PlayerYouth<T> &PlayerYouth<T>::operator=(const PlayerYouth<T> &p)
{
    if (this != &p)
    {
        PlayerBase<T>::cash = p.cash;
        this->name = p.name;
        this->age = p.age;                 // Copy age member
        this->attackCards = p.attackCards; // Copy attackCards vector
    }
    return *this;
}



#endif