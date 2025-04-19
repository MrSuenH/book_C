#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <process.h>
using namespace std;

#include "StuList.h"
#include "BSTree.h"

// Book.h
void op_admin_menu();                               // ͼ��������湦�ܺ���
void Insert_book(BSTree &T);                        // ͼ��¼�빦�ܺ���
void Delete_book(BSTree &T);                        // ɾ��ͼ�鹦�ܺ���
void Modify_Info(BSTree &T);                        // �޸�ͼ����Ϣ���ܺ���
void Search_book(BSTree T);                         // ����ͼ�鹦�ܺ���
void PrintInfo(BSTree T);                           // ��ʾ����ͼ�鹦�ܺ���
void File_in_Tree(BSTree &T);                       // ���ݵ��빦�ܺ���
void Tree_to_Array(BSTree T, Book array[], int &n); // ���������������ݵ��뵽���鹦�ܺ���
void Tree_out_file(BSTree T);                       // ���ݵ������ܺ��������������������ݵ������ļ����湦�ܺ���

// Stu.h
void op_user_menu();                                         // �û������˵�����
void login_menu();                                           // ��½���û�����˵�����
void Register(LinkList &L);                                  // �û�ע�ắ��
void Log_in(LinkList L, BSTree &T);                          // �û���¼����
void Log_out(LinkList &L);                                   // �û�ע������
void Modify_Password(LinkList &L);                           // �û������޸ĺ���
void File_in_List(LinkList &L);                              // ���ļ��е�����д�뵽L
void List_out_file(LinkList L);                              // //��L������д���ļ�book.txt
void PrintList(LinkList L);                                  // ��������û���ѧ�š�������רҵ
void PrintMe(LinkList L, string &num, BSTree T);             // ���������Ϣ
void Borrow_op(LinkList &L, string &student_num, BSTree &T); // ����
void Rerurn_op(LinkList &L, string &student_num, BSTree &T); // ����

void main_menu()
{
    cout << "/*********��ӭʹ��ͼ�����ϵͳ*********/" << endl;
    cout << "1. �����" << endl;
    cout << "2. ѧ����" << endl;
    cout << "0. �˳�����" << endl;
    cout << "����������ѡ��: ";
}

