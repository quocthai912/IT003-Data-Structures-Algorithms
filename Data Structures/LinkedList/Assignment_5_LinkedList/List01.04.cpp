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
void PrintList(const LIST &l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE *p = l.pHead;
        while (p)
        {
            cout << p->value << " ";
            p = p->pNext;
        }
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
void add_after_all_prime(LIST &l, int Y)
{
    if (l.pHead == nullptr)
        return;
    else
    {
        NODE *p = l.pHead;
        while (p)
        {
            if (isPrime(p->value))
            {
                NODE *addNode = initNode(Y);
                addNode->pNext = p->pNext;
                p->pNext = addNode;
                p = addNode->pNext;
            }
            else
            {
                p = p->pNext;
            }
        }
    }
}
int main()
{
    LIST L;
    int Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> Y;
    add_after_all_prime(L, Y);
    PrintList(L);

    return 0;
}
