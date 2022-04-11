#include "binary_sort_tree.h"

#include <windows.h>


Status BST_init(NodePtr*T){
	*T=NULL; 
	return succeed;
}

Status BST_insert(NodePtr* t, ElemType x) {
	if(*t==NULL){
		*t=(NodePtr)malloc(sizeof(Node));
		(*t)->value =x;
		(*t)->left=(*t)->right=NULL;
		
	}else if((*t)->value>x){//比根结点小 在左边 
		BST_insert(&(*t)->left , x);//递归到空
	}
	else if((*t)->value <x){ //比根结点da 在you边 
		BST_insert(&(*t)->right , x);
	}
	return succeed;	
}
//递归中序遍历 
Status BST_inorderR(NodePtr t){
	if(t==NULL)
		return succeed;
		
	BST_inorderR(t->left);
	printf("%d\n",t->value );
	BST_inorderR(t->right );	
	return succeed;
} 
//递归前序
 Status BST_preorderR(NodePtr t){
 	if(t==NULL)
		return succeed;
	printf("%d\n",t->value );	
	BST_inorderR(t->left);	
	BST_inorderR(t->right );	
	return succeed;	
 } 
 //递归后序
 Status BST_postorderR(NodePtr t){
 	if(t==NULL)
		return succeed;
		
	BST_inorderR(t->left);	
	BST_inorderR(t->right );
	printf("%d\n",t->value );	
	return succeed;	
 } 
 //查找
 Status BST_search(NodePtr t, ElemType x){
 	
	if(t==NULL){		
	//	*p=f;
		return false;	 
	}
	if(t->value ==x){
	//	*p=T;
 		return true;
	}	
		
 	if(t->value < x){
 		return BST_search(t->right , x);//大于根节点 在右边 
	 } 
	if(t->value > x){
 		return BST_search(t->left  , x);//小于根节点 在左边 
	} 

} 
//删除
Status BST_delete(NodePtr* T, ElemType x){
	if(!(*T))
		return false;
	else
	{
		if((*T)->value<x)//da you
			return BST_delete(&(*T)->right ,x);
		else if ((*T)->value >x)//小
			 return BST_delete(&(*T)->left  ,x);
		else if(x==(*T)->value){
			NodePtr q,s;
			NodePtr*p=T;
			if ((*p)->right==NULL)
			{
				q=*p; *p=(*p)->left; free(q);
			}				
			else if((*p)->left==NULL) /* 只需重接它的右子树 */
			{
				q=*p; *p=(*p)->right; free(q);
			}
			else /* 左右子树均不空 */
			{
				q=*p; s=(*p)->left;
				while(s->right) /* 转左，然后向右到尽头（找待删结点的前驱） */
				{
					q=s;
					s=s->right;
				}
				(*p)->value=s->value; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
				if(q!=*p)
					q->right=s->left; /*  重接q的右子树 */ 
				else
					q->left=s->left; /*  重接q的左子树 */
				free(s);
			}
					return true;
					
		}
	}
} 
//非递归 先序 
Status BST_preorderI(NodePtr t){
	LinkStack s;
	InitStack(&s);
	if(t==NULL)
		return succeed;
	NodePtr p=t;
	Push(&s,*p);
	while(!(StackEmpty(s)))
	{
		printf("%d\n",p->value );
		if(p->right )
		{		
			Push(&s,*(p->right ));
		}
		if(p->left  )
		{		
			p=p->left ;
		}
		else
		{
			GetTop(s,p);
			Pop(&s,p);
			
		}
	}
	ClearStack(&s);
	return succeed; 
}
//中序 非递归 
Status BST_inorderI(NodePtr t){
	if(t==NULL)
		return succeed;
	NodePtr p=t;
	LinkStack s;
	InitStack(&s);
	while(!(StackEmpty(s))||p) 
	{
		if(p)
		{
			Push(&s,*(p->right ));
			p=p->left ;
		}
		else
		{
			GetTop(s,p);
			Pop(&s,p);
			printf("%d\n",p->value );
			p=p->right ;
		}
	}
	return succeed;
}
Status BST_postorderI(NodePtr t){
	LinkStack s;
	InitStack(&s);
	NodePtr pcur,plast;
	pcur=t;
	plast=NULL;
	while(pcur)
	{
		Push(&s,*pcur);	
		pcur=pcur->left ;
	}
	while(!(StackEmpty(s)))
	{
		GetTop(s,pcur);
		Pop(&s,pcur);
		if(pcur->right ==NULL||pcur->left ==plast){
			printf("%d\n",pcur->value );
		}
		else
		{
			Push(&s,*pcur);
			pcur=pcur->right ;
			while(pcur){
				Push(&s,*pcur);
				pcur=pcur->left ;
			}
		}
	}
	return succeed;
} 

//层序遍历
Status BST_levelOrder(NodePtr t){
	LinkQueue q;
	InitQueue(&q);
	if(!t)
	{
		printf("目前没有数据\n");
		return failed;
	}
	EnQueue(&q,*t);//更结点入
	while(!(QueueEmpty(q)) )
	{
		DeQueue(&q,t);
		printf("%d\n",t->value );
		if(t->left )
			EnQueue(&q,*(t->left));
		if(t->right )
			EnQueue(&q,*(t->right ));
	}
	return succeed;
} 

/*  构造一个空栈S */
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}
///若栈不空，则用e返回S的栈顶元素，
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* 把当前的栈顶元素赋值给新结点的直接后继，见图中① */
        S->top=s;         /* 将新的结点s赋值给栈顶指针，见图中② */
        S->count++;
        return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* 将栈顶结点赋值给p，见图中③ */
        S->top=S->top->next;    /* 使得栈顶指针下移一位，指向后一结点，见图中④ */
        free(p);                    /* 释放结点p */        
        S->count--;
        return OK;
}
/*是否为空栈*/ 
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}
//清杖 
Status ClearStack(LinkStack *S)
{ 
        LinkStackPtr p,q;
        p=S->top;
        while(p)
        {  
                q=p;
                p=p->next;
                free(q);
        } 
        S->count=0;
        return OK;
}

/* 构造一个空队列Q */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(1);
	Q->front->next=NULL;
	return OK;
}

/* 若Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* 插入元素e为Q的新的队尾元素 */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* 存储分配失败 */
		exit(1);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
	Q->rear=s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
	return OK;
}

/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* 将欲删除的队头结点暂存给p，见图中① */
	*e=p->data;				/* 将欲删除的队头结点的值赋值给e */
	Q->front->next=p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
	if(Q->rear==p)		/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ */
		Q->rear=Q->front;
	free(p);
	return OK;
}
