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