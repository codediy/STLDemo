#include <vector>
#include <iostream>

using namespace std;

/*
## vector

### ÉùÃ÷
vector<int> coll;

### ²Ù×÷
- 
*/
int main()
{	

	cout << "Hello" << endl;
	
	vector<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_back(i);
	}

	for (int i = 0; i < coll.size(); ++i)
	{
		cout << coll[i] << " ";
	}

	system("pause");
	return 0;
}