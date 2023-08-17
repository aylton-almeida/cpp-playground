#include <iostream>
#include <string>

using namespace std;

int main()
{
  string name;

  cout << "What is your name? ";
  getline(cin, name); // read a line of text into yourName

  cout << "Your name is " << name << endl;

  name += " is a cool name!"; // append to string

  cout << name << endl;

  return 0;
}
