#include <bits/stdc++.h>
using namespace std;



class base{
    public:
    int x;
    base(){
        x=y=z=0;
    }
    protected:
    int y;
    private:
    int z;
};

class derived : public base{
    //all data comes except private;
    //public int x;
    //protected int y;
};

class derived : protected base{
    //all data comes except private;
    //protected int x;
    //protected int y;
};

class derived : private base{
    //all data comes except private;
    //private int x;
    //private int y;
}

void outside(base b){
    //only x can be accessed
    cout<<b.x<<b.y<<b.z<<endl;
}

int main(){
    base b();
    outside(b);
    return 0;
}