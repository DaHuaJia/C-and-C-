#include<iostream>
using namespace std;

main(int argc,char *argv[]){
	//C�����������������в���������ֻ�ܴ�������������һ�������α�����һ�������顣
	//�������Ĳ����ɲ���ϵͳ���룬���еĲ���ϵͳ����ͼ�λ��ģ������Ĵ��붼�����������ġ����Խ���cmd���崫����� 
	int i=0;
	cout<<"��������������Ĳ���Ϊ��"<<endl;
	cout<<argc;
	while(argv[i]!='\0'){
		cout<<argv[i]<<endl;
		i++; 
	} 
	return 0;
} 
