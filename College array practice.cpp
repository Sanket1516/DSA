#include<iostream>
#include<climits>
using namespace std;
//Function of average
void averageofarray(){
    int arr[10];
    int arr_size;
    int avg = 0;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>arr_size;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"The average of the array is : "<<endl;
    int sum =0;
    for(int i = 0;i<arr_size;i++){
        sum += arr[i];
    }
    avg = sum/arr_size;
    cout<<"The avg of the array is : "<<avg<<endl;
}
//insert the new score in the array
void insert_element(){
    int arr[10];
    int arr_size;
    int index=0;
    int insert_element=0;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>arr_size;
    if(arr_size < 9){
    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to insert in array : "<<endl;
    cin>>insert_element;
    cout<<"Enter at which index you have to insert : "<<endl;
    cin>>index;
    for(int i=arr_size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=insert_element;
    for(int i = 0;i<arr_size+1;i++){
        cout<<arr[i];
    }
}
else{
    cout<<"The array is full : "<<endl;
}
}
//remove the specific element
void remove_specific_element(){
     int arr[10];
     int arr_size;
     int remove_element;
     int index =0;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>arr_size;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element in array to remove : "<<endl;
    cin>>remove_element;
    for(int i = 0;i<arr_size;i++){
        if(arr[i]==remove_element){
            index=i;
            break;
        }
    }
    for(int i=index;i<arr_size;i++){
        arr[i]=arr[i+1];
    }
    for(int i = 0;i<arr_size-1;i++){
        cout<<arr[i];
    }
}
//show_lowest_element
void show_lowest_element(){
     int arr[10];
     int arr_size;
     int lowest=INT_MAX;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>arr_size;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0;i<arr_size;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<arr_size;i++){
        if(arr[i]<lowest){
        lowest = arr[i];
    }
}
    cout<<"The lowest element in the array is : "<<lowest;
}
//update_score
void update_score(){
     int arr[10];
     int arr_size;
     int update_element;
     int updated_value;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>arr_size;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element in array to update : "<<endl;
    cin>>update_element;
    cout<<"Enter the element to update : "<<endl;
    cin>>updated_value;
    for(int i = 0;i<arr_size;i++){
        if(arr[i]==update_element){
            arr[i]=updated_value;
            break;
        }
    }
    for(int i = 0;i<arr_size;i++){
        cout<<arr[i];
    }
}
//sort array in ascending order
void sort_array(){
    int arr[10];
     int arr_size;
     int lowest=INT_MAX;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>arr_size;
    cout<<"Enter the elements in the array : "<<endl;
    for(int i = 0;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"Sorted array is : "<<endl;
    for(int i=0;i<arr_size-1;i++){
    for(int j = 0;j<arr_size;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
 }
 for(int i = 0;i<arr_size;i++){
        cout<<arr[i];
    }
}
int main(){
    int choise;
    char continue_operation;
    do{
    cout<<"Enter the operations to be performed : "<<endl;
    cout<<"Enter 1 to perform average of the elements in the array  : "<<endl;
    cout<<"Enter 2 insert new score into an array of scores : "<<endl;
    cout<<"Enter 3 to perform a program to remove specific element in the array :  : "<<endl;
    cout<<"Enter 4 to show the lowest age in the array  : "<<endl;
    cout<<"Enter 5 to update the score of student in the array : "<<endl;
    cout<<"Enter 6 to perform to sort an array in asecending order : "<<endl;
    cin>>choise;

        if(choise == 1){
            averageofarray();
        }
        else if(choise == 2){
            insert_element();
        }
        else if(choise == 3){
            remove_specific_element();
        }
        else if(choise == 4){
            show_lowest_element();
        }
        else if(choise == 5){
            update_score();
        }
        else if(choise == 6){
            sort_array();
        }
        else{
            cout<<"Enter the proper element : "<<endl;
        }
        cout<<endl;
        cout<<"if you have to continue enter (Y) or to Exit(N)";
        cin>>continue_operation;
    }while(continue_operation == 'Y');
    return 0;
    }
