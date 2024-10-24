#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Fib(int n){
	int i;
	if(n<=0){
		printf("Invalid. Enter a positive number\n");
		return;
	}
	long long fib[n];
	fib[0]=0;
	if(n>1){
	fib[1]=1;
}
	
	#pragma omp for
	for(i=2;i<n;i++){
		fib[i]=fib[i-1]+fib[i-2];
}
	printf("The first %d fibonacci numbers are: \n",n);
	for(i=0;i<n;i++){
		printf("%lld ",fib[i]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter element: ");
	scanf("%d",&n);
	Fib(n);
	return 0;
	

}
