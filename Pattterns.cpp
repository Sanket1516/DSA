//hollow diamond
#include<iostream>
using namespace std;
int main()
{
    int n =5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<i+1;j++){
            if(j!=0){
            cout<<"  ";
            }
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i;j++){
            if(j!=0){
            cout<<"  ";
            }
        }
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
//Fancy Pattern 2
#include <iostream>
using namespace std;
int main()
{
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<i+1;
            if(j!=i){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<n-i;
            if(j!=n-i-1){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}
//Fancy pattern 3
#include <iostream>
using namespace std;
int main()
{
    int j;
    int k;
    int n=4;
    for(int i=0;i<n;i++){
        for(j=0;j<i+1;j++){
            char ch = j+'A';
            cout<<ch;
        }
        k=j-1;
        for(k;k>=1;k--){
            int ans = k-1;
            char ch = ans+'A';
            cout<<ch;
        }
        cout<<endl;
    }
}
//Fancy pattern 4
#include <iostream>
using namespace std;
int main()
{
    int n=5;
    for (int i = 0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(i==0){
                cout<<j+1<<" ";
            }
            else if(j==0){
                cout<<i+1<<" ";
            }
            else if(j==(n-i-1)){
                cout<<5<<" ";
            }
            else{
                cout<<"  ";
            }
    }
    cout<<endl;
}
    return 0;
}
//Fancy Pattern 5
#include <iostream>
using namespace std;
int main(){
    int n =5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        int j;
        for(j=0;j<i+1;j++){
            cout<<j+1;
        }
        j = j-1;
        for(j;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
//Fancy Pattern 6
#include <iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
        
    }
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-i)-1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    return 0;
}
//Fancy Pattern 7
#include <iostream>
using namespace std;
int main()
{
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i+3;j++){
            cout<<"*";
        }
        for(int j=0;j<i+1;j++){
            cout<<i+1;
            if(i!=j){
                cout<<"*";
            }
        }
        for(int j=0;j<n+3-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
//fancy Pattern 8
#include <iostream>
using namespace std;
int main()
{
    int n=4;
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<x;
            x++;
            if(i!=j){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    int start = x-n;
    for(int i=0;i<n;i++){
        int k = start;
        for(int j=0;j<=n-i-1;j++){
            cout<<k;
            k++;
            if(j!=n-i-1){
                cout<<"*";
            }
        }  
        start = start-(n-i-1);
        cout<<endl;
    }
    return 0;
}