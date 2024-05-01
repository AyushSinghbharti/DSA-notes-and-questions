#include <iostream>
#include <vector>
using namespace std;

class Node { //Prefer to use class because of its optimized behaviours like inheritance, copy properties etc....
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    //Another construct if we only want to pass header 
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int> arr){ //Take time complexity of O(n)
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void traveseLL(Node* head){ //Take time complexity of O(n)
    Node* temp = head;
    while(temp){
        cout << temp->data << " " << temp->next << endl;
        temp = temp->next;
    }
    return;
}

int lengthOfLL(Node* head){ //Take time complexity of O(n)
    Node* temp = head;
    int length = 0;
    while(temp){
        temp = temp->next;
        length++;
    }
    return length;
}

int searchElement(Node* head, int value){
    Node* temp = head;
    int index = 0;
    while(temp){
        if(temp->data == value) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}


int main() {
    vector<int> arr = {12, 89, 95, 46, 50};
    Node* y = new Node(arr[0], nullptr); //Accessing address of Node header
    Node z = Node(arr[1], nullptr); //Accessing data of Node header
    cout << y->data << ":" << y->next << endl; //Method to access data from address
    cout << z.data << ":" << z.next << endl; //Method to access data directly
    Node* head = convertArrayToLL(arr); //Converting array to pointer
    cout << head->data << endl;
    traveseLL(head);
    int length = lengthOfLL(head);
    cout << length << endl;
    int index = searchElement(head, 95);
    cout << index << endl;
    index = searchElement(head, 100);
    cout << index << endl;
}


//For Java we can write it in same manner but we doesn't have concept of pointers there so....
// class Node{
//     //They are by default by public
//     int data;
//     Node next;

//     Node(int data1, Node next1){
//         this.data = data1;
//         this.next = next1;
//     }
    
//     Node(int data){
//         this.data = data1;
//         this.next = null;
//     }
// }

