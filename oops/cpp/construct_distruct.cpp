#include <bits/stdc++.h>
using namespace std;


/*

Constructor: 

A special member function of a class which initializes
data in the class

 C++ generates default contructor for us

Types: 

default
parameterized
copy

Destructor:

When is it called??
1. when onj goes out of scope from execution
2. when the local variables end

no args no return not even void

we dont need to create a desctructor since the default one the compiler
makes is descent enough.
Its needed when we have dynamically allocated memeory or pointer in class


*/

#include <bits/stdc++.h>
using namespace std;

class car{
    private:
    int name;
    public:
    int id;
    
    car(){
        id=1;
    }
    car(int a){
        id=a;
    }
    car(int a,int b){
        id=b;
    }
    car (car &obj){
        id=obj.id;
    }
    void display(){
        cout<<id<<endl;
    }
    ~car(){
        cout<<"des called\n";
    }
};

int main(){
    car c1,c2(1),c3(2,3),c4(c3);
    
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    
    car c5=c3; //here copy cons is called
    c5.display();
    c4.display();// here c4 is getting out of scope so here destrcutor is being called
    return 0;
}

//deep and shallow copy

#include <bits/stdc++.h>
using namespace std;

class car{
    private:
    int name;
    public:
    int id,*p;
    
    car(){
        id=1;
        p=new int(10);
    }
    car(int a){
        id=a;
        p=new int(10);
    }
    car (car &obj){//deep copy
        id=obj.id;
        p=new int;
        *p=*(obj.p);// this is why we are writing the code to create new pointer
    }
    void display(){
        cout<<id<<endl;
    }
    ~car(){
        cout<<"des called\n";
        delete p;
    }
};

int main(){
    car c1(2);
    car c2=c1; // copy cons is copying
    
    //if deep copy constructor not writter, then default copy construtor initializes and you get diff pointers pointing to same thing
    cout<<c1.p<<" "<<c2.p; //address will be same if default copy
    
    return 0;
}