#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include "print.hpp"

using namespace std;
/*

### �����Ļ�������
1. �����ṩ�Ķ���`value����`,
���� �ǿ���`copy`��`move`,
����`reference`����Ҫʹ��`pointer`
2. Ԫ�����������ض�˳��
�����ṩ`������`��Ϊ��������
3. �����������԰�ȫ

### �����Ĺ�ͨ����

```
ContType c		 Default���캯��,����δ���κ�Ԫ�ص�����
ContType c(c2)   Copy���캯��
ContType c = c2  Copy���캯��
ContType c(rv)   Move���캯��
ContType c  = rv Move���캯��
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

1. ��ʼ��
ÿ���������ṩһ��default���캯��,
һ��copy���캯����һ����������
2 ��ֵ��swap()
3 �Ƚϴ�С
4 ����
```
for (auto pos = coll.cbegin();pos != coll.end(); ++ pos){}
for (auto pos = coll.begin();pos != coll.end(); ++pos)
{
  *pos = ...;
}
```
### �����Ĺ�ͨ����
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
1. ��ʼ��
```c++
std::array<int,4> x;
std::array<int,4> x = {}
std::array<int,5> coll = {42,377,611,21,44}
std::array<int,10> c2 = {42}

std::sort(coll.begin(),coll.end())
std:cout << coll.front();

2. ����
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
