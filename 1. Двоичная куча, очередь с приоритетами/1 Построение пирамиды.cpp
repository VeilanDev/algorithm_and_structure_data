#include <iostream>
using namespace std;

void downheap(int a[], int n, int i = 0)
{
    while (i < n / 2)
    {
        int i_max = i * 2 + 1;
        if (i_max + 1 < n)
            if (a[i_max + 1] > a[i_max])
                i_max = i_max + 1;

        if (a[i] >= a[i_max])
            break;

        int tmp = a[i];
        a[i] = a[i_max];
        a[i_max] = tmp;
        i = i_max;
    }
}

int main()
{
    int n; cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n / 2 - 1; i >= 0; i--)
        downheap(a, n, i);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}