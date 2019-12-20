#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include "print.hpp"

using namespace std;

/*
Vector
> ���Ȳ�ȷ���Ķ�̬����
> Vector�����㹻�������������Ԫ��
> �����ռ任��ʱ��

```
v.reserve(80)		//��������
v.shrink_to_fit()   //��������

```
## ����
```
vector<Elem> c
vector<Elem> c(c2)
vector<Elem> c = c2

vector<Elem> c(rv)
vector<Elem> c = rv

vector<Elem> c(n)
vector<Elem> c(n,elem)
vector<Elem> c(beg,end)
vector<Elem> c(initlist)
vector<Elem> c = initlist

```

```
c.empty()
c.size()
c.max_size()
c.capacity()
c.reserve()
c.shrink_to_fit()
```

```
c = c2
c = rv


c =initlist
c.assign(n,elem)
c.assign(beg,end)
c.assign(initlist)
c1.swap(c2)
swap(c1,c2)
```

```
c[idx]
c.at(idx)
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
```
c.push_back()
c.pop_back()

c.insert(pos,elem)
c.insert(pos,n,elem)
c.insert(pos,beg,end)
c.insert(pos,initlist)

c.emplace(pos,args...)
c.emplace_back(args...)

c.erase(pos)
c.erase(beg,end)
c.resize(num)
c.resize(num,elem)
c.clear()
```
*/
int main()
{
	vector<string> sentence;
	
	sentence.reserve(5);
	sentence.push_back("Hello,");

	sentence.insert(sentence.end(), { "how", "are", "you", "?" });
	
	

	// Copy���
	copy(sentence.cbegin(), sentence.cend(),
		ostream_iterator<string>(cout, " ")
	);
	cout << endl;

	
	cout << "max_size():" << sentence.max_size() << endl;
	cout << "size():" << sentence.size() << endl;
	cout << "capacity():" << sentence.capacity() << endl;

	swap(sentence[1], sentence[3]);
	// �滻?Ϊalways;
	sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
	sentence.back() = "!";

	// ɾ�����һ��Ԫ��
	sentence.pop_back();
	sentence.pop_back();

	sentence.shrink_to_fit();


	PRINT_ELEMENTS(sentence);
	system("pause");
	return 0;
}