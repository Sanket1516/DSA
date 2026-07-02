// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& st , int pos,int& ans){
    //BC
    if(pos == 1){
        ans = st.top(); //for delete just use the pop() function here just chnage these line //Maximum question follows same logic just change the base condition
        return;
    }
    
    int temp = st.top();
    st.pop();
    solve(st,pos-1,ans);
    //BT
    st.push(temp);
}

int main() {
    stack<int>st;
    
    for(int i =1;i<10;i++){
        st.push(i*10);
    }
    
    int pos = 0;
    if(st.size()%2==0){
        pos = st.size()/2;
    }
    else{
        pos = (st.size()/2)+1;
    }
    
    int ans = -1;
    solve(st,pos,ans);
    cout<<ans;
    return 0;
}

class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int>& s,int pos){
        if(pos == 1){
            s.pop();
            return;
        }
        
        int temp = s.top();
        s.pop();
        pos --;
        solve(s,pos);
        s.push(temp);
    }
    
    void deleteMid(stack<int>& s) {
        if(s.size()==1){
            s.pop();
        }

        else{
            int pos = 0;
            if(s.size()%2==0){
                pos = ((s.size()/2)+1); //mentioned in que
            }
            else{
                pos = ((s.size()/2)+1); //mentioned in que
            }
            solve(s,pos);
        }
    }
};

//To insert at bottom of stack
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& st , int pos,int& val){
    //BC
    if(pos == 0){
        st.push(val);
        return;
    }
    
    int temp = st.top();
    st.pop();
    solve(st,pos-1,val);
    //BT
    st.push(temp);
}

int main() {
    stack<int>st;
    for(int i =1 ;i<9;i++){
        st.push(10*i);
    }
    cout<<st.size()<<endl;
    int pos = st.size();
    int val = 0;
    solve(st,pos,val);
    cout<<st.size()<<endl;
    return 0;
}

//2nd there is no need of the pos 
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& st,int& val){
    //BC
    if(st.empty()){
        st.push(val);
        return;
    }
    
    int temp = st.top();
    st.pop();
    solve(st,val);
    //BT
    st.push(temp);
}

int main() {
    stack<int>st;
    for(int i =1 ;i<9;i++){
        st.push(10*i);
    }
    cout<<st.size()<<endl;
    int val = 0;
    solve(st,val);
    cout<<st.size()<<endl;
    return 0;
}


//Reverse a stack without using any extra space
#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int>& st,int& val){
    //BC
    if(st.empty()){
        st.push(val);
        return;
    }
    
    int temp = st.top();
    st.pop();
    solve(st,val);
    //BT
    st.push(temp);
}

void reverse_stack(stack<int>& st){
    //BC
    if(st.empty()){
        return;
    }
    
    int temp = st.top();
    st.pop();
    //empty stack 
    reverse_stack(st);
    //BT
    //and add that element at the bottom of the stack which has beeen pooped
    solve(st,temp); 
}


int main() {
    stack<int>st;
    for(int i =1 ;i<9;i++){
        st.push(10*i);
    }
    
    reverse_stack(st);
    
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}

//Add a element in a sorted stack without using any extra space
//Sort a stack

//Imliment 2 stcak using single array

class Stack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2-top1>1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
            return;
        }

    void push2(int data){
        if(top2-top1>1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
            return;
        }
    }

    void pop1(){
        if(top1>=0){
            top1--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
            return;
        }
    }

    void pop2(){
        if(top2<size){
            top2++;
        }
        else{
            cout<<"Stack Underflow"<<endl;
            return;
        }
    }

    void print(){
        int i =0;
        while(i<size){
            cout<<arr[i]<<" ";
            i++;
        }
    }

    int main(){
        Stack st(10);
        st.push1(10);
        st.push1(20);
        st.push1(30);
        st.push2(100);
        st.push2(200);
        st.push2(300);

        st.print();

        return 0;

}


//Valid Parenthesis IMP
class Solution {
public: 
    bool isValid(string s) {
        stack<char> st;

        for(auto ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
        }
        else{
        //As we are assecing top we have to take care about that we are not having a empty stack as if we are trying to access top of empty stack it will give us error so we have to check that stack is not empty 
        if(st.empty()){
            return false;
        }
        else{            
            if(ch == ')' && st.top() == '('){
                st.pop();
            }
            else if(ch == '}' && st.top() == '{'){
                st.pop();
            }
            else if(ch == ']' && st.top() == '['){
                st.pop();
            }
            //if there is no matching pair then return false if we agin push till end it will be of no use as we have already found the answer
            else{
                return false;
            }
        }
        }
        }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
};