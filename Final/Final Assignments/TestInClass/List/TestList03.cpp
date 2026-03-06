/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
###End banned keyword*/

#include <iostream>
using namespace std;

struct User
{
    int ID;
    int BirthDate;
};

struct NODE
{
    User info;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNODE(User x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = nullptr;
    return p;
}

void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}

void InputList(LIST &l)
{
    l.pHead = l.pTail = nullptr;
    int length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        User x;
        cin >> x.ID >> x.BirthDate;
        AddTail(l, CreateNODE(x));
    }
}

int Count(LIST l, string birthY)
{
    int count = 0;
    NODE *p = l.pHead;
    while (p)
    {
        string birthX = "";
        string year = to_string(p->info.BirthDate);
        for (int i = 4; i <= 7; i++)
        {
            birthX += year[i];
        }
        if (birthX == birthY)
            count++;
        p = p->pNext;
    }
    return count;
}

int MaxCount(LIST l)
{
    int MaxCount = -1;
    NODE *p = l.pHead;
    while (p)
    {
        string birthX = "";
        string year = to_string(p->info.BirthDate);
        for (int i = 4; i <= 7; i++)
        {
            birthX += year[i];
        }
        if (Count(l, birthX) > MaxCount)
            MaxCount = Count(l, birthX);
        p = p->pNext;
    }
    return MaxCount;
}

bool LinearSearch(LIST l, string birthY)
{
    NODE *p = l.pHead;
    while (p)
    {
        string birthX = "";
        string year = to_string(p->info.BirthDate);
        for (int i = 4; i <= 7; i++)
        {
            birthX += year[i];
        }
        if (birthX == birthY)
            return true;
        p = p->pNext;
    }
    return false;
}

void Fun(LIST l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty";
        return;
    }
    int maxCount = MaxCount(l);
    if (maxCount == 1)
    {
        cout << "NotFound";
        return;
    }
    LIST Output;
    Output.pHead = Output.pTail = nullptr;
    NODE *p = l.pHead;
    while (p)
    {
        string birthX = "";
        string year = to_string(p->info.BirthDate);
        for (int i = 4; i <= 7; i++)
        {
            birthX += year[i];
        }
        if (Count(l, birthX) == maxCount)
        {
            if (!LinearSearch(Output, birthX))
            {
                AddTail(Output, CreateNODE(p->info));
            }
        }
        p = p->pNext;
    }
    p = Output.pHead;
    while (p)
    {
        string birthX = "";
        string year = to_string(p->info.BirthDate);
        for (int i = 4; i <= 7; i++)
        {
            birthX += year[i];
        }
        cout << birthX << endl;
        p = p->pNext;
    }
}

int main()
{
    LIST l;
    InputList(l);
    Fun(l);
    return 0;
}
