// sum of subset

#include<iostream>
using namespace std;
int main(){
	cout << "enter number of items:";
	int n;
	cin >> n;
	int sum;
	cout << "Enter the sum:";
	cin >> sum;
	int p[n];
	int w[n];
	int t[n][sum];
	cout << "enter array:";
	for(int i=1;i<=4;i++){
    	cin >> p[i];
	}
	p[n]=w[n];
    
   
	for(int i=0;i<=n;i++){
    	t[i][0]=0;
	}
	for(int j=1;j<=sum;j++){
    	t[0][j]=0;
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=sum;j++){
        	if(j<w[i]){
            	t[i][j]=t[i-1][j];
        	}
        	else{
            	t[i][j]=max(t[i-1][j],p[i]+t[i-1][j-w[i]]);
        	}
    	}
	}
    	int tprofit=t[n][sum];
   	if(tprofit==sum){
       	cout << "True" << endl;
   	}
   	else{
       	cout << "False" << endl;
   	}
    
	return 0;
}
