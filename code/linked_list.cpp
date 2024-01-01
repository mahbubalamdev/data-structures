#include<iostream>
using namespace std;

class Node1{
    public:
        int data;
        Node1* next;
        Node1(int data){
            this->data = data;
            this->next = NULL;
        }
};

class SLL{
    public:
        Node1* head;
        SLL(){
            this->head = NULL;
        }
        void add(int d){
            if (this->head == NULL){
                this->head = new Node1(data);
            }
        }
}
int main(){

    
    return 0;
}