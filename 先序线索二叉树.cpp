#include <bits/stdc++.h>

#define fi first
#define se second
using namespace std;
//线序二叉树结构体
typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild;
    int lTag; //标记左儿子是否是前驱， 1为前驱，0为真正的左儿子
    struct BiThrNode *rchild;
    int rTag; //跟上面同理
} BiThrNode, *BiThrTree;
BiThrNode *preNode = NULL;
BiThrTree p = NULL; //这行没用
//将一颗二叉树先序线索化
void preOrderThreading(BiThrNode *pNode)
{
    if (pNode != NULL)             //当前点为空那么对其他点的影响是可有可无的，节点为空，他也没有什么数据域和指针域了，说明前驱节点可以更新左右儿子节点信息
                                   //或者你可以把
    {                              //当前点为空的例子举出来，比如这棵树本来就是空的，左儿子遍历到空树了，右儿子遍历到空树了
        if (pNode->lchild == NULL) //当前节点左儿子为空，因为是先序遍历，所以我们应该更新当前节点的左指针域到前驱
        {
            pNode->lchild = preNode;
            pNode->lTag = 1;
        }
        if (preNode != NULL && preNode->rchild == NULL) //判断前驱节点的右指针域是否非空，如果是非空，说明当前节点为pre的右儿子
        {                                               //如果是空，就应该把pre的右指针域更新为当前节点p，完成线索化
            preNode->rchild = pNode;
            preNode->rTag = 1;
            // cout << preNode->data << "***" << endl;
        }
        preNode = pNode; //转移pre到当前节点

        if (pNode->lTag == 0) //看是否有左子树，继续递归
        {
            preOrderThreading(pNode->lchild);
        }
        if (pNode->rTag == 0) //看是否有右子树，继续递归
        {
            preOrderThreading(pNode->rchild);
        }
        // cout << pNode->data << " " << pNode->lTag << " " << pNode->rTag << " " << endl; // pNode->lchild->data << " " << pNode->rchild->data << endl;
        //回溯
    }
}
// 创建一棵线序二叉树
/*
     A
     / \
    B   C
   / \   \
  D   E   F
*/
BiThrNode *createBiThrTree()
{
    BiThrNode *A = (BiThrNode *)malloc(sizeof(BiThrNode));
    A->data = 'A';
    A->lTag = 0;
    A->rTag = 0;
    A->lchild = NULL;
    A->rchild = NULL;

    BiThrNode *B = (BiThrNode *)malloc(sizeof(BiThrNode));
    B->data = 'B';
    B->lTag = 0;
    B->rTag = 0;
    B->lchild = NULL;
    B->rchild = NULL;

    BiThrNode *C = (BiThrNode *)malloc(sizeof(BiThrNode));
    C->data = 'C';
    C->lTag = 0;
    C->rTag = 0;
    C->lchild = NULL;
    C->rchild = NULL;
    BiThrNode *D = (BiThrNode *)malloc(sizeof(BiThrNode));
    D->data = 'D';
    D->lTag = 0;
    D->rTag = 0;
    D->lchild = NULL;
    D->rchild = NULL;
    BiThrNode *E = (BiThrNode *)malloc(sizeof(BiThrNode));
    E->data = 'E';
    E->lTag = 0;
    E->rTag = 0;
    E->lchild = NULL;
    E->rchild = NULL;
    BiThrNode *F = (BiThrNode *)malloc(sizeof(BiThrNode));
    F->data = 'F';
    F->lTag = 0;
    F->rTag = 0;
    F->lchild = NULL;
    F->rchild = NULL;

    A->lchild = B;
    A->rchild = C;
    B->lchild = D;
    B->rchild = E;
    C->rchild = F;

    return A; // 返回根节点
}

void check(BiThrNode *root)
{
    if (root)
    {
        cout << root->data << " " << root->lTag << " " << root->rTag << endl;
        if (root->lTag == 0)
        {
            check(root->lchild);
        }
        if (root->rTag == 0)
        {
            check(root->rchild);
        }
    }
}
void solve()
{
    BiThrNode *root = createBiThrTree();
    preOrderThreading(root);
    check(root);//检查是否正确(lTag,rTag);
}

int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
