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
		
	}else if((*t)->value>x){//�ȸ����С ����� 
		BST_insert(&(*t)->left , x);//�ݹ鵽��
	}
	else if((*t)->value <x){ //�ȸ����da ��you�� 
		BST_insert(&(*t)->right , x);
	}
	return succeed;	
}
//�ݹ�������� 
Status BST_inorderR(NodePtr t){
	if(t==NULL)
		return succeed;
		
	BST_inorderR(t->left);
	printf("%d\n",t->value );
	BST_inorderR(t->right );	
	return succeed;
} 
//�ݹ�ǰ��
 Status BST_preorderR(NodePtr t){
 	if(t==NULL)
		return succeed;
	printf("%d\n",t->value );	
	BST_inorderR(t->left);	
	BST_inorderR(t->right );	
	return succeed;	
 } 
 //�ݹ����
 Status BST_postorderR(NodePtr t){
 	if(t==NULL)
		return succeed;
		
	BST_inorderR(t->left);	
	BST_inorderR(t->right );
	printf("%d\n",t->value );	
	return succeed;	
 } 
 //����
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
 		return BST_search(t->right , x);//���ڸ��ڵ� ���ұ� 
	 } 
	if(t->value > x){
 		return BST_search(t->left  , x);//С�ڸ��ڵ� ����� 
	} 

} 
//ɾ��
Status BST_delete(NodePtr* T, ElemType x){
	if(!(*T))
		return false;
	else
	{
		if((*T)->value<x)//da you
			return BST_delete(&(*T)->right ,x);
		else if ((*T)->value >x)//С
			 return BST_delete(&(*T)->left  ,x);
		else if(x==(*T)->value){
			NodePtr q,s;
			NodePtr*p=T;
			if ((*p)->right==NULL)
			{
				q=*p; *p=(*p)->left; free(q);
			}				
			else if((*p)->left==NULL) /* ֻ���ؽ����������� */
			{
				q=*p; *p=(*p)->right; free(q);
			}
			else /* �������������� */
			{
				q=*p; s=(*p)->left;
				while(s->right) /* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ���� */
				{
					q=s;
					s=s->right;
				}
				(*p)->value=s->value; /*  sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ�� */
				if(q!=*p)
					q->right=s->left; /*  �ؽ�q�������� */ 
				else
					q->left=s->left; /*  �ؽ�q�������� */
				free(s);
			}
					return true;
					
		}
	}
} 
//�ǵݹ� ���� 
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
//���� �ǵݹ� 
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

//�������
Status BST_levelOrder(NodePtr t){
	LinkQueue q;
	InitQueue(&q);
	if(!t)
	{
		printf("Ŀǰû������\n");
		return failed;
	}
	EnQueue(&q,*t);//�������
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

/*  ����һ����ջS */
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}
///��ջ���գ�����e����S��ջ��Ԫ�أ�
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(LinkStack *S,SElemType e)
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;	/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�̣���ͼ�Т� */
        S->top=s;         /* ���µĽ��s��ֵ��ջ��ָ�룬��ͼ�Т� */
        S->count++;
        return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
        LinkStackPtr p;
        if(StackEmpty(*S))
                return ERROR;
        *e=S->top->data;
        p=S->top;					/* ��ջ����㸳ֵ��p����ͼ�Т� */
        S->top=S->top->next;    /* ʹ��ջ��ָ������һλ��ָ���һ��㣬��ͼ�Т� */
        free(p);                    /* �ͷŽ��p */        
        S->count--;
        return OK;
}
/*�Ƿ�Ϊ��ջ*/ 
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}
//���� 
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

/* ����һ���ն���Q */
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(1);
	Q->front->next=NULL;
	return OK;
}

/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Status GetHead(LinkQueue Q,QElemType *e)
{ 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* �洢����ʧ�� */
		exit(1);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear=s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	*e=p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next=p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	if(Q->rear==p)		/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
		Q->rear=Q->front;
	free(p);
	return OK;
}
