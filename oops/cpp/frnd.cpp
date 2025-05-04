#include <bits/stdc++.h>
using namespace std;

 /* 
 Theory

1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, 
   it lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3) Friendship is not inherited 
4) The concept of friends is not there in Java. 

friend function can be: 
a) A member of another class 
b) A global function 
c) class itself

*/

// basic example
class A{
    public:
    friend int add(A &a,int x);
    private:
    int x=10;
    
};

int add(A &a,int x){
    return a.x+x;
}

int main(){
    A a;
    cout<<add(a,8);
}

//friend class

class B;

class A {
    int a=10;
    friend class B;
};

class B {

public:

void showA(A& a)
{
	// Since showB() is friend of B, it can
	// access private members of B
	std::cout << a.a;
}
    
};

int main()
{
	A a;
	B x;
	x.showA(a);
	return 0;
}



//friend class method
#include <iostream>

class B;

class A {
public:
	void showB(B&x);
};

class B {
private:
	int b;

public:
	B() { b = 0; }
	friend void A::showB(B& x); // Friend function
};

void A::showB(B& x)
{
	// Since showB() is friend of B, it can
	// access private members of B
	std::cout << "B::b = " << x.b;
}

int main()
{
	A a;
	B x;
	a.showB(x);
	return 0;
}
