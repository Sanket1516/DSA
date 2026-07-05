//reverse a queue
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>st;

        //using stack to reverse the queue
        
        while(!q.empty()){
            int ele = q.front();
            st.push(ele);
            q.pop();
        }
        
        while(!st.empty()){
            int ele = st.top();
            q.push(ele);
            st.pop();
        }
    }
};

//using recursion to reverse a queue
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        if(q.empty()){
            return;
        }
        
        int temp = q.front();
        q.pop();
        reverseQueue(q);
        q.push(temp);
    }
};

//reverse first k elements of a queue
class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {

        if (k > q.size())
            return q;

        int remaining = q.size() - k;
        stack<int> st;

        while (k--) {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        while (remaining--) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

 //interleave the first half of the queue with second half
 class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int>q2;
        
        int mid = q.size()/2;
        
        int curr = mid;

        //Store a first half of the queue in a temporary queue
        while(curr!=0){
            int val = q.front();
            q2.push(val);
            q.pop();
            curr--;
        }
        
        //then interleave the elements of the two queues
        while(!q2.empty()){
            int first = q2.front();
            q2.pop();
            int second = q.front();
            q.pop();
            q.push(first);
            q.push(second);
        }
        
        //if the list is odd then at left there would be one element left 
        if(q2.size()==1){
            int item = q2.front();
            q2.pop();
            q.push(item);
        }
    }
};

//MOSt imp queue question with slideing window technique 
//Just look it every time
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int>q;
        vector<int>ans;
        int n = arr.size();
        for(int i =0;i<k;i++){
            if(arr[i]<0){
                q.push(i);
            }
        }
        
        for(int i = k;i<n;i++){
            //Print 
            
            if(q.empty()){
                ans.push_back(0);
            }
            
            else{
                ans.push_back(arr[q.front()]);
            }
            
            //Remove the unwanted elements in queue
            while(!q.empty() && i-q.front()>=k){
                q.pop();
            }
            
            //Check for insertion
            if(arr[i]<0){
                q.push(i);
            }
            
        }
        
        //As we are adding first then checking the last window is still remained to add
            if(q.empty()){
                ans.push_back(0);
            }
            
            else{
                ans.push_back(arr[q.front()]);
            }
            
            return ans;
    }
};

//FIrst non repeating character
class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int freq[26] = {0};
        queue<char>q;
        string ans="";
        
        for(int i =0;i<s.length();i++){
            
            //Inc the frequency of the character and push it into the queue
            freq[s[i]-'a'] ++;
            
            q.push(s[i]);
            
            //as we want always and printing the first non repeating character so we will check the front of the queue and if it is repeating then we will pop it out and check for the next element in the queue
            while(!q.empty()){
                //if first element in a queue is repeating then we will pop it out and check for the next element in the queue
                if(freq[q.front()-'a'] > 1){
                    q.pop();
                }
                
                //the elemnt in front of queue is the non repaeting
                else{
                    ans+=q.front();
                    break;
                }
            }
            
            //if we move out of the loop and we get that there was not a single element who was unique then we will add # in the answer as mentioned in the question
            if(q.empty()){
                ans+="#";
            }
        }
        
        return ans;
    }
};

//Maximum element in a window leetcode 239 (Hard) using deque
//Most imp look every time as it is used in many questions
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        for(int i =0;i<k;i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i] ){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);


        for(int i =k;i<nums.size();i++){
            //Only these case where we are removing out off window elements
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

//Gas station leetcode 134 (Medium) tell all theree approaches
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int balance = 0;
        int depriciate = 0;

        for(int i =0;i<gas.size();i++){
            balance += gas[i]-cost[i];
            if(balance<0){
                depriciate += balance;
                start = i+1;
                balance = 0;
            }
        }
        if(balance+depriciate>=0){
            return start;
        }
        else{
            return -1;
        }
    }
};