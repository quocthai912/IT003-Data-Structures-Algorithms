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
bool perfectNumber(int number)
{
    if (number <= 1)
        return false;
    int sum = 1;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
            if (i != number / i)
            {
                sum += number / i;
            }
        }
    }
    return sum == number;
}
void count_perfect_number(NODE *head, int &count)
{
    count = 0;
    NODE *p = head;
    while (p)
    {
        if (perfectNumber(p->value))
            count++;
        p = p->pNext;
    }
}
int main()
{
    LIST L;
    int count;
    CreateEmptyList(L);

    CreateList(L);
    count_perfect_number(L.pHead, count);
    cout << count;

    return 0;
}
