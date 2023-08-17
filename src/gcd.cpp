#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int a, int b)
{

  if (a == 0)
    return b;

  if (b == 0)
    return a;

  if (a == b)
    return a;

  return gcd(b, a % b);
}

void gcdMain()
{
  cout << "Enter two positive integers: ";
  int a, b;

  if (!(cin >> a >> b) || a < 0 || b < 0)
  {
    cout << "Invalid input" << endl;
    return;
  }

  int result = gcd(a, b);

  cout << "The greatest common divisor of " << a << " and " << b << " is " << result << endl;
}

int main()
{
  gcdMain();

  return 0;
}
