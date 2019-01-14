#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

char *memmove(char*dest,const  char*src,size_t n)
{
	char *p1=dest;
	const char *p2=src;
	while(*p2!='\0')
	{
		*p1++=*p2++;
	}
	return p1;

}
template <class T>
void FillValue(T &vect ,int first, int last)
{
	if (first <= last)
	{
		for (int i=first; i<last; i++)
		{
			vect.insert(vect.end(),i);
		}
	}
	else
	{
		cout<<"first > last"<<endl;
	}
}

void PrintItem(int elem)
{
	cout<< elem<<endl;
}

template <class T>
class Multiple
{
public:
	T theValue;
public:
	Multiple(const T&v):theValue(v)
	{

	}

	void operator()(T &elem)const{
		elem *=theValue;
	}
};

class SUM
{
public:
	long sum_D;
public:
	SUM():sum_D(0)
	{

	}
	void operator ()(int item)
	{
		sum_D +=item;
	}
	operator double()
	{
		return static_cast<double>(sum_D);
	}
};

bool AbsLess(int elem1,int elem2)
{
	return abs(elem1) < abs(elem2);
}
int main()
{
	char str[7]={'a','b','c','d','e','f','\0'};
	const char tt[7]={'h','l','l','e','o','n','\0'};
	char * dd=memmove(str,tt,3);
	cout<<str<<endl;
	cout<<dd<<endl;
	cout<<dd<<endl;
	cout<<*dd<<endl;
	cout<<&dd<<endl;
	
	vector<int> vect;
	::FillValue(vect,1,10);
	for_each(vect.begin(),vect.end(),PrintItem);
	for_each(vect.begin(),vect.end(),Multiple<int>(2));
	for_each(vect.begin(),vect.end(),PrintItem);
	int sum = for_each(vect.begin(),vect.end(),SUM());
	cout<<"sum=" <<sum<<endl;
	int m_min = *min_element(vect.begin(),vect.end());
	int ct = count_if(vect.begin(),vect.end(),bind2nd(greater<int>(),5));
	cout<<"the count greater than 5 have :"<<ct<<endl;
	cout<<m_min<<endl;
	int ct_max =*max_element(vect.begin(),vect.end(),AbsLess);
	cout<<"ct_max"<<ct_max<<endl;

	vector<int>::iterator m_num;
	m_num = find(vect.begin(),vect.end(),10);
	cout<<"10 in the the vector index:"<<distance(vect.begin(),m_num)+1<<endl;

	int dim[]={1,2,3,4,5,6,7,8};
	int dim1[]={11,12,13,14,15,16,17,18};
	vector<int>v1;
	vector<int>v2;
	v1.assign(dim,dim+9);
	cout<<"v1"<<endl;
	copy(v1.begin(),v1.end(),ostream_iterator<int>(cout,","));
	copy(dim1,dim1+8,back_inserter(v2));
	cout<<"vector v2"<<endl;
	system("pause");
	return 0;
}
