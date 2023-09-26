// Tính tổng ước của 1 số nguyên dương n.
// Input
// Dòng đầu tiên là số lượng test case T(1≤n≤100).
// T dòng tiếp theo mỗi dòng là 1 số nguyên dương n (1≤n≤10^9)
// Output
// Mỗi test case in ra trên 1 dòng.

#include <iostream>
using namespace std;

int sumDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << sumDivisors(n) << endl;
    }
    return 0;
}
