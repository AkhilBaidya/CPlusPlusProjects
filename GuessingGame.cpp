#include <iostream>

using namespace std;

int main() {
  int tries = 0;
  char again = 'y';
  int randNum = 0;
  int guess = 0;

  while (again == 'y') {

    srand(time(NULL));
    randNum = rand();
    cout << "I chose a number between 0 and 100 (inclusive) " << randNum << endl;
    
    do {
      cout << "Guess my number!" << endl;
      cin >> guess;
      tries++;

      if (guess < randNum) {
	cout << "You're low!" << endl;
      }
      else if (guess > randNum) {
	cout << "You're high!" << endl;
      }

    } while (guess != randNum);

    cout << "You guessed my number in " << tries << "tries!"; 
    tries = 0;
    cout << "Would you like to play again? y/n";
    cin >> again;

  }
  
  return 0;
}
