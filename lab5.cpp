// Native String Matching


#include<iostream>
#include<cstring>


using namespace std;
void naive(char* T,char* P){
     
       int n=strlen(T);
       int m=strlen(P);
      
       int i=1;
       int j=1;
  
       for(int s=0;s<=n-m;s++){
      
       while(j<=m && T[s+i]==P[j]){
            i++;
            j++;
       }
       if(j==m+1){
       cout << "Pattern occurs with shift";
       cout << endl << s;
       }
       }
      
}
int main(){
       char t[]="aaabcade";
       char p[]="cad";
      
       naive(t,p);


       return 0;


}


