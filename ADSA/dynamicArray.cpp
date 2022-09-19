#include <bits/stdc++.h>
using namespace std;

class DynamicArray
{
public:
    int currSize;
    int capacity;
    int A[];

    void resizeArray()
    {
        if (capacity == currSize)
        {
            int temp[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = A[i];
                // everything copied to temp array
            }
            free(A);
            A = temp; // temp array becomes new array
            capacity = 2 * capacity;
        }
    }

    DynamicArray()
    {
        A = new int[1]; // size of 1;
        currSize = 0;
        capacity = 1;
    }

    void insertAtEnd(int x)
    {
        if (currSize == capacity)
        {
            resizeArray();
        }
        A[currSize] = x;
        currSize++;
    }

    void deleteAtEnd()
    {
        if (currSize == 0)
        {
            cout << "DYNAMIC ARRAY IS EMPTY" << endl;
            return;
        }
        else
        {
            A[currSize - 1] = INT_MIN;
            currSize = currSize - 1;
        }
    }

    int getSize()
    {
        return currSize;
    }
};

int main()
{
    DynamicArray a = new DynamicArray();
    cout << "SIZE:" << a.getSize();
    a.insertAtEnd(12);
    a.insertAtEnd(13);
    a.insertAtEnd(14);
    cout << "SIZE:" << a.getSize();
}