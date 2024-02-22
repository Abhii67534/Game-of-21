#ifndef _CARD_GAME_H
#define _CARD_GAME_H

#include "PlayerBase.h"
#include "PlayerYouth.h"
#include "PlayerAdult.h"
#define NUM 2
#define MAX 21

enum GameMode
{
    LowDefinition,
    HighDefinition,
    Quit,
};

template <typename T>
class CardGame
{
private:
    GameMode mode;
    int bet;
    PlayerBase<T> *player[NUM];

public:
    CardGame(GameMode mode);
    ~CardGame();
    void run();
};

template <typename T>
CardGame<T>::CardGame(GameMode _mode)
{
    if (_mode == GameMode::LowDefinition)
    {
        player[0] = new PlayerYouth<T>("Noah", 10); // Provide an appropriate age (e.g., 10) for youth
        player[1] = new PlayerAdult<T>("Kenneth");
    }
    else if (_mode == GameMode::HighDefinition)
    {
        player[0] = new PlayerYouth<T>("Noah", 16); // Provide an appropriate age (e.g., 16) for youth
        player[1] = new PlayerAdult<T>("Kenneth");
    }
}

template <typename T>
CardGame<T>::~CardGame()
{
    delete player[0];
    delete player[1];
}

template <typename T>
void CardGame<T>::run()
{

    int depcards;
    int attcards;
   // int age;
    int bet;
    char answer;
   

    do
    {
        cout << "How much you both want to bet?(min $10 , max $300)" << endl;
        cin >> bet;
        do
        {
            if (bet < 10 || bet > 300)
            {
                cout << "Please enter a valid number(min $10 , max $300)" << endl;
                cin >> bet;
            }
        } while (bet < 10 || bet > 300);

        for (int i = 0; i < NUM; i++)
        {
            // dependent cards
            cout << player[i]->GetName() << ", how many dependent cards you want?" << endl;
            cin >> depcards;
            player[i]->AddDependentCards(depcards);

            // attack cards
            cout << player[i]->GetName() << "How many attack cards you want?" << endl;
            cin >> attcards;
            player[i]->AddAttackCards(attcards);

            // sum of cards
            cout << "The sum of your cards is " << player[i]->SumCards();

            // ask to add more dependent cards
            do
            {
                cout << "Do you want to add a dependent card? [Y,N]";
                cin >> answer;
                if (answer == 'Y' || answer == 'y')
                {
                    player[i]->AddOneDependentCard();
                }
                else if (answer == 'N' || answer == 'n')
                {
                    break;
                }
                else
                {
                    cout << "Please enter a valid response" << endl;
                }
            } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

            // sum of cards
            cout << player[i]->GetName() << " ,the sumof your cards is" << player[i]->SumCards() << endl;

            // ask if player wants to add attack cards
            do
            {
            cout << "Do you want to add an attack card?[Y,N]";
            cin >> answer;
            if (answer == 'Y' || answer == 'y')
            {
                player[i]->AddOneCard();
            }
            else if (answer == 'N' || answer == 'n')
            {
                cout << "ok";
            }
            else
            {
                cout << "Please add a valid input" << endl;
            }
            } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

            // sum of cards
            cout << player[i]->GetName() << " ,the sumof your cards is" << player[i]->SumCards() << endl;

            // Report the name and points for each player
            for (int i = 0; i < NUM; i++)
            {
                cout << player[i]->GetName() << " has " << player[i]->SumCards() << " points" << endl;
            }
            cout << endl;
        }

        // DETERMINE WINNER

        if (player[0]->SumCards() > MAX && player[1]->SumCards() > MAX)
        {
            cout << "Both Player are over the limit and have been disqualified" << endl;
        }

        // for (int i = 0; i < NUM; i++)
        // {
        //     if (player[i]->SumCards() > MAX)
        //     {
        //         cout << player[i]->GetName() << " ,with " << player[i]->SumCards() << " , has been disqualified" << endl;
        //     }
        // }

        if (player[0]->SumCards() > MAX)
        {
            cout << player[0]->GetName() << " has been disqualified ," << player[1]->GetName() << " has won" << endl;
            *player[0] >> bet;
            *player[1] << bet;
        }
        if (player[1]->SumCards() > MAX)
        {
            cout << player[1]->GetName() << " has been disqualified ," << player[0]->GetName() << " has won" << endl;
            *player[0] >> bet;
            *player[1] << bet;
        }

        for (int i = 0; i < NUM; i++)
        {
            cout << player[i]->GetName() << " has $ " << player[i]->GetCash() << endl;
        }

    } while (player[0]->GetCash() > 0 && player[1]->GetCash() > 0);
}

#endif