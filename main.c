#include <stdio.h>
#include <windows.h>

#include "binary_sort_tree.h"

int main() {
	
	NodePtr T;	//���ڵ� 
	BST_init(&T) ;//��ʼ�� 
    int flag=1;
	int menu; 
		while(flag) {

		printf("---------����������ʵ��---------\n");
		printf("--------1.����------------------\n");
		printf("--------2.����-----------------\n");
		printf("--------3.ɾ��-----------------\n");
		printf("--------4.�ݹ���������к�---\n");
		printf("--------5.�ǵݹ���������к�-\n");	
		printf("--------6.�������-------------\n");
		printf("--------7.�˳�-----------------\n");
	
		printf("����������(1~7)��\n");
		scanf("%d",&menu);
		switch(menu){
				case 1:					
					printf("������������\n����0ʱ��ʾ��������\n");
					ElemType a;
					scanf("%d",&a);
					while (a){
						BST_insert( &T, a);
						printf("��һ����\n");
						scanf("%d",&a);
					}
					system("pause");
					system("cls");				 
					break;
				case 2:			 
						if  (T==NULL){
							printf("Ŀǰû������\n");
							Sleep(1000); 
							system("cls");
							break;
						}
					printf("�����ҵ������ǣ�\n");
					scanf("%d",&menu);
					menu=BST_search(T, menu);
					if(menu){
						printf("�������\n");
					}else{
						printf("û�������\n");
					}
					system("pause");
					system("cls");
					break;
						
				case 3:
					printf("��ɾ���������ǣ�\n");
					scanf("%d",&menu);
					menu=BST_delete(&T, menu) ;
					if(menu){
						printf("ɾ���ɹ�\n"); 
					}else{
						printf("û�������\n");
					}
					system("pause");
					system("cls"); 
					break;
				case 4:
						if  (T==NULL){
							printf("Ŀǰû������\n");
							Sleep(1000); 
							system("cls");
							break;
						}
					printf("�������У�\n") ;
					BST_preorderR(T);
					printf("�������У�\n") ;
					BST_inorderR(T);
					printf("�������У�\n") ;
					BST_postorderR(T);
					
					system("pause");
					system("cls");
					break;
				case 5:
						if  (T==NULL){
							printf("Ŀǰû������\n");
							Sleep(1000); 
							system("cls");
							break;
						}
					printf("(bug)�������У�\n") ;
					BST_preorderI(T);
					printf("(bug)�������У�\n") ;
					BST_inorderI(T);
					printf("(bug)�������У�\n") ;
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
					printf("��������Ч����(1~7)��\n");
					Sleep(1000); 
					system("cls");	
		}
}
    return 0;
}
