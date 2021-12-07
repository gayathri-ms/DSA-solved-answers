// GFG - https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0#

#include <bits/stdc++.h>
using namespace std;

void sorted(vector<int> a,int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int s=0;
    while(s<n)
    {
        pq.push(a[s]);
        if(pq.size()>k)
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
        s++;
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
    return;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int k;
	    cin>>n>>k;
	    int inp;
	    vector<int> arr;
	    for(int j=0;j<n;j++)
	    {
	        cin>>inp;
	        arr.push_back(inp);
	    }
	    sorted(arr,n,k);
	    
	}
	return 0;
}
