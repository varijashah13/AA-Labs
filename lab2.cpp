// AA LAB:02
// CE128-Varija Shah
// Implement Randomized Primality Testing using Fermat's Theorem.
#include <iostream>
#include <algorithm>

using namespace std;
int gcd(int a, int b){
    if(a < b){
   	 return gcd(b,a);
    }
    else if((a % b) == 0){
   	 return b;
    }
    else
    return gcd(b, a % b);
}

int power(int a,int n,int p){
    int res = 1;
    a = a % p;
    while(n > 0){
   	 if(n & 1){
   	 res = (res *a) % p;
   	 }
   	 n = n >> 1;
   	 a = (a*a) % p;
    }
    return res;
}


bool isprime(int n){
    if(n <= 1 || n == 4){
   	 return false;
    }
    if(n <= 3){
   	 return true;
    }
    int k=4;  //how many times you want to run loop
    while(k > 0){
   	 int a = 2 + rand() % (n-4);
  	 
   	 if(gcd(n,a) != 1 ){
   		 return false;
   	 }
   	 if(power(a, n-1, n) !=  1){
   		 return false;
   	 }
   	 k--;
    }
    return true;
}


int main() {
  int n;
 
  cin >> n;
  bool ans=isprime(n);
  if(ans==true){
  	cout<<"Prime";
  }
  else{
  	cout<<"Not Prime";
  }
  return 0;
}
