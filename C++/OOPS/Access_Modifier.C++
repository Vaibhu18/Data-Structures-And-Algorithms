#include <iostream>
using namespace std;

class Access_Modifier
{
    //  By default Access modifire is private you can change it manually
    //  public => it is used to specify the member of class that can be accessed and used outside  the class any where means in any function. This allows greatter flexibility between classes and object.
    //  Private => it is used to specify the member of class that can not be accessed and used outside the class that is used within the same class.

    //  Constructor => it is special member function that is automatically called when an object of class is created. Constructor are used to initiallize the object's data members. constructor have same name as the class name and do not have a return type, not even void . A class can have multiple constructor.

    //  this keyword => this keyword refer to nearest class
private:
    int num1;
    int num2;

public:
    int level;
    int age;

    int getnum1()
    {
        return num1;
    }
    void setnum1(int n)
    {
        num1 = n;
    }

    //  Constructor
    Access_Modifier()
    {
        string name = "salman";
        int age;
        int profit;
        cout<<name<<endl;
    }

    // Parameterize constructor
    Access_Modifier(int val){
        this->age = val;
    }
};

int main()
{
    Access_Modifier hero;
    
    //  Creating Class of object
    //  Static Allocation
    // Access_Modifier cls1;
    // accessed
    // cls1.setnum1(5);
    // cout << cls1.getnum1() << endl;

    //  Dynamically Allocation
    // Access_Modifier *cls2 = new Access_Modifier();
    // Value accessing (there are two types to access class member by dot operator and arow operator)
    // cout << cls1.level << endl;
    // cls2->level;

    // Construction calling and accessing
   
}