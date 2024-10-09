#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class QueueImplimentaion{
    private:
    int front, rear, size;
    int* arr;

    
    public:
    // Constructor to initialize the queue
    QueueImplimentaion(int capacity) {
        front = -1;
        rear = -1;
        size = capacity;
        arr = new int[size];
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        front++;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
};

class QueueImplimentationUsingLL{
    private:
    Node* start = nullptr; Node* rear = nullptr;
    int size = 0;

    public:
    void enqueue(int x){
        if(!start && !rear ){
            rear = new Node(x);
            start = rear;
            size++;
            return;
        }
        Node* newNode = new Node(x);
        rear->next = newNode;
        rear = newNode;
        size++;
    }

    public:
    void dequeue(){
        if(!start) return;
        if(start == rear){
            start = nullptr; rear = nullptr;
            size--;
            return;
        }
        start = start -> next;
        return;
    }

    void getFront(){
        if(start) cout << start->data << endl;
        return;
    }

    void display(){
        Node* temp = start;
        while(temp){
            cout << temp->data;
            temp = temp->next;
        }
        cout << "\n";
        return;
    }
};

class QueueUsingStack {
    stack<int> s1;
    stack<int> s2;

    public:
        void enqueue(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        void dequeue(){
            cout << "Element is popped: " << s1.top() << endl;
            s1.pop();
            return;
        }

        int getTop(){
            return s1.top();
        }

        void display(){
            stack<int> temp = s1;
            while(!temp.empty()){
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
            return;
        }
};

int main(int argc, char const *argv[])
{
    QueueUsingStack q;
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.enqueue(5);
    q.display();
    return 0;
}
