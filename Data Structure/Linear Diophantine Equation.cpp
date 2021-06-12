#include <bits/stdc++.h>
using namespace std;
int g;
int x_0,y_0;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x_0, int &y_0, int &g) {
    g = gcd(abs(a), abs(b), x_0, y_0);
    if (c % g) {
        return false;
    }

    x_0 *= c / g;
    y_0 *= c / g;
    if (a < 0) x_0 = -x_0;
    if (b < 0) y_0 = -y_0;
    return true;
}int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    bool check=find_any_solution(a,b,c,x_0,y_0,g);
    if(check)
    cout << x_0 << " " << y_0 << endl;
    else
    {
        cout << "Impossible" << endl;
    }
}
