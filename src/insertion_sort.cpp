#include <iostream>

#include "utils.h"

using namespace std;

int *insertionSort(int s, int arr[])
{
  for (int i = 1; i < s; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  return arr;
}

int main()
{
  const int s = 100000;
  int *v = randomArray(s);
  // cout << "Vetor Original: " << join(s, v) << endl;

  int *resp = insertionSort(s, v);
  // cout << "Vetor Ordenado: " << join(s, resp) << endl;

  return 0;

  return 0;
}
