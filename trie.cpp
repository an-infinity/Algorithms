/*Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.

Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.

INPUT

First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.

OUTPUT

Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.*/
#include <bits/stdc++.h>
using namespace std;

struct trienode
{
    struct trienode* children[26];
	struct trienode* parent;
	int max;
    bool end;
};

struct trienode* getroot()
{
    trienode* root=new trienode;
    for(int i=0;i<26;++i)
    {
        root->children[i]=NULL;
    }
    root->end=false;
	root->parent=NULL;
	root->max=INT_MIN;
    return root;
}
void insert(trienode* root,string s,int pr)
{
    trienode* temp=root;
    for(int i=0;i<s.length();++i)
    {
        int key=(s[i]-'a');
        if(!temp->children[key])
        {
			trienode* t=getroot();
            temp->children[key]=t;
			t->parent=temp;
        }
        temp=temp->children[key];
    }
    temp->end=true;
	while(temp->parent)
	{
		temp->max=max(pr,temp->max);
		temp=temp->parent;
	}
}

int search(trienode* root,string s)
{
    trienode* temp=root;
    for(int i=0;i<s.length();++i)
    {
        int key=(s[i]-'a');
        if(!temp->children[key])
        {
            return -1;
        }
        temp=temp->children[key];
    }
    if(temp==NULL) return -1;
	return temp->max;
}
int main() 
{  
	trienode* root=new trienode;
	int n,q;
	cin >> n >> q;
	string s[n];
	int pr[n];
	for(int i=0;i<n;++i)
	{
		cin >> s[i] >> pr[i];
		insert(root,s[i],pr[i]);
	}
	string str;
	for(int i=0;i<q;++i)
	{
		cin >> str;
		cout << search(root,str) << endl;
	}
} 
