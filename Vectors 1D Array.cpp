//Unique element in the array
#include<iostream>
#include<vector>
using namespace std;
int findunique(vector<int>arr){
    int sum =0;
    for(int i=0;i<arr.size();i++){
        sum = sum^arr[i];
    }
    return sum;
}
int main(){
    int n;
    cout<<"enter the size of the array : "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    cout<<"The only element is : "<<findunique(arr);
    return 0;
}
//union of two arrays
#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int>arr{1,2,3,4,5,6,8};
    vector<int>brr{5,2,4,6,2,4,8};
    vector<int>crr;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<brr.size();j++){
            if(arr[i]==brr[j]){
                brr[j]=INT_MIN;
            }
        }
    }
    for(int i=0;i<arr.size();i++){
        crr.push_back(arr[i]);
    }
    for(int i=0;i<brr.size();i++){
        if(brr[i]!=INT_MIN){
        crr.push_back(brr[i]);
        }
    }
    for(int i=0;i<crr.size();i++){
        cout<<crr[i]<<" ";
    }
    return 0;
}
//intersection
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>arr{1,2,3,4,5,6,7};
    vector<int>brr{5,4,7,9,6,3,1};
    vector<int>crr;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<brr.size();j++){
            if(arr[i]==brr[j]){
                crr.push_back(arr[i]);
                break;
            }
        }
    }
    for(int i=0;i<crr.size();i++){
        cout<<crr[i]<<" ";
    }
    return 0;
}
//sum of two == sum from two array
#include <iostream>
#include<vector>
using namespace std;
int main(){
    int sum;
    cout<<"Enter the sum pair to be found : "<<endl;
    cin>>sum;
    vector<int>arr{1,2,3,4,5,6,7,8,9};
    vector<int>brr{1,2,3,5,6,3,4,6,8};
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<brr.size();j++){
            if((arr[i]+brr[j])==sum){
                cout<<"The pair is : "<<"("<<arr[i]<<" , "<<brr[j]<<")"<<endl;
                break;
            }
        }
    }
    return 0;
}
//From single array
#include <iostream>
#include<vector>
using namespace std;
int main(){
    int sum;
    cout<<"Enter the sum pair to be found : "<<endl;
    cin>>sum;
    vector<int>arr{1,2,3,4,5,6,7,8,9};
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]+arr[j])==sum){
                cout<<"The pair is : "<<"("<<arr[i]<<" , "<<arr[j]<<")"<<endl;
                break;
            }
        }
    }
    return 0;
}
//triplet sum
#include <iostream>
#include<vector>
using namespace std;
int main(){
    int sum;
    cout<<"Enter the sum pair to be found : "<<endl;
    cin>>sum;
    vector<int>arr{1,2,3,4,5,6,7,8,9};
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            for(int k=i+2;k<arr.size();k++){
            if((arr[i]+arr[j])+arr[k]==sum){
                cout<<"The pair is : "<<"("<<arr[i]<<" , "<<arr[j]<<" , "<<arr[k]<<")"<<endl;
                break;
            }
        }
    }
}
    return 0;
}
//Find repeating and mssing element in the array 
#include <iostream>
#include<vector>
using namespace std;
void two(vector<int>arr){
    int repeating=0;
    int missing=0;
    for(int i=0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i]==arr[j]){
                repeating = arr[i];
                break;
            }
        }
    }
    for(int i=1;i<=arr.size();i++){
        bool flag = false;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==i){
                flag = true;
                break;
            }
        }
        if(flag == false){
                missing = i;
      }
    }
cout<<"The missing element is : "<<missing<<endl;
cout<<"The repeated element is : "<<repeating<<endl;
}
int main()
{
    vector<int>arr{1,2,3,4,6,6,8,7};
    two(arr);
    return 0;
}
//Move all negative elements to the one side of a arry
#include <iostream>
#include <vector>
using namespace std;
void move (vector<int>arr){
    int start = 0;
    int end = arr.size()-1;
    while(start < end){
        if(arr[start]>0){
            start ++;
        }
        else{
            swap(arr[start],arr[end]);
            end --;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector <int> arr{1,-1,-2,5,-9,-7,4,5,7};
    move(arr);
    return 0;
}
//Find The repetative element in the array
#include <iostream>
#include<vector>
using namespace std;
void repetative (vector<int>arr,vector<int>brr){
    int repetative =0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j]){
                repetative = arr[i];
                brr.push_back(repetative);
                break;
            }
        }
    }
    cout<<"The repetative elements are : "<<endl;
   for(int i=0;i<brr.size();i++){
    cout<<brr[i]<<" ";
   }
}
int main()
{
    vector<int>arr{2,3,4,6,3,4,5};
    vector<int>brr;
    repetative(arr,brr);
    return 0;
}
//Finds the common element in the three array
#include <iostream>
#include<vector>
using namespace std;
void common (vector<int>arr,vector<int>brr,vector<int>crr){
    int repetative =0;
    vector<int>rep;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<brr.size();j++){
            for(int k=0;k<crr.size();k++){
                if(arr[i]==brr[j] && brr[j]==crr[k]){
                    repetative = arr[i];
                    rep.push_back(repetative);
                    break;
                }
            }
        }
    }
    cout<<"The repetative elements are : "<<endl;
    for(int i=0;i<rep.size();i++){
        cout<<rep[i]<<" ";
    }
}
int main()
{
    vector <int> arr{1,2,3,4,5,6,8,9};
    vector <int> brr{2,3,4,5,8,9,7,6};
    vector <int> crr{1,4,5,7,7,5,1,7};
    common(arr,brr,crr);
    return 0;
}
//Print Factorial Of the large numberr in the array
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int fact(int max){
    int sum =1;
    for(int i=1;i<=max;i++){
        sum *= i;
    }
    return sum;
}
void maximum(vector<int>arr){
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int num = fact(max);
    cout<<"The factorial of the largest number is : "<<endl;
    cout<<num;
}
int main()
{
    vector<int>arr{2,3,4,5,6,5};
    maximum(arr);
}
//sort one two and 0 or color sort Three pointer approach
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int>arr{0,1,2,0,1,2,1,2,0};
    int l = 0;
    int m = 0;
    int h = arr.size()-1;
    while(m<=h){
        if(arr[m]==0){
            swap(arr[m],arr[l]);
            m++;
            l++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            swap(arr[m],arr[h]);
            h--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
return 0;
}

//Minimum Start Value to keep the array positive leetcode 1413  
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int mini = 0;
        for(int n:nums){
            sum += n;
            mini = min(mini,sum);
        }
            return abs(mini)+1;
    }

};