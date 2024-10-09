#include <bits/stdc++.h>
using namespace std;

class Node
{ // Prefer to use class because of its optimized behaviours like inheritance, copy properties etc....
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Another construct if we only want to pass header
public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class StackImpliment
{
private:
    int top = -1, st[10];

public:
    void push(int x)
    {
        if (top >= 9)
        {
            cout << "Stack full return" << endl;
            return;
        }
        top++;
        st[top] = x;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return st[top];
    }

    void pop()
    {
        if (top == -1)
            return;
        top--;
    }

    int size()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
        }
        return top + 1;
    }
};

class StackImplimentUsingLL
{
private:
    int size = 0;
    Node *top;

public:
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        if (!top)
        {
            cout << "Stack is empty";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete (temp);
        size--;
    }

    int checkSize()
    {
        return size;
    }

    int getTop()
    {
        return top->data;
    }
};

class StackUsingQueue{
    queue<int> q;

    public:
    void push(int x){
        int s = q.size();
        q.push(x);
        for(int i = 0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
        return;
    }

    void pop(){
        cout << "element is popped: " << q.front() << endl;
        q.pop();
    }

    int getTop(){
        return q.front();
    }

    void display(){
        queue<int> temp = q;
        int n = q.size();
        for(int i=0; i<n; i++){
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
        return;
    }
};

int main()
{
    // StackImplimentUsingLL s;
    StackUsingQueue s;
    s.push(5);
    s.display();
    s.push(10);
    s.display();
    s.push(15);
    s.display();
    s.push(20);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.push(25);
    s.display();
    return 0;
}