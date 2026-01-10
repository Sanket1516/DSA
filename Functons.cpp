//Add Two numbers
# include <iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the value of a and b : ";
    cin>>a>>b;
    cout<<"The sum of the two numbers are : "<<sum(a,b);
    return 0;
}
int sum(int a,int b){
    return a+b;
}
//Greatest of three numbers
#include <iostream>
using namespace std;
int max(int a,int b,int c);
int main(){
    int a,b,c;
    cout<<"Enter the 1st number : ";
    cin>>a;
    cout<<"Enter the 2nd number : ";
    cin>>b;
    cout<<"Enter the 3rd number : ";
    cin>>c;
    cout<<"The greates of all the three numbers is : "<<max(a,b,c);
    return 0;
}
int max(int a,int b,int c){
    if(a>b && a>c){
        return a;
    }
    else if(b>c && b>a){
        return b;
    }
    else{
        return c;
    }
}
//Student Grade Problem
#include <iostream>
using namespace std;
char grade(int n);
int main(){
    int n;
    cout<<"Enter your Grade : "<<endl;
    cin>>n;
    cout<<"Your grade is : "<<grade(n);
}
char grade(int n){
    if(n>=90){
        return 'A';
    }
    else if(n>=80){
        return 'B';
    }
    else if(n>=70){
        return 'C';
    }
    else if(n>=60){
        return 'D';
    }
    else{
        return 'E';
    }
}
//Sum Of even numbers upto n
#include<iostream>
using namespace std;
int evensum(int n){
    int sum =0;
    for(int i=0;i<n+1;i++){
        if(i%2==0){
        sum += i;
        }
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter upto which you have to find the sum of even numbers : "<<endl;
    cin>>n;
    cout<<"The sum of even numbers upto n is : "<<evensum(n);
    return 0;
}
//Area of the Circle
#include<iostream>
using namespace std;
float area(int r){
    return (2*3.14*r*r);
}
int main(){
    int r;
    cout<<"Enter the radius of the circle : "<<endl;
    cin>>r;
    cout<<"The area of the circle is : "<<area(r);
    return 0;
}
