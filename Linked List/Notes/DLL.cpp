#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArrtoDll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printDll(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    return;
}

void printFromBack(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->prev;
    }
    return;
}

// Deletion of DLL
// Head
Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    // Using LL method
    //  Node* temp = head;
    //  while(temp->next->next){
    //      temp = temp->next;
    //  }
    //  Node* move = temp->next;
    //  temp->next->prev = NULL;
    //  temp->next = NULL;
    //  free(move);
    //  return head;

    // Using prev method
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    Node *temp = tail->prev;
    temp->next = NULL;
    tail->prev = NULL;
    free(tail);
    return head;
}

Node *deleteIndex(Node *head, int index)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == index)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;
    if (prevNode == NULL && nextNode == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (prevNode == NULL)
        return deleteHead(head);
    else if (nextNode == NULL)
        return deleteTail(head);
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete temp;
    return head;
}

void deleteNode(Node *node)
{
    Node *front = node->next;
    Node *back = node->prev;

    if (front == NULL)
    {
        back->next = nullptr;
        node->prev = nullptr;
        free(node);
        return;
    }

    back->next = front;
    front->prev = back;
    node->next = node->prev = nullptr;
    delete node;
    return;
}

// Insersion of Node:
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head, nullptr);
    head->prev = temp;
    return temp;
}

Node *insertTail(Node *head, int val)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(val, nullptr, temp);
    temp->next = newNode;
    return head;
}

Node *insertIndex(Node *head, int index, int val)
{
    if (index == 0)
        return insertHead(head, val);
    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == index)
        {
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            return head;
        }
        temp = temp->next;
    }
    if(cnt+1 == index) return insertTail(head, val);
    cout << "invalid index: " << endl;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrtoDll(arr);
    // printDll(head);
    // printFromBack(head);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteIndex(head, 3);
    // deleteNode(head->next);
    // head = insertTail(head, 10);
    // head = insertIndex(head, 2, 20);
    // for (int i = 0; i <= 6; i++)
    // {
    //     cout << "index:" << i << ": ";
    //     vector<int> arr = {1, 2, 3, 4, 5};
    //     Node *head = convertArrtoDll(arr);
    //     head = insertIndex(head, i, 20);
    //     printDll(head);
    // }
    
    printDll(head);
    printFromBack(head);

    return 0;
}