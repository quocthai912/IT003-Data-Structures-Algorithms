/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *CreateNODE(int data)
{
    NODE *p = new NODE;
    p->data = data;
    p->next = nullptr;
    return p;
}

struct LIST
{
    NODE *head;
    NODE *tail;
};

void CreateEmptyList(LIST &l)
{
    l.head = l.tail = nullptr;
}

void AddHead(LIST &l, int data)
{
    NODE *p = CreateNODE(data);
    if (l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

int soChuSo(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

bool Armstrong(int num)
{
    if (num == 0)
        return false;
    int n = soChuSo(num);
    int sum = 0;
    int checkNum = num;
    while (num > 0)
    {
        sum += pow((num % 10), n);
        num /= 10;
    }
    if (sum == checkNum)
        return true;
    return false;
}

void CreateList(LIST &l)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        AddHead(l, data);
        cin >> data;
    }
}

void PrintList_Armstrong(LIST &l)
{
    if (l.head == nullptr)
    {
        cout << "Empty List.";
        return;
    }
    NODE *p = l.head;
    bool find = false;
    while (p)
    {
        if (Armstrong(p->data))
        {
            find = true;
            cout << p->data << " ";
        }
        p = p->next;
    }
    if (!find)
    {
        cout << "Không có số armstrong trong mảng.";
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
