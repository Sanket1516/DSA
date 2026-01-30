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


//Remove all the occurances of the substring leetcode 1910 (medium)
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

//valid palindrome 2 leetcode 680 (Easy)
class Solution {
public:

    bool check_palindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        string new_string = s;
        int i = 0;
        int j = s.length()-1;
         while(i<=j){
            if(s[i]!=s[j]){
                if(check_palindrome(s,i+1,j) || check_palindrome(s,i,j-1)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};

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

//Decode the message leetcode 2325 (Easy)
class Solution {
public:
    string decodeMessage(string key, string message) {
        //Mapping
        char start = 'a';
        //All are initalized to zero first it is done to reduce the duplicate entry
        char mapping[300] = {0};
        for(auto ch:key){
            //if for a particular character mapping is not done(it is seen by the zero is present there otherwise there is mapping allready done)and it is not space
            if(ch!=' ' && mapping[ch]==0){
            mapping[ch] = start;
            start++;
            }
        }

        //Decoding
        string ans = "";
        for(auto ch:message){
            if(ch==' '){
                ans.push_back(ch);
            }
            else{
                ans.push_back(mapping[ch]);
            }
        }
        return ans;
    }
};

//minium amount to collect the garbage LeetCode 2391 (Medium) 
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //Total garbage of each type
        int garbageP=0;
        int garbageG=0;
        int garbageM=0;

        //Last index where each type of garbage is present To travel only till that index
        int lastindexP=0;
        int lastindexG=0;
        int lastindexM=0;

        //Total travel time for each type
        int travelP=0;
        int travelG=0;
        int travelM=0;

        //Calculating total garbage of each type and last index where each type of garbage is present
        for(int i =0;i<garbage.size();i++){
            for(auto c : garbage[i]){
                if(c == 'G'){
                    garbageG++;
                    lastindexG = i;
                }

                if(c == 'P'){
                    garbageP++;
                    lastindexP = i;
                }

                if(c == 'M'){
                    garbageM++;
                    lastindexM = i;
                }
            }
        }
       
        //Calculating total travel time for each type of garbage truck
        for(int i =0;i<lastindexG;i++){
            travelG +=travel[i];
        }

        for(int i =0;i<lastindexP;i++){
            travelP +=travel[i];
        }

        for(int i =0;i<lastindexM;i++){
            travelM +=travel[i];
        }

        //The sumation of time required to collect all garbage plus the time required to pick all the garbage by each truck
        return (travelP+garbageP)+(travelG+garbageG)+(travelM+garbageM);
        }
};


//Custom Sort String LeetCode 791 (Medium)
class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};
        string ans="";
        //mapping the characters from o - 1 as a starts from zero if we minus a
        for(auto ch:s){
            freq[ch-'a']++;
        }

        //now adding all the charecters which come sin order first
        for(auto ch : order){
            while(freq[ch-'a']>0){
                ans += ch;
                freq[ch-'a']--;
            }
        }

        //now put rest of the all charecters in the string as they are
        for(int i =0;i<26;i++){
            while(freq[i]>0){
                ans += char(i+'a');
                freq[i]--;
            }
        }

        return ans;
    }
};

