#include <iostream>
using namespace std;
int recursiveSum(int arr[], int size)
{
    if (size == 0)
        return 0;
    return arr[size - 1] + recursiveSum(arr, size - 1);
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Sum = " << recursiveSum(arr, size);
    delete[] arr;
    return 0;
}