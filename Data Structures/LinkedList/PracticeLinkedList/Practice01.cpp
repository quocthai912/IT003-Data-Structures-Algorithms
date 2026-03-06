#include <iostream>
#include <sstream>
#include <string.h>
#include <cctype>
using namespace std;
#define MAX 100
struct User
{
    string birth;
    string name;
};
struct NODE
{
    User info;
    NODE *pNext;
};
NODE *initNODE(User info)
{
    NODE *p = new NODE;
    p->info = info;
    p->pNext = nullptr;
    return p;
}
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateList(LIST &l)
{
    l.pHead = l.pTail = nullptr;
}
void addTail(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
struct NodeString
{
    string s;
    NodeString *pNext;
};
NodeString *initNodeString(string s)
{
    NodeString *p = new NodeString;
    p->s = s;
    p->pNext = nullptr;
    return p;
}
struct ListString
{
    NodeString *pHead;
    NodeString *pTail;
};
void addTailListString(ListString &l, NodeString *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void chuanHoaChuoi(string &s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
}
ListString sinhEmail(const LIST &l)
{
    ListString result;
    result.pHead = result.pTail = nullptr;
    NODE *p = l.pHead;
    while (p)
    {
        chuanHoaChuoi(p->info.name);
        string email = "";
        stringstream ss(p->info.name);
        string word;
        ListString temp;
        temp.pHead = temp.pTail = nullptr;
        while (ss >> word)
        {
            addTailListString(temp, initNodeString(word));
        }
        email += temp.pTail->s;
        if (temp.pHead != temp.pTail)
        {
            NodeString *duyetList = temp.pHead;
            while (duyetList->pNext != temp.pTail)
            {
                email += duyetList->s[0];
                duyetList = duyetList->pNext;
            }
            email += duyetList->s[0];
        }
        for (int i = 4; i <= 7; i++)
            email += p->info.birth[i];
        addTailListString(result, initNodeString(email));
        p = p->pNext;
    }
    return result;
}
void Fun(LIST &l)
{
    int soLuong;
    cin >> soLuong;
    cin.ignore();
    for (int i = 0; i < soLuong; i++)
    {
        User thongTin;
        cin >> thongTin.birth;
        getline(cin, thongTin.name);
        addTail(l, initNODE(thongTin));
    }
    ListString email = sinhEmail(l);
    NodeString *p = email.pHead;
    while (p)
    {
        cout << p->s << endl;
        p = p->pNext;
    }
}
int main()
{
    LIST l;
    CreateList(l);
    Fun(l);
    return 0;
}