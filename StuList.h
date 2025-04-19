//
// StuList.h�ļ�������˳���ṹ����������������������ʵ��
//

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status; // Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣

typedef struct
{
    string num;      // ѧ��
    string name;     // ����
    string major;    // רҵ
    string password; // ��¼����
    string b_book;   // ���ĵ�ͼ����
} student;           // �����û���Ϣ����student

typedef student ElemType; 

typedef struct LNode
{
    ElemType data;      // ������
    struct LNode *next; // ָ����
} LNode, *LinkList;     // ��������ڵ����ͺ���������

Status InitList(LinkList &L) // ��ʼ��
{
    // ����һ���յ�����L
    L = new LNode;
    L->next = NULL; // ͷ���ָ����Ϊ��
    return OK;
}

Status GetElem(LinkList L, int i, ElemType &e) // ȡֵ
{
    // ������L��ȡ��i��Ԫ�ص�ֵ������e
    LinkList p = L->next;
    int j = 1; // jΪ����������ʼΪ1
    while (p && j < i)
    { // p��Ϊ����jС��iʱѭ������
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR; // ��i��Ԫ�ز�����
    e = p->data;
    return OK;
}

string LocateElem(LinkList L, string &stu_num) // ��ѧ�Ų��ң��з���ѧ�ţ�û�з��ؿգ�
{
    LinkList p = L->next;
    while (p)
    {
        if (p->data.num == stu_num)
        {
            stu_num = p->data.num; // ���� stu_num Ϊ�ҵ���ѧ��
            return stu_num;
        }
        p = p->next;
    }
    return ""; // δ�ҵ�ƥ���ѧ�ţ����ؿ��ַ���
}

Status ListInsert(LinkList &L, int i, ElemType &e) // ����
{
    // ������L�е�i��λ��ǰ����Ԫ��e
    LinkList p = L;
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR; // ��i��Ԫ�ز�����
    LinkList s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList &L, int i) // ɾ��
{
    // ������L��ɾ����i��Ԫ��
    LinkList p = L;
    int j = 0;
    while (p->next && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return ERROR; // ��i��Ԫ�ز�����
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}
