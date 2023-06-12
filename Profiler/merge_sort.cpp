//In this sample (recursive sorting algorithm) we can show the profiler execution result:
//On the "Call Tree" tab show that CLion effectively collapses recursive calls as well as "Filtered Calls" (chain of functions/methods from standard library)
//On the "Method List" tab show the difference between "Samples" and "Own Samples" for "mergeSort" function
//The "Own Samples" column shows the number of those samples where the stack trace ends on the current method (not on its callees).
// The Own Samples values may be helpful when examining long-running methods that don't call other methods.

#include <vector>

using namespace std;

void merge(int left, int mid, int right, vector<int> &array) {
    vector<int> leftArray(mid - left + 1);
    vector<int> rightArray(right - mid);

    for (int i = 0; i < leftArray.size(); i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < rightArray.size(); j++)
        rightArray[j] = array[j + mid + 1];

    int leftArrayIndex = 0, rightArrayIndex = 0;
    int mergedArrayIndex = left;

    while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size()) {
        if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex]) {
            array[mergedArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        } else {
            array[mergedArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }
        mergedArrayIndex++;
    }

    while (leftArrayIndex < leftArray.size()) {
        array[mergedArrayIndex] = leftArray[leftArrayIndex];
        leftArrayIndex++;
        mergedArrayIndex++;
    }

    while (rightArrayIndex < rightArray.size()) {
        array[mergedArrayIndex] = rightArray[rightArrayIndex];
        rightArrayIndex++;
        mergedArrayIndex++;
    }
}

void mergeSort(int left, int right, vector<int> &array) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid, array);
    mergeSort(mid + 1, right, array);
    merge(left, mid, right, array);
}

int main() {
    const int size = 1000000;
    std::vector<int> arr;
    arr.reserve(size);
    for (int i = size; i > 0; --i) {
        arr.push_back(i);
    }
    mergeSort(0, arr.size() - 1, arr);
}