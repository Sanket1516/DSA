//Sum OF rows 
#include <iostream>
using namespace std;
int main()
{
    int arr[5][4];
    int row =5;
    int col = 4;
    cout<<"Enter the Values : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Sum aoording to row : "<<endl;
    for(int i=0;i<row;i++){
        int sum =0;
        for(int j=0;j<col;j++){
            sum += arr[i][j];
        }
        cout<<"The Sum of "<<i<<" row is : "<<sum<<endl;
    }
    return 0;
}
//Sum of coloumn
#include <iostream>
using namespace std;
int main()
{
    int arr[5][4];
    int row =5;
    int col = 4;
    cout<<"Enter the Values : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Sum aoording to coloumn : "<<endl;
    for(int i=0;i<col;i++){
        int sum =0;
        for(int j=0;j<row;j++){
            sum += arr[j][i];
        }
        cout<<"The Sum of "<<i<<" row is : "<<sum<<endl;
    }
    return 0;
}
//Linear Search In the 2D Array
#include <iostream>
using namespace std;
bool search(int arr[][4],int row,int col,int key){
    bool flag = false;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(key == arr[i][j]){
                flag =true;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    int arr[3][4];
    int row =3;
    int col =4;
    int key;
    cout<<"Enter the key : "<<endl;
    cin>>key;
    cout<<"Enter the values in the array : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    if(search(arr,row,col,key)){
        cout<<"The nuumber is Present ! "<<endl;
    }
    else{
        cout<<"The number is not present !"<<endl;
    }
    return 0;
}
//Find Maximum and Minimum from the 2D array
#include <iostream>
#include <climits>
using namespace std;
void maxnmin(int arr[][2],int row,int col){
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]<min){
                min = arr[i][j];
            }
            if(arr[i][j]>max){
                max = arr[i][j];
            }
        }
    }
    cout<<"The Maximum number in the arrray is : "<<max<<endl;
    cout<<"The minimum nmber in the arrray is : "<<min<<endl;
}
int main()
{
    int arr[2][2];
    int row = 2;
    int col = 2;
    cout<<"Enter the value of array  : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    maxnmin(arr,row,col);
    return 0;
}
//Transpose of the matrix
#include <iostream>
using namespace std;
void transpose(int arr[][3],int row,int col){
    cout<<"The Transpose of the matrix is : "<<endl;
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;
    cout<<"Enter the values in the array : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    transpose(arr,row,col);
    return 0;
}
//Rotate The matrix by 90 Degree
#include <iostream>
using namespace std;
int main()
{
    int arr[4][4];
    int row = 4;
    int col = 4;
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"The rotated matrix is : "<<endl;
    for(int i=0;i<col;i++){
        for(int j=row-1;j>=0;j--){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//MOst Important Spiral Question
#include <iostream>
using namespace std;
void spiral(int arr[][3],int row , int col){
    //Initialization of the pointers is also important
    int startingrow = 0;
    int endingrow = row-1;
    int startingcol = 0;
    int endingcol = col-1;
    int total = row * col;
    int count = 0;
    //count == total not allowed beacause the loop will run one extra time if count == total and we dont have elements left all are sorted hence we can also write count!=total
    while(count<total){
        //<= beacuse we have alredy minused the row and coloumn by 1
        for(int i=startingcol;i<=endingcol;i++){
            //for these one should think about what will be constant
            cout<<arr[startingrow][i]<<" ";
            count++;
        }

        startingrow ++;

        for(int i=startingrow;i<=endingrow  && count<total;i++){
            cout<<arr[i][endingcol]<<" ";
            count++;
        }

        endingcol --;

        for(int i=endingcol;i>=startingcol  && count<total;i--){
            cout<<arr[endingrow][i]<<" ";
            count ++;
        }

        endingrow --;

        for(int i=endingrow;i>=startingrow  && count<total;i--){
            cout<<arr[i][startingcol]<<" ";
            count ++;
        }

        startingcol ++;
    }
}
int main()
{
    int arr[3][3];
    int row =3;
    int col =3;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    spiral(arr,row,col);
    return 0;
}
//Print in Wave Form from col
#include <iostream>
using namespace std;
void wave(int arr[][3],int row,int col){
    for(int j=0;j<col;j++){
        if(j%2==0){
            for(int i=0;i<row;i++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int i=row-1;i>=0;i--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}
int main()
{
    int arr[3][3];
    int row = 3;
    int col =3;
    cout<<"enter the elemnets in the array : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"The spiral print is : "<<endl;
    wave(arr,row,col);
    return 0;
}
//From row Wise
#include <iostream>
using namespace std;
void wave (int arr[][3],int row ,int col){
    for(int i=0;i<row;i++){
        if(i%2==0){
            for(int j=0;j<col;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=col-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}
int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;
    cout<<"Enter the Values In the Array : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    wave(arr,row,col);
    return 0;
}
