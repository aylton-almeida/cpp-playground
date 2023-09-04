#include <iostream>
#include <climits>
#include "utils.h"

using namespace std;

/**
 * Merge Sort without Sentinel value
 * first: initial index
 * middle: middle index
 * last: final index
 */

void merge(int arr[], int first, int middle, int last)
{
  int size1 = middle - first + 1; // This is the size of sub array 1
  int size2 = last - middle;      // This is the size of sub array 2

  // Creating the sub arrays and copying the values from the original array
  int left[size1 + 1] = {};
  int right[size2 + 1] = {};
  for (int i = 0; i < size1; i++)
  {
    left[i] = arr[first + i];
  }
  for (int j = 0; j < size2; j++)
  {
    right[j] = arr[middle + j + 1];
  }

  int i = 0;
  int j = 0;
  for (int k = first; k <= last; k++)
  {

    if (i == size1)
    {
      arr[k] = right[j];
      j++;
      continue;
    }

    if (j == size2)
    {
      arr[k] = left[i];
      i++;
      continue;
    }

    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
  }
}

/**
 * Merge Sort with Sentinel value to avoid checking if the sub arrays are empty
 * first: initial index
 * middle: middle index
 * last: final index
 */
void mergeWithSentinel(int arr[], int first, int middle, int last)
{
  int size1 = middle - first + 1; // This is the size of sub array 1
  int size2 = last - middle;      // This is the size of sub array 2

  // Creating the sub arrays and copying the values from the original array
  int left[size1 + 1] = {};
  int right[size2 + 1] = {};
  for (int i = 0; i < size1; i++)
  {
    left[i] = arr[first + i];
  }
  for (int j = 0; j < size2; j++)
  {
    right[j] = arr[middle + j + 1];
  }

  left[size1] = INT_MAX;
  right[size2] = INT_MAX;

  int i = 0;
  int j = 0;
  for (int k = first; k <= last; k++)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
  }
}

int *mergeSort(int arr[], int first, int last)
{
  if (first >= last)
  {
    // This means the array only has one element and, therefore, is already sorted
    return arr;
  }

  int middle = (first + last) / 2;

  mergeSort(arr, first, middle);    // Sorting the first half
  mergeSort(arr, middle + 1, last); // Sorting the last half
  merge(arr, first, middle, last);  // Merging both halfs

  return arr;
}

int main()
{
  const int s = 7;
  int *v = randomArray(s);
  cout << "Vetor Original: " << join(s, v) << endl;

  int *resp = mergeSort(v, 0, s - 1);
  cout << "Vetor Ordenado: " << join(s, resp) << endl;

  return 0;

  return 0;
}
