#include <iostream>

using namespace std;

int main()
{
    int a=0, b, c;
    int n;
    cin >> n;
    c=0;
    b=1;
    int sum=0;
    if (n==0)
        cout << 0;
    else if (n==1)
        cout << 1;
    else
    {
        for (int i=2; i<=n; i++)
        {
            a=c+b;
            c=b;
            b=a;
        }
        cout << a;
    }
}
