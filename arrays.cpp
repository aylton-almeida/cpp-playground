#include <iostream>
#include <string>

using namespace std;

int main()
{
  const string arr[5] = {"1", "2", "3", "4", "5"};
  const int arrLength = sizeof(arr) / sizeof(arr[0]);

  for (size_t i = 0; i < arrLength; i++)
  {
    cout << arr[i] << endl;
  }
}
