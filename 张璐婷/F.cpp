#include<stdio.h>

/*
找到树的根节点，根节点到三个子节点的路径长度和为最短距离（去除一次公共边）
*/

#define MaxSize 200010
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;

typedef struct HNode{
    int elem;
    LNode *firstArc;
}HNode;

typedef struct TNode{
    int n;
    HNode tree[MaxSize];
}TNode;

//链表插入
void InsertLNode(TNode *T,int a,int b){

}

int main(void){
    int n,a,b;
    TNode *T;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d",&a,&b);
        InsertLNode(T,a,b);
        InsertLNode(T,b,a);
    }
}