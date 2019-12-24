#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

#include "print.hpp"
using namespace std;

/*
Deque与Vector相似，采用动态数组管理元素
Deque的动态数组头尾都开放，可以在头尾两端添加和删除


deque<Elem> c
deque<Elem> c(c2)
deque<Elem> c = c2
deque<Elem> c = c2
deque<Elem> c(rv)
deque<Elem> c = rv
deque<Elem> c(n)
deque<Elem> c(n,elem)
deque<Elem> c(beg,end)
deque<Elem> c(initlist)
deque<Elem> c = initlist
c.~deque()

c.empty()
c.size()
c.max_size()
c.shrink_to_fit()

c1 == c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2

c[idx]
c.at(idx)

c.front()
c.back()
c.begin()
c.end()
c.cbegin()
c.cend()
c.rbegin()
c.rend()
c.crbegin()
c.crend()

c = c2
c = rv
c = initlist

c.assign(n,elem)
c.assign(beg,end)
c.assign(initlist)
c1.swap(c2)
swap(c1,c2)

c.push_back(elem)
c.pop_back()
c.push_front(elem)
c.pop_front()

c.insert(pos,elem)
c.insert(pos,n,elem)
c.insert(pos,beg,end)
c.insert(pos,initlist)

c.emplace(pos,args...)
c.emplace_back(args...)
c.emplace_front(args...)

c.erase(pos)
c.erase(beg,end)
c.resize(num)
c.resize(num,elem)
c.clear()
*/
int main()
{
	deque<string> coll;

	coll.assign(3, string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<string>(cout, "\n")
		);

	PRINT_ELEMENTS(coll);

	coll.pop_front();
	coll.pop_back();

	PRINT_ELEMENTS(coll);

	for (unsigned i = 1; i < coll.size(); ++i)
	{
		coll[i] = "another" + coll[i];
	}

	coll.resize(4, "resized string");

	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<string>(cout, "\n")
	);

	system("pause");
	return 0;
}