// PlayerMain.cpp - main program for the card player
// clang++ -std=c++20 PlayerMain.cpp -o main

#include "CardGame.h"

int main()
{
    srand((time(nullptr)));
    char choice;
    cout << "How you want to play the game" << endl;
    cout << "L --Low Definition\n"
         << "H--High Definition\n"
         << "Q--Quit the game" << endl;
    cin >> choice;

    if (choice == 'L')
    {
        CardGame<int> cGame1(GameMode::LowDefinition);
        cGame1.run();
    }
    else if (choice == 'H')
    {
        CardGame<double> cGame2(GameMode::HighDefinition);
        cGame2.run();
    }
    else if (choice == 'Q')
    {
        cout << "Thankyou for playing" << endl;
    }

    else{
        cout<<"Please enter a valid input"<<endl;
    }
  
   

    return 0;
}