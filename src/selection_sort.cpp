#include <iostream>

#include "utils.h"

using namespace std;

int *selectionSort(int s, int arr[])
{
  for (int i = 0; i < s; i++)
  {
    int min = i;
    for (int j = i + 1; j < s; j++)
    {
      if (arr[min] > arr[j])
      {
        min = j;
      }
    }

    int tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }

  return arr;
}

int main()
{
  const int s = 10;
  int *v = randomArray(s);
  cout << "Vetor Original: " << join(s, v) << endl;

  int *resp = selectionSort(s, v);
  cout << "Vetor Ordenado: " << join(s, resp) << endl;

  return 0;

  return 0;
}
