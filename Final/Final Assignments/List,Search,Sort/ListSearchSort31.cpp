/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct DONTHUC
{
    float HeSo;
    int SoMu;
};
struct NODE
{
    DONTHUC info;
    NODE *pNext;
};
struct DATHUC
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNode(DONTHUC val)
{
    NODE *p = new NODE;
    p->info = val;
    p->pNext = nullptr;
    return p;
}

void CreateEmptyDATHUC(DATHUC &dt)
{
    dt.pHead = dt.pTail = nullptr;
}

void AddTail(DATHUC &dt, NODE *p)
{
    if (dt.pHead == nullptr)
    {
        dt.pHead = dt.pTail = p;
    }
    else
    {
        dt.pTail->pNext = p;
        dt.pTail = p;
    }
}

void QuickSort(DATHUC &dt)
{
    if (dt.pHead == nullptr || dt.pHead->pNext == nullptr)
        return;
    NODE *pivot = CreateNode(dt.pHead->info);
    dt.pHead = dt.pHead->pNext;
    NODE *p = dt.pHead;
    DATHUC Before;
    DATHUC After;
    CreateEmptyDATHUC(Before);
    CreateEmptyDATHUC(After);
    while (p)
    {
        if (p->info.SoMu < pivot->info.SoMu)
            AddTail(Before, CreateNode(p->info));
        else
            AddTail(After, CreateNode(p->info));
        p = p->pNext;
    }
    QuickSort(Before);
    QuickSort(After);
    if (Before.pHead == nullptr)
    {
        dt.pHead = pivot;
    }
    else
    {
        dt.pHead = Before.pHead;
        Before.pTail->pNext = pivot;
    }
    if (After.pHead == nullptr)
    {
        dt.pTail = pivot;
    }
    else
    {
        pivot->pNext = After.pHead;
        dt.pTail = After.pTail;
    }
}

void CreatePolynomial(DATHUC &dt)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        DONTHUC val;
        cin >> val.HeSo >> val.SoMu;
        if (val.HeSo != 0)
            AddTail(dt, CreateNode(val));
    }
    QuickSort(dt);
    if (dt.pHead == nullptr)
        return;
    NODE *p = dt.pHead;
    DATHUC Poly;
    CreateEmptyDATHUC(Poly);
    DONTHUC result;
    result.HeSo = 0.0;
    result.SoMu = p->info.SoMu;
    while (p->pNext)
    {
        if (p->info.SoMu == p->pNext->info.SoMu)
        {
            result.HeSo += p->info.HeSo;
        }
        else
        {
            result.HeSo += p->info.HeSo;
            if (result.HeSo != 0)
                AddTail(Poly, CreateNode(result));
            result.HeSo = 0.0;
            result.SoMu = p->pNext->info.SoMu;
        }
        p = p->pNext;
    }
    result.HeSo += p->info.HeSo;
    if (result.HeSo != 0)
        AddTail(Poly, CreateNode(result));
    dt.pHead = Poly.pHead;
}

void Output(DONTHUC a)
{
    if (a.HeSo == -1)
        cout << "-";
    else if (a.HeSo == 1)
        cout << "";
    else
        cout << a.HeSo;

    if (a.SoMu == 0)
        cout << "";
    else if (a.SoMu == 1)
        cout << "x";
    else if (a.SoMu < 1)
        cout << "-x";
    else // s.SoMu>1
        cout << "x^" << a.SoMu;
}

void Output(DATHUC L)
{
    NODE *p;

    if (L.pHead == NULL)
        cout << "Empty DATHUC.";
    else
    {
        p = L.pHead;
        Output(p->info);
        p = p->pNext;
        while (p)
        {
            cout << " + ";
            Output(p->info);
            p = p->pNext;
        }
    }
}

int main()
{
    DATHUC poly;
    CreateEmptyDATHUC(poly);
    CreatePolynomial(poly);
    Output(poly);
    return 0;
}
