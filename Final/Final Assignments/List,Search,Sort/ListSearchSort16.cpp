/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}

void QuickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int pivot = nums[left + (right - left) / 2];
    while (i <= j)
    {
        while (nums[i] < pivot)
            i++;
        while (nums[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    QuickSort(nums, left, j);
    QuickSort(nums, i, right);
}

void Sort(vector<int> &nums)
{
    QuickSort(nums, 0, nums.size() - 1);
    vector<int> Even;
    vector<int> Odd;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
            Even.push_back(nums[i]);
        else
            Odd.push_back(nums[i]);
    }
    int k = 0;
    for (int i = 0; i < Even.size(); i++)
    {
        nums[k++] = Even[i];
    }
    for (int i = 0; i < Odd.size(); i++)
    {
        nums[k++] = Odd[i];
    }
}