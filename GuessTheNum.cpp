// written by chankruze on 1st august 2020

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// generate truly random magic number
int genRandNum() {
    srand(time(NULL));
    // rand() % (b - a + 1) + a
    return rand() % 900 + 100;
}

// helper function to reuse code for user input
int userIn(int max, int count) {
    int guess;
    cout << "\n# Guess [" << max - count + 1 << "]" << endl;
    cout << "Your guess: ";
    cin >> guess;
    return guess;
}

int main(int argc, char const *argv[]) {
    // generate random number
    int magicNum = genRandNum(), maxChances = 7, chancesLeft = maxChances, prevGuess, prevDiff;

    // user hint
    cout << "========== Feking Guess Game ===============" << endl;
    cout << "= Your guess must be in between [100, 999] =" << endl;
    cout << "= You have " << maxChances << " chances for it ! =" << endl;
    cout << "========== Not for 50 IQ guys ==============" << endl;
    cout << "" << endl;

    // guessing loop
    while (chancesLeft != 0) {
        // save user guess & calculate difference between guess & magic
        int guess = userIn(maxChances, chancesLeft), diff = abs(magicNum - guess);

        // comparison to magic num
        if (guess != magicNum) {
            // only set prev guess & diff for first time
            if (chancesLeft == 5) {
                prevGuess = guess;
                prevDiff = diff;
            }

            // user feedback for their guess
            cout << (prevDiff < diff ? "Previous guess was closer !" : "This guess is closer !") << endl;
            cout << (guess < magicNum ? "This guess is lower !" : "This guess is higher !") << endl;
            
            // update prev guess & diff to current
            prevGuess = guess;
            prevDiff = diff;
            
            // update & show chances left
            cout << "Changes left: " << --chancesLeft << endl;
        } else {
            // winning message & exit
            cout << "Madarchod... You guessed it !" << endl;
            cout << "You are a fucking ROBOT!" << endl;
            return 0;
        }
    }
    
    // loosing message & exit
    cout << "\n------ Game Over ! ------" << endl;
    cout << "- MAGIC NUMBER WAS: " << magicNum << " -" <<endl; 
    cout << "\nMoral: Your guess sucks !" << endl;

    return 0;
}
