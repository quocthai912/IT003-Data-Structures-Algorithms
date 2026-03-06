/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int key;
    cin >> key;
    while (key != -1)
    {
        A.push_back(key);
        cin >> key;
    }
}

void SAPXEP(vector<int> &A){
    for (int i = 1; i < A.size(); i++){
        int j = i - 1;
        int pos = A[i];
        while (j >= 0 && A[j] >= pos){
            A[j + 1] = A[j];
            j--;
        }
        int e = j + 1;
        A[e] = pos;
        cout << "i=" << i << ": pos=" << pos << " e=" << e << endl;
        for (int k = 0; k < A.size(); k++){
            cout << A[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> A;
    Input(A);
    SAPXEP(A);
    return 0;
}
