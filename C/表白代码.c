#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#include<windows.h> 
int main(){
	int k = 1;         
	char a[12],name[12] ="������",string[] = "������: �Ұ��㣡"; 
	printf("����������ϲ�����˵����֣�");
	scanf("%s",a);       //�ж�������˵����֡� 
	if(strcmp(a,name)==0){   
		printf("%s\n",string);
		printf("\n"); printf("\n"); printf("\n");
		printf("  *******           *             **       *              *   *********           *         *       **        *         * \n");
		printf("     *              *            *  *       *            *    *                    *       *       *  *       *         * \n");
		printf("     *              *           *    *       *          *     *                     *     *       *    *      *         * \n");
		printf("     *              *          *      *      *          *     *                      *   *       *      *     *         * \n");
		printf("     *              *         *        *      *        *      *                       * *       *        *    *         * \n");
		printf("     *              *        *          *      *      *       *********                *       *          *   *         * \n");
		printf("     *              *         *        *       *      *       *                        *        *        *    *         * \n");
		printf("     *              *          *      *         *    *        *                        *         *      *     *        *  \n");
		printf("     *              *           *    *          *    *        *                        *          *    *       *      *   \n");
		printf("     *              *            *  *            *  *         *                        *           *  *         *    *    \n");
		printf("  *******           ********      **              *           **********               *            **            **      \n");
		} 
		else{
			printf("��Ȼ�����ң��Ǿ��ټ��ˣ�"); 
			sleep(1000);
			system("warning.vbs");  //ִ���ļ����Զ��ػ� 
		}
	return 0;
}

