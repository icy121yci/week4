#include <stdio.h>
#include <windows.h>

#include "binary_sort_tree.h"

int main() {
	
	NodePtr T;	//根节点 
	BST_init(&T) ;//初始化 
    int flag=1;
	int menu; 
		while(flag) {

		printf("---------二叉排序树实现---------\n");
		printf("--------1.插入------------------\n");
		printf("--------2.查找-----------------\n");
		printf("--------3.删除-----------------\n");
		printf("--------4.递归遍历（先中后）---\n");
		printf("--------5.非递归遍历（先中后）-\n");	
		printf("--------6.层序遍历-------------\n");
		printf("--------7.退出-----------------\n");
	
		printf("请输入数字(1~7)：\n");
		scanf("%d",&menu);
		switch(menu){
				case 1:					
					printf("请输入整数：\n输入0时表示结束输入\n");
					ElemType a;
					scanf("%d",&a);
					while (a){
						BST_insert( &T, a);
						printf("下一个：\n");
						scanf("%d",&a);
					}
					system("pause");
					system("cls");				 
					break;
				case 2:			 
						if  (T==NULL){
							printf("目前没有数据\n");
							Sleep(1000); 
							system("cls");
							break;
						}
					printf("你想找的整数是；\n");
					scanf("%d",&menu);
					menu=BST_search(T, menu);
					if(menu){
						printf("有这个数\n");
					}else{
						printf("没有这个数\n");
					}
					system("pause");
					system("cls");
					break;
						
				case 3:
					printf("你删除的整数是；\n");
					scanf("%d",&menu);
					menu=BST_delete(&T, menu) ;
					if(menu){
						printf("删除成功\n"); 
					}else{
						printf("没有这个数\n");
					}
					system("pause");
					system("cls"); 
					break;
				case 4:
						if  (T==NULL){
							printf("目前没有数据\n");
							Sleep(1000); 
							system("cls");
							break;
						}
					printf("先序排列：\n") ;
					BST_preorderR(T);
					printf("中序排列：\n") ;
					BST_inorderR(T);
					printf("后序排列：\n") ;
					BST_postorderR(T);
					
					system("pause");
					system("cls");
					break;
				case 5:
						if  (T==NULL){
							printf("目前没有数据\n");
							Sleep(1000); 
							system("cls");
							break;
						}
					printf("(bug)先序排列：\n") ;
					BST_preorderI(T);
					printf("(bug)中序排列：\n") ;
					BST_inorderI(T);
					printf("(bug)后序排列：\n") ;
					BST_postorderI(T);
					
					system("pause");
					system("cls"); 
					break;
				case 6:
					BST_levelOrder(T);
					system("pause");
					system("cls");
					break;
				case 7:
					flag=false;
					break;
				
				default:
					printf("请输入有效数字(1~7)：\n");
					Sleep(1000); 
					system("cls");	
		}
}
    return 0;
}
