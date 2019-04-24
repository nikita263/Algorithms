#include<iostream>
#include<map>
#include<stack>
using namespace std;

struct trie_node{
  bool end;
  map<char, trie_node*> next;
  trie_node(){end = false;}
};

class trie{
    trie_node* root;
public:
    trie() {root = new trie_node();}
    void insert(string s)
    {
      trie_node* tmp = root;
      for(int i=0; i<s.size(); i++)
      {
        if(tmp->next[s[i]]==NULL)
            tmp->next[s[i]] = new trie_node();
        tmp = tmp->next[s[i]];
      }
      tmp->end = true;
    }

    bool query(string s)
    {
      trie_node* tmp = root;
      for(int i=0; i<s.size(); i++)
      {
        if(tmp->next[s[i]]==NULL)
        {
          tmp->next.erase(s[i]);
          return false;
        }
        tmp = tmp->next[s[i]];
      }
      return tmp->end;
    }

    void delete_word(string s)
    {
      //If s exists in trie then try to delete
      if(query(s))
      {
        //Push all nodes on stack, leading to end node
        stack<trie_node*> stk;
        trie_node *tmp = root;
        for(int i=0; i<s.size(); i++)
        {
            stk.push(tmp);
            tmp = tmp->next[s[i]];
        }
        //Mark end node false. This word is deleted
        tmp->end = false;

        int k = s.size()-1;
        while(tmp->next.size()==0)
        {
          tmp = stk.top(); stk.pop();
          tmp->next.erase(s[k]);
          k--;
          if(tmp->end) break;
        }
      }
    }
};

int main()
{
   trie t;
   t.insert("Hello");
   cout<<"Hello?"<<t.query("Hello")<<endl;
   cout<<"Helalo?"<<t.query("Helalo")<<endl;
   t.insert("Hell");
   cout<<"Hell?"<<t.query("Hell")<<endl;
   t.delete_word("Hello");
   cout<<"Hello?"<<t.query("Hello")<<endl;
   cout<<"Hell?"<<t.query("Hell")<<endl;
   return 0;
}
