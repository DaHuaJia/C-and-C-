#include<stdio.h>
main(){
	int n;
	void fun(int n);
	printf("How do you judge number? \n");
	scanf("%d",&n);
	printf("input %d number: \n",n);
	fun(n);
	return 0;
} 
void fun(int n){
	int i,j,k;
	int num[n];
	for(i=0; i<n; i++){
		if(getchar()=='\n'){ n=i; break; }
		else scanf("%d",&num[i]);           
	}
	for(j=0; j<n-1; j++){             
		for(k=0; k<n-1-j; k++){       
			if(num[k] > num[k+1]){
				i=num[k+1];
				num[k+1]=num[k];
				num[k]=i;
			}
		}
	}
	printf("new %d number: \n",n);
	i=0;
	while(i<n){
		printf("%3d",num[i]);   
		i++;
	}
}
