#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int max(int s, int v[])
{
  int max = v[0];

  for (int i = 1; i < s; i++)
  {
    if (v[i] > max)
    {
      max = v[i];
    }
  }

  return max;
}

int *randomArray(int size)
{
  int *arr = new int[size];

  srand(time(NULL));

  for (int i = 0; i < size; i++)
  {
    arr[i] = rand() % 100;
  }

  return arr;
}

int main()
{
  const int s = 100;
  int *v = randomArray(s);
  int resp = max(s, v);

  string original = "";
  for (int i = 0; i < s; i++) {
    original += to_string(v[i]) + ", ";
  }

  cout << "Vetor Original: " << original << endl;
  cout << "O maior eh: " << resp << endl;

  return 0;
}
