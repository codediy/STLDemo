/*
Map和multimap将key/value pair作为元素进行管理
可以根据key的排序自动为元素排序
multimap允许重复元素，map不允许

map/multimap以平衡二叉树实现
set,map,multimap,multiset使用相同的内部结构
set和multiset看做特殊的map,multimap
set元素的value和key是同一个对象
所以map具有set所有的能力和操作

## 操作函数
map c
map c(op)
map c(c2)
map c = c2
map c(rv)
map c = rv
map c(beg,end)
map c(beg,end,op)
map c(initlist)
map c = initlist
c.~map()

map<Key,Val>
map<Key,Val,Op>
multimap<Key,Val>
multimap<Key,Val,Op>

c.key_comp()
c.vaue_comp()
c.empty()
c.size()
c.max_size()

c1 == c2
c1 != c2
c1 < c2
c1 > c2

c1 <= c2
c1 >= c2

c.count(val
c.find(val)
c.lower_bound(val)
c.upper_bound(val)
c.equal_range(val)


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

c.insert(val)
c.insert(post,val)
c.insert(beg,end)
c.insert(initlist)
c.emplace(args...)
c.emplace_hint(pos,args.)
c.erase(val)
c.erase(pos)
c.erase(beg,end)
c.clear()

c[key]
c.at(key)

*/

#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;
int mapLambda()
{
	map<string, double> coll{
		{ "tim",9.9 },
		{ "struppi",11.77 }
	};

	for_each(coll.begin(), coll.end(),
		[](pair<const string, double>& elem) {
		elem.second *= elem.second;
	});

	for_each(coll.begin(), coll.end(),
		[](const map<string, double>::value_type& elem) {
		cout << elem.first << ":" << elem.second << endl;
	});

	return 0;
}

int mapArray()
{
	typedef map<string, float> StringFloatMap;
	StringFloatMap stocks;

	stocks["BASF"] = 369.50;
	stocks["VW"] = 413.50;
	stocks["Daimler"] = 819.00;
	stocks["BMW"] = 834.00;
	stocks["Siemens"] = 842.20;

	StringFloatMap::iterator pos;
	cout << left;

	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
		cout << "stcoks: " << setw(12) << pos->first
			<< "price:" << pos->second <<endl;
	}
	cout << endl;

	for (pos = stocks.begin(); pos != stocks.end(); ++pos)
	{
		pos->second *= 2;
	}

	for (pos = stocks.begin(); pos != stocks.end(); ++pos){
		cout << "stcoks: " << setw(12) << pos->first
			<< "price:" << pos->second << endl;
	}

	stocks["Volkswagen"] = stocks["VW"];
	stocks.erase("VW");

	for (pos = stocks.begin(); pos != stocks.end(); ++pos){
		cout << "stcoks: " << setw(12) << pos->first
			<< "price:" << pos->second << endl;
	}
	return 0;
}

int main()
{	
	mapArray();

	system("pause");
	return 0;
}