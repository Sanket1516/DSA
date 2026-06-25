
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

    int Size(Node* head){
        int count = 0;
        Node*temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    } ; 
    
    void printList(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void insertAtStart(Node*& head,int data){
        Node* temp = head;
        Node* newNode = new Node(data);
        
        if(temp == NULL){
            head = newNode;
        }
        
        else{
        newNode->next = head;
        head = newNode;
        }
    }
    
    void insertAtTail(Node*& head,int data){
        Node* temp = head;
        Node* newNode = new Node(data);
        
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        newNode->next = NULL;
        temp->next = newNode;
    }
    
    void insertAfter(Node*& head,int data, int value){
        Node* newNode = new Node(data);
        Node* temp = head;
        
        while(temp->data != value){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void findTail(Node* head,Node* &tail){
        Node* temp = head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        tail = temp;
    }

    void insertAtPosition(Node*& head,int pos,int data){
        //Case 1 : if pos is < 1 or = 1 then insert at head
        if(pos<=1){
            insertAtStart(head,data);
            return;
        }
        //Case 2 : if pos is > length + 1 or equal to = length+1
        else if(pos>Size(head)){
            insertAtTail(head,data);
            return;
        }

        else{
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;

            // while(pos != 1){
            //     prev = curr;
            //     curr = curr->next;
            //     pos--;
            // }

            // prev->next = newNode;
            // newNode->next = curr;

            //Without using two pointers only using prev
            prev=head;
            while(pos != 2){
                prev = prev->next;
                pos--;
            }  
            newNode->next = prev->next;   
            prev->next = newNode;
        }
    }
    
        
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    

    //Now use these functions no need to initialize the nodes like these
    Node* First = new Node(10);
    Node* Second = new Node(20);
    Node* Third = new Node(30);
    Node* Fourth = new Node(40);
    Node* Fifth = new Node(50);
    
    First->next = Second;
    Second->next = Third;
    Third->next = Fourth;
    Fourth->next = Fifth;
    //Till these

    
    head = First;

    
    findTail(head,tail);
    
    cout<<tail->data<<endl;

    printList(head);
    Size(head);
    insertAtStart(head,5);
    printList(head);
    insertAtTail(head,60);
    printList(head);
    insertAfter(head,25,20);
    printList(head);
    insertAtPosition(head,55,-55);
    printList(head);
    return 0;
}



//Same But with Deleteion

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

    int Size(Node* head){
        int count = 0;
        Node*temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    } ; 
    
    void printList(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void insertAtStart(Node*& head,int data){
        Node* temp = head;
        Node* newNode = new Node(data);
        
        if(temp == NULL){
            head = newNode;
        }
        
        else{
        newNode->next = head;
        head = newNode;
        }
    }
    
    void insertAtTail(Node*& head,int data){
        Node* temp = head;
        Node* newNode = new Node(data);
        
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        newNode->next = NULL;
        temp->next = newNode;
    }
    
    void insertAfter(Node*& head,int data, int value){
        Node* newNode = new Node(data);
        Node* temp = head;
        
        while(temp->data != value){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void findTail(Node* head,Node* &tail){
        Node* temp = head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        tail = temp;
    }

    void insertAtPosition(Node*& head,int pos,int data){
        //Case 1 : if pos is < 1 or = 1 then insert at head
        if(pos<=1){
            insertAtStart(head,data);
        }
        //Case 2 : if pos is > length + 1 or equal to = length+1
        else if(pos>Size(head)){
            insertAtTail(head,data);
        }

        else{
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;

            // while(pos != 1){
            //     prev = curr;
            //     curr = curr->next;
            //     pos--;
            // }

            // prev->next = newNode;
            // newNode->next = curr;

            //Without using two pointers only using prev
            prev=head;
            while(pos != 2){
                prev = prev->next;
                pos--;
            }  
            newNode->next = prev->next;   
            prev->next = newNode;
        }
    }
    
    void deletefromHead(Node*& head,Node* tail){
        if(head == NULL){
            return ;
        }
        
        if(head == tail){
            delete tail;
            head = NULL;
            return;
        }
        
        else{
        Node* temp = head;
        head = head->next;
        delete temp;
        }
    }
    
     void posBeforeTail(Node*& prev,Node* head){
         Node* temp = head;
         while(temp->next->next != NULL){
             temp = temp->next;
         }
         prev = temp;
     }
    
    void deletefromTail(Node*& head,Node*& tail){
        if(head == NULL){
            return ;
        }
        
        if(head == tail){
            delete tail;
            head = NULL;
            return;
        }        
        
        else{
        Node* removeNode = tail;
        Node* prev = NULL;
        posBeforeTail(prev,head);
        tail = prev;
        tail->next = NULL;
        delete removeNode;
        }
    }
    
    void deletefromMiddle(Node*& head,int pos,Node*& tail){
        
        if(head == NULL){
            return ;
        }
        
        if(head == tail){
            delete tail;
            head = NULL;
            return;
        }        
                
        
        else{

        if(pos == 1){
            deletefromHead(head,tail);
            return;
        }

        else if(pos == Size(head)){
            deletefromTail(head,tail);
            return;
        }

        else{
        
        Node* curr = head;
        Node* prev = NULL;
        while(pos!=1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        delete curr;
        }
        }
    }
    
        
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    // Node* First = new Node(10);
    // Node* Second = new Node(20);
    // Node* Third = new Node(30);
    // Node* Fourth = new Node(40);
    // Node* Fifth = new Node(50);
    
    // First->next = Second;
    // Second->next = Third;
    // Third->next = Fourth;
    // Fourth->next = Fifth;
    
    
    insertAtStart(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);

    
    findTail(head,tail);


    // printList(head);
    // Size(head);
    // insertAtStart(head,5);
    // printList(head);
    // insertAtTail(head,60);
    // printList(head);
    // insertAfter(head,25,20);
    // printList(head);
    // insertAtPosition(head,55,-55);
    // printList(head);
    // deletefromHead(head);
    printList(head);
    // deletefromHead(head);
    // printList(head);
    // deletefromHead(head);
    // printList(head);
    // deletefromTail(head,tail);
    // printList(head);
    deletefromMiddle(head,4,tail);
    printList(head);
    return 0;
}

//Doubly Linked List

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(){
            this->prev = NULL;
            this->next = NULL;
        }

        Node(int data){
            this->prev = NULL;
            this->next = NULL;
            this->data = data;
        }
};

int LLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}

void Print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node*& head, Node*& tail , int pos,int data){
    Node* temp = head;
    Node* newNode = new Node(data);
    newNode->next = temp;
    temp->prev = newNode;
    head = newNode;
}

void insertAtTail(Node*& head,Node*& tail , int pos,int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(Node*& head, Node*& tail , int pos,int data){
    //List Empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //List Full
    else{
        if(pos == 1){
            insertAtHead(head,tail,pos,data);
            return;
        }

        else if(pos == LLength(head)+1){
            insertAtTail(head,tail,pos,data);
            return;
        }
        else{
            Node* newNode = new Node(data);
            Node* prev = NULL;
            Node* curr = head;

            while(pos != 1){
                prev = curr;
                curr = curr->next;
                pos--;
            }

            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = curr;
            curr->prev = newNode;
            return;
        }
    }
}

//Insertion in doubly Linked List
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtPos(head,tail,1,20);
    Print(head);

    insertAtPos(head,tail,1,10);
    Print(head);  

    insertAtPos(head,tail,1,5);
    Print(head);  
    
    insertAtPos(head,tail,3,15);
    
    Print(head); 
    
    insertAtPos(head,tail,5,100);
    
    Print(head);     

    return 0;
}

//Leetcode Problem 206: Reverse Linked List
//using iterative approach


//reverse a list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* forward = curr;
            curr->next = prev;
            prev = curr;
            curr = forward->next;
        }

        head = prev;

        return head;
    }
};

//Using Recursion
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



class Solution {
public:

    void reverse(ListNode* current,ListNode* prev,ListNode*& head){
        if(current == NULL){
            head = prev;
            return;
        }

        ListNode* nextptr = current->next;
        current->next = prev;
        reverse(nextptr,current,head);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        reverse(current,prev,head);
        return head;
    }
};