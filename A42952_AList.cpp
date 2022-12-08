#include<iostream>
using namespace std;
template <class E>
class Alist{
	int maxSize, size;
	E *a;
public:
	Alist():maxSize(100), size(0), a(new E[maxSize]){}
	Alist(int n):maxSize(n), size(0), a(new E[n]){}
	void print() const{
		for (int i = 0; i < size; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	~Alist(){delete [] a;}
	void add(int i, const E & v){
		if(i<0 || i>size || size==maxSize) throw "loi";
		for (int j = size; j >= i ; j--) a[j] = a[j-1];
		a[i]=v;
		size++;
	}
	void remove(int i){
		if(i<0 || i>=size || size==0) throw "loi";
		for (int j = i; j < size-1; j++) a[j] = a[j+1];
			size--;
	}
	void replace(int i, const E & v){
		if(i<0 || i>=size || size==maxSize) throw "loi";
		remove(i);
		add(i,v);
	}
	bool isEmpty() const{
		return size==0;
	}
	bool isFull() const{
		return size==maxSize;
	}
	Alist(const Alist & r){
		maxSize = r.maxSize;
		size = r.size;
		a = new E[r.maxSize];
		for (int i = 0; i < r.size; i++)
		{
			a[i] = r.a[i];
		}
	}
	int getsize() const{
		return size;
	}
	const Alist & operator=(const Alist & r){
		maxSize = r.maxSize;
		size = r.size;
		a = new E[r.maxSize];
		for (int i = 0; i < r.size; i++)
		{
			a[i] = r.a[i];
		}
		return *this;
	}


};
int main(){
	Alist<double> a, c;
	for (int i = 0; i < 5; ++i)
	{
		a.add(i,i);
	}
	a.add(5,100);
	cout<<a.getsize()<<endl;
	a.replace(5,200);
	a.print();
	a.remove(5);
	// cout<<a.isEmpty()<<" "<<a.isFull()<<endl;
	c=a;
	c.remove(2);
	c.print();
	return 0;
}
