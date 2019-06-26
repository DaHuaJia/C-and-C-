#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct singer{
	char name[30];   //����ѡ������
	int id;          //ѡ�����
	char  sex;      //�Ա� 
	char song[30];    //��������
}singer_num[10]={
	"�Ż�",16238,'F',"����ǰ�",
	"���Ⱥ",16237,'F',"Զ�߸߷�",
	"����",16232,'F',"˵ɢ��ɢ",
};
int score[10];    //�ۺϳɼ� 

int main(){
	int fun_grade();      //���ֺ���
	int fun_search();     //��������
	int fun_cheak();      //�޸���Ϣ���� 
	int fun_add();        //�����Ϣ
	int fun_order();      //������
	int fun_delect();     //ɾ������
	int fun_average();    //���ۺϳɼ����� 
	int fun_save();       //�����ۺϳɼ����� 
	int fun_read();       //��ȡ�ۺϳɼ����� 
	int fun_menu();       //�˵����� 
	printf("��ӭ����ͨ��16�� �質���� ����ϵͳ��\n");
	fun_menu();  
	return 0; 
};

int fun_grade(){       //���ֺ���
	int i;    //�������ѡ����Ϣ��¼��ɼ� 
	float sum;
	printf("��ǰѡ���У�\n");
	for(i=0; i<10; i++){        //���ѡ����Ϣ 
		if(singer_num[i].id!=0) printf("%s (%d)\t\t",singer_num[i].name,singer_num[i].id);
		else if(i==0){printf("ϵͳ����"); return fun_menu();}
	}
	loop1:     //����������󣬷��ص�ǰ��� 
	printf("\n��������Ҫ���ֵ�ѡ�ֵ����(��λ)��"); 
	scanf("%d",&i); 
	if(i>16100 && i<16244){      //���ϵͳ����Ч�� 
		int j;
		for(j=0; j<10; j++){
			if(i==singer_num[j].id){
				sum=fun_average();     //���ۺϳɼ����� 
				score[j]=sum;
				break;
			}
		}
		if(j==10){printf("��ѡ����Ų����ڣ�");goto loop1;}
	}else {printf("��ѡ����Ų����ڣ�");goto loop1;}
	fun_save();      //�����ѡ�ֵ��ۺϳɼ� 
	printf("ȥ��һ����߷֣�ȥ��һ����ͷ�,��ѡ�ֵ����÷�Ϊ��%5.2f ",sum);
	return fun_menu();    //���ز˵����� 
};

int fun_search(){  //��������
	int num,i;
	printf("��������Ҫ������ѡ�ֵ����(��λ)��"); 
	scanf("%d",&num);
	for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("������%s\t��ţ�%d\t�Ա�%c \t�������ƣ�%s\n",singer_num[i].name,singer_num[i].id,singer_num[i].sex,singer_num[i].song);
			break;
		}
	}
	if(i==10){printf("��ѡ����Ų����ڣ�\n");return fun_menu();}
	return fun_menu();
};

int fun_cheak(){      //�޸���Ϣ���� 
	int num,i;
	printf("��������Ҫ�޸ĵ�ѡ�ֵ����(��λ)��");
	scanf("%d",&num);
	for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("������%s\t��ţ�%d\t�Ա�%c \t�������ƣ�%s\n",singer_num[i].name,singer_num[i].id,singer_num[i].sex,singer_num[i].song);
			break;	
		}
	} 
	if(i==10){printf("��ѡ����Ų����ڣ�\n");return fun_menu();}
	printf("�Ƿ�ȷ���޸ĸ�ѡ�ֵ���Ϣ��(1��ȷ��)��");
	scanf("%d",&num); 
	if(num!=1) return fun_menu();
	printf("�������ѡ���޸ĺ�����֣�");
	scanf("%s",&singer_num[i].name); 
	printf("�������ѡ���޸ĺ�ĸ������֣�");
	scanf("%s",&singer_num[i].song); 
	printf("��Ϣ�޸ĳɹ���");
	return fun_menu(); 
};

