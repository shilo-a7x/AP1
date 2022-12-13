#include "Algorithm.h"

class Algorithm
{
private:
    // Standard partition process of QuickSort().
    // It considers the last element as pivot
    // and moves all smaller element to left of
    // it and greater elements to right
    int partition(vector<Classifiable> vectors, int l, int r)
    {
        double x = vectors[r].getDistance();
        int i = l;
        for (int j = l; j <= r - 1; j++)
        {
            if (vectors[j].getDistance() <= x)
            {
                swap(vectors[i], vectors[j]);
                i++;
            }
        }
        swap(vectors[i], vectors[r]);
        return i;
    }

public:
    // This function returns k'th smallest
    // element in arr[l..r] using QuickSort
    // based method.  ASSUMPTION: ALL ELEMENTS
    // IN ARR[] ARE DISTINCT
    int QuickSelect(vector<Classifiable> vectors, int l, int r, int k)
    {
        // If k is smaller than number of
        // elements in array
        if (k > 0 && k <= r - l + 1)
        {

            // Partition the array around last
            // element and get position of pivot
            // element in sorted array
            int index = partition(vectors, l, r);

            // If position is same as k
            if (index - l == k - 1)
                return index;

            // If position is more, recur
            // for left subarray
            if (index - l > k - 1)
                return QuickSelect(vectors, l, index - 1, k);

            // Else recur for right subarray
            return QuickSelect(vectors, index + 1, r,
                               k - index + l - 1);
        }

        // If k is more than number of
        // elements in array
        return 0;
    }
    vector<Classifiable> KClosest(double maxDis, vector<Classifiable> vectors)
    {
        vector<Classifiable> Kclosest = new vector<Classifiable>;
        int i;
        for (i = 0; i < vectors.size(); i++{
            if(vectors[i].getDistane() < )
        })
    }

    string mostCommon(vector<Classifiable> vectors)
    {
    }
};