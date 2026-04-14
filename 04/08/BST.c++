#include<bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 非递归
BiTNode* BSTSearch(BiTree T,ElemType key){
    while(T!=NULL && key!=T->data){
        if(key < T->data){
            T=T->lchild;
        }else{
            T=T->rchild;
        }
    }
    return T;
}

//递归方式

BiTNode* BSTSearch2(BiTree T,ElemType key){
    if(T->data == key){
        return T;
    }else if(T->data < key){
        return BSTSearch2(T->lchild,key);
    }else{
        return BSTSearch2(T->rchild,key);
    }
}

bool BST_Insert(BiTree T,ElemType key){
    //如果是空树
    if(T == NULL){
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T ->data = key;
        T->lchild = NULL;
        T ->rchild = NULL;
        return true;
    }
    if(T->data == key){
        return false;
    }
    if(T->data < key){
        return BST_Insert(T->lchild,key);
    }
    if(T->data > key){
        return BST_Insert(T->rchild,key);
    }
}



//二叉搜索树的删除

BiTNode* BST_Delete(BiTree T,ElemType key){
    if(T == NULL) return NULL;

    if(key<T->data){
        T->lchild = BST_Delete(T->lchild,key);
    }
    else if(key > T->data){
        T->rchild = BST_Delete(T->rchild,key);
    }
    else{
        if(T->lchild == NULL){
            return T->rchild;
        }
        else if(T->rchild == NULL){
            return T->lchild;
        }
        else{
            BiTNode*p=T->rchild;
            while(p->lchild){
                p = p->rchild;
            }
            T->data = p->data;
            T->rchild = BST_Delete(T->rchild,p->data);
        }
    }
    return T;
}

//二叉搜索树构造
BiTree CreateBST(ElemType a[],int n){
    BiTree T = NULL;
    
    for(int i = 0;i < n;i++){
        BST_Insert(T,a[i]);
    }
    return T;
}