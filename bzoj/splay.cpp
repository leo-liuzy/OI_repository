/*Copyright (c)2014 YeGuanghao
*This source-code is licensed under GPLv3
*/
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#define PROB "3224"
using namespace std;
inline void Read(int & x)
{
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	x = 0;
	while (ch <= '9' && ch >= '0') {
		x *= 10, x += ch - '0';
		ch = getchar();
	}
}

struct node{
	node *l, *r, *f;
	int size,v,cnt;
	node()
	{
		l = r = f = NULL;
		cnt = size = v = 0;
	}
};

struct splay_tree
{
	node *root;
	void update(node *p)
	{
		p->size = p->cnt + p->l->size + p->r->size;
	}
	void rot_l(node * cur) //cur is which want to be higher
	{
		node * temp = cur->f;
		temp->r = cur->l;
		temp->r->f = temp;
		if (root != temp)
		{
			if (temp != cur->f->l)//cur's parent is not the lchild of the cur's grand parent
			{
				temp->f->r = cur;
			}
			else
			{
				temp->f->l = cur;
			}
			cur->f = temp->f;
		}
		else
		{
			root = cur;
		}
		cur->l = temp;
		cur->l->f = cur;
		update(cur);
		update(temp);
	}
	void rot_r(node *cur)
	{
		node *temp = cur->f;
		temp->l = cur->r;
		temp->l->f = cur->r;
		if (root != cur)
		{
			if (cur != cur->f->l)
			{
				temp->f->r = cur;
			}
			else
			{
				temp->f->l = cur;
			}
			temp->f = cur->f;
		}
		else
		{
			root = cur;
		}
		cur->r = temp;
		update(cur);
		update(temp);
	}
	void splay(node *cur)
	{
		while (cur != root)
		{
			if (cur->f == root)//zig
			{
				if (root->l == cur)
				{
					rot_r(cur);
				}
				else
				{
					rot_l(cur);
				}
			}
			else if (cur->f->f->l == cur->f&&cur->f->l == cur)//zig zig both left
			{
				rot_r(cur->f);
				rot_r(cur);
			}
			else if (cur->f->f->r == cur->f&&cur->f->r == cur)//zig zig both right;
			{
				rot_l(cur->f);
				rot_l(cur);
			}
			else if (cur->f->r == cur&&cur->f->f->l == cur->f)
			{
				rot_l(cur);
				rot_r(cur);
			}
			else if (cur->f->l == cur&&cur->f->f->r == cur->f)
			{
				rot_r(cur);
				rot_l(cur);
			}
		}
	}
	void splay(node *cur, node * goal)
	{
		if (cur->v < goal->v)//at lchilde
		{
			while (cur != goal->l)
			{
				if (cur->f == goal)//zig
				{
					if (goal->l == cur)
					{
						rot_r(cur);
					}
					else
					{
						rot_l(cur);
					}
				}
				else if (cur->f->f->l == cur->f&&cur->f->l == cur)//zig zig both left
				{
					rot_r(cur->f);
					rot_r(cur);
				}
				else if (cur->f->f->r == cur->f&&cur->f->r == cur)//zig zig both right;
				{
					rot_l(cur->f);
					rot_l(cur);
				}
				else if (cur->f->r == cur&&cur->f->f->l == cur->f)
				{
					rot_l(cur);
					rot_r(cur);
				}
				else if (cur->f->l == cur&&cur->f->f->r == cur->f)
				{
					rot_r(cur);
					rot_l(cur);
				}
			}
		}
                else 
                {
                        while (cur != goal->r)
			{
				if (cur->f == goal)//zig
				{
					if (goal->l == cur)
					{
						rot_r(cur);
					}
					else
					{
						rot_l(cur);
					}
				}
				else if (cur->f->f->l == cur->f&&cur->f->l == cur)//zig zig both left
				{
					rot_r(cur->f);
					rot_r(cur);
				}
				else if (cur->f->f->r == cur->f&&cur->f->r == cur)//zig zig both right;
				{
					rot_l(cur->f);
					rot_l(cur);
				}
				else if (cur->f->r == cur&&cur->f->f->l == cur->f)
				{
					rot_l(cur);
					rot_r(cur);
				}
				else if (cur->f->l == cur&&cur->f->f->r == cur->f)
				{
					rot_r(cur);
					rot_l(cur);
				}
			}
                }
	}
	void find_prev(node *p)
	{
		splay(p);
		node * ret;
		ret = p->l;
		if (ret == NULL)
			return NULL;
		while (ret->r != NULL)
		{
			ret = ret->r;
		}
		return ret;
	}
	void find_succ(node *p)
	{
		splay(p);
		node *ret;
		ret = p->r;
		if (ret == NULL)
			return NULL;
		else
		{
			while (ret->l != NULL)
			{
				ret = ret->l;
			}
			return ret;
		}
	}
	void Insert(int n)
	{
                node *item;
                item->v=n;
                item->size=1;
                item->cnt=1;
                node *ptr=root;
		for(;;)
                {
                        if(n==ptr->v)
                        {
                                  ptr->cnt++;
                                  ptr->size++;
                                  return ;
                        }
                        else if(n>ptr->v&&ptr->r==NULL)
                        {
                                item->f=ptr;
                                ptr->r=item;
                                return ;
                        }
                        else if(n<ptr->v&&ptr->l==NULL)
                        {
                                item->f=ptr;
                                ptr->l=item;
                        }
                        else// can not be insert at cur loop
                        {
                                ptr->size++;
                                if(n>ptr->v)
                                {
                                        ptr=ptr->r;
                                        continue;
                                }
                                else if(n<ptr->v)
                                {
                                        ptr=ptr->l;
                                        continue;
                                }
                        }
                }
	}
	void Delete(node *p)
        {
                node *  prev=find_prev(p);
                node *  succ=find_succ(p);
                splay(prev);
                splay(succ,prev);
                if(p->cnt!=1)
                {
                        p->cnt--;
                }
                else
                {
                        prev->l=NULL;
                }
                update(prev);
                return ;
        }
        node * find(int n)
        {
                node *  ret= root;
                while(ret->v!=value&&ret!=NULL)
                {
                        if(n>ret->value)
                        {
                                ret=ret->r;
                                continue;
                        }
                        else if(n<ret->value)
                        {
                                ret=ret->l;
                                continue;
                        }
                }
                return ret;
        }
        void QueryRand(int n)
        {
                node * cur=find(n);
                splay(cur);
                printf("%d\n",cur->l->size);
        }
        void Delete(int n)
        {
                node * cur= find(n);
                Delete(n);
                return ;
        }
        void Query(int k)
        {
                node * ret;
                ret=root;
                for(;;)
                {
                        if(ret->l->size<k&&ret->l->size+ret->cnt>=k)
                        {
                                printf("%d\n",ret->v);
                                return ;
                        }
                        else if(ret->l->size>=k)
                        {
                                ret=ret->l;
                                continue;
                        }
                        else
                        {
                                k-=ret->l->szie;
                                k-=ret->cnt;
                                ret=ret->r;
                                continue;
                                
                        }
                }
                return ;
        }
        void QuerySmall(int n)
        {
                Insert(n);
                node * cur;
                cur=find(n);
                printf("%d\n",find_prev(cur)->v);
                Delete(cur);
                return ;
        }
        void QueryBig(int n)
        {
                Insert(n);
                node * cur;
                cur=find(n);
                printf("%d\n",find_succ(cur)->v);
                Delete(cur);
                return ;
        }
}tree;

int main()
{
        int M;
        register int opt,x;
        Read(M);
        while(M--)
        {
                Read(opt);
                Read(x);
                switch(opt)
                {
                        case 1: tree.Insert(x);
                                break;
                        case 2: tree.Delete(x);
                                break;
                        case 3: tree.QueryRand(x);
                                break;
                        case 4; tree.Query(x);
                                break;
                        case 5: tree.QuerySmall(x);
                                break;
                        case 6: tree.QueryBig(x);
            }
        }
        return 0;
}
