#include <iostream>
#include <iomanip>

using namespace std;

int generateRandomNumber(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

int main()
{
  int secret = generateRandomNumber(1, 100);

  int guess;

  do
  {
    cout << "Guess a number between 1 and 100: ";
    if (!(cin >> guess))
    {
      cout << "Please enter a number." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
    else if (guess < secret)
    {
      cout << "Too low!" << endl;
    }
    else if (guess > secret)
    {
      cout << "Too high!" << endl;
    }
    else
    {
      cout << "You got it!" << endl;
    }

  } while (guess != secret);

  cout << "Congrats!" << endl;

  return 0;
}
