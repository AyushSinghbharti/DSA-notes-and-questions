//Topic covered
// Insertion and deletion in linked list

#include <bits/stdc++.h>
using namespace std;

//Initializing and converting the linked list
class Node{
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

Node* convertArrtoLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
        // mover = temp;
    }
    return head;
}

void traveseLL(Node* head){ //Take time complexity of O(n)
    Node* temp = head;
    while(temp){
        cout << temp->data << " " << temp->next << endl;
        temp = temp->next;
    }
    cout << endl;
    return;
}


//Deletetion in Linked List
Node* deleteHeadOfLL(Node* head){
    if(head == NULL) return head;
    Node* temp = head; //Use to remove that space occupied by head
    head = head->next;
    free(temp); //We can also write delete temp //In java we don't have to do it manually and done with garbage collector
    return head;
}

Node* deleteTailofLL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteKthelementofLL(Node* head, int k){
    if(head == NULL) return NULL;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int index = 0;
    Node* temp = head;
    Node* prev;
    
    while(temp != NULL){
        index++;
        if(index == k){
            // delete prev->next;
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\nindex is invalid\n";
    return head;
}

Node* deleteValueinLL(Node* head, int k){
    if(head == NULL) return NULL;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int index = 0;
    Node* temp = head;
    Node* prev;
    
    while(temp != NULL){
        index++;
        if(temp->data == k){
            // delete prev->next;
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\value is invalid\n";
    return head;
}


//Insertion in linkedlist
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val){
    Node* temp = new Node(val);
    Node* mover = head;
    while(mover->next){
        mover = mover->next;
    }
    mover->next = temp;
    mover = temp;
    return head;
}

Node* insertk(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1) return new Node(val);
        else NULL;
    }
    if(k == 0) return insertHead(head, val);
    Node* mover = head;
    Node* temp = new Node(val);
    int index = 0;
    while(mover){
        index++;
        if(index == k){
            temp->next = mover->next;
            mover->next = temp;
            return head;
        }
        mover = mover->next;
    }
    cout << "Value index invalid\n";
    return head;

}

//Insert value before value x
Node* insertBeforeX(Node* head, int val, int x){
    if(head == NULL){
        return NULL;
    }
    if(head->data == x) return new Node(val, head);

    Node* temp = head;
    while(temp->next){
        if(temp->next->data == x){
            Node* noder = new Node(val, temp->next);
            temp->next = noder;
            return head;
        }
        temp = temp->next;
    }
    cout << "value not found";
    return head;
    
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArrtoLL(arr);
    traveseLL(head);
    head = deleteHeadOfLL(head);
    traveseLL(head);
    head = deleteTailofLL(head);
    traveseLL(head);
    head = deleteKthelementofLL(head, 4);
    head = deleteValueinLL(head, 3);
    traveseLL(head);
    head = insertHead(head, 12);
    traveseLL(head);
    head = insertTail(head, 25);
    traveseLL(head);
    head = insertk(head, 13, 3);
    traveseLL(head);
    head = insertk(head, 25, 0);
    traveseLL(head);
    head = insertBeforeX(head, 36, 13);
    traveseLL(head);
    head = insertBeforeX(head, 18, 4);
    traveseLL(head);
    return 0;
}