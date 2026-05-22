#include <iostream>
using namespace std;
// Helper Recursive Function: Evaluates whether a subset can add up to target
// It bypasses the 'skipIdx' element (the current largest number being tested)
bool isSubsetSumRecursive(int arr[], int n, int target, int currentIdx, int skipIdx) {
    // Base Case 1: Target achieved
    if (target == 0)
    return true;
    // Base Case 2: Out of array bounds or target went negative
    if (currentIdx >= n || target < 0) 
    return false;
    // If current index is the number we are trying to match, skip it
    if (currentIdx == skipIdx) {
        return isSubsetSumRecursive(arr, n, target, currentIdx + 1, skipIdx);
    }
    // Branch Choice 1: Include the current element in the subset sum
    bool includeElement = isSubsetSumRecursive(arr, n, target - arr[currentIdx], currentIdx + 1, skipIdx);
    // Branch Choice 2: Exclude the current element
    bool excludeElement = isSubsetSumRecursive(arr, n, target, currentIdx + 1, skipIdx);
    // If either path satisfies the subset target, return true
    return includeElement || excludeElement;
}
//Recursive Function: Simulates sorting/arranging elements natively without loops
// Arranges the array in descending order using recursive bubbles
void sortDescendingRecursive(int arr[], int n, int i = 0, int j = 0) {
    if (n <= 1) 
    return;
    if (i < n - 1) {
        if (j < n - i - 1) {
            if (arr[j] < arr[j + 1]) {
                // Manual Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            sortDescendingRecursive(arr, n, i, j + 1);
        } else {
            sortDescendingRecursive(arr, n, i + 1, 0);
        }
    }
}
// Core Recursive Function: Iterates down sorted candidates to evaluate magic number status
int findMagicNumberHelper(int arr[], int n, int currentIdx) {
    // If we have evaluated all elements without a match, no magic number exists
    if (currentIdx >= n) 
    return -1;
    int candidate = arr[currentIdx];
    // Check if 'candidate' equals the sum of any subset from the remaining elements
    if (isSubsetSumRecursive(arr, n, candidate, 0, currentIdx)) {
        return candidate; // Found it!
    }
    // Candidate failed; move automatically to the next largest number
    return findMagicNumberHelper(arr, n, currentIdx + 1);
}
// Master wrapper function
int findMagicNumber(int arr[], int n) {
    // Sort array in descending order recursively first so index 0 holds the absolute largest
    sortDescendingRecursive(arr, n);
    return findMagicNumberHelper(arr, n, 0);
}
int main() {
    // Sample Test Case provided in instruction
    int sampleArr[] = {2, 3, 5, 8, 13};
    int sampleSize = 5;
    cout << "Testing Sample Input [2, 3, 5, 8, 13]"<<endl;
    int sampleResult = findMagicNumber(sampleArr, sampleSize);
   cout << "Resulting Magic Number: " << sampleResult <<endl;
   // Dynamic Test Case: Handled with unique numbers to demonstrate multi-tier testing
    int dynamicArr[] = {4, 30, 2, 7, 12}; 
    int dynamicSize = 5;
    // Explainer for dynamic check:
    // Sorted -> [30, 12, 7, 4, 2]
    // 1st candidate: 30. Can remaining [12, 7, 4, 2] sum to 30? Max possible sum is 25. No.
    // 2nd candidate: 12. Can remaining [30 (ignored), 7, 4, 2] sum to 12? No combination hits 12 (7+4+2=13, 7+4=11). No.
    // 3rd candidate: 7. Can remaining [4, 2] sum to 7? No.
    // 4th candidate: 4. Can remaining [2] sum to 4? No.
    // Therefore, it should return -1.
    cout << "Testing Dynamic Input [4, 30, 2, 7, 12] "<<endl;
    int dynamicResult = findMagicNumber(dynamicArr, dynamicSize);
    cout << "Resulting Magic Number: " << dynamicResult <<endl;
    return 0;
}