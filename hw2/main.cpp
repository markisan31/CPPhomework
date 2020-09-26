#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <fstream>
#include <ctime>

using namespace std;
static int dollar_spent = 0;

string give_hint(int user_digit_answer, int random_number){
    string hint;
    dollar_spent += 2;
    
    cout << "You gave $2.00 for hint" << endl;
    
    if (user_digit_answer < random_number){
        hint = "You number is too low";
    } else {
        hint = "You number is too high";
    }
    return hint;
}

void guess_process(int random_number){
    bool game_in_progress = true;
    cout << "Welcome to Guess game. You must guess the number in range 0 to 100 000 to win $1 000 000. Good luck!" << endl;
    while (game_in_progress) {
        cout << "Insert $1.00 and enter your number or 'q' to quit: ";
        string user_answer;
        int user_digit_answer;
        cin >> user_answer;
        
        if (user_answer == "q"){
            cout << "You lost " << dollar_spent << "$. Thanks for playing. Come again!" << endl;
            break;
        } else {
            dollar_spent += 1;
            user_digit_answer = stoi(user_answer);
        }
        
        if (user_digit_answer == random_number){
            cout << "You win $1 000 000. That's awesome!" << endl;
            game_in_progress = false;
        }
        
        if (user_digit_answer != random_number){
            cout << "\nGood guess, but not right. Do you want go get a hint? y/n: ";
            cin >> user_answer;
            if(user_answer == "y"){
                cout << give_hint(user_digit_answer, random_number) << endl;
            }
            
        }
        
    }
    
    
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_number = rand() % 100000;
    
    guess_process(random_number);
    
    return 0;
}
