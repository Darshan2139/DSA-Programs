#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    int key;
    cout << "Enter the element of array:-";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    cout << "Sorted Array is:-";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
        cout<<endl<<"Prepared by 23CE051 Darshan";

    return 0;
}