void admin_op(LinkList &L, BSTree &T) // ����Ա�����˵�
{
    int op;
    while (true)
    {
        op_admin_menu(); // ����Ա�������溯��
        cin >> op;
        switch (op)
        {
        case 1: // ¼��ͼ��
            Insert_book(T);
            break;
        case 2:
            Delete_book(T); // ɾ��ͼ��
            break;
        case 3: // �޸�ͼ��
            Modify_Info(T);
            break;
        case 4: // ��ʾͼ����Ϣ
            PrintInfo(T);
            break;
        case 5: // ��ʾѧ����Ϣ
            PrintList(L);
            break;
        case 6: // ע��ѧ���˺�
            Log_out(L);
            break;
        case 0: // ����0�����������˳�����
            Tree_out_file(T);
            List_out_file(L);
            return;
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    }
}

void admin_menu(LinkList &L, BSTree &T) // ����Ա��¼�ɹ������
{
    int seq1 = 0;
    while (seq1 < 3)
    {
        string name, pwd;
        string user = "123456";
        string password = "123456";
        cout << "�������¼���û���" << endl;
        cin >> name;
        cout << "�������¼������" << endl;
        cin >> pwd;

        if (name == user && pwd == password)
        {
            cout << "��¼�ɹ�" << endl;
            admin_op(L, T);
            return;
        }
        else
        {
            cout << "�˺Ż��������������������" << endl;
        }

        seq1++;
    }
    cout << "��ε�½ʧ�ܣ�" << endl;
}

void Login_op(LinkList &L, BSTree &T, string student_num) // ��¼�ɹ�����еĲ���
{
    int op;
    while (true)
    {
        login_menu();
        cin >> op;
        switch (op)
        {
        case 1: // �ҵ���Ϣ
            PrintMe(L, student_num, T);
            break;
        case 2: // ��ʾͼ��
            PrintInfo(T);
            break;
        case 3: // ����ͼ��
            Search_book(T);
            break;
        case 4:
            Borrow_op(L, student_num, T); // ����ͼ��
            break;
        case 5: // �黹ͼ��
            Rerurn_op(L, student_num, T);
            break;
        case 6: // �޸ĵ�¼����
            Modify_Password(L);
            break;
        case 0: // ����������
            List_out_file(L);
            Tree_out_file(T);
            return;
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    }
}

void student_menu(LinkList &L, BSTree &T) // ѧ���˲����˵�
{
    int op;
    while (true)
    {
        op_user_menu(); // �û������˵�����
        cin >> op;
        switch (op)
        {
        case 1: // ע���û�
            Register(L);
            break;
        case 2: // �û���¼
            Log_in(L, T);
            break;
        case 3: // �û�ע��
            Log_out(L);
            break;
        case 0: // ���������˳�����
            List_out_file(L);
            return;
        default:
            cout << "��Ч��ѡ��������ѡ��" << endl;
        }
    }
}

int main()
{
    BSTree T;
    LinkList L;      // ���嵥�������L
    File_in_Tree(T); // ����ͼ�����ݵ�����������T
    File_in_List(L); // �����û����ݵ���L

    int choice;
    while (true)
    {
        main_menu();
        cin >> choice;
        switch (choice)
        {
        case 1: // �����
            admin_menu(L, T);
            break;
        case 2: // ѧ����
            student_menu(L, T);
            break;
        case 0: // �˳�����
            Tree_out_file(T);
            List_out_file(L);
            return 0;
        default:
            cout << "��Ч��ѡ��������ѡ��" << endl;
        }
    }
    return 0;
}

void op_user_menu()
{
    cout << endl;
    cout << "/*********�������ֽ��в���ѡ��*********/" << endl;
    cout << "1.ע��" << endl;
    cout << "2.��¼" << endl;
    cout << "0.���沢�˳�����" << endl;
    cout << endl;
    return;
}

void login_menu()
{
    cout << endl;
    cout << "*********�û����棬�������ֽ��в���ѡ��*********" << endl;
    cout << "1.�ҵ���Ϣ" << endl;
    cout << "2.��ʾͼ��" << endl;
    cout << "3.����ͼ��" << endl;
    cout << "4.����ͼ��" << endl;
    cout << "5.�黹ͼ��" << endl;
    cout << "6.�޸ĵ�¼����" << endl;
    cout << "0.���沢������һ���˵�" << endl;
}

void Register(LinkList &L) // ע��
{
    ElemType newStudent;

    cout << "����������Ϣ����ע��" << endl;
    cout << "ѧ�ţ�" << endl;
    cin >> newStudent.num;
    if (LocateElem(L, newStudent.num) != "")
    {
        cout << "��ѧ���Ѵ��ڣ���������" << endl;
        return;
    }
    cout << "������" << endl;
    cin >> newStudent.name;
    cout << "רҵ��" << endl;
    cin >> newStudent.major;
    cout << "���룺" << endl;
    cin >> newStudent.password;
    newStudent.b_book = "NULL";

    if (ListInsert(L, 1, newStudent) == OK)
    {
        cout << "ע��ɹ�" << endl;
    }
    else
    {
        cout << "ע��ʧ�ܣ�ϵͳ����" << endl;
    }
}

void Log_in(LinkList L, BSTree &T) // ��¼
{
    ElemType s;
    int seq = 0;

    cout << "����ѧ�ź�������е�¼" << endl;

    while (seq < 3)
    {
        cout << "ѧ�ţ�" << endl;
        cin >> s.num;

        cout << "���룺" << endl;
        cin >> s.password;

        // ����ѧ�Ž��в���
        string stu_name = LocateElem(L, s.num);
        if (stu_name == "")
        {
            cout << "ѧ�Ų����ڣ�����������" << endl;
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
                cout << "��¼�ɹ�" << endl;
                Login_op(L, T, s.num);
                return;
            }
            else
            {
                cout << "�����������������" << endl;
            }
        }

        seq++;
    }

    cout << "��γ��Ե�¼ʧ�ܣ����Ժ�����" << endl;
    return;
}

void Modify_Password(LinkList &L) // �޸�����
{
    string login_user, pass1, pass2;
    cout << "����ѧ�Ž�����Ϣ�޸�" << endl;
    cout << "ѧ�ţ�" << endl;
    cin >> login_user;
    string stu_name = LocateElem(L, login_user);
    if (stu_name == "")
    {
        cout << "���û�������" << endl;
    }
    else
    {
        cout << "�����룺" << endl;
        cin >> pass1;
        cout << "�ٴ����������룺" << endl;
        cin >> pass2;
        while (pass1 != pass2)
        {
            cout << "�������벻һ�£���������" << endl;
            cout << "�����룺" << endl;
            cin >> pass1;
            cout << "�ٴ����������룺" << endl;
            cin >> pass2;
        }
        L->data.password = pass1;
        cout << "�����޸ĳɹ�" << endl;
    }

    return;
}

void PrintMe(LinkList L, string &num, BSTree T) // �ҵ���Ϣ
{
    LNode *p = L->next;
    while (p && p->data.num != num)
    {
        p = p->next;
    }

    if (!p)
    {
        cout << "δ�ҵ����û���Ϣ" << endl;
        return;
    }

    cout << "/****�ҵ���Ϣ****/" << endl;
    cout << "ѧ�ţ�" << p->data.num << endl;
    cout << "������" << p->data.name << endl;
    cout << "רҵ��" << p->data.major << endl;
    BSTree bookNode = SearchBST(T, p->data.b_book); // �������ĵ�ͼ��
    if (!bookNode)
        cout << "�ҵĽ���ͼ�飺��" << endl;
    else
        cout << "�ҵĽ���ͼ�飺" << bookNode->data.name << endl;
}

void Borrow_op(LinkList &L, string &student_num, BSTree &T) // ����ͼ��
{
    string isbn;
    cout << "����Ҫ����ͼ���isbn" << endl;
    cin >> isbn;
    BSTree bookNode = SearchBST(T, isbn);
    if (!bookNode)
    {
        cout << "isbn��������޴��鼮" << endl;
        return;
    }
    if (bookNode->data.num == 0)
    {
        cout << "ͼ����Ϊ0���޷�����" << endl;
        return;
    }
    LinkList p = L;
    while (p != nullptr)
    {
        if (p->data.num == student_num)
        {
            p->data.b_book = bookNode->data.id;
            bookNode->data.num--;
            cout << "���ĳɹ�" << endl;
            return;
        }
        p = p->next;
    }

    cout << "ѧ����Ϣδ�ҵ�" << endl;
}

void Rerurn_op(LinkList &L, string &student_num, BSTree &T) // �黹ͼ��
{
    LinkList p = L;
    while (p != nullptr)
    {
        if (p->data.num == student_num)
        {
            BSTree bookNode = SearchBST(T, p->data.b_book);
            if (!bookNode)
            {
                cout << "δ�ҵ����ĵ�ͼ����Ϣ" << endl;
                return;
            }

            p->data.b_book = "NULL";
            bookNode->data.num++;
            cout << "�黹ͼ��ɹ�" << endl;
            return;
        }
        p = p->next;
    }

    cout << "ѧ����Ϣδ�ҵ�" << endl;
}

void File_in_List(LinkList &L)
{
    ElemType e;
    ifstream file("student.txt");
    if (!file)
    {
        cout << "����δ�ҵ��ļ���" << endl;
        exit(ERROR);
    }

    InitList(L); // ��ʼ������ L
    int i = 1;
    while (file >> e.num >> e.name >> e.major >> e.password)
    {
        ListInsert(L, i, e); // ������ L �ĵ� i ��λ�ò���Ԫ�� e
        i++;
    }
    cout << "���� student.txt ��Ϣ���\n\n";
    file.close();
}

void List_out_file(LinkList L)
{
    ofstream file("student.txt", ios::out | ios::trunc); // ���ļ���д��ģʽ������������ݣ�
    if (!file)
    {
        cout << "����δ�ҵ��ļ���" << endl;
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
    cout << "/*********�������ֽ��в���ѡ��*********/" << endl;
    cout << "1.¼��ͼ��" << endl;
    cout << "2.ɾ��ͼ��" << endl;
    cout << "3.�޸�ͼ��" << endl;
    cout << "4.��ʾ����ͼ����Ϣ" << endl;
    cout << "5.��ʾ����ѧ����Ϣ" << endl;
    cout << "6.ע��ѧ���˺�" << endl;
    cout << "0.���沢�˳�����" << endl;
    cout << endl;
    return;
}

void Insert_book(BSTree &T) // ¼��ͼ��
{
    Book x;
    cout << "����ͼ����Ϣ����¼�룺" << endl;
    cout << "ISBN:" << endl;
    cin >> x.id;
    cout << "������" << endl;
    cin >> x.name;
    cout << "�۸�" << endl;
    cin >> x.price;
    cout << "��棺" << endl;
    cin >> x.num;
    InsertBST(T, x);
    return;
}

void Delete_book(BSTree &T) // ɾ��ͼ��
{
    string isbn;
    cout << "����ͼ����Ϣ����ɾ��" << endl;
    cout << "ISBN:" << endl;
    cin >> isbn;
    if (SearchBST(T, isbn))
    {
        DeleteBST(T, isbn);
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "ɾ��ʧ��" << endl;
        return;
    }
}

void Modify_Info(BSTree &T) // �޸�ͼ��
{
    BSTNode *p;
    string isbn;
    cout << "ISBN:" << endl;
    cin >> isbn;
    p = SearchBST(T, isbn);
    if (p == NULL)
    {
        cout << "���Ȿͼ��" << endl;
        return;
    }
    else
    {
        cout << "������" << p->data.name << endl;
        cout << "�۸�" << endl;
        cin >> p->data.price;
        cout << "���" << endl;
        cin >> p->data.num;
        cout << "�޸ĳɹ�" << endl;
        return;
    }
}

void Search_book(BSTree T) // ����ͼ��
{
    BSTNode *p;
    string isbn;
    cout << "����ͼ���isbn" << endl;
    cin >> isbn;
    p = SearchBST(T, isbn);
    if (p == NULL)
    {
        cout << "����ʧ��" << endl;
        return;
    }
    else
    {
        cout << "������" << p->data.name << endl
             << "�۸�" << p->data.price << endl
             << "��棺" << p->data.num << endl;
    }
}

void PrintInfo(BSTree T) // ��ʾ����ͼ����Ϣ
{
    if (T)
    {
        PrintInfo(T->lchild);
        cout << left << setw(20) << T->data.id << left << setw(40) << T->data.name << left << setw(15) << T->data.price << left << setw(10) << T->data.num << endl;
        PrintInfo(T->rchild);
    }
    return;
}

void PrintList(LinkList L) // ��ʾ����ѧ����Ϣ
{
    LinkList p = L->next; // ָ���һ���ڵ�
    while (p != nullptr)
    {
        cout << p->data.num << " " << p->data.name << " " << p->data.major << endl;
        p = p->next;
    }
    cout << endl;
}

void Log_out(LinkList &L) // ע��ѧ���˺�
{
    string stu_num;
    cout << "������ѧ����ע��: ";
    cin >> stu_num;

    // ����ѧ�Ŷ�Ӧ��ѧ���ڵ�
    string actual_stu_num = stu_num;
    string stu_name = LocateElem(L, stu_num);
    if (stu_name == "")
    {
        cout << "ѧ�Ų����ڣ�ע��ʧ�ܣ�" << endl;
        return;
    }

    // ɾ��ѧ�Ŷ�Ӧ��ѧ���ڵ�
    Status status = ListDelete(L, 1); // ����ѧ����Ϣ�洢������ĵ�һ���ڵ�
    if (status == OK)
    {
        cout << "ע���ɹ����ټ���" << stu_name << "��" << endl;
    }
    else
    {
        cout << "ע��ʧ�ܣ�" << endl;
    }
}

void File_in_Tree(BSTree &T) // ���ļ��е�����д�뵽����������
{
    Book e;
    fstream file;
    T = NULL;
    file.open("book.txt");
    if (!file)
    {
        cout << "����δ�ҵ��ļ���" << endl;
        exit(ERROR);
    }
    while (!file.eof())
    {
        file >> e.id >> e.name >> e.price >> e.num;
        InsertBST(T, e);
    }
    cout << "���� book.txt ��Ϣ���\n\n";
    file.close();
}

void Tree_to_Array(BSTree T, Book array[], int &n) // �����������Ի�����
{
    if (T)
    {
        array[n] = T->data;
        n++;
        Tree_to_Array(T->lchild, array, n);
        Tree_to_Array(T->rchild, array, n);
    }
}

void Tree_out_file(BSTree T) // ����������������������н������д���ļ�book.txt
{
    int n = 0, i;
    Book *array = new Book[MAXSIZE];
    fstream file("book.txt", fstream::out | ios_base::trunc); // ��ʱ����ļ�
    if (!file)
    {
        cout << "����δ�ҵ��ļ���" << endl;
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
