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