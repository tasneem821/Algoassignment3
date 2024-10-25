#include "iostream"
#include "vector"

using namespace std;
//heap and its maxheap and minheap
class Heap{
protected:
    vector<int>heap;
public:
    int parent(int index){
        return (index-1)/2;
    }
    virtual void heapify(int index)=0;

};
class MinHeap:public Heap{
public:

    int extractMinNumber();
    void insertNumber(int number);
    void heapify(int index);
};
//get the minimum value and remove it from heap
int MinHeap::extractMinNumber() {

    int rootNumber = heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    heapify(0);
    return rootNumber;
}
void MinHeap::insertNumber(int number) {
heap.push_back(number);
int index = heap.size()-1;
    while (index!=0&&heap[parent(index)]>heap[index]){
        int temp = heap[index];
        heap[index]=heap[parent(index)];
        heap[parent(index)]=temp;
        index = parent(index);
    }

}

void MinHeap::heapify(int index) {
 int leftnode = 2*index +1;
 int rightnode = 2*index+2;
 int smallestNumber = index;
 if(heap[leftnode]<heap[smallestNumber]){
     smallestNumber = leftnode;
 }
 if(heap[rightnode]<heap[smallestNumber]){
     smallestNumber=rightnode;
 }
 if(smallestNumber!=index){
     int temp = heap[index];
     heap[index]=heap[smallestNumber];
     heap[smallestNumber]=temp;
     heapify(smallestNumber);
 }
}
class Maxheap:public Heap{
public:

    int extractMaxNumber();
    void insertNumber(int number);
    void heapify(int index);
};

int Maxheap::extractMaxNumber() {

    int rootNumber = heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    heapify(0);
    return rootNumber;
}

void Maxheap::insertNumber(int number) {
    heap.push_back(number);
    int index = heap.size()-1;
    while (index!=0&&heap[parent(index)]<heap[index]){
        int temp = heap[index];
        heap[index]=heap[parent(index)];
        heap[parent(index)]=temp;
        index = parent(index);
    }
}

void Maxheap::heapify(int index) {
    int leftnode = 2*index +1;
    int rightnode = 2*index+2;
    int largestNumber = index;
    if(heap[leftnode]>heap[largestNumber]){
        largestNumber = leftnode;
    }
    if(heap[rightnode]>heap[largestNumber]){
        largestNumber=rightnode;
    }
    if(largestNumber!=index){
        int temp = heap[index];
        heap[index]=heap[largestNumber];
        heap[largestNumber]=temp;
        heapify(largestNumber);
    }
}
int main(){
    MinHeap minHeap;
    minHeap.insertNumber(3);
    minHeap.insertNumber(2);
    minHeap.insertNumber(15);
    minHeap.insertNumber(1);

    minHeap.insertNumber(9);

    cout << "MinHeap root (Min): " << minHeap.extractMinNumber() << endl;

    Maxheap maxHeap;
    maxHeap.insertNumber(3);
    maxHeap.insertNumber(2);
    maxHeap.insertNumber(15);
    maxHeap.insertNumber(16);

    maxHeap.insertNumber(17);

    cout << "MaxHeap root (Max): " << maxHeap.extractMaxNumber() << endl;
}
