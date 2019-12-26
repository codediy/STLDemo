/*
根据特定排序，自动排序元素
set不允许元素重复，multiset允许元素重复

set和multiset一般以平衡二叉树实现
自动排序在于查询元素高效
不能直接修改元素的值
如果需要修改，先删除旧元素，然后再插入新元素

## 操作函数
set c
set c(op)
set c(c2)
set c = c2
set c(rv)
set c = rv
set c(beg,end)
set c(beg,end,op)
set c(initlist)
set c = initlist
c.~set()

set<Elem>
set<Elem,Op>
multiset<Elem>
multiset<Elem,Op>

c.key_comp()
c.value_compo()
e.empty()
c.size()
c.max_size()

c1 == c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2

c.count(val)
c.find(val)
c.lower_bound(val)
c.upper_bound(val)
c.equal_range()

c = c2
c = rv
c = initlist
c1.swap(c2)
swap(c1,c2)

c.begin()
c.end()
c.cbegin()
c.cend()
c.rbegin()
c.rend()
c.crbegin()
c.crend()

c.inset(val)
c.insert(post,val)
c.insert(beg,end)
c.insert(initlist)
c.emplace(args...)
c.emplace_hint(pos,args...)
c.erase(val)
c.erase(pos)
c.erase(beg,end)
c.clear()
*/

#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>
#include<functional>

using namespace std;

int main()
{
	set<int,greater<int>> coll1;
	
	coll1.insert({ 4, 3, 5, 1, 6, 2 });
	coll1.insert(5);

	for (int elem : coll1)
	{
		cout << elem << " ";
	}
	cout << endl;

	auto status = coll1.insert(4);
	if (status.second){
		cout << "4 insetted as elemet"
			<< distance(coll1.begin(), status.first) + 1 << endl;

	}
	else{
		cout << "4 already exists" << endl;
	}

	set<int> coll2(coll1.cbegin(), coll1.cend());

	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));

	cout << endl;

	coll2.erase(coll2.begin(), coll2.find(3));
	int num;
	num = coll2.erase(5);
	cout << num << "element(s) removed" << endl;

	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}