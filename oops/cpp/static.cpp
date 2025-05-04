#include <bits/stdc++.h>
using namespace std;

 /* 
 Theory
 
1. There is no such thing as a static class in C++. The closest approximation is a class that only contains static data members and static methods.
2. Members of static classes are normally stored on the heap, members of value types are normally stored on the stack.
3. static members are shared among all objects.

*/

// 1. intialising static data members not possible
class A{
    static int a=0;
    public:
    void get(){
        a++;
        cout<<a<<endl;
    }
}
int main() {
    A a;
    a.get();
}

// right way (if not public u can access using scope operator also)
class C{
    public:
    static int x;
};

int C::x=9;


int main()
{
    cout<<C::x<<endl;
	return 0;
}

// 2. constructors can access static members once they are initialized and static members cant be initialised inside a function

class C{
    public:
    static int x;
    C(){
        x=11;
        cout<<x<<endl;
    }
};

int C::x=9;


int main()
{
	static class C c;
	return 0;
}


/* 

    3. static objects

 static objects just make the object undistructable until the program ends.
 its doesnt make the members and functions static

*/

class C{
    public:
    int x;
    C(){
        x++;
        cout<<x<<endl;
    }
};




int main()
{
	static class C c1,c2,c3;
	return 0;
}

//output: 1 1 1 not 1 2 3

/*

 4. static methods
 
It is a member function that is used to access only static data members. It cannot access non-static data members not even call non-static member functions. 
It can be called even if no objects of the class exist. It is also used to maintain a single copy of the class member function across different objects of the class.

*/

class A {
public:
	static void f()
	{
		cout << "GeeksforGeeks!";
	}
};

// Driver Code
int main()
{
	A::f();
}

