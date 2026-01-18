//count the number of prime leetcode (204) medium
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        //if n is zero then there are no prime numbers
        if(n==0){
            return 0;
        }
        //createing a boolean array to mark the all numbers as prime initially
        vector<bool>space(n,true);
        //0 and 1 are not prime numbers
        space[0]=false;
        space[1]=false;
        //Sieve of Eratosthenes
        //starting from 2 as 0 and 1 are not prime numbers
        for(int i = 2;i<n;i++){
            //if the number is still marked as prime then we will mark all its multiples as not prime
            if(space[i]){
                count++;
                //pointing to the next value in a table of a given i
                int j = 2*i;
                //traverse a table of that paricular number till n
                while(j<n){
                    //mark them as nonprime
                    space[j]=false;
                    //increment to next value of a table
                    j+=i;
                }
            }
        }
        return count;
    }
};

//Euclead method to find the GCD of two numbers
gcd(int a,int b){
    if(b==0){
        return a;
    }
    if(a==0){
        return b;
    }
    while(a!=0 && b!=0){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    //return opposite of the number which has become zero
    return a==0 ? b:a;
}

//find GCD of an array leetcode 1979 (Easy)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = INT_MIN;
        int min = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]<min){
                min = nums[i];
            }
        }

        //GCD of max and min
        while(max!=0 && min!=0){
            if(max>min){
                max = max-min;
            }
            else{
                min = min - max;
            }
        }

        return max==0 ? min:max;

    }
};

//to calculate LCM of two numbers
lcm(a,b)*gcd(a,b) = a*b;

so lcm = (a*b)/gcd(a,b);

lcm(int a,int b){
    return (a*b)/gcd(a,b);
}