int fun_add(){     //�����Ϣ
	int num,i;
	printf("��������Ҫ��ӵ�ѡ�ֵ����(��λ)��");
	scanf("%d",&num);
	for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("����ŵ�ѡ���Ѵ��ڣ��޷���ӣ�");
			return fun_menu(); 
		}else if(singer_num[i].id==0) break;
	}
	if(i==10){
		printf("��ǰ�޷������ѡ�֣�");
		return fun_menu();
	}
	singer_num[i].id=num;     //������Ÿ�ֵ����ѡ��
	printf("�������ѡ�ֵ����֣�");      //����µ�ѡ�ֵ����� 
	scanf("%s",&singer_num[i].name); 
	printf("�������ѡ�ֵ��Ա�"); 
	scanf("%s",&singer_num[i].sex); 
	printf("�������ѡ�ֵĸ������֣�");    //���ѡ�ֵĸ������� 
	scanf("%s",&singer_num[i].song);  
	printf("��Ϣ��ӳɹ���");
	return fun_menu(); 
};

int fun_order(){      //������
	int max,i,j,k;
	fun_read();
	for(j=1; j<10; j++){
		for(i=0,max=0,k=10; i<10; i++){
			if(max<score[i]){
				max=score[i];
				k=i;
			}
		}
		if(singer_num[k].id==0){score[k]=0;continue;} 
		printf("��%d����%s\t�÷֣�%d\t��ţ�%d\t�������ƣ�%s \n",j,singer_num[k].name,score[k],singer_num[k].id,singer_num[k].song);
		score[k]=0;
	}
	fun_read();
	return fun_menu();
};

int fun_delect(){       //ɾ������
	int i,num;
	printf("��������Ҫɾ����ѡ�ֵ���ţ�"); 
	scanf("%d",&num);
		for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("������%s\t��ţ�%d\t�Ա�%c \t�������ƣ�%s\n",singer_num[i].name,singer_num[i].id,singer_num[i].sex,singer_num[i].song);
			break;
		}
	}
	if(i==10){printf("��ѡ����Ų����ڣ�\n");return fun_menu();}
	printf("��ȷ��ɾ����ѡ�֣�(1��ȷ��)��");
	scanf("%d",&num);
	if(num==1){
		singer_num[i].id=0;
		printf("ɾ���ɹ���");
		return fun_menu(); 
	}else{
		printf("���ѷ���ɾ����ѡ�֣�");
		return fun_menu(); 
	}
};

int fun_average(){    //���ۺϳɼ����� 
	int i;
	int num[5];      //���ڱ�����λ��ί�����ķ��� 
	int max,min,sum;
	printf("��������λ��ί�����ķ���(100����)��");
	scanf("%d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4]); 
	max=num[0];min=num[0];sum=num[0];
	for(i=1; i<5; i++){
		if(max>num[i]) min=num[i];
		if(max<=num[i]) max=num[i];
		sum+=num[i];
	}
	sum=(sum-max-min)/3.0;   //ȥ��һ����߷֣�ȥ��һ����ͷ�,��ƽ����
	return sum;
};

int fun_save(){    //�����ۺϳɼ����� 
    //���ۺϳɼ����ݱ��浽file1.txt�����ļ���   
    int i;
    FILE *fpWrite=fopen("file1.txt","w");  
    if(fpWrite==NULL)  
    {
        printf("�޷����ļ�\n");
		exit(0);  
    }
   	for(i=0; i<10; i++){
   		fprintf(fpWrite,"%d ",score[i]); 
	} 
    fclose(fpWrite); 
	return 0; 
};

fun_read(){  	  //��ȡ�ۺϳɼ����� 
    //��file1.txt�����ļ��ж����ɼ�����  
    int i;
    FILE *fpRead=fopen("file1.txt","r");  
    if(fpRead==NULL)  
    {  
        printf("�޷����ļ�\n");
		exit(0);  
    }  
    for(i=0;i<10;i++) fscanf(fpRead,"%d ",&score[i]); 
    fclose(fpRead); 
    return 0;
};

int fun_menu(){       //�˵����� 
	loop:                                    //�������ʱ�����ش���� 
	printf("\n1����������\n");
	printf("2������ѡ����Ϣ\n");
	printf("3���޸�ѡ����Ϣ\n");
	printf("4�����ѡ����Ϣ\n");
	printf("5��ѡ�ֳɼ�����\n");
	printf("6��ɾ��ѡ����Ϣ\n"); 
	printf("0���˳�\n");
	printf("��ѡ����Ҫѡ��Ĺ��ܣ�"); 
	fun_read();
	int power;
	scanf("%d",&power);
	switch(power){
		case 1: fun_grade();break;
		case 2: fun_search();break;
		case 3: fun_cheak();break;
		case 4: fun_add();break;
		case 5: fun_order();break;
		case 6: fun_delect();break;
		case 0: exit(0); 
		default :printf("�������������ѡ��"); goto loop; 
	}
	return 0; 	
};


