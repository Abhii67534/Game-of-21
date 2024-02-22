#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <random>

using namespace std;

template <typename T>
class PlayerBase
{
protected:
    string name;
    int cash;
    vector<int> depCards;
    vector<T> attackCards;

public:
    PlayerBase();
    PlayerBase(string _name);
    PlayerBase(const PlayerBase &p);

    void SetName(string _name);
    string GetName();

    void AddDependentCards(int cards);
    void AddOneDependentCard();
    int SumDependentCards();
    bool SetDepCards();

    void SetCash(int _cash);
    int GetCash();
    void AddCash(int _cash);

    T SumAttackCards();
    T SumCards();
    virtual void AddOneCard(){};
    virtual void AddAttackCards(int cards){};
    virtual ~PlayerBase();

    PlayerBase<T> &operator=(const PlayerBase<T> &p);
    bool operator==(const PlayerBase<T> &p);
    bool operator<(const PlayerBase<T> &p);
    bool operator>(const PlayerBase<T> &p);

    void operator>>(double amount);
    void operator<<(double amount);
};

template <typename T>
PlayerBase<T>::~PlayerBase()
{
}

template <typename T>
bool PlayerBase<T>::operator==(const PlayerBase<T> &p)
{
    return this->SumCards() == p.SumCards();
}

template <typename T>
bool PlayerBase<T>::operator<(const PlayerBase<T> &p)
{
    return this->SumCards() < p.SumCards();
}

template <typename T>
bool PlayerBase<T>::operator>(const PlayerBase<T> &p)
{
    return this->SumCards() > p.SumCards();
}

template <typename T>
void PlayerBase<T>::operator>>(double amount)
{
    this->cash -= static_cast<int>(amount);
}

template <typename T>
void PlayerBase<T>::operator<<(double amount)
{
    this->cash += static_cast<int>(amount);
}

template <typename T>
T PlayerBase<T>::SumAttackCards()
{
    return accumulate(attackCards.begin(), attackCards.end(), static_cast<T>(0));
}

template <typename T>
T PlayerBase<T>::SumCards()
{
    T num1 = accumulate(attackCards.begin(), attackCards.end(), static_cast<T>(0));
    T num2 = accumulate(depCards.begin(), depCards.end(), static_cast<int>(0));
    return num1 - num2;
}

template <typename T>
void PlayerBase<T>::AddOneDependentCard()
{

    int x = (rand() % 5) + 1;
    depCards.push_back(x);
}

template <typename T>
PlayerBase<T>::PlayerBase()
{
    name = "";
    cash = 1000;
}

template <typename T>
PlayerBase<T>::PlayerBase(string _name)
{
    name = _name;
    cash = 1000;
}

template <typename T>
PlayerBase<T>::PlayerBase(const PlayerBase &p)
{
    name = p.name;
    copy(p.depCards.begin(), p.depCards.end(), back_inserter(depCards));
    cash = p.cash;
}

template <typename T>
void PlayerBase<T>::SetName(string _name)
{
    name = _name;
}

template <typename T>
string PlayerBase<T>::GetName()
{
    return name;
}

template <typename T>
void PlayerBase<T>::AddDependentCards(int cards)
{
    depCards.clear();

    cout << "The dependent cards are" << endl;
    for (int i = 0; i < cards; i++)
    {
        
        int x = (rand() % 5) + 1;
        depCards.push_back(x);
    }
   
}

template <typename T>
int PlayerBase<T>::SumDependentCards()
{
    return accumulate(depCards.begin(), depCards.end(), static_cast<int>(0));
}

template <typename T>
bool PlayerBase<T>::SetDepCards()
{
    return !depCards.empty();
}

template <typename T>
void PlayerBase<T>::SetCash(int _cash)
{
    cash = _cash;
}

template <typename T>
int PlayerBase<T>::GetCash()
{
    return cash;
}

template <typename T>
void PlayerBase<T>::AddCash(int _cash)
{
    cash += _cash;
}

#endif