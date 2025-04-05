#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "The number of elements in the array is: " << n << endl;
    cout << "Enter the elements of the array: ";
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << "Enter the elements of the array: ";
        }
        cout << "The array is: ";
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
            }
            return 0;
            











    return 0;
}