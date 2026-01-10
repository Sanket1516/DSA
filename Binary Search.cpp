#include <iostream>
using namespace std;
int binarysort(int arr[],int size,int key){
    int start = 0;
    int end = size -1 ;
    int mid = (start-end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = (start + end )/2;
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10} ;
    int size = 10;
    int key;
    cout<<"Enter the element you have to find in the array : "<<endl;
    cin>>key;
    int element = binarysort(arr,size,key);
    if(element == -1){
        cout<<"Element not Found :"<<endl;
    }
    else{
        cout<<"Element found at the "<<element<<" index "<<endl;
    }
    return 0;
}
//Find The first occurance of the element in the array 
#include <iostream>
#include <vector>
using namespace std;
int firstoccurance(vector <int> arr,int key){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    int ans=-1;
    while(start<=end){
        if(arr[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
int main()
{
    vector <int> arr {1,2,3,4,5,4,4,4,6};
    int key;
    cout<<"Enter the number to find its first occurance : "<<endl;
    cin>>key;
    int ans = firstoccurance(arr,key);
    if(ans == -1){
        cout<<"Element Not Found ! ";
    }
    else{
        cout<<"Element "<<key<<" Found at "<<ans<<" Index !";
    }
    return 0;
}
//Find last Occurance of the key 
#include <iostream>
#include <vector>
using namespace std;
int lastoccurance(vector<int>arr,int key){
    int start = 0;
    int end = arr.size()-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while(start<=end){
        if(arr[mid]==key){
            ans = mid;
            start = mid +1;
        }
        else if(arr[mid]<key){
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
int main()
{
    vector <int> arr{2,3,4,5,2,7,7,8,7,7,7};
    int key;
    cout<<"The the element to find the last Occurance : "<<endl;
    cin>>key;
    int ans = lastoccurance(arr,key);
    if(ans == -1){
        cout<<"The element not found !"<<endl;
    }
    else{
        cout<<"The element "<<key<<"found at "<<ans<<" index"<<endl;
    }
    return 0;
}
//Find the largest element in the mountain array ## IMP
#include <iostream>
#include <vector>
using namespace std;
int mountain(vector<int>arr){
    int start = 0;
    int end =arr.size()-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while(start<end){
        if(arr[mid]>arr[mid+1]){
            end = mid;
        }
        else{
            start = mid + 1 ;
        }
        mid = start+(end-start)/2;
    }
    ans = arr[start];
    return ans;
}
int main()
{
    vector<int>arr{1,2,3,4,5,6,7,8,9,10,11,8,7,6,5,4,3,2,1};
    int num =mountain(arr);
    if(num == -1){
        cout<<"element Not found : "<<endl;
    }
    else{
        cout<<"The largest element is : "<<num;
    }
    return 0;
}
//Find the number of occurance of the number in a asorted array using binar search
#include <iostream>
#include <vector>
using namespace std;
int lastoccurance(vector<int>arr,int key){
    int start =0 ;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;
    int lastoccurance = 0;

     while(start<=end){
        if(arr[mid]==key){
            lastoccurance = mid;
            start = mid+1;
        }
        else if(arr[mid]>key){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return lastoccurance;
}
int occurance(vector<int>arr,int key){
    int start =0 ;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;
    int firstoccurance = 0;
    while(start<=end){
        if(arr[mid]==key){
            firstoccurance = mid;
            end = mid-1;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return lastoccurance(arr,key) - firstoccurance + 1;
}
int main()
{
    vector<int>arr{1,2,3,4,4,4,4,4,4,5};
    int key;
    cout<<"Enter the number of occurance you have to find : "<<endl;
    cin>>key;
    int num = occurance(arr,key);
    cout<<num;
    return 0;
}
//Find the sqrt of a number using binary search
#include <iostream>
using namespace std;
int findsqrt(int target){
    int start = 0;
    int end = target/2;
    int mid = start+(end-start)/2;
    int ans = 0;
    while(start<=end){
        if(mid*mid==target){
            return mid;
        }
        else if(mid*mid>target){
            end = mid-1;
        }
        else{
            ans = mid;
            start= mid + 1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
int main()
{
    int target;
    cout<<"Enter the target : "<<endl;
    cin>>target;
    int num = findsqrt(target);
    cout<<num;
    return 0;
}
//For square root in decimal
#include <iostream>
using namespace std;
int findsqrt(int target){
    int start = 0;
    int end = target/2;
    int mid = start+(end-start)/2;
    int ans = 0;
    while(start<=end){
        if(mid*mid==target){
            return mid;
        }
        else if(mid*mid>target){
            end = mid-1;
        }
        else{
            ans = mid;
            start= mid + 1;
        }
         mid = start+(end-start)/2;
    }
    return ans;
}
int main()
{
    int target;
    cout<<"Enter the target : "<<endl;
    cin>>target;
    int precesion;
    cout<<"Enetr the precesion : "<<endl;
    cin>>precesion;
    int num = findsqrt(target);
    //From Here is Change
    double ans = num;
    double step =0.1;
    for(int i=0;i<precesion;i++){
        //we will add 0.1 till the condition
        //suppose the ans is 3 then in this loop it will be 3.1,3.2,3.3,3.4,3.5,3.6 and soo on till the condition is meet
        for(double j=ans;j*j<=target;j=j+step){
            ans = j;
        }
        step = step /10;
        //then we will add 0.01 till the condition and it continues till preccision
        //suppose the upper loop is stop on 3.2 then in this loop they will be 3.11 ,3.111,3.1111 up to the presision.
    }
    cout<<ans<<endl;
    return 0;
}
//Binary Search In Nearly Sorted Array
#include<iostream>
#include<vector>
using namespace std;
int search_element(vector<int>arr,int key){
    int start = 0;
    int end = arr.size()-1;
    int mid = start+(end-start)/2;
    while(start <= end){
        if(key == arr[mid]){
            return mid;
        }
        if(key == arr[mid+1]){
            return mid+1;
        }
        if(key == arr[mid-1]){
            return mid - 1;
        }
        if(key > arr[mid]){
            start += 2;
        }
        else{
            end -= 2;
        }
        mid = start + (end - start)/2;
    }
}
int main(){
    vector<int>arr{10,3,40,20,50,80,70};
    int key;
    cout<<"enter the number to be searched in a array : \n";
    cin>>key;
    int k = search_element(arr,key);
    cout<<"The Element is on index : "<<k<<endl;
    return 0;
}
//Division using Binaray Serach
#include <iostream>
using namespace std;
int quotient(int divident,int divisor){
    int ans = -1;
    int start = 1;
    int end = int(divident/2);
    int mid = start+(end-start)/2;
    while(start<=end){
        if(divisor * mid == divident){
            return mid;
        }
        else if(divisor * mid > divident){
            end = mid - 1;
        }
        else{
            ans = mid;
            start = mid +1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
int main()
{
    int divisor,divident;
    float ans = 0;
    cout<<"Enter the Divisor : \n";
    cin>>divisor;
    cout<<"Enter the divident : \n";
    cin>>divident;
    int Quotient = quotient(divident,divisor);
    if(Quotient * divisor == divident){
        cout<<"The quotient is : "<<Quotient;
    }
    else{
    int precision;
    cout<<"Enter the Precision : "<<endl;
    cin>>precision;
    float step = 0.1;
    for(int i =0 ;i<precision;i++){
        for(float j = Quotient;j*divisor<=divident;j = j+step){
            ans = j;
        }
        step = step/10;
    }
    cout<<"The quotient is : "<<ans;
    }
    return 0;
}
//Find the unique element in the pair 
#include<iostream>
#include<vector>
using namespace std;
int odd_occuring(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2; // Mid calculated before the loop

    while (start < end) {
        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) {
                start = mid + 2;
            } else {
                end = mid;
            }
        } else {
            if (arr[mid] == arr[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        mid = start + (end - start) / 2; // Mid recalculated at the end of the loop
    }

    return arr[start];
}
int main(){
    vector<int>arr{2,2,4,4,5,5,6,6,7,7,8,8,9,9,10,11,11};
    int p = odd_occuring(arr);
    cout<<"The Unique element is : "<<p<<endl;
    return 0;
}
