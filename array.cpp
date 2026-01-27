//Take the numbers as input and print the double of these numbers
#include <iostream>
using namespace std;
int main() {
    int arr[10];
    cout<<"Enter tthe values you have to add in the array : "
    for(int i=0;i<10;i++){
        cout<<"Enetr the "<<i+1<<" Element "<<endl;
        cin>>arr[i];
    }
    cout<<"The double of the input is : "<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i]*2<<" ";
    }
    return 0;
}
//Do Linear search nd tell weather the numberr is preset or not.
#include<iostream>
using namespace std;
bool find(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i==k]){
            return true;
            break;
        }
    }
    return false;
}
int main(){
    int arr[10];
    int n,k;
    cout<<"Enter the size of the array less than 10: ";
    cin>>n;
    cout<<"Enter the element to find in array : ";
    cin>>k;
    cout<<"Ener the elements in the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(find(arr,n,k)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}
//Find 0 and 1 in the arrray 
#include<iostream>
using namespace std;
void find(int arr[],int size){
    int countzero =0;
    int countone =0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            countzero ++;
        }
        else if(arr[i]==1){
            countone ++;
        }
        else{
            continue;
        }
    }
    if(countone >0 || countzero >0){
        cout<<"The number of Zero are : "<<countzero<<endl;
        cout<<"The numbeer of one are : "<<countone<<endl;
    }
    else{
        cout<<"No zeros and one present ";
    }
}
int main(){
    int arr[10];
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements in the arrray : "<<endl;
    for(int i=0;i<size;i++){
    cin>>arr[i];
    }
    find(arr,size);
    return 0;
}
//maximum number in the array
#include<iostream>
#include<climits>
using namespace std;
int max(int arr[],int size){
        int max=INT_MIN;
        for(int i=0;i<size;i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
    }
int main(){
    int arr[10];
    int size;
    cout<<"Enter the size of the arrray :"<<endl;
    cin>>size;
    cout<<"enter the elements in the array : "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The max of the given numbers is "<<max(arr,size);
    return 0;
}

//most imp patters think to reduce the repeteded calculations

//leetcode 2574. Left and Right Sum Differences (Easy)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int s = nums.size();
        vector<int>left_sum(s);
        vector<int>right_sum(s);
        vector<int>ans(s,0);
        if(s == 1){
            return ans;
        }
        //everytime the leftmost element will have 0 sum on left side and rightmost element will have 0 sum on right side
        left_sum[0] = 0;
        right_sum[s-1] = 0;

        //prefix sum for left sum array and suffix sum for right sum array
        //left element left some as it is not present in the in its own sum + that element value
        for(int i = 1;i<s;i++){
            left_sum[i] = left_sum[i-1] + nums[i-1];
        }
        //right element right sum as it is not present in its own sum + that element value
        for(int j = s-2;j>=0;j--){
            right_sum[j] = right_sum[j+1] + nums[j+1];
        }
        //final ans array will be abs diff of left sum and right sum
        for(int k = 0;k<s;k++){
            ans[k] = abs(left_sum[k] - right_sum[k]);
        }

        return ans;
    }
};

//leetcode 1365. How Many Numbers Are Smaller Than the Current Number (Easy)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>freq(101,0);
        //count the number of all elements
        for(auto x :nums){
            freq[x]++;
        }

        //as we are gooing from smaller to larger value we will add all the number counts which occur before them
        int running = 0;
        for(int i =0;i<101;i++){
            int count = freq[i];
            freq[i] = running;
            running = running+count;
        }

        for(int i =0;i<nums.size();i++){
            nums[i] = freq[nums[i]];
        }

        return nums;
    }
};

//kadane algorithmn LeetCode 53 Max imum Subarray (Medium)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};

//if asked give that subarray also
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        //to store the starting and ending index of the maximum subarray
        int start =0;
        int end =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            //whenver we are getting the maximum sum we will update the ending index to current index
            if(sum>maxi){
                maxi=sum;
                end = i;
            }
            //whenever we are getting the zero means we are starting fresh subarray from next index
            if(sum<0){
                sum=0;
                start = i+1;
            }
        }
        return maxi;
    }
};

