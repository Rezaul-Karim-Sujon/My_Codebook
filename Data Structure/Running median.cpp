#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<double>max_heap,min_heap;
    int n,i;
    double a;
    vector<int>v;
    cin >> n;
    double median=0.00;
    for(i=0;i<n;i++)
    {
        cin >> a;
        int maxi=max_heap.size();
        int mini=min_heap.size();
        if(maxi>mini)
        {
            if(a<median){
            int fe=max_heap.top();
            min_heap.push(-fe);
            max_heap.pop();
            max_heap.push(a);
            }
            else
            {
                min_heap.push(-a);
            }
            median=(max_heap.top()+abs(min_heap.top()))/2;
        }
        else if(maxi<mini)
        {
            if(a>median)
            {
                int fe=abs(min_heap.top());
                max_heap.push(fe);
                min_heap.pop();
                min_heap.push(-a);
            }
            else
            {
                max_heap.push(a);
            }
            median=(max_heap.top()+abs(min_heap.top()))/2;
        }
        else
        {
            if(a<median)
            {
                max_heap.push(a);
                median=max_heap.top();
            }
            else
            {
                min_heap.push(-a);
                median=abs(min_heap.top());
            }
        }
        cout << median << endl;
    }
}
