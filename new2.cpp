#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& arr,int start,int end,int mid){
    int i =start;
    int j =mid+1;
    int k =0;
    int temp[100];

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }

    for(int i = start,int j =0 ; i<=end ; i++,j++){
        arr[i] = temp[j];
    }

}

void mergeSort(vector<int>& arr,int start,int end){
    int mid = 0;
    if(start<end){
        mid = start+(end-start)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,end,mid);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array :" <<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1); 
    return 0;
}
