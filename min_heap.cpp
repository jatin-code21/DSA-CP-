#include <bits/stdc++.h>
using namespace std;

class minHeap
{
public:
    int *arr;      // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // current number of elements in min heap

    minHeap(int cap)
    {
        capacity = cap;
        heap_size = 0;
        arr = new int[capacity];
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i) + 1;
    }

    int right(int i)
    {
        return (2 * i) + 2;
    }

    void insert(int k)
    {
        if (heap_size == capacity)
        {
            cout << "Overflow" << "\n";
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        arr[i] = k;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && arr[l] < arr[i])
            smallest = l;
        if (r < heap_size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extraction() // extract minimum element from heap and delete it from heap
    {
        if (heap_size <= 0) return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heap_size - 1];
        heap_size--;
        minHeapify(0);
        return root;
    }

    void decreaseKey(int i, int new_val)
    {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extraction();
    }
};

main()
{
    minHeap obj1(5);
}