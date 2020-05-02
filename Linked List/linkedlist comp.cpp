class DSU{
	public:
	vector<int> arr;
	DSU(int n)
	{
		arr.assign(n,0);
		for(int i=0;i<n;i++)
		{
			arr[i]=i;
		}

	}

	int find(int x)
	{
		if(arr[x]!=x)
		{
			arr[x]=find(arr[x]);
		}
		return arr[x];
	}

	void merge(int a, int b)
	{
		int x=find(a);
		int y=find(b);
		arr[x]=y;
	}
};
class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int> connect(G.begin(),G.end());
		vector<int> cnt;
		while(head)
		{
			cnt.push_back(head->val);
			head=head->next;
		}
		int MAX=*max_element(cnt.begin(),cnt.end());
		int n=cnt.size();
		DSU* dsu=new DSU(MAX+1);
		for(int i=1;i<cnt.size();i++)
		{
			if(connect.count(cnt[i]) && connect.count(cnt[i-1]))
			{
				dsu->merge(cnt[i],cnt[i-1]);
			}
		}
		unordered_set<int> res;
		for(int i=0;i<dsu->arr.size();i++)
		{
			if(connect.count(i))
			{
				dsu->arr[i]=dsu->find(i);
				res.insert(dsu->arr[i]);
			}
		}
		return res.size();
	}
};