#include<stdio.h>
#include<windows.h>
#include<math.h>
#define p 3.1415926
#define r p/180 //r=p/180,p=3.14....,p/180�����1���ȣ�����sin(����Ҫ����ǻ���)��sin��30���ȣ�=0.5��
 int main()
{
float i,j,k;
int l,m,n,a[10];
char cmd;
LOOP:
system("cls");
printf("***********************\n");
printf("*******������******\n");
printf("***********************\n");
printf("\n\n���������ṩ+��-��*��/�������㡣\n");
printf("p-����Բ����pai��\n");
printf("a-����ʮ����ת��Ϊ�����ơ�\n");
printf("b-����ʮ����ת��Ϊ�˽��ơ�\n");
printf("c-����ʮ����ת��Ϊʮ�����ơ�\n");
printf("d-�������ֵ������\n");
printf("e-�������ֵ��������\n");
printf("f-�����󼸴η���\n");
printf("S-����sin��\n");
printf("C-����cos��\n");
printf("T-����tan��\n");
printf("\n\n������Ҫ��������ֺ�������ţ����롰#��ʱ���˳����������롰������Ӣ��״̬��ʱ��λ��\n");

scanf("%f",&k);
while((cmd=getchar())!='#')
{
switch(cmd)
{
case '+': scanf("%f",&i);     //�ӷ� 
k=k+i;
printf("=%5.2f",k);
break; case '-': scanf("%f",&i);   //���� 
k=k-i;
printf("=%5.2f",k);
break; case '*': scanf("%f",&i);     //�˷� 
k=k*i;
printf("=%5.2f",k);
break; case '/': scanf("%f",&i);      //���� 
k=k/i;
printf("=%5.2f",k);
break;

case 'p': k=k*p;           //����pi 
printf("%6.4f",k);
break; case 'f': printf("������Ҫ������ֵļ��η���");   //��ƽ�� 
scanf("%d",&n);
i=k;
for(m=0;m<n-1;m++)
k=k*i;
printf("%5.2f",k);
break; case 'a': printf("ת���ɶ�����\n");      //ת���ɶ����� 
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
break; case 'b': printf("ת���ɰ˽���\n");     //ת���ɰ˽��� 
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

case 'c': printf("ת����ʮ������\n");        //ת����ʮ������ 
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
case 'e': printf("����ֵ��������\n");      // ������
i=pow(k,1.0/3);
printf("%5.2f",i );
break;

case 'd': printf("����ֵ������\n");     // ����
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
