#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    char data;
    bool isTerminal;
    TrieNode **child;
    int childcount;
    TrieNode(char data)
    {
        this->data=data;
        isTerminal=false;
        childcount=0;
        child=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};
class Trie
{
    TrieNode *root;
    int noofwords;
    public:
    Trie()
    {
        root=new TrieNode('\0');
        noofwords=0;
    }
     bool InsertWord(string word , TrieNode *root )
    {
        if(word.length()==0)
        {
            if(!root->isTerminal)
            {
                root->isTerminal=true;
                return true;
            }
            else
            {
                return false;
            }
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->child[index]==NULL)
        {
            child=new TrieNode(word[0]);
            root->child[index]=child;
            root->childcount++;
        }
        else
        {
            child=root->child[index];
        }
        return InsertWord(word.substr(1) , child);
    }
    void InsertWord(string word)
    {
        if(InsertWord(word,root))
        {
            noofwords++;
        }
    }
    bool searchword(string word ,TrieNode *root)
    {
        if(word.length()==0)
        {
            return root->isTerminal;
        }
        int index=word[0]-'a';
        if(root->child[index]==NULL)
        {
            return false;
        }
        return searchword(word.substr(1),root->child[index]);
    }
    bool searchword(string word)
    {
        return searchword(word,root);
    }
    bool delword(string word , TrieNode *root)
    {
        if(word.length()==0)
        {
            if(root->isTerminal==true)
            {
                root->isTerminal=false;
                return true;
            }
            else
            {
                return false;
            }
        }
        int index=word[0]-'a';
        TrieNode *child=root->child[index];
        if(child==NULL)
        {
            return false;
        }
        return delword(word.substr(1),child);
        if(!child->isTerminal && child->childcount==0)
        {
            root->child[index]=NULL;
            delete child;
            root->childcount--;
        }
    }
    void delword(string word)
    {
        if(delword(word,root))
        {
            noofwords--;
        }
    }
    int countwords()
    {
        return noofwords;
    }
    void printallwords(TrieNode *root,string s)
    {
        if(root->isTerminal && root->childcount==0)
        {
            cout<<s<<endl;
            return;
        }
        else if(root->isTerminal)
        {
            cout<<s<<endl;
        }
        for(int i=0;i<26;i++)
        {
            if(root->child[i]!=NULL)
            {
                printallwords(root->child[i],s+root->child[i]->data);
            }
            //s="";
        }
    }
    void printallwords()
    {
        string s="";
        printallwords(root,s);
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Trie t;
    t.InsertWord("h");
    t.InsertWord("hello");
    t.InsertWord("hi");
    t.InsertWord("the");
    t.InsertWord("there");
    t.InsertWord("their");
    t.InsertWord("those");
    t.InsertWord("this");
    cout<<t.searchword("this")<<endl;
    cout<<t.searchword("th")<<endl;
    cout<<t.countwords()<<endl;
    t.delword("this");
    cout<<t.countwords()<<endl;
    t.printallwords();
    return 0;
}
