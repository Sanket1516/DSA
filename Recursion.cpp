//Fibonacii Series 
//Two Approaches 1st recursion TC(O(2^n))
#include <iostream>
using namespace std;

int fib(int n){
    //Base Case
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    
    //recursive relation
    int first_term = fib(n-1);
    int second_term = fib(n-2);

    //Processing
    int ans = first_term + second_term;
    return ans;
}

int main() {
    int n = 0;
    cin>>n;
    int ans = fib(n);
    cout<< ans;
    return 0;
}

//Using Loop TC(O(n))
class Solution {
public:
    int fib(int n) {
     std::vector<int> fibo{0,1};
     for(int i = 2; i <= n; i++){
        fibo.push_back(fibo[i-1] + fibo[i-2]);
     }
     return fibo[n];
    };
};

//Binary serach using recurssion 


int binarySearch(int *arr, int s, int e, int k){

    //base case
    //element not found
    if(s>e){
        return -1;
    }

    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k){
        return mid;
    }

    if(arr[mid] > k){
        return binarySearch(arr, s, mid-1, k);
    }
    else{
        return binarySearch(arr, mid+1, e, k);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = binarySearch(arr, 0, n-1, k);
    if(ans != -1){
        cout<<"Element found at index: "<<ans<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }
}

//cheeck if array is sorted or not using recursion
bool isSorted(int *arr, int n){
    //base case
    if(n==0 || n==1){
        return true;
    }

    //processing
    if(arr[0]>arr[1]){
        return false;
    }

    //Recursive call
    bool ans = isSorted(arr+1, n-1);
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    bool ans = isSorted(arr, n);
    if(ans){
        cout<<"Array is sorted."<<endl;
    }
    else{
        cout<<"Array is not sorted."<<endl;
    }
}


//Inclusion Exclusion principle
//Number of subsequences in a string
void subsequences(strng s,string output,int index){
    //base case
    if(index>=s.length()){
        cout<<output<<endl;
        return;
    }

    char ch = s[index];

    //exclude
    subsequences(s, output, index+1);

    //include
    output.push_back(ch);
    subsequences(s,output, index+1);

    //if we want to incldue first and then exclude then we can also do that
    //just change the order of the recursive calls
    //remove the included element for the next calls
     //include the element at the index
    //  char ch = s[index];
    // output.push_back(ch);
    // subsequences(s,output, index+1);

    // //exclude the element at the index
    // output.pop_back();
    // subsequences(s, output, index+1);
}
int main(){
    string s;
    cin>>s;
    string output = "";
    subsequences(s, output, 0);
    return 0;
}


//What if w ehave to store the subsequences in an array instead of printing them
void subsequences(strng s,string output,int index, vector<string> &ans){
    //base case
    if(index>=s.length()){
        ans.push_back(output);
        return;
    }

    char ch = s[index];

    //exclude
    subsequences(s, output, index+1, ans);

    //include
    output.push_back(ch);
    subsequences(s, output, index+1, ans);
}
int main(){
    string s;
    cin>>s;
    string output = "";
    vector<string> ans;
    subsequences(s, output, 0, ans);
    //printing the subsequences stored in the ans vector
    for(string str : ans){
        cout<<str<<endl;
    }
    return 0;
}

//Pattern 2 explore all possible ways or path
//Que 1 Maximize the number of segments of length x, y and z
int maximizeSegments(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
    }

    int ans = INT_MIN;
    int option1 = maximizeSegments(n-x, x, y, z);
    int option2 = maximizeSegments(n-y, x, y, z);
    int option3 = maximizeSegments(n-z, x, y, z);

    int ans = max(option1, max(option2, option3));

    retrun ans;
}
int main(){
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    int ans = maximizeSegments(n, x, y, z);
    if(ans == INT_MIN){
        cout<<"Not possible to cut the rope into segments of given lengths."<<endl;
    }
    else{
        cout<<"Maximum number of segments: "<<ans<<endl;
    }
    return 0;
}

