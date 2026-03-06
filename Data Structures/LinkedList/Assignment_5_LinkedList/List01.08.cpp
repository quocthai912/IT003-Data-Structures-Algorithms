/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
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
void addTail(LIST &l, NODE *addNode)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = addNode;
    }
    else
    {
        l.pTail->pNext = addNode;
        l.pTail = addNode;
    }
}
void CreateList(LIST &l)
{
    int value;
    cin >> value;
    while (value != -1)
    {
        addTail(l, initNode(value));
        cin >> value;
    }
}
bool isPrime(int number)
{
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
void PrintList_Prime(const LIST &l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        bool prime = false;
        NODE *p = l.pHead;
        while (p)
        {
            if (isPrime(p->value))
            {
                prime = true;
                cout << p->value << " ";
            }
            p = p->pNext;
        }
        if (!prime)
        {
            cout << "Không có số nguyên tố trong mảng.";
        }
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Prime(L);

    return 0;
}
