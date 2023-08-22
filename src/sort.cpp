#include <iostream>
#include <ctime>
#include <cstdlib>

#include "utils.h"

using namespace std;

int *sort(int s, int *v)
{
  int *sorted = new int[s];
  for (int i = 0; i < s; i++)
  {
    sorted[i] = v[i];
  }

  for (int i = 1; i < s; i++)
  {
    int tmp = sorted[i];
    for (int j = i - 1; j >= 0 && tmp < sorted[j]; j--)
    {
      sorted[j + 1] = sorted[j];
      sorted[j] = tmp;
    }
    cout << "Current array: " << join(s, sorted) << " -> index = " << i << endl;
  }

  return sorted;
}

int main()
{
  const int s = 10;
  int *v = randomArray(s);
  int *resp = sort(s, v);

  cout << "Vetor Original: " << join(s, v) << endl;
  cout << "Vetor Ordenado: " << join(s, resp) << endl;

  return 0;
}
