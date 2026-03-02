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
