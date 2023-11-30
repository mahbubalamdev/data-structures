// Now, you have to implement a circular deque using an array. Just
// like acircular queue, the last position of the deque is connected back to the first position, making a
// circle. You may want to leverage the concept or your implementation of a circular queue.
// 1. Given n (a user-provided positive integer), construct a data structure to represent a
// deque, which can hold at most n integer elements.
// 2. Write the following functions to manipulate or operate on the deque.
// (a) insertFront (v): inserts the given element v at the front of the deque.
// (b) removeFront() : removes and returns an element from the front of the deque.
// (c) insertRear(v) : inserts the given element v at the rear of the deque.
// (d) removeRear() : removes and returns an element from the rear of the deque.
// (e) isEmpty() : returns true if the deque is empty, otherwise false
// (F) isFull () : return true if the deque is full, otherwise false
// Your implementation should gracefully handle the corner cases. The time complexity ot all these functions should be O(1)

#include<iostream>
using namespace std;

class Dqueue{
    private:
        int front;
        int rear;
        int* queue;
        int itemCount;
        int size;
    public:
        Dqueue(int n){
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
        void insertFront(int val){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }else if(isEmpty()){
                rear = 0;
                front = 0;
                queue[front] = val;
            }else{
                front = (front-1+size)%size;
                queue[front] = val;
            }
            itemCount++;
        }
        void insertRear(int val){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }else if(isEmpty()){
                rear = 0;
                front = 0;
                queue[rear] = val;
            }else{
                rear = (rear+1)%size;
                queue[rear] = val;
            }
            itemCount++;
        }
        int removeFront(){
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
                front = (front+1)%size;
                itemCount--;
                return x;
            }
        }
        int removeBack(){
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
                x = queue[rear];
                rear = (rear-1+size)%size;
                itemCount--;
                return x;
            }
        }
};
int main()
{
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;
    Dqueue q(n);
    int choice, val;
    int continueChoice = 1;
    do{
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Front" << endl;
        cout << "2. Insert Rear" << endl;
        cout << "3. Remove Front" << endl;
        cout << "4. Remove Rear" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> choice;
        switch(choice){
            case 0:
                continueChoice = 0;
                break;
            case 1:
                cout << "Enter an item to insert front in the queue: ";
                cin >> val;
                q.insertFront(val);
                break;
            case 2:
                cout << "Enter an item to insert back in the queue: ";
                cin >> val;
                q.insertRear(val);
                break;
            case 3:
                cout << "Removed " << q.removeFront() << " from the front of queue." << endl;
                break;
            case 4:
                cout << "Removed " << q.removeBack() << " from the back of queue." << endl;
                break;
            case 5:
                system("cls");
                break;
            default:
                cout << "Enter a valid option number." << endl;
        }
    }while(continueChoice);
    return 0;

}