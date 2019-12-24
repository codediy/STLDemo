/*
## ForwardList

单向链表
内存较少，行动略快

## ForwardList操作
- 创建
fl<Elem> c
fl<Elem> c(c2)
fl<Elem> c = c2
fl<Elem> c(rv)
fl<Elem> c = rv
fl<Elem> c(n)
fl<Elem> c(n,elem)
fl<Elem> c(beg,end)
fl<Elem> c(initlist>
fl<Elem> c = initlist
c.~fl()

c.empty()
c.max_size()
c1 == c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2

c = c2
c = rv
c =initlist
c.assign(n,elem)
c.assign(beg,end)
c.assign(initlist)
c1.swap(c2)
swap(c1,c2)

c.front()
c.begin()
c.end()
c.cbegin()
c.cend()
c.before_begin()
c.cbefore_begin()

c.push_front(elem)
c.pop_front()
c.insert_after(pos,elem)
c.insert_after(pos,n,elem)
c.insert_after(pos,beg,end)
c.insert_after(pos,initlist)

c.emplace_after(pos,args...)
c.emplace_front(args...)

c.erase_after(pos)
c.erase_after(beg,end)

c.remove(val)
c.remove_if(op)
c.resize(num)
c.resize(num,elem)
c.clear()

c.unique()
c.unique(op)

c.splice_after(pos,c2)
c.splice_after(pos,c2,c2pos)
c.splice_after(pos,c2,c2beg,c2end)

c.sort()
c.sort(op)
c.merge(c2)
c.merge(c2,op)
c.reverse()

*/

#include<forward_list>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

void printLists(
	const string& s,
	const forward_list<int>& l1,
	const forward_list<int>& l2
	)
{
	cout << s << endl;
	cout << " list1: ";
	copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << " list2: ";
	copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	forward_list<int> list1 = { 1, 2, 3, 4 };
	forward_list<int> list2 = { 77, 88, 99 };
	printLists("initial:", list1, list2);

	list2.insert_after(list2.before_begin(), 99);
	list2.push_front(10);
	list2.insert_after(list2.before_begin(), { 10, 11, 12, 13 });
	printLists("6 new elems:", list1, list2);

	list1.insert_after(list1.before_begin(), list2.begin(), list2.end());
	printLists(" list2 into list1:", list1, list2);

	list2.erase_after(list2.begin());
	list2.erase_after(find(list2.begin(), list2.end(), 99), list2.end());
	printLists(" delete 2nd and after 99", list1, list2);

	list1.sort();
	list2 = list1;
	list2.unique();
	printLists(" sorted and unique:", list1, list2);

	list1.merge(list2);
	printLists("merged:", list1, list2);

	system("pause");
	return 0;
}