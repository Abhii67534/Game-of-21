#ifndef _PLAYER_ADULT_
#define _PLAYER_ADULT_
#include "PlayerBase.h"

template <typename T>

class PlayerAdult : public PlayerBase<T>
{
    

public:
    PlayerAdult();
    PlayerAdult(string _name);
    PlayerAdult(const PlayerAdult &p);

    PlayerAdult operator=(PlayerAdult &p);

    void AddOneCard();
    void AddAttackCards(int cards);

    ~PlayerAdult();
};

// template<typename T>
// void PlayerAdult<T>::SetName(string _name){
//     name = _name;
// }

// template<typename T>
// string PlayerAdult<T>::GetName(){
//     return name;
// }

template <typename T>
PlayerAdult<T>::PlayerAdult()
{
   PlayerBase<T>::name = "";
    PlayerBase<T>::attackCards.clear();
}

template <typename T>
PlayerAdult<T>::PlayerAdult(string _name)
{
    PlayerBase<T>::name = _name;
    PlayerBase<T>::attackCards.clear();
}

template <typename T>
PlayerAdult<T>::PlayerAdult(const PlayerAdult &p)
{
   PlayerBase<T>::name = p.name;
    copy(p.attackCards.begin(), p.attackCards.end(), this->attackCards.begin());
}

template <typename T>
PlayerAdult<T> PlayerAdult<T>::operator=(PlayerAdult &p)
{
    PlayerBase<T>::name = p.name;
    copy(p.attackCards.begin(), p.attackCards.end(), this->attackCards.begin());

    return p;
}

template <typename T>
void PlayerAdult<T>::AddAttackCards(int cards)
{
   PlayerBase<T>:: attackCards.clear();

    for (int i = 0; i < cards; i++)
    {
        
        T x = static_cast<T>(rand() % (15) + 1);
       PlayerBase<T>:: attackCards.push_back(x);
    }
  
    
}

template <typename T>
void PlayerAdult<T>::AddOneCard()
{
    
    T x = static_cast<T>(rand() % (15) + 1);
   PlayerBase<T>:: attackCards.push_back(x);
}

template <typename T>
PlayerAdult<T>::~PlayerAdult()
{

}

#endif