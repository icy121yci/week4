//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#include <stdio.h>

#define true 1
#define false 0
#define succeed 1
#define failed 0

typedef int Status;
typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root ;
} BinarySortTree, *BinarySortTreePtr;


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(NodePtr* T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr *t, ElemType x) ;

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(NodePtr* T, ElemType x);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr t, ElemType x);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr t);

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr t);

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr t);

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr t);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr t);

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr t);

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr t);



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;


typedef Node SElemType;
/* ��ջ�ṹ */

typedef struct StackNode
{
        SElemType data;
        struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
        LinkStackPtr top;
        int count;
}LinkStack;
//��ʼ�� 
Status InitStack(LinkStack *S);
//S��ջ��Ԫ��
Status GetTop(LinkStack S,SElemType *e); 
//��ջ 
Status Push(LinkStack *S,SElemType e);
//��ջ 
Status Pop(LinkStack *S,SElemType *e);
 //�Ƿ�Ϊ��ջ
Status StackEmpty(LinkStack S);

Status ClearStack(LinkStack *S);
 


typedef Node QElemType;
typedef struct QNode	/* ���ṹ */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ���е�����ṹ */
{
   QueuePtr front,rear; /* ��ͷ����βָ�� */
}LinkQueue;

Status DeQueue(LinkQueue *Q,QElemType *e);

Status EnQueue(LinkQueue *Q,QElemType e);

Status GetHead(LinkQueue Q,QElemType *e);

Status QueueEmpty(LinkQueue Q);

Status InitQueue(LinkQueue *Q);
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
