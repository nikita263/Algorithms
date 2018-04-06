#include<bits/stdc++.h>
using namespace std;
bool check_for_pattern_matching(string text, string pattern, vector<int> & pattern_arr)
{

	int text_index = 0, pattern_index = 0;
	while(text_index<text.size() && pattern_index<pattern.size())
	{
		if(text[text_index]==pattern[pattern_index])
		{
			text_index++;
			pattern_index++;
		}
		else
		{
			if(pattern_index!=0)
				pattern_index = pattern_arr[pattern_index-1];
			else
				text_index++;
		}
	}
	if(pattern_index==pattern.size())
		return true;
	else
		return false;
}
void build_pattern_array(vector<int> &pattern_arr, string pattern)
{
	int n = pattern.size();
	int j=0, i=1;
	while(i<n)
	{
		if(pattern[i]==pattern[j])
		{
			pattern_arr[i]=j+1;
			j++;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = pattern_arr[j-1];
			}
			else i++;

		}
	}
}
int main()
{
	string pattern;
	string text;
	cin>>text;
	cin>>pattern;
	int n = pattern.size();
	vector<int> pattern_arr(n, 0);
	build_pattern_array(pattern_arr, pattern);
	bool ans = check_for_pattern_matching(text, pattern, pattern_arr);
	cout<<ans<<endl;
	return 0;
}