//Que 2 Leetcode 322 Coin Change Not solved yet can be solved using dp
class Solution {
public:
    static int solve(vector<int>& coins, int amount) {
        // Base Case
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        int to_return_ans = INT_MAX;
        // processing
        for (int i = 0; i < coins.size(); i++) {
            int coin_value = coins[i];

            if (coin_value <= amount) {
                int final_ans = solve(coins, amount - coin_value);
                if (final_ans != INT_MAX) {
                    int ans = 1 + final_ans;
                    to_return_ans = min(to_return_ans, ans);
                }
            }
        }
        return to_return_ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};

//Que 3 Leetcode 198 House Robber Not solved yet can be solved using dp
class Solution {
public:
    static int solve(vector<int>& nums,int size,int index){
        
        if(index >= size){
            return 0;
        }

        //we rob first house
        int ans1 = nums[index] + solve(nums,size,index+2);

        //we not first house
        int ans2 = 0 + solve(nums,size,index+1);

        return max(ans1,ans2); 
    }
    int rob(vector<int>& nums) {
     //to call reccursion we need three values arr of nums , size , index 
     // so we will call new function and get value from there
     int size = nums.size();
     int index = 0;
     int ans = solve(nums,size,index);
     return ans;   
    }
};




//Rat Maze Problem with back tracking

#include<iostream>
#include<vector>
using namespace std;



bool isSafe(int posx,int posy,int row,int col,vector<vector<bool>>&visited,int maze[][4]){
    if(
        (posx>=0 && posx<row) && (posy>=0 && posy < col) &&
        (visited[posx][posy] == false) &&
        (maze[posx][posy] == 1) 
    ){
        return true;
    }

    return false;
}


void allpossiblepaths(int maze[][4],int sorceposx,int sorceposy,vector<vector<bool>>&visited,int row,int col,string path){


    //Base case
    if(sorceposx == row-1 && sorceposy == col-1){
        cout<<path<<endl;
        return;
    }

int newx=0;
int newy=0;
//Up
newx = sorceposx-1;
newy = sorceposy;

if(isSafe(newx,newy,row,col,visited,maze)){
visited[newx][newy] = true;
path.push_back('U');
//Reccursive relation
allpossiblepaths(maze,newx,newy,visited,row,col,path);
//Backtracking
visited[newx][newy] = false;
path.pop_back();
}



//Down
newx = sorceposx+1;
newy = sorceposy;

if(isSafe(newx,newy,row,col,visited,maze)){
visited[newx][newy] = true;
path.push_back('D');
//Reccursive relation
allpossiblepaths(maze,newx,newy,visited,row,col,path);
//Backtracking
visited[newx][newy] = false;
path.pop_back();
}

//Left 
newx = sorceposx;
newy = sorceposy-1;

if(isSafe(newx,newy,row,col,visited,maze)){
visited[newx][newy] = true;
path.push_back('L');
//Reccursive relation
allpossiblepaths(maze,newx,newy,visited,row,col,path);
//Backtracking
visited[newx][newy] = false;
path.pop_back();
}

//Right
newx = sorceposx;
newy = sorceposy+1;

if(isSafe(newx,newy,row,col,visited,maze)){
visited[newx][newy] = true;
path.push_back('R');
//Reccursive relation
allpossiblepaths(maze,newx,newy,visited,row,col,path);
//Backtracking
visited[newx][newy] = false;
path.pop_back();
}
}


int main(){
    int maze [][4] = {
        {1,1,1,1},
        {1,1,1,1},
        {0,1,0,1},
        {1,1,0,1}
    };

    int row = 4;
    int col = 4;

    vector<vector<bool>>viseted(4,vector<bool>(4,false));

    int sorceposx = 0;
    int sorceposy = 0;

    string path = "";

    viseted[sorceposx][sorceposy]=true;
    allpossiblepaths(maze,sorceposx,sorceposy,viseted,row,col,path);
}

//count Total Diarrangement
class Solution {
  public:
    int solve(int n){
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        
        return (n - 1) * (solve(n - 1) + solve(n - 2));
    }  
  
    int derangeCount(int n) {
        return solve(n);
    }
};


//Color Fencing 
class Solution {
  public:
    int solve(int n , int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return (k)+(k*(k-1));
        }
        
        return (k-1)*(solve(n-1,k)+solve(n-2,k));
    }
    int countWays(int n, int k) {
        return solve(n,k);
    }
};

//Maximum square leetcode 221
class Solution {
public:

    //BC When we reach out of the matrix then we will return 0 because we cannot form a square with out of bound index
    int solve(vector<vector<char>>& matrix,int i ,int j,int row,int col,int& ans){
        if(i>=row || j>=col){
            return 0;
        }

        //recursive relation
        //for right , diagonal and down we will call the solve function and get the value of the maximum square that can be formed from those positions
        //right
        int right = solve(matrix,i,j+1,row,col,ans);
        //diagonal
        int diagonal = solve(matrix,i+1,j+1,row,col,ans);
        //down 
        int down = solve(matrix,i+1,j,row,col,ans);

        //processing
        //if the current position is 1 then we can form a square of size 1 + minimum of right , diagonal and down because we can only form a square if all three positions are 1
        if(matrix[i][j]=='1'){
            int mini = 1+ min(right,min(down,diagonal));
            //store the maximum square that can be formed in the ans variable
            ans = max(ans,mini);
            return mini;
        }
        else{
            return 0;
        }
        return ans;
    }


    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0;
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        solve(matrix,i,j,row,col,ans);
        return ans*ans;
    }
};


//edit distance leetcode 72
class Solution {
public:

    int solve(int i , int j,string& word1,string& word2,int ans){
        if(i>=word1.length()){
            return word2.length()-j;
        }
        else if(j>=word2.length()){
            return word1.length()-i;
        }

        if(word1[i]==word2[j]){
        ans = 0+solve(i+1,j+1,word1,word2,ans);
        }
        
        else{
        int insert = 1+solve(i,j+1,word1,word2,ans);
        int del = 1+solve(i+1,j,word1,word2,ans);
        int update = 1+solve(i+1,j+1,word1,word2,ans);
        
        ans = min(insert,min(del,update));
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int sub = 0;
        int ans=solve(i , j , word1 , word2,sub);
        return ans;
    }
};