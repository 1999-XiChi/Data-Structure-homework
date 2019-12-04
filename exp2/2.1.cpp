#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BinaryTreeNode{
    ElemType Data;
    struct BinaryTreeNode *LChild, *RChild;
}BiTree;

//�������
void PreOrderTransverse(BiTree *t){
    if(t==NULL){
        return;
    }
    printf("%c",t->Data);           //��ӡ�������㣬�˴����Զ�����������
    PreOrderTransverse(t->LChild);  //Ȼ���������������
    PreOrderTransverse(t->RChild);  //����������������
}

//�������
void InOrderTransverse(BiTree *t){
    if(t==NULL){
        return;
    }
    InOrderTransverse(t->LChild);  //�������������������
    printf("%c",t->Data);          //��ӡ�������㣬�˴����Զ�����������
    InOrderTransverse(t->RChild);  //����������������������
}


//�������
void PostOrderTransverse(BiTree *t){
    if(t==NULL){
        return;
    }
    PostOrderTransverse(t->LChild);  //�������������������
    PostOrderTransverse(t->RChild);  //Ȼ��������������������
    printf("%c",t->Data);            //����ӡ�������㣬�˴����Զ�����������
}


//�����������������
BiTree *PreCreateBt(BiTree *t){
    char ch;
    ch = getchar();
    if(ch == '#'){                           //����Ϊ#��ʾ���ｨ���ն��������������㷨�Ŀղ���
        t = NULL;
    }
    else{
        t = (BiTree *)malloc(sizeof(BiTree));
        t->Data = ch;                        //��������
        t->LChild = PreCreateBt(t->LChild);  //����������
        t->RChild = PreCreateBt(t->RChild);  //����������
    }
    return t;
}

int main(){
    BiTree *t = NULL;
    printf("PreCreateBt:\n");
    t = PreCreateBt(t);                     
    printf("\nPreOrderTransverse:\n");
	PreOrderTransverse(t);
    printf("\nInOrderTransverse:\n");
    InOrderTransverse(t);
    printf("\nPostOrderTransverse:\n");
    PostOrderTransverse(t);
    printf("\n");
    getchar();
    return 0;
}
