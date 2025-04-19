//
// StuList.h文件包含了顺序表结构的类型描述、基本操作的实现
//

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status; // Status 是函数返回值类型，其值是函数结果状态代码。

typedef struct
{
    string num;      // 学号
    string name;     // 姓名
    string major;    // 专业
    string password; // 登录密码
    string b_book;   // 借阅的图书名
} student;           // 定义用户信息类型student

typedef student ElemType; 

typedef struct LNode
{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;     // 定义链表节点类型和链表类型

Status InitList(LinkList &L) // 初始化
{
    // 构造一个空的链表L
    L = new LNode;
    L->next = NULL; // 头结点指针域为空
    return OK;
}

Status GetElem(LinkList L, int i, ElemType &e) // 取值
{
    // 在链表L中取第i个元素的值，赋给e
    LinkList p = L->next;
    int j = 1; // j为计数器，初始为1
    while (p && j < i)
    { // p不为空且j小于i时循环继续
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR; // 第i个元素不存在
    e = p->data;
    return OK;
}

string LocateElem(LinkList L, string &stu_num) // 按学号查找，有返回学号，没有返回空；
{
    LinkList p = L->next;
    while (p)
    {
        if (p->data.num == stu_num)
        {
            stu_num = p->data.num; // 更新 stu_num 为找到的学号
            return stu_num;
        }
        p = p->next;
    }
    return ""; // 未找到匹配的学号，返回空字符串
}

Status ListInsert(LinkList &L, int i, ElemType &e) // 插入
{
    // 在链表L中第i个位置前插入元素e
    LinkList p = L;
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR; // 第i个元素不存在
    LinkList s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList &L, int i) // 删除
{
    // 在链表L中删除第i个元素
    LinkList p = L;
    int j = 0;
    while (p->next && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return ERROR; // 第i个元素不存在
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}
