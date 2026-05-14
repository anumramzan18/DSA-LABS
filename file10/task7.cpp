#include <iostream>
using namespace std;
int findMax(int arr[], int size, int index = 0)
{
    if (index == size - 1)
        return arr[index];

    int maxRest = findMax(arr, size, index + 1);

    return (arr[index] > maxRest) ? arr[index] : maxRest;
}
bool subsetSum(int arr[], int size, int index, int target)
{
       if (target == 0)
        return true;

    if (index == size || target < 0)
        return false;
    return subsetSum(arr, size, index + 1, target - arr[index]) ||
        subsetSum(arr, size, index + 1, target);
}
void copyWithoutMax(int arr[], int newArr[], int size,
    int maxVal, int index = 0, int j = 0)
{
    if (index == size)
        return;

    if (arr[index] != maxVal)
    {
        newArr[j] = arr[index];
        copyWithoutMax(arr, newArr, size, maxVal, index + 1, j + 1);
    }
    else
    {
        copyWithoutMax(arr, newArr, size, maxVal, index + 1, j);
    }
}
int magicNumber(int arr[], int size)
{
    if (size == 0)
        return -1;

    int maxVal = findMax(arr, size);

    int* temp = new int[size - 1];

    copyWithoutMax(arr, temp, size, maxVal);

    if (subsetSum(temp, size - 1, 0, maxVal))
    {
        delete[] temp;
        return maxVal;
    }

    int result = magicNumber(temp, size - 1);

    delete[] temp;

    return result;
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
        int result = magicNumber(arr, size);

    if (result == -1)
        cout << "No Magic Number Found";
    else
        cout << "Magic Number: " << result;
    delete[] arr;
    return 0;
}