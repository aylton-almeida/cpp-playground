#include <iostream>

int max(int n, int arr[])
{
  int max = arr[0];

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int main()
{
  int arr[] = {1, 2, 3, 7, 5, 4, 3, 8, 4};
  int resp = max(9, arr);

  std::cout << resp << std::endl;

  return 0;
}
