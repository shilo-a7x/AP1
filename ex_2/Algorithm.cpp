#include "Algorithm.h"

class Algorithm
{
private:
    Distance disFunc;
    // Standard partition process of QuickSort().
    // It considers the last element as pivot
    // and moves all smaller element to left of
    // it and greater elements to right
    int partition(int arr[], int l, int r)
    {
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }

public:
    Algorithm(string type)
    {
        this->disFunc = Distance(type);
        string err = disFunc.getType;
        if (err.compare("ERR"))
        {
            cout << "wrong distance input" << endl;
            this->disFunc = nullptr;
        }
    }
    // This function returns k'th smallest
    // element in arr[l..r] using QuickSort
    // based method.  ASSUMPTION: ALL ELEMENTS
    // IN ARR[] ARE DISTINCT
    int QuickSelect(int arr[], int l, int r, int k)
    {
        // If k is smaller than number of
        // elements in array
        if (k > 0 && k <= r - l + 1)
        {

            // Partition the array around last
            // element and get position of pivot
            // element in sorted array
            int index = partition(arr, l, r);

            // If position is same as k
            if (index - l == k - 1)
                return arr[index];

            // If position is more, recur
            // for left subarray
            if (index - l > k - 1)
                return kthSmallest(arr, l, index - 1, k);

            // Else recur for right subarray
            return kthSmallest(arr, index + 1, r,
                               k - index + l - 1);
        }

        // If k is more than number of
        // elements in array
        return INT_MAX;
    }
};