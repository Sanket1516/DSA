#include<iostream>
using namespace std;
int main(){
    char ch[100];
    ch = "Sanket";
    cin>>ch;
    return 0;
}
//After Spaces tyhe cin stops to read so getline function for that
#include<iostream>
using namespace std;
int main(){
    char ch[100];
    cin.getline(ch,100);
    cout<<ch;
    return 0;
}

//Quiz
//Create  a array of lenght 50;
#include<iostream>
using namespace std;
int main(){
char arr[50];
cin>>arr[2];
cin>>arr;
cin>>arr[49];
cin.getline(arr,50);
cout<<arr;
    return 0;
}

//Questions
//NO library is used
//NUmber of chaeracters in the string
#include<iostream>
using namespace std;
int main(){
    char ch[100];
    cin.getline(ch,100);
    int i =0,count0=0;
    while(ch[i]!='\0'){
        i++;
        count0++;
    }
    cout<<count0;
    return 0;
}
//With functions
//library is used called cstrings
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char ch[100];
    cin.getline(ch,100);
    cout<<strlen(ch);
    return 0;
}
//Reverse a string
#include<iostream>
using namespace std;
int main(){
   char arr[100];
   cin.getline(arr,100);
   int i =0,index = 0;
   while(arr[i]!='\0'){
    index = i;
    i++;
   }
   for(int i = index;i>=0;i--){
    cout<<arr[i];
   }
    return 0;
}
//in a array
//Reverse a string
#include<iostream>
using namespace std;
int main(){
   char arr[100];
   cin.getline(arr,100);
   int i =0,index = 0;
   while(arr[i]!='\0'){
    index ++;
    i++;
   }
    i =0;
    int j = index-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    cout<<arr;
return 0;
}
//Replace spaces with the @
#include<iostream>
using namespace std;
int main(){
   char arr[100];
   cin.getline(arr,100);
  int i =0;
  while(arr[i]!='\0'){
    if(arr[i]==' '){
        arr[i]= '@';
    }
    i++;
  }
cout<<arr;
return 0;
}
//Palindrome without using the additional array
#include<iostream>
using namespace std;
int main(){
   char arr[100];
   cin.getline(arr,100);
   int i =0,index = 0;
   while(arr[i]!='\0'){
   index = i;
   i++;
}
i=0;
int j = index;
bool flag = true;
while(i<=j){
    if(arr[i] != arr[j]){
            flag = false;
    break;
    }
    i++;
    j--;
}
if(flag==true){
    cout<<"Is palindrome";
}
else{
    cout<<"Not a palindrome";
}
return 0;
}
//lower to upper with all test cases
#include <iostream>
#include<cstring>
using namespace std;
checkupperto(char arr[]){
    int sizeo = strlen(arr);
    for(int i =0;i<sizeo;i++){
        if(arr[i]==' '){
            continue;
        }
        if(arr[i]>='A' && arr[i]<='Z'){
            continue;
        }
        else{
        arr[i]=arr[i]-'a'+'A';
        }
    }
}
int main(){
    char arr[100];
    cin.getline(arr,100);
    checkupperto(arr);
    cout<<arr<<" ";
    return 0;
}


//upper to lower with all test cases
#include <iostream>
#include<cstring>
using namespace std;
checkupperto(char arr[]){
    int sizeo = strlen(arr);
    for(int i =0;i<sizeo;i++){
        if(arr[i]==' '){
            continue;
        }
        if(arr[i]>='a' && arr[i]<='z'){
            continue;
        }
        else{
        arr[i]=arr[i]-'A'+'a';
        }
    }
}
int main(){
    char arr[100];
    cin.getline(arr,100);
    checkupperto(arr);
    cout<<arr<<" ";
    return 0;
}




//Strings
//Compare two strings  
#include <iostream>
using namespace std;
bool compare(string a,string b){
    int i =0;
    int j =0;
     if(a.length()!=b.length()){
            return false;
        }
    for(int k =0;k<=a.length();k++){
        if(a[i]!=a[j]){
            return false;
        }
    }
    return true;
}
int main()
{
    string a;
    string b;
    cout<<"Enter the First String"<<endl;
    getline(cin,a);
    cout<<"Enter the Second String"<<endl;
    getline(cin,b);
    if(compare(a,b)){
        cout<<"They are equal !";
    }
    else{
        cout<<"They are not equal !";
    }
    return 0;
}
//Leetcode
//remove same adjacent characters 
#include <iostream>
#include<cstring>
using namespace std;
string ans(string ans){
    string temp="";
    for(int i =0;i<ans.length();i++){
        if(temp.length()>0){
        if(temp[temp.length()-1]==ans[i]){
            temp.pop_back();
        }
        else{
            temp.push_back(ans[i]);
        }
    }
    else{
        temp.push_back(ans[i]);
    }
    }
    return temp;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<"The resultant array is : "<<ans(s)<<" ";
    return 0;
}


//Remove all the occurances of the substring 
#include <iostream>
#include<cstring>
using namespace std;
string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while(pos!=string::npos){
            s.erase(pos,part.length());
            pos = s.find(part);
        }
        return s;
    }
int main(){
    sting main;
    getline(cin,main);
    string part;
    getline(cin,part);
    removeOccurrences(main,part);
    return 0;
}

//Minimum Time difference leetcode 539 (Medium)
#include<iostream>
using namespace std;
int findMinDifference(vector<string>timePoints) {
        vector<int> minutes;

        for(int i =0;i<timePoints.size();i++){
            string curr = timePoints[i];
            int hours = stoi(curr.substr(0,2));
            int mins = stoi(curr.substr(3,2));
            int totalmin = hours*60 + mins;

            minutes.push_back(totalmin);
        }

        sort(minutes.begin(),minutes.end());
        int n = minutes.size();
        int mini = INT_MAX;
        for(int i =0;i<n-1;i++){
            int com = minutes[i+1]-minutes[i];
            mini = min(mini,com);
        }

        int lastcom = (minutes[0]+1440) - minutes[n-1];
        mini = min(mini,lastcom) ; 
        return mini;
    };
    int main(){
        vector<string>time;
        for(int i = 0;i<2;i++){
            cin>>time[0];
        }
        findMinDifference(time);
    return 0;
}


//String to Integer atoi leetcode 8 (Medium)
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long ans = 0;

        // 1. Skip leading spaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
             // 4. Handle overflow
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;   
            i++;
        }
        return ans * sign;
    }
};

//Plus one leetcode 66 (Easy)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]+=1;
                return digits;
            }
            digits[i]=0;
        }
        //twist case all 9's
        //here we have to insert 1 at the begining of the array and it will automatically shift all the elements to the right
        //syntax digits.insert(position,value);
        //position only takes iterator like digits.begin()+index or digits.end()
        digits.insert(digits.begin(),1);
        return digits;
    }
};