//Find and Replace Pattern LeetCode 890 (Medium)
class Solution {
public:
     void createPatten(string& s){
     char start = 'a';
        char table[26] = {0}; //to store mapping of characters because we will scale or index in the form of 0,1,2,3...
        for(auto ch : s){
            //ch-a beacuse we have to store in the form of 0,1,2,3...eg a->0,b->1,c->2... (a = 97 in ascii - 97 = 0 b= 98 - 97 = 1)
            //just to remember to return that specific character we have to add 'a' again egc char(ch+'a');
            if(table[ch-'a']==0){
                table[ch-'a'] = start++;
            }
        }

        for(int i=0;i<s.length();i++){
            s[i] = table[s[i]-'a'];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //The variable to store the original string that we have to return
        //as it will be modified in the createPatten function
       string to_return = "";
       //array to store the final result and return it
       vector<string>arr;
       //Creating pattern for the given pattern string normalizing both the strings i the format of abc..
       createPatten(pattern);
       //Now checking for each string in the words array
       for(string s : words){
        //storing the original string
        to_return = s;
        //creating pattern for the current string
        createPatten(s);
        //if both the patterns match then we will push the original string to the result array
        if(s==pattern){
            arr.push_back(to_return);
        }
       }
       return arr;
    }
};

//remove all adjacent duplicates in string LeetCode 1047 (Easy)
class Solution {
public:
    string removeDuplicates(string s) {
        int i =0;
        string ans="";
        while(i<s.length()){
            if(ans.length()>0 && ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};

//remove all adjacent duplicates in string II LeetCode 1209 (Medium)
//own logic
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string new_string = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If we have at least k-1 characters to compare
            if (new_string.length() >= k - 1) {
                bool flag = true;

                // Check last k-1 characters
                for (int j = 0; j < k - 1; j++) {
                    if (new_string[new_string.length() - 1 - j] != ch) {
                        flag = false;
                        break;
                    }
                }

                // If k consecutive characters found
                if (flag) {
                    for (int j = 0; j < k - 1; j++) {
                        new_string.pop_back();
                    }
                } else {
                    new_string.push_back(ch);
                }
            } 
            else {
                new_string.push_back(ch);
            }
        }

        return new_string;
    }
};
//optimized approach 
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string new_string = "";
        vector<int> count;   // stores consecutive counts

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            //if current charecter is same as last one then increase the count and if also new_string is not empty
            if (!new_string.empty() && new_string.back() == ch) {
                count.back()++;
            } 
            //if different charecter then push it to the new_string and initialize its count to 1
            else {
                new_string.push_back(ch);
                count.push_back(1);
            }
            //if the same charecter count reaches k then we have to remove it from the new_string and also pop its count from the count array
            if (count.back() == k) {
                new_string.pop_back();
                count.pop_back();
            }
        }

        // rebuild final string
        string ans = "";
        for (int i = 0; i < new_string.length(); i++) {
            //append the current character count[i] times to the ans string 
            ans.append(count[i], new_string[i]);
        }

        return ans;
    }
};

//Longest Substring Without Repeating Characters LeetCode 3 (Medium)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //craeting a pos array to store the last index of the character 
        //initialized to -1 as initially no character is present
        vector<int>pos(256,-1);
        //using sliding window approach
        int left = 0;
        int right = 0;
        int maxlen = 0;
        //the right pointer will move ahead in each iteration
        //the left pointer will move only when a repeating character is found in the current window
        while(right<s.length()){
            //if the charecter is occured before and its index is in the current window
            if(pos[s[right]]!=-1 && pos[s[right]]>=left){
                //move the left pointer to the next index then the last occured index of the current charecter
                left = pos[s[right]]+1;
            }
            //calculate the length of the current window
            int len = (right-left)+1;
            //update the maxlen if current length is greater
            maxlen = max(len,maxlen);
            //update the last occured index of the current charecter
            pos[s[right]] = right;
            //move the right pointer ahead
            right++;
        }
        return maxlen;
    }
};


//Longest Common Prefix LeetCode 14 (Easy)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Most Imp Edge Cases
        if(strs.size()==1){
            return strs[0];
        }
        if(strs.size() == 0){
            return "";
        }

        //sort the strings in alpahbetical order
        sort(strs.begin(),strs.end());
        //as if there is something common in all the strings we just have to compare the first and last string after sorting
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        string ans="";
        int max =min(s1.length(),s2.length());
        int i =0;
        while(i<max){
            if(s1[i]==s2[i]){
                ans+=s1[i];
            }
            else{
                break;
            }
            i++;
        }
        return ans;
    }
};

//reverse the vovels in the string LeetCode 345 (Easy)
class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

//rearrange string LeetCode 767 (Medium) Pattren = storing frequency
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        //calculating frequency of each character
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        //finding the character with maximum frequency and also the maximum frequency value
        int max_freq = 0;
        int max_char = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                max_char = i;
            }
        }

        //frequency should not be more than (n+1)/2 else it is not possible to rearrange
        if (max_freq > (n + 1) / 2) {
            return "";
        }

        vector<char> ans(n);
        int idx = 0;

        //placing the character with maximum frequency at even indices first
        while (freq[max_char] > 0) {
            ans[idx] = char(max_char + 'a');
            idx += 2;
            freq[max_char]--;
        }


        //placing the rest of the characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                //if even indices are filled then start placing at odd indices
                if (idx >= n) idx = 1;  
                ans[idx] = char(i + 'a');
                idx += 2;
                freq[i]--;
            }
        }

        //converting the character array to string
        string to_return = "";
        for (int i = 0; i < ans.size(); i++) {
            to_return += ans[i];
        }

        return to_return;
    }
};
