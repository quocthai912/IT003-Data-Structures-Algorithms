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
void CreateEmptyList(LIST &L)
{
    L.pHead = nullptr;
    L.pTail = nullptr;
}
void addTail(LIST &L, NODE *addNode)
{
    if (L.pHead == nullptr)
    {
        L.pHead = L.pTail = addNode;
    }
    else
    {
        L.pTail->pNext = addNode;
        L.pTail = addNode;
    }
}
void CreateList(LIST &L)
{
    int value;
    cin >> value;
    while (value != -1)
    {
        addTail(L, initNode(value));
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
int search_prime(NODE *Head)
{
    if (Head == nullptr)
        return 0;
    int viTriNode = 0;
    NODE *p = Head;
    while (p)
    {
        viTriNode++;
        if (isPrime(p->value))
        {
            return viTriNode;
        }
        p = p->pNext;
    }
    return 0;
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << search_prime(L.pHead);

    return 0;
}
