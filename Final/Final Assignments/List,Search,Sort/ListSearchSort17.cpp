/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <fstream>

using namespace std;

struct Word
{
    string Text;
    string Explanation;
};

void loadData(Word dictionary[], int &n)
{
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getline(cin >> ws, s);
        dictionary[i].Text = s;
        getline(cin >> ws, s);
        dictionary[i].Explanation = s;
    }
}
void saveData(Word dictionary[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << dictionary[i].Text << endl
             << dictionary[i].Explanation << endl;
    }
}
void Sort(Word[], int);

int main()
{
    Word *dictionary = new Word[15000];
    int n;
    loadData(dictionary, n);
    Sort(dictionary, n);

    saveData(dictionary, n);
    delete[] dictionary;
    return 0;
}

bool SoSanhWord(Word &w1, Word &w2)
{
    return w1.Text < w2.Text;
}

void QuickSort(Word w[], int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    Word pivot = w[left + (right - left) / 2];
    while (i <= j)
    {
        while (SoSanhWord(w[i], pivot))
            i++;
        while (SoSanhWord(pivot, w[j]))
            j--;
        if (i <= j)
        {
            swap(w[i], w[j]);
            i++;
            j--;
        }
    }
    QuickSort(w, left, j);
    QuickSort(w, i, right);
}

void Sort(Word w[], int n)
{
    QuickSort(w, 0, n - 1);
}
