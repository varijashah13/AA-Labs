// AA LAB:01
// CE128-Varija Shah


// Implement Randomized Quick sort algorithm.  Use the Random function provided by Programming Language.

#include <iostream>
using namespace std;
randomized_qs(int a[],int p,int r){
	if(p<r){
    	int q;
    	q=randomized_partition(a,p,r);
    	randomized_qs(a,p,q-1);
    	randomized_qs(a,q+1,r);
	}
}
randomized_partition(int a[],int p,int r){
    
    	int i;
   	srand(time(0));
    	i=p+rand()%(r-p+1);
    	swap(a[i],a[r]);
    	return(partition(a,p,r));
   	 
}

int partition(int a[],int p,int q){
	int x=a[r];
	int i=p-1;
	for(int j=p;j<=r-1,j++){
    	if(a[j]<=x){
        	i++;
        	swap(a[i],a[j]);
    	}
	}
	swap(a[i+1],a[r]);
	return(i+1);
}
int main() {

	int a[5]={30,76,56,34,12};
	int p=12;
	int q=34;
	randomized_qs(a,p,r);
    

	return 0;
}
