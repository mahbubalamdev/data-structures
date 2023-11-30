// Now, you have to implement a kQueues using one single array,
// where each of these k queues is an individual circular queue. You may want to leverage the concept
// or your implementation of a circular queue.
// 1. Given n and k (user-provided positive integers and n is a multiple of k), construct
// a data structure to represent a kQueues, where k is the total number of circular queues. Each
// queue can hold at most n/k integer elements, and thus the entire kQueues can hold at most n
// integer elements in total.
// 2. Write the following functions to manipulate or operate on the kQueues.
// (Convention: Below, q is an integer such that q <- {0, 1, ..., k-1})
// (a) enqueue(q,v): adds the given element v to the queue number q
// (b) dequeue(q): removes and returns an element from the queue number q
// (c) isEmpty(q): returns true if the queue q is empty, otherwise false
// (d) isFull(q): return true if the queue q is full, otherwise false
// (e) isEmpty(): returns true if the kQueues is empty, otherwise false
// (f) isFull(): return true if the kQueues is full, otherwise false
// Your implementation should gracefully handle the corner cases. The time complexity of all
// these functions should be O(1).

#include<iostream>
using namespace std;

class kQueues{
    private:
        int* fronts;
        int* rears;
        int* queue;
        int* itemCounts;
        int size;
        int k;
    public:
        kQueues(int n, int k){
            this->size = n;
            this->k = k;
            this->queue = new int[n];
            itemCounts = new int[k];
            fronts = new int[k];
            rears = new int[k];
            for(int i = 0; i < k; i++){
                itemCounts[i] = 0;
                fronts[i] = -1;
                rears[i] = -1;
            }
            for(int i=0; i<n; i++){
                queue[i] = 0;
            }
        }
        bool isEmpty(int q){
            if(fronts[q] == -1 && rears[q] == -1){
                return true;
            }else{
                return false;
            }
        }
        bool isFull(int q){
            if((rears[q]+1)%size == fronts[q]){
                return true;
            }else{
                return false;
            }
        }
        bool isEmpty(){
            for(int i = 0; i < k; i++){
                if(!isEmpty(i)){
                    return false;
                }
            }
            return true;
        }
        bool isFull(){
            for(int i = 0; i < k; i++){
                if(!isFull(i)){
                    return false;
                }
            }
            return true;
        }
        void enqueue(int q, int val){
            if(isFull(q)){
                cout << "Queue " << q << " is full" << endl;
                return;
            }else if(isEmpty(q)){
                rears[q] = q*size/k;
                fronts[q] = q*size/k;
                queue[rears[q]] = val;
            }else{
                rears[q] = (rears[q]+1)%size;
                queue[rears[q]] = val;
            }
            itemCounts[q]++;
        }
        int dequeue(int q){
            int x = 0;
            if(isEmpty(q)){
                cout << "Queue " << q << " is empty" << endl;
                return x;
            }else if(fronts[q] == rears[q]){
                x = queue[fronts[q]];
                queue[fronts[q]] = 0;
                fronts[q] = -1;
                rears[q] = -1;
                itemCounts[q]--;
                return x;
            }else{
                x = queue[fronts[q]];
                queue[fronts[q]] = 0;
                fronts[q] = (fronts[q]+1)%size;
                itemCounts[q]--;
                return x;
            }
        }
        void print(){
            for(int i = 0; i < size; i++){
                cout << queue[i] << " ";
            }
            cout << endl;
        
        }

};

int main(){
    int n, k;
    cin >> n >> k;
    kQueues kq(n, k);
    kq.enqueue(0, 1);
    kq.enqueue(0, 2);
    kq.enqueue(0, 3);
    kq.enqueue(1, 3);
    kq.enqueue(1, 4);
    kq.enqueue(2, 5);
    kq.enqueue(2, 6);
    kq.print();
    cout<<kq.dequeue(0)<<endl;
    cout<<kq.dequeue(1)<<endl;
    cout<<kq.dequeue(1)<<endl;
    cout<<kq.dequeue(1)<<endl;
    kq.print();
    cout<<kq.isEmpty()<<endl;
    cout<<kq.isFull()<<endl;
    cout<<kq.isEmpty(3)<<endl;
    cout<<kq.isFull(2)<<endl;

    return 0;
}