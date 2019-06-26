#include<stdio.h>
main(){
	char *a,b[6],c[]="I am student.";
	a="I am student.";
	b[0]='I';b[1]=' ';b[2]='a';b[3]='m';b[4]=' ';b[5]='s';
	printf("%s\n",a);
	printf("%s %c %s \n",b[6],b[6],b);
	printf("%c %s",c[11],c);	
} 
