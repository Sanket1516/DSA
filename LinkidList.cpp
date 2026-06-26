
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

//LEETCODE 876 Middle Node of Linked List
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

int sizeo(ListNode* head){
    int count = 0;
    ListNode* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void findMiddle(ListNode*& head,int middle){
    ListNode* temp = head;
    while(middle!=0){
        temp = temp->next;
        middle --;
    }
    head = temp;
}

public:
    ListNode* middleNode(ListNode* head) {
        int len = sizeo(head);
        int middle = (len/2);
        findMiddle(head,middle);
        return head;
    }
};

//Using slow and fast pointer approach
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
    ListNode* middleNode(ListNode* head) {
        //First Both slow and fast pointer will point to head
        ListNode* slow = head;
        ListNode* fast = head;

        //We will loop till fast pointer is not NULL
        while(fast!=NULL){
            //Move fast one step
            fast = fast->next;
            //then chek weathe rthe fast can move one more step or not if yes then move slow one step and fast one step
            if(fast!= NULL){
                fast = fast -> next;
                slow = slow->next;
            }
        }
        return slow;
    }
};

//Find Palindrome in Linked List Leetcode 234
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
    ListNode* middle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }  
    
    void reverse(ListNode*& head2){
        ListNode* curr = head2;
        ListNode* prev = NULL;
        while(curr!=NULL){
        ListNode* nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        }
        head2 = prev;
    }

    bool compareList(ListNode* head1,ListNode* head2){
        while(head1 != NULL && head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            else{
                head1 = head1->next;
                head2 = head2->next; 
            }
    }
    return true;
}
    bool isPalindrome(ListNode* head) {
        //Find middle
        ListNode* middlelist = middle(head);

        //Break in two parts
        ListNode* head2 = middlelist->next;
        middlelist->next = NULL;


        //Reverse Second 
        reverse(head2);
        //compare 
       return compareList(head,head2);
    }
};

//Find the Cycle in a LL LEETCODE 141

//Using MAPS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map <ListNode*,bool> table;
        ListNode* temp = head;
        while(temp!=NULL){
            if(table[temp]==false){
                table[temp] = true;
            }
            else{
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

//Using the fast and slow pointer approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

//linkid list cycle 2 Leetcode 142
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }

            if(fast == slow){
                break;
            }
        }

        //If no Cycle is present then return NULL
        if(fast == NULL){
            return NULL;
        }

        //If Cycle is present then move slow to head and move both slow and fast one step at a time till they meet
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

//letcode add two linked list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummy = new ListNode(0);

        ListNode* temp3 = dummy;

        int carry = 0;
        while(temp1!=NULL || temp2!=NULL){
            int sum = carry;

            if(temp1!=NULL){
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if(temp2!=NULL){
                sum +=temp2->val;
                temp2 = temp2->next;
            }

            carry = sum/10;
            sum = sum%10;

            ListNode* newnode = new ListNode(sum);
            temp3->next = newnode;
            temp3 = newnode;
        }

        return dummy->next;

    }
};