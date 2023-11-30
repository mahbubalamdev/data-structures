// You have to implement a circular queue using an array.
// 1.  Given n (a user-provided positive integer), construct a data structure to represent a
// circular queue, which can hold at most n integer elements.
// 2.  Write a function enqueue ( value ) that inserts an element value into the circular
// queue. Your implementation should gracefully handle the corner case (i.e., the queue is full).
// For example, it can display an error message but must not cause the program using this circular
// data structure crash/terminate. (Hint: the time complexity should be O(1)).
// 3. Write a function dequeue that removes and returns an element value into the
// circular queue. Your implementation should gracefully handle the corner case (i.e., the queue is
// empty). (Hint: the time complexity should be O(1)).

#include<iostream>
using namespace std;


inline const char* boolalpha(const bool b){
    return b ? "true" : "false";
}

class CircularQueue{
    private:
        int front;
        int rear;
        int* queue;
        int itemCount;
        int size;
    public:
        CircularQueue(int n){
            size = n;
            queue = new int[n];
            itemCount = 0;
            front = -1;
            rear = -1;
        }
        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }else{
                return false;
            }
        }
        bool isFull(){
            if((rear+1)%size == front){
                return true;
            }else{
                return false;
            }
        }
        void enqueue(int val){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }else if(isEmpty()){
                rear = 0;
                front = 0;
                queue[rear] = val;
            }else{
                rear = (rear+1)%5;
                queue[rear] = val;
            }
            itemCount++;
        }
        int dequeue(){
            int x = 0;
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return x;
            }else if(front == rear){
                x = queue[front];
                front = -1;
                rear = -1;
                itemCount--;
                return x;
            }else{
                x = queue[front];
                front = (front+1)%5;
                itemCount--;
                return x;
            }
        }
        int count(){
            return itemCount;
        }
        void display(){
            cout << "All values in the Queue are - " << endl;
            for(int i=0; i<size; i++){
                cout << queue[i] << " ";
            }
        }
};



int main(){
    int n;
    cout<<"Enter the size of the queue: ";
    cin>>n;
    CircularQueue cq = CircularQueue(n);

    cout<<"Empty: " << boolalpha(cq.isEmpty())<<endl;
    cout<<"Full: "<<boolalpha(cq.isFull())<<endl;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout<<"Empty: " << boolalpha(cq.isEmpty())<<endl;
    cout<<"Full: "<< boolalpha(cq.isFull())<<endl;
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cout<<"Empty: " << boolalpha(cq.isEmpty())<<endl;
    cout<<"Full: "<< boolalpha(cq.isFull())<<endl;

    return 0;
}