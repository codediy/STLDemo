/*
## List对象
List对象使用双向链表管理元素
每个元素都有pointer指向前一个和后一个元素

List对象提供了两个pointer
指向第一个和最后一个元素

## Array/Vector/Deque与List
Array,Vector,Deque支持随机访问
List不支持随机访问
任何位置的添加,修改和删除常量时间完成

List读速度慢，写速度快
Array/Vector/Deque读速度快，写速度慢

## List操作
- 创建
list<Elem> c
list<Elem> c(c2)
list<Elem> c = c2
list<Elem> c(rv)
list<Elem> c = rv
list<Elem> c(n)
list<Elem> c(n,elem)
list<Elem> c(beg,end)
list<Elem> c(initlist)
list<Elem> c = initlist
c.~list()


c.empty()
c.size()
c.max_size()
c1 = c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2

元素访问 迭代循环
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
c.remove(val)
c.remove_if(op)
c.resize(num)
c.resize(num,elem)
c.clear()

c.unique()
c.unique(op)
c.splice(pos,c2)
c.splice(pos,c2,c2pos)
c.splice(pos,c2,c2beg,c2.end)
c.sort()
c.sort(op)
c.merge(c2)
c.merge(c2,op)
c.reverse()
*/

#include<list>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

void printLists(const list<int>& l1, const list<int>& l2)
{
	cout << "list1:";
	copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << "list2:";
	copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
}

int main()
{
	list<int> list1, list2;

	for (int i = 0; i < 6; i++)
	{
		list1.push_back(i);
		list2.push_front(i);
	}

	printLists(list1, list2);

	/*
	find()从list2中查找3所在索引i3
	c.splice(pos,c2)然后将list1的索引i3前的元素转移到list2
	*/
	list2.splice(find(list2.begin(), list2.end(), 3), list1);
	printLists(list1, list2);
	
	/*
	c.splice(pos,c2,c2pos)
	*/
	list2.splice(list2.end(), list2, list2.begin());
	printLists(list1, list2);

	list2.sort();
	list1 = list2;
	list2.unique();
	printLists(list1, list2);

	list1.merge(list2);
	printLists(list1, list2);
	
	system("pause");
	return 0;
}