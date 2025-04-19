// 算法7.4　二叉排序树的递归查找
// 算法7.5　二叉排序树的插入
// 算法7.6　二叉排序树的创建
// 算法 7.7　二叉排序树的删除

typedef struct
{
	string id;	  // ISBN
	string name;  // 书名
	double price; // 定价
	int num;	  // 库存
} Book;			  // 定义图书信息数据类型

typedef string Keytype; // 查找关键字类型

typedef struct BSTNode
{
	Book data;				  // 结点数据域,存数据元素
	BSTNode *lchild, *rchild; // 左右孩子指针
} BSTNode, *BSTree;			  // 二叉排序树节点及树结构描述

// 算法7.4　二叉排序树的递归查找
BSTree SearchBST(BSTree T, Keytype key)
{ // 根据ISBN号查找
	// 在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素
	// 若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
	if ((!T) || key == T->data.id)
		return T; // 查找结束
	else if (key < T->data.id)
		return SearchBST(T->lchild, key); // 在左子树中继续查找
	else
		return SearchBST(T->rchild, key); // 在右子树中继续查找
} // SearchBST

// 算法7.5　二叉排序树的插入
void InsertBST(BSTree &T, Book e)
{
	// 当二叉排序树T中不存在关键字等于e.key的数据元素时，则插入该元素
	if (!T)
	{								  // 找到插入位置，递归结束
		BSTree S = new BSTNode;		  // 生成新结点*S
		S->data = e;				  // 新结点*S的数据域置为e
		S->lchild = S->rchild = NULL; // 新结点*S作为叶子结点
		T = S;						  // 把新结点*S链接到已找到的插入位置
	}
	else if (e.id < T->data.id)
		InsertBST(T->lchild, e); // 将*S插入左子树
	else if (e.id > T->data.id)
		InsertBST(T->rchild, e); // 将*S插入右子树
} // InsertBST

BSTNode *FindMin(BSTree T)
{
	BSTNode *p;
	if (T == NULL)
		return NULL; // 空树返回空指针
	p = T;
	while (p->lchild) // 找最左边的
	{
		p = p->lchild;
	}
	return p;
}

// 算法 7.7　二叉排序树的删除
void DeleteBST(BSTree &T, Keytype key)
{
	BSTNode *temp;
	// 从二叉排序树T中删除关键字等于key的结点
	if (!T)
		return; // 空树，删除失败
	/*从根开始查找关键字等于key的结点*p*/
	if (T->data.id > key)
		DeleteBST(T->lchild, key); // 在T的左子树中递归删除
	else if (T->data.id < key)
		DeleteBST(T->rchild, key); // 在T的右子树中递归删除
	else
	{ // 找到，分情况讨论删除
		if ((T->lchild) && (T->rchild))
		{										 // 左右孩子都有
			temp = FindMin(T->rchild);			 // 右子树找最小的节点temp
			T->data = temp->data;				 // 用后继替代T结点
			DeleteBST(T->rchild, temp->data.id); // 到右子树删除temp结点
		} // if
		else
		{
			temp = T;
			if (!T->lchild)
			{				   // 只有右孩子
				T = T->rchild; // 直接拿右孩子替代
			}
			else if (!T->rchild)
			{				   // 只有左孩子
				T = T->lchild; // 直接拿左孩子替代
			}
			delete temp; // 叶子直接删除
		}
	}

} // DeleteBST
