#include "iostream"
#include "stdio.h"
using namespace std;
class node {
	int data;
	node* next;
	friend class cirlink;
	node(){
	data = 0;
	next = NULL;
	}
};
class cirlink {
private:
	node* last;
public:
	cirlink(){
		last = NULL;
	}
	void push_back(int i)
	{
		if (last == NULL)
		{
			last = new node;
			last->data = i;
			last->next = last;
			return;
		}
		else {
			node* p;
			p = last->next;
			last->next = new node;
			last->next->data = i;
			last = last->next;
			last->next = p;
		}
	}
	void output()
	{
		node* cache = last->next;
		while (1)
		{
			cout <<cache<<' ' << cache->data << ',' << cache->next << endl;
			if (cache == last)
				break;
			cache = cache->next;
		}
	}
	void output_C()
	{
		node* cache = last->next;
		while (1)
		{
			printf_s("%p %c,%p\n", cache, cache->data, cache->next);
			if (cache == last)
				break;
			cache = cache->next;
		}
	}
	node* getADDR(int i)
	{
		node* cache = last->next;
		while (1)
		{
			if (i == cache->data)
				return cache;
			if (cache == last)
				break;
			cache = cache->next;
		}
		return NULL;
	}
	void del(node * ADDR)
	{
		node* cache = last->next;
		
		while (1)
		{
			if (cache->next->next == ADDR)
			{
				if (ADDR == last->next) {
					//cout << 1;
					cout << 'N' << endl;
					return;
				}
				else {
					//cout << 3;
					node* p = cache->next;
					cache->next = cache->next->next;
					delete p;
					return;
				}
			}
			if (cache == last)
				break;
			cache = cache->next;
		}
	}
};
int j(char p)
{
	if ((p >= 'a' && p <= 'z') ||( p >= 'A' && p <= 'Z'))
		return 1;
	if (p >= '0' && p <= '9')
		return 2;
	return 3;
}
int main()
{
	cirlink cl;
	cl.push_back(3);
	cl.push_back(10);
	cl.push_back(9);
	cl.push_back(100);
	cl.output();
	cl.del(cl.getADDR(10));
	cl.output();
	string p;
	cin >> p;
	cirlink alpha, num, other;
	for (int i = 0; i < p.length(); i++)
	{
		switch (j(p[i]))
		{
		case 1:alpha.push_back(p[i]); break;
		case 2:num.push_back(p[i]); break;
		case 3:other.push_back(p[i]); break;
		default: break;
		}
	}
	alpha.output_C();
	num.output_C();
	other.output_C();
}
