#include<stdio.h>
#include<windows.h>
#include<math.h>
#define p 3.1415926
#define r p/180 //r=p/180,p=3.14....,p/180是求的1弧度，下面sin(里面要求的是弧度)，sin（30弧度）=0.5。
 int main()
{
float i,j,k;
int l,m,n,a[10];
char cmd;
LOOP:
system("cls");
printf("***********************\n");
printf("*******计算器******\n");
printf("***********************\n");
printf("\n\n本计算器提供+、-、*、/四种运算。\n");
printf("p-代表圆周率pai。\n");
printf("a-代表十进制转换为二进制。\n");
printf("b-代表十进制转换为八进制。\n");
printf("c-代表十进制转换为十六进制。\n");
printf("d-代表该数值开方。\n");
printf("e-代表该数值开立方。\n");
printf("f-代表求几次方。\n");
printf("S-代表sin。\n");
printf("C-代表cos。\n");
printf("T-代表tan。\n");
printf("\n\n请输入要计算的数字和运算符号，输入“#”时，退出函数；输入“！”（英文状态）时复位。\n");

scanf("%f",&k);
while((cmd=getchar())!='#')
{
switch(cmd)
{
case '+': scanf("%f",&i);     //加法 
k=k+i;
printf("=%5.2f",k);
break; case '-': scanf("%f",&i);   //减法 
k=k-i;
printf("=%5.2f",k);
break; case '*': scanf("%f",&i);     //乘法 
k=k*i;
printf("=%5.2f",k);
break; case '/': scanf("%f",&i);      //除法 
k=k/i;
printf("=%5.2f",k);
break;

case 'p': k=k*p;           //乘以pi 
printf("%6.4f",k);
break; case 'f': printf("请输入要求该数字的几次方：");   //求平方 
scanf("%d",&n);
i=k;
for(m=0;m<n-1;m++)
k=k*i;
printf("%5.2f",k);
break; case 'a': printf("转换成二进制\n");      //转换成二进制 
m=0;

while((int)k>0)
{
l=k;
k=k/2;
l=l%2;
a[m]=l;
m++;
}
for(n=m-1;n>=0;n--)
printf("%d",a[n]);
break; case 'b': printf("转换成八进制\n");     //转换成八进制 
m=0;
while((int)k>0)
{
l=k;
k=k/8;
l=l%8;
a[m]=l;
m++;
}
for(n=m-1;n>=0;n--)
printf("%d",a[n]);
break;

case 'c': printf("转换成十六进制\n");        //转换成十六进制 
m=0;
while((int)k>0)
{
l=k;
k=k/16;
l=l%16;
a[m]=l;
m++;
}
for(n=m-1;n>=0;n--)
{
if(a[n]==10)
{ printf("A");continue;}
else if(a[n]==11)
{ printf("B");continue;}
else if(a[n]==12)
{ printf("C");continue;}
else if(a[n]==13)
{ printf("D");continue;}
else if(a[n]==14)
{ printf("E");continue;}
else if(a[n]==15)
{ printf("F");continue;} printf("%d",a[n]);
}

break;
case 'e': printf("该数值开立方得\n");      // 开立方
i=pow(k,1.0/3);
printf("%5.2f",i );
break;

case 'd': printf("该数值开方得\n");     // 开方
i=k/2;
j=sqrt(k);
printf("%5.2f",j);
break; case 'S': k=k*r;
i=sin(k);
printf("%5.2f",i);
break;

case 'C': k=k*r;
i=cos(k);
printf("%5.2f",i);
break; case 'T': k=k*r;
i=tan(k);
printf("%5.2f",i);
break; case '!': goto LOOP;

}

}
} 
