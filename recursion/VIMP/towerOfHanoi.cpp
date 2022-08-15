#include <bits/stdc++.h>
using namespace std;
void hanoiSolver(int n, char source, char helper, char destination, int &count)
{
    count++;
    if (n == 1)
    {
        // plates 1 then we can directly move
        cout << "Moving plate " << n << " "
             << " from A to C" << endl;
        return;
    }
    hanoiSolver(n - 1, source, destination, helper, count);
    cout << "Moving plate " << n << " "
         << " from " << source << " "
         << " to " << destination << " " << endl;
    hanoiSolver(n - 1, helper, source, destination, count);
}
int main()
{
    int n;
    cin >> n;
    int count = 0;
    hanoiSolver(n, 'A', 'B', 'C', count);
    cout << count << endl;
    return 0;
}