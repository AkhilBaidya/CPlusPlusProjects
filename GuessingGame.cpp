/* C++ Programming DC - 9/11/2023 (d/mm/yyyy)

"Guessing Game" Program by Akhil Baidya (help from Mr. Galbraith)

Note (How It Works):
The computer will choose a random number between 0 and 100 (inclusive).
Once prompted, the player will type their guess, which the computer will
report as too high or too low. These guesses will loop until the player 
gets the number correct. The computer wil display the number of guesses
it took. 

At the end of the game, the player will be prompted to play again. Answering
"y" (yes) will restart the game; otherwise, the game and code will end.


Note 2 (The Three Rules of a C++ Class):
(Source: C++ Canvas - https://bsd.instructure.com/courses/134896/pages/introduction-to-c++?module_item_id=3666878) 

1. Don't make global variables. Making global constants is okay.  

2. Don't use strings. Use cstrings and character arrays instead. 

3. Include <iostream> instead of stdio. Additionally, use "new" and "delete"
and not "malloc" and "free."
 
(The other two important rules: try not to use your mouse and only use the
statements "break" and "continue" when necessary in your code)
*/

#include <iostream>

using namespace std; //this prevents needing to specify this during cout and cin, later in the code

int main() {

  //VARIABLES:
  int tries = 0; //the number of guesses the player took
  char again = 'y'; //whether the player wants to repeat the game (y = yes, otherwise interpreted as no)
  int randNum = 0; //random number generated by computer
  int guess = 0; //number guessed by player

  //INSIDE THE GUESSING GAME:
  while (again == 'y') { /*Only enter Guessing Game if player wants to continue.
  Again is already defined as 'y' to enter the Guessing Game on the first playing.*/


    //Computer generates random number:
    
    srand(time(NULL)); //sets the random seed
    randNum = rand() % 101; /* rand() returns random number between 0 and max number. Use modulus 101,
    returning remainder of random number / 101 which is between 0 and 100 inclusive (Modulus suggested by Mr. Galbraith) */
    cout << "I chose a number between 0 and 100 (inclusive) " << endl;


    //Player guesses: 
    do {
      cout << "Guess my number!" << endl;
      cin >> guess; //sets "guess" to player input
      tries++; //increase number of player guesses by 1
      
      if (guess < randNum) { //let the player know if guess is too low or high
	cout << "You're low!" << endl;
      }
      else if (guess > randNum) {
	cout << "You're high!" << endl;
      }

    }
    while (guess != randNum); //continue looping guessing section until player guesses the randNum


    //Player chooses to play again or not:
    cout << "You guessed my number in " << tries << " tries!"; 
    tries = 0;
    cout << "Would you like to play again? y/n";
    cin >> again; //set again to player input (if "y", while loop continues)
  }

  //OUTSIDE THE GUESSING GAME:
  cout << "Thanks for playing!";
  return 0;
}
