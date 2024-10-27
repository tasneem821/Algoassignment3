#include <iostream>
#include <vector>
#include <optional>

using namespace std;

// Heap and its max-heap and min-heap
class Heap {
protected:
    vector<int> heap;
public:
    int parent(int index) {
        return (index - 1) / 2;
    }
    virtual void heapify(int index) = 0;
};

class MinHeap : public Heap {
public:
    int extractMinNumber();
    void insertNumber(int number);
    void heapify(int index);
    bool isEmpty() const;
};

bool MinHeap::isEmpty() const {
    return heap.empty();
}

// Get the minimum value and remove it from heap
int MinHeap::extractMinNumber() {
    int rootNumber = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);
    return rootNumber;
}

void MinHeap::insertNumber(int number) {
    heap.push_back(number);
    int index = heap.size() - 1;
    while (index != 0 && heap[parent(index)] > heap[index]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void MinHeap::heapify(int index) {
    int leftnode = 2 * index + 1;
    int rightnode = 2 * index + 2;
    int smallestNumber = index;

    if (leftnode < heap.size() && heap[leftnode] < heap[smallestNumber]) {
        smallestNumber = leftnode;
    }
    if (rightnode < heap.size() && heap[rightnode] < heap[smallestNumber]) {
        smallestNumber = rightnode;
    }

    if (smallestNumber != index) {
        swap(heap[index], heap[smallestNumber]);
        heapify(smallestNumber);
    }
}

class MaxHeap : public Heap {
public:
    int extractMaxNumber();
    void insertNumber(int number);
    void heapify(int index);
    bool isEmpty() const;
};


bool MaxHeap::isEmpty() const {
    return heap.empty(); // Check if the heap is empty
}

int MaxHeap::extractMaxNumber() {
    int rootNumber = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);
    return rootNumber;
}

void MaxHeap::insertNumber(int number) {
    heap.push_back(number);
    int index = heap.size() - 1;
    while (index != 0 && heap[parent(index)] < heap[index]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void MaxHeap::heapify(int index) {
    int leftnode = 2 * index + 1;
    int rightnode = 2 * index + 2;
    int largestNumber = index;

    if (leftnode < heap.size() && heap[leftnode] > heap[largestNumber]) {
        largestNumber = leftnode;
    }
    if (rightnode < heap.size() && heap[rightnode] > heap[largestNumber]) {
        largestNumber = rightnode;
    }

    if (largestNumber != index) {
        swap(heap[index], heap[largestNumber]);
        heapify(largestNumber);
    }
}
// PriorityQueue class using MaxHeap
class PriorityQueue {
private:
    MaxHeap maxHeap;

public:
    void insert(int priority);
    void top();
    bool isEmpty() const;
};


void PriorityQueue::insert(int priority) {
    maxHeap.insertNumber(priority);
}


void PriorityQueue::top() {
    if (maxHeap.isEmpty()) {
        cout<<"Priority queue is empty!\n";
    }
    else {
        cout<<maxHeap.extractMaxNumber()<<'\n';
    }
}

// Check if the priority queue is empty
bool PriorityQueue::isEmpty() const {
    return maxHeap.isEmpty();
}


// HeapSort function using MaxHeap
void heapSort(vector<int> &arr) {
    MaxHeap maxHeap;

    // Insert elements into the heap
    for (int num : arr) {
        maxHeap.insertNumber(num);
    }

    // Extract elements from heap and place at end of array
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = maxHeap.extractMaxNumber();
    }
}

int main() {
    MinHeap minHeap;
    minHeap.insertNumber(3);
    minHeap.insertNumber(2);
    minHeap.insertNumber(15);
    minHeap.insertNumber(1);
    minHeap.insertNumber(9);

    cout << "MinHeap root (Min): " << minHeap.extractMinNumber() << endl;

    MaxHeap maxHeap;
    maxHeap.insertNumber(3);
    maxHeap.insertNumber(2);
    maxHeap.insertNumber(15);
    maxHeap.insertNumber(16);
    maxHeap.insertNumber(17);

    cout << "MaxHeap root (Max): " << maxHeap.extractMaxNumber() << endl;

    // Apply HeapSort
    vector<int> v = {3, 5, 1, 10, 2, 7};
    heapSort(v);
    cout << "Sorted array: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    // Priority queue
    PriorityQueue pq;
    pq.insert(5);
    pq.insert(10);
    pq.insert(7);

    pq.top();
    pq.top();
    pq.top();
    pq.top();

    return 0;
}
