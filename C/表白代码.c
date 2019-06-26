#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#include<windows.h> 
int main(){
	int k = 1;         
	char a[12],name[12] ="郭明德",string[] = "郭明德: 我爱你！"; 
	printf("请输入你最喜欢的人的名字：");
	scanf("%s",a);       //判断输入的人的名字。 
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
			printf("既然不是我，那就再见了！"); 
			sleep(1000);
			system("warning.vbs");  //执行文件，自动关机 
		}
	return 0;
}

