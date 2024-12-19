#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

template <typename T>
class Heap {
private:
    int childCount;       // Number of children per node
    vector<T> data;       // Heap data storage

    // Validate that childCount is a power of 2 and greater than 0
    void validateChildCount(int childCount) {
        if (childCount <= 0) {
            throw invalid_argument("childCount must be greater than zero");
        }
        double logChildCount = log2(childCount);
        if (ceil(logChildCount) != floor(logChildCount)) {
            throw invalid_argument("childCount must be a power of 2");
        }
    }

    // Swap a child up the heap if it violates the max-heap property
    int swapUp(int childIndex) {
        T childValue = data[childIndex];
        int parentIndex = (childIndex - 1) / childCount;

        if (parentIndex >= 0) {
            T parentValue = data[parentIndex];
            if (childValue > parentValue) {
                swap(data[parentIndex], data[childIndex]);
                return parentIndex;
            }
        }
        return -1;
    }

    // Swap a parent down the heap if it violates the max-heap property
    int swapDown(int parentIndex) {
        T parentValue = data[parentIndex];
        int largestChildIndex = -1;
        T largestChildValue;

        // Find the largest child among all children
        for (int i = 0; i < childCount; ++i) {
            int childIndex = childCount * parentIndex + i + 1;
            if (childIndex < data.size()) {
                T childValue = data[childIndex];
                if (largestChildIndex == -1 || childValue > largestChildValue) {
                    largestChildIndex = childIndex;
                    largestChildValue = childValue;
                }
            }
        }

        // If a larger child is found, swap and continue
        if (largestChildIndex != -1 && parentValue < largestChildValue) {
            swap(data[parentIndex], data[largestChildIndex]);
            return largestChildIndex;
        }

        return -1;
    }

public:
    // Constructor
    Heap(int childCount) {
        validateChildCount(childCount);
        this->childCount = childCount;
    }

    // Insert a value into the heap
    void insert(const T& item) {
        data.push_back(item);
        int itemIndex = data.size() - 1;
        while (itemIndex > 0) {
            itemIndex = swapUp(itemIndex);
        }
    }

    // Pop the max value from the heap
    T popMax() {
        if (data.empty()) {
            throw runtime_error("Heap is empty!");
        }

        T maxItem = data[0];
        if (data.size() > 1) {
            T lastItem = data.back();
            data.pop_back();
            data[0] = lastItem;

            int itemIndex = 0;
            while (itemIndex >= 0) {
                itemIndex = swapDown(itemIndex);
            }
        } else {
            data.pop_back();
        }
        return maxItem;
    }

    // Print the heap contents
    void printHeap() const {
        for (const auto& val : data) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        int childCount = 4; // Example: 4 children per node
        Heap<int> heap(childCount);

        heap.insert(10);
        heap.insert(20);
        heap.insert(5);
        heap.insert(30);
        heap.insert(15);

        cout << "Heap after inserts: ";
        heap.printHeap();

        cout << "Extracted max: " << heap.popMax() << endl;

        cout << "Heap after extraction: ";
        heap.printHeap();

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}