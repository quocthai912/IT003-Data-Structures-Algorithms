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
int getThang(User x)
{
    string s = to_string(x.BirthDate);
    string month = "";
    for (int i = 2; i <= 3; i++)
    {
        month += s[i];
    }
    int result = stol(month);
    return result;
}
int getDay(User x)
{
    string s = to_string(x.BirthDate);
    string day = "";
    for (int i = 0; i <= 1; i++)
    {
        day += s[i];
    }
    int result = stol(day);
    return result;
}
void Delete(LIST &l)
{
    User x;
    x.ID = 0;
    x.BirthDate = 0;
    NODE dummyNode;
    dummyNode.info = x;
    dummyNode.pNext = nullptr;
    NODE *curr = &dummyNode;
    dummyNode.pNext = l.pHead;
    while (curr->pNext)
    {
        if (getThang(curr->pNext->info) < 1 || getThang(curr->pNext->info) > 12 || getDay(curr->pNext->info) < 1 || getDay(curr->pNext->info) > 31)
        {
            NODE *q = curr->pNext;
            curr->pNext = q->pNext;
            delete q;
        }
        else
            curr = curr->pNext;
    }
    l.pHead = dummyNode.pNext;
    l.pTail = curr;
}
void PrintList(LIST L)
{
    if (L.pHead == NULL)
        cout << "Empty";
    else
    {
        NODE *p = L.pHead;
        while (p)
        {
            cout << (p->info.ID) << " " << (p->info.BirthDate) << endl;
            p = p->pNext;
        }
    }
}

int main()
{
    LIST l;
    InputList(l);
    Delete(l);
    PrintList(l);
    return 0;
}
