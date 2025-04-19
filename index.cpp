#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <process.h>
using namespace std;

#include "StuList.h"
#include "BSTree.h"

// Book.h
void op_admin_menu();                               // 图书操作界面功能函数
void Insert_book(BSTree &T);                        // 图书录入功能函数
void Delete_book(BSTree &T);                        // 删除图书功能函数
void Modify_Info(BSTree &T);                        // 修改图书信息功能函数
void Search_book(BSTree T);                         // 查找图书功能函数
void PrintInfo(BSTree T);                           // 显示所有图书功能函数
void File_in_Tree(BSTree &T);                       // 数据导入功能函数
void Tree_to_Array(BSTree T, Book array[], int &n); // 二叉排序树的数据导入到数组功能函数
void Tree_out_file(BSTree T);                       // 数据导出功能函数：二叉排序树的数据导出到文件保存功能函数

// Stu.h
void op_user_menu();                                         // 用户操作菜单函数
void login_menu();                                           // 登陆后用户界面菜单函数
void Register(LinkList &L);                                  // 用户注册函数
void Log_in(LinkList L, BSTree &T);                          // 用户登录函数
void Log_out(LinkList &L);                                   // 用户注销函数
void Modify_Password(LinkList &L);                           // 用户密码修改函数
void File_in_List(LinkList &L);                              // 将文件中的数据写入到L
void List_out_file(LinkList L);                              // //表L的数据写回文件book.txt
void PrintList(LinkList L);                                  // 按行输出用户的学号、姓名、专业
void PrintMe(LinkList L, string &num, BSTree T);             // 输出个人信息
void Borrow_op(LinkList &L, string &student_num, BSTree &T); // 借书
void Rerurn_op(LinkList &L, string &student_num, BSTree &T); // 还书

void main_menu()
{
    cout << "/*********欢迎使用图书管理系统*********/" << endl;
    cout << "1. 管理端" << endl;
    cout << "2. 学生端" << endl;
    cout << "0. 退出程序" << endl;
    cout << "请输入您的选择: ";
}

