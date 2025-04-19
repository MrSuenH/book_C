// �㷨7.4�������������ĵݹ����
// �㷨7.5�������������Ĳ���
// �㷨7.6�������������Ĵ���
// �㷨 7.7��������������ɾ��

typedef struct
{
	string id;	  // ISBN
	string name;  // ����
	double price; // ����
	int num;	  // ���
} Book;			  // ����ͼ����Ϣ��������

typedef string Keytype; // ���ҹؼ�������

typedef struct BSTNode
{
	Book data;				  // ���������,������Ԫ��
	BSTNode *lchild, *rchild; // ���Һ���ָ��
} BSTNode, *BSTree;			  // �����������ڵ㼰���ṹ����

// �㷨7.4�������������ĵݹ����
BSTree SearchBST(BSTree T, Keytype key)
{ // ����ISBN�Ų���
	// �ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ��
	// �����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
	if ((!T) || key == T->data.id)
		return T; // ���ҽ���
	else if (key < T->data.id)
		return SearchBST(T->lchild, key); // ���������м�������
	else
		return SearchBST(T->rchild, key); // ���������м�������
} // SearchBST

// �㷨7.5�������������Ĳ���
void InsertBST(BSTree &T, Book e)
{
	// ������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ��������Ԫ��
	if (!T)
	{								  // �ҵ�����λ�ã��ݹ����
		BSTree S = new BSTNode;		  // �����½��*S
		S->data = e;				  // �½��*S����������Ϊe
		S->lchild = S->rchild = NULL; // �½��*S��ΪҶ�ӽ��
		T = S;						  // ���½��*S���ӵ����ҵ��Ĳ���λ��
	}
	else if (e.id < T->data.id)
		InsertBST(T->lchild, e); // ��*S����������
	else if (e.id > T->data.id)
		InsertBST(T->rchild, e); // ��*S����������
} // InsertBST

BSTNode *FindMin(BSTree T)
{
	BSTNode *p;
	if (T == NULL)
		return NULL; // �������ؿ�ָ��
	p = T;
	while (p->lchild) // ������ߵ�
	{
		p = p->lchild;
	}
	return p;
}

// �㷨 7.7��������������ɾ��
void DeleteBST(BSTree &T, Keytype key)
{
	BSTNode *temp;
	// �Ӷ���������T��ɾ���ؼ��ֵ���key�Ľ��
	if (!T)
		return; // ������ɾ��ʧ��
	/*�Ӹ���ʼ���ҹؼ��ֵ���key�Ľ��*p*/
	if (T->data.id > key)
		DeleteBST(T->lchild, key); // ��T���������еݹ�ɾ��
	else if (T->data.id < key)
		DeleteBST(T->rchild, key); // ��T���������еݹ�ɾ��
	else
	{ // �ҵ������������ɾ��
		if ((T->lchild) && (T->rchild))
		{										 // ���Һ��Ӷ���
			temp = FindMin(T->rchild);			 // ����������С�Ľڵ�temp
			T->data = temp->data;				 // �ú�����T���
			DeleteBST(T->rchild, temp->data.id); // ��������ɾ��temp���
		} // if
		else
		{
			temp = T;
			if (!T->lchild)
			{				   // ֻ���Һ���
				T = T->rchild; // ֱ�����Һ������
			}
			else if (!T->rchild)
			{				   // ֻ������
				T = T->lchild; // ֱ�����������
			}
			delete temp; // Ҷ��ֱ��ɾ��
		}
	}

} // DeleteBST
