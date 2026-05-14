#include <iostream>
using namespace std;
int recursiveMax(int arr[], int size)
{
    if (size == 1)
        return arr[0];
    int maxRest = recursiveMax(arr, size - 1);
    if (arr[size - 1] > maxRest)
        return arr[size - 1];
    return maxRest;
}
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum element: "
        << recursiveMax(arr, size);
    delete[] arr;
    return 0;
}