void admin_op(LinkList &L, BSTree &T) // 管理员操作菜单
{
    int op;
    while (true)
    {
        op_admin_menu(); // 管理员操作界面函数
        cin >> op;
        switch (op)
        {
        case 1: // 录入图书
            Insert_book(T);
            break;
        case 2:
            Delete_book(T); // 删除图书
            break;
        case 3: // 修改图书
            Modify_Info(T);
            break;
        case 4: // 显示图书信息
            PrintInfo(T);
            break;
        case 5: // 显示学生信息
            PrintList(L);
            break;
        case 6: // 注销学号账号
            Log_out(L);
            break;
        case 0: // 输入0，保存数据退出程序
            Tree_out_file(T);
            List_out_file(L);
            return;
        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    }
}

void admin_menu(LinkList &L, BSTree &T) // 管理员登录成功后操作
{
    int seq1 = 0;
    while (seq1 < 3)
    {
        string name, pwd;
        string user = "123456";
        string password = "123456";
        cout << "请输入登录的用户名" << endl;
        cin >> name;
        cout << "请输入登录的密码" << endl;
        cin >> pwd;

        if (name == user && pwd == password)
        {
            cout << "登录成功" << endl;
            admin_op(L, T);
            return;
        }
        else
        {
            cout << "账号或者密码错误，请重新输入" << endl;
        }

        seq1++;
    }
    cout << "多次登陆失败！" << endl;
}

void Login_op(LinkList &L, BSTree &T, string student_num) // 登录成功后进行的操作
{
    int op;
    while (true)
    {
        login_menu();
        cin >> op;
        switch (op)
        {
        case 1: // 我的信息
            PrintMe(L, student_num, T);
            break;
        case 2: // 显示图书
            PrintInfo(T);
            break;
        case 3: // 查找图书
            Search_book(T);
            break;
        case 4:
            Borrow_op(L, student_num, T); // 借阅图书
            break;
        case 5: // 归还图书
            Rerurn_op(L, student_num, T);
            break;
        case 6: // 修改登录密码
            Modify_Password(L);
            break;
        case 0: // 保存数据退
            List_out_file(L);
            Tree_out_file(T);
            return;
        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    }
}

void student_menu(LinkList &L, BSTree &T) // 学生端操作菜单
{
    int op;
    while (true)
    {
        op_user_menu(); // 用户操作菜单函数
        cin >> op;
        switch (op)
        {
        case 1: // 注册用户
            Register(L);
            break;
        case 2: // 用户登录
            Log_in(L, T);
            break;
        case 3: // 用户注销
            Log_out(L);
            break;
        case 0: // 保存数据退出程序
            List_out_file(L);
            return;
        default:
            cout << "无效的选择，请重新选择。" << endl;
        }
    }
}

int main()
{
    BSTree T;
    LinkList L;      // 定义单链表变量L
    File_in_Tree(T); // 导入图书数据到二叉排序树T
    File_in_List(L); // 导入用户数据到表L

    int choice;
    while (true)
    {
        main_menu();
        cin >> choice;
        switch (choice)
        {
        case 1: // 管理端
            admin_menu(L, T);
            break;
        case 2: // 学生端
            student_menu(L, T);
            break;
        case 0: // 退出程序
            Tree_out_file(T);
            List_out_file(L);
            return 0;
        default:
            cout << "无效的选择，请重新选择。" << endl;
        }
    }
    return 0;
}

void op_user_menu()
{
    cout << endl;
    cout << "/*********输入数字进行操作选择*********/" << endl;
    cout << "1.注册" << endl;
    cout << "2.登录" << endl;
    cout << "0.保存并退出程序，" << endl;
    cout << endl;
    return;
}

void login_menu()
{
    cout << endl;
    cout << "*********用户界面，输入数字进行操作选择*********" << endl;
    cout << "1.我的信息" << endl;
    cout << "2.显示图书" << endl;
    cout << "3.查找图书" << endl;
    cout << "4.借阅图书" << endl;
    cout << "5.归还图书" << endl;
    cout << "6.修改登录密码" << endl;
    cout << "0.保存并返回上一级菜单" << endl;
}

void Register(LinkList &L) // 注册
{
    ElemType newStudent;

    cout << "输入以下信息进行注册" << endl;
    cout << "学号：" << endl;
    cin >> newStudent.num;
    if (LocateElem(L, newStudent.num) != "")
    {
        cout << "该学号已存在，重新输入" << endl;
        return;
    }
    cout << "姓名：" << endl;
    cin >> newStudent.name;
    cout << "专业：" << endl;
    cin >> newStudent.major;
    cout << "密码：" << endl;
    cin >> newStudent.password;
    newStudent.b_book = "NULL";

    if (ListInsert(L, 1, newStudent) == OK)
    {
        cout << "注册成功" << endl;
    }
    else
    {
        cout << "注册失败，系统错误" << endl;
    }
}

void Log_in(LinkList L, BSTree &T) // 登录
{
    ElemType s;
    int seq = 0;

    cout << "输入学号和密码进行登录" << endl;

    while (seq < 3)
    {
        cout << "学号：" << endl;
        cin >> s.num;

        cout << "密码：" << endl;
        cin >> s.password;

        // 根据学号进行查找
        string stu_name = LocateElem(L, s.num);
        if (stu_name == "")
        {
            cout << "学号不存在，请重新输入" << endl;
        }
        else
        {
            ElemType *foundStudent = nullptr;
            LinkList p = L->next;
            while (p)
            {
                if (p->data.num == s.num)
                {
                    foundStudent = &(p->data);
                    break;
                }
                p = p->next;
            }

            if (foundStudent && foundStudent->password == s.password)
            {
                cout << "登录成功" << endl;
                Login_op(L, T, s.num);
                return;
            }
            else
            {
                cout << "密码错误，请重新输入" << endl;
            }
        }

        seq++;
    }

    cout << "多次尝试登录失败，请稍后再试" << endl;
    return;
}

void Modify_Password(LinkList &L) // 修改密码
{
    string login_user, pass1, pass2;
    cout << "输入学号进行信息修改" << endl;
    cout << "学号：" << endl;
    cin >> login_user;
    string stu_name = LocateElem(L, login_user);
    if (stu_name == "")
    {
        cout << "该用户不存在" << endl;
    }
    else
    {
        cout << "新密码：" << endl;
        cin >> pass1;
        cout << "再次输入新密码：" << endl;
        cin >> pass2;
        while (pass1 != pass2)
        {
            cout << "两次密码不一致，重新输入" << endl;
            cout << "新密码：" << endl;
            cin >> pass1;
            cout << "再次输入新密码：" << endl;
            cin >> pass2;
        }
        L->data.password = pass1;
        cout << "密码修改成功" << endl;
    }

    return;
}

void PrintMe(LinkList L, string &num, BSTree T) // 我的信息
{
    LNode *p = L->next;
    while (p && p->data.num != num)
    {
        p = p->next;
    }

    if (!p)
    {
        cout << "未找到该用户信息" << endl;
        return;
    }

    cout << "/****我的信息****/" << endl;
    cout << "学号：" << p->data.num << endl;
    cout << "姓名：" << p->data.name << endl;
    cout << "专业：" << p->data.major << endl;
    BSTree bookNode = SearchBST(T, p->data.b_book); // 搜索借阅的图书
    if (!bookNode)
        cout << "我的借阅图书：无" << endl;
    else
        cout << "我的借阅图书：" << bookNode->data.name << endl;
}

void Borrow_op(LinkList &L, string &student_num, BSTree &T) // 借阅图书
{
    string isbn;
    cout << "输入要借阅图书的isbn" << endl;
    cin >> isbn;
    BSTree bookNode = SearchBST(T, isbn);
    if (!bookNode)
    {
        cout << "isbn输入错误，无此书籍" << endl;
        return;
    }
    if (bookNode->data.num == 0)
    {
        cout << "图书库存为0，无法借阅" << endl;
        return;
    }
    LinkList p = L;
    while (p != nullptr)
    {
        if (p->data.num == student_num)
        {
            p->data.b_book = bookNode->data.id;
            bookNode->data.num--;
            cout << "借阅成功" << endl;
            return;
        }
        p = p->next;
    }

    cout << "学生信息未找到" << endl;
}

void Rerurn_op(LinkList &L, string &student_num, BSTree &T) // 归还图书
{
    LinkList p = L;
    while (p != nullptr)
    {
        if (p->data.num == student_num)
        {
            BSTree bookNode = SearchBST(T, p->data.b_book);
            if (!bookNode)
            {
                cout << "未找到借阅的图书信息" << endl;
                return;
            }

            p->data.b_book = "NULL";
            bookNode->data.num++;
            cout << "归还图书成功" << endl;
            return;
        }
        p = p->next;
    }

    cout << "学生信息未找到" << endl;
}

void File_in_List(LinkList &L)
{
    ElemType e;
    ifstream file("student.txt");
    if (!file)
    {
        cout << "错误！未找到文件！" << endl;
        exit(ERROR);
    }

    InitList(L); // 初始化链表 L
    int i = 1;
    while (file >> e.num >> e.name >> e.major >> e.password)
    {
        ListInsert(L, i, e); // 在链表 L 的第 i 个位置插入元素 e
        i++;
    }
    cout << "输入 student.txt 信息完毕\n\n";
    file.close();
}

void List_out_file(LinkList L)
{
    ofstream file("student.txt", ios::out | ios::trunc); // 打开文件以写入模式（清空现有内容）
    if (!file)
    {
        cout << "错误！未找到文件！" << endl;
        exit(ERROR);
    }

    LinkList p = L->next;
    while (p != nullptr)
    {
        file << left << p->data.num << "\t" << left << p->data.name << "\t" << left << p->data.major << "\t" << left << p->data.password << endl;
        p = p->next;
    }

    file.close();
}

void op_admin_menu()
{
    cout << endl;
    cout << "/*********输入数字进行操作选择*********/" << endl;
    cout << "1.录入图书" << endl;
    cout << "2.删除图书" << endl;
    cout << "3.修改图书" << endl;
    cout << "4.显示所有图书信息" << endl;
    cout << "5.显示所有学生信息" << endl;
    cout << "6.注销学号账号" << endl;
    cout << "0.保存并退出程序，" << endl;
    cout << endl;
    return;
}

void Insert_book(BSTree &T) // 录入图书
{
    Book x;
    cout << "输入图书信息进行录入：" << endl;
    cout << "ISBN:" << endl;
    cin >> x.id;
    cout << "书名：" << endl;
    cin >> x.name;
    cout << "价格：" << endl;
    cin >> x.price;
    cout << "库存：" << endl;
    cin >> x.num;
    InsertBST(T, x);
    return;
}

void Delete_book(BSTree &T) // 删除图书
{
    string isbn;
    cout << "输入图书信息进行删除" << endl;
    cout << "ISBN:" << endl;
    cin >> isbn;
    if (SearchBST(T, isbn))
    {
        DeleteBST(T, isbn);
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "删除失败" << endl;
        return;
    }
}

void Modify_Info(BSTree &T) // 修改图书
{
    BSTNode *p;
    string isbn;
    cout << "ISBN:" << endl;
    cin >> isbn;
    p = SearchBST(T, isbn);
    if (p == NULL)
    {
        cout << "无这本图书" << endl;
        return;
    }
    else
    {
        cout << "书名：" << p->data.name << endl;
        cout << "价格：" << endl;
        cin >> p->data.price;
        cout << "库存" << endl;
        cin >> p->data.num;
        cout << "修改成功" << endl;
        return;
    }
}

void Search_book(BSTree T) // 查找图书
{
    BSTNode *p;
    string isbn;
    cout << "输入图书的isbn" << endl;
    cin >> isbn;
    p = SearchBST(T, isbn);
    if (p == NULL)
    {
        cout << "查找失败" << endl;
        return;
    }
    else
    {
        cout << "书名：" << p->data.name << endl
             << "价格：" << p->data.price << endl
             << "库存：" << p->data.num << endl;
    }
}

void PrintInfo(BSTree T) // 显示所有图书信息
{
    if (T)
    {
        PrintInfo(T->lchild);
        cout << left << setw(20) << T->data.id << left << setw(40) << T->data.name << left << setw(15) << T->data.price << left << setw(10) << T->data.num << endl;
        PrintInfo(T->rchild);
    }
    return;
}

void PrintList(LinkList L) // 显示所有学生信息
{
    LinkList p = L->next; // 指向第一个节点
    while (p != nullptr)
    {
        cout << p->data.num << " " << p->data.name << " " << p->data.major << endl;
        p = p->next;
    }
    cout << endl;
}

void Log_out(LinkList &L) // 注销学生账号
{
    string stu_num;
    cout << "请输入学号以注销: ";
    cin >> stu_num;

    // 查找学号对应的学生节点
    string actual_stu_num = stu_num;
    string stu_name = LocateElem(L, stu_num);
    if (stu_name == "")
    {
        cout << "学号不存在，注销失败！" << endl;
        return;
    }

    // 删除学号对应的学生节点
    Status status = ListDelete(L, 1); // 假设学生信息存储在链表的第一个节点
    if (status == OK)
    {
        cout << "注销成功！再见，" << stu_name << "！" << endl;
    }
    else
    {
        cout << "注销失败！" << endl;
    }
}

void File_in_Tree(BSTree &T) // 将文件中的数据写入到二叉排序树
{
    Book e;
    fstream file;
    T = NULL;
    file.open("book.txt");
    if (!file)
    {
        cout << "错误！未找到文件！" << endl;
        exit(ERROR);
    }
    while (!file.eof())
    {
        file >> e.id >> e.name >> e.price >> e.num;
        InsertBST(T, e);
    }
    cout << "输入 book.txt 信息完毕\n\n";
    file.close();
}

void Tree_to_Array(BSTree T, Book array[], int &n) // 二叉树的线性化处理
{
    if (T)
    {
        array[n] = T->data;
        n++;
        Tree_to_Array(T->lchild, array, n);
        Tree_to_Array(T->rchild, array, n);
    }
}

void Tree_out_file(BSTree T) // 按照先序遍历将二叉排序中结点数据写回文件book.txt
{
    int n = 0, i;
    Book *array = new Book[MAXSIZE];
    fstream file("book.txt", fstream::out | ios_base::trunc); // 打开时清空文件
    if (!file)
    {
        cout << "错误！未找到文件！" << endl;
        exit(ERROR);
    }
    Tree_to_Array(T, array, n);

    for (i = 0; i < n - 1; i++)
    {
        file << left << array[i].id << "\t" << left << array[i].name << "\t" << left << array[i].price << "\t" << left << array[i].num << endl;
    }
    file << left << array[i].id << "\t" << left << array[i].name << "\t" << left << array[i].price << "\t" << left << array[i].num;
    file.close();
}
