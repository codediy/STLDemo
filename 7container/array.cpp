#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include "print.hpp"

using namespace std;
/*

### 容器的基础能力
1. 容器提供的都是`value语义`,
必须 是可以`copy`和`move`,
对于`reference`的需要使用`pointer`
2. 元素在容器有特定顺序
容器提供`迭代器`作为遍历操作
3. 操作并发绝对安全

### 容器的共通操作

```
ContType c		 Default构造函数,创建未含任何元素的容器
ContType c(c2)   Copy构造函数
ContType c = c2  Copy构造函数
ContType c(rv)   Move构造函数
ContType c  = rv Move构造函数
ContType c(beg,end)
ContType c(inittlist)
ContType c = initlist

c.~ContType()
c.empty()
c.size()
c.max_size()

c1 == c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2

c = c2
c = rv
c = initlist

c1.swap(c2)
swap(c1,c2)

c.begin()
c.end()
c.cbegin()
c.cend()
c.clear()

```

1. 初始化
每个容器都提供一个default构造函数,
一个copy构造函数和一个析构函数
2 赋值和swap()
3 比较大小
4 迭代
```
for (auto pos = coll.cbegin();pos != coll.end(); ++ pos){}
for (auto pos = coll.begin();pos != coll.end(); ++pos)
{
  *pos = ...;
}
```
### 容器的共通类型
```
size_type
difference_type
value_type
reference
cosnt_reference
iterator
const_iterator
pointer
const_pointer

## Array
1. 初始化
```c++
std::array<int,4> x;
std::array<int,4> x = {}
std::array<int,5> coll = {42,377,611,21,44}
std::array<int,10> c2 = {42}

std::sort(coll.begin(),coll.end())
std:cout << coll.front();

2. 操作
```
array<ElemType,N> c

array<ElemType,N> c(c2)
array<ElemnType,N> c = c2

array<ElemType,N> c(rv)
array<ElemType,N> c =rv

array<ElemType,N> c = initlist
```

```
c.empty()
c.size()
c.max_size90

c1 == c2
c1 != c2
c1 < c2
c1 > c2
c1 <= c2
c1 >= c2
```

```
c = c2
c = rv
c.fill(val)
c1.swap(c2)
swap(c1,c2)
```

```
c[idx]
c.at[idx)

c.front()
c.back()
```

```
c.begin()
c.end()
c.cbegin()
c.cend()

c.rbegin()
c.rend()
c.crbegin()
c.crend()
```
*/
int main()
{
	array<int, 10> a = { 11, 22, 33, 44 };

	PRINT_ELEMENTS(a);
	
	a.back() = 9999;
	a[a.size() - 2] = 42;

	PRINT_ELEMENTS(a);

	cout << "sum:"
		<< accumulate(a.begin(), a.end(), 0);

	transform(
		a.begin(), a.end(),
		a.begin(),
		negate<int>()
		);
	PRINT_ELEMENTS(a);
	system("pause");
	return 0;
}
