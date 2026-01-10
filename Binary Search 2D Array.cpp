#include <iostream>
using namespace std;
bool searchelement(int arr[][4],int row,int col,int target){
    int start = 0;
    int end = (row*col)-1;
    int mid = 0;
    int rowindex = 0;
    int colindex = 0;
    int element = 0;
    while(start <= end){
        mid = start+(end-start)/2;
        rowindex = mid/col;
        colindex = mid%col;
        element = arr[rowindex][colindex];
        if(element==target){
            return true;
        }
        else if(element>target){
            end = mid - 1;
        }
        else{
            start = mid+1;
        }
    }
    return false;
}
int main()
{
    int arr[4][4];
    int row = 4;
    int col = 4;
    int target = 0;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<row;i++){
        for(int j =0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter the Target to Find :  "<<endl;
    cin>>target;
    if(searchelement(arr,row,col,target)){
        cout<<"The Element Is Found ! ";
    }
    else{
        cout<<"The element Not found ! ";
    }
    return 0;
}