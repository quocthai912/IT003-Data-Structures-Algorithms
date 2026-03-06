/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;
struct NODE
{
    int value;
    NODE *pNext;
};
NODE *initNode(int value)
{
    NODE *p = new NODE;
    p->value = value;
    p->pNext = nullptr;
    return p;
}
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}
void addHead(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void CreateList(LIST &l)
{
    int value;
    cin >> value;
    while (value != -1)
    {
        addHead(l, initNode(value));
        cin >> value;
    }
}
int tongSoChuSo(int number)
{
    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }
    return count;
}
bool isArmstrong(int number)
{
    if (number < 1)
        return false;
    int bac = tongSoChuSo(number);
    int compare = number;
    int sum = 0;
    while (number > 0)
    {
        sum += pow(number % 10, bac);
        number /= 10;
    }
    return sum == compare;
}
void PrintList_Armstrong(const LIST &l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        bool armstrong = false;
        NODE *p = l.pHead;
        while (p)
        {
            if (isArmstrong(p->value))
            {
                armstrong = true;
                cout << p->value << " ";
            }
            p = p->pNext;
        }
        if (!armstrong)
        {
            cout << "Không có số armstrong trong mảng.";
        }
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
