//Encapsulation simple
//Noraml Class and Objects
//Complete Encapsulation means all the data members of the class are private

//Inheritance
//Types of Inheritance
//Simple,Multiple,Multilevel,Hierarchical,Hybrid

//Simple Inheritance

class Animal{
    public:
    int age;
    int weight;
    string name;

    void eat(){
        cout<<"Animal Eating "<<endl;
    }

    void sleep(){
        cout<<"Animal Sleeping "<<endl;
    }
};

class Lion : public Animal{

};

int main(){
    Animal l1;

    l1.age = 5;
    l1.weight = 200;
    l1.name = "Simba";
    l1.eat();
    l1.sleep();
}


//Multiple Inheritance
class Animal{
    public:
    int age;
    int weight;
    string name;

    void eat(){
        cout<<"Animal Eating "<<endl;
    }

    void sleep(){
        cout<<"Animal Sleeping "<<endl;
    }
};

class Mammal{
    public:
    int mammalAge;
    int mammalWeight;
    string name;

    void walk(){
        cout<<"Mammal Walking "<<endl;
    }
};

class Lion : public Animal, public Mammal{

};

int main(){
    Lion l1;

    l1.age = 5;
    l1.weight = 200;
    l1.name = "Simba";
    l1.eat();
    l1.sleep();
    l1.mammalAge = 5;
    l1.mammalWeight = 200;
    l1.walk();
}
//Diamond Problem in Multiple Inheritance
//When two classes are inherited from the same base class and then a class is inherited from those two classes then it creates ambiguity as to which base class's properties and methods should be used by the derived class
//To solve this problem we can use virtual inheritance or the scope resolution operator
//In tehse the compiler will be confused which name to print 
int main(){
    Lion l1;
    //so for printing its name in animal we will write
    cout<<l1.Animal::name<<endl;
    //for printing its name in mammal we will write
    cout<<l1.Mammal::name<<endl;
}


//Multilevel Inheritance
class Animal{
    public:
    int age;
    int weight;
    string name;

    void eat(){
        cout<<"Animal Eating "<<endl;
    }

    void sleep(){
        cout<<"Animal Sleeping "<<endl;
    }
};

class Mammal : public Animal{
    public:
    int mammalAge;
    int mammalWeight;
    string name;

    void walk(){
        cout<<"Mammal Walking "<<endl;
    }
};

class Lion : public Mammal{

};

int main(){
    Lion l1;
    l1.age = 5;
    l1.weight = 200;
    l1.name = "Simba";
    l1.eat();
    l1.sleep();
    l1.mammalAge = 5;
    l1.mammalWeight = 200;
    l1.walk();
}


//Hierarchical Inheritance
class Animal{
    public:
    int age;
    int weight;
    string name;

    void eat(){
        cout<<"Animal Eating "<<endl;
    }

    void sleep(){
        cout<<"Animal Sleeping "<<endl;
    }
};
class Lion : public Animal{

};
class Tiger : public Animal{

};

int main(){
    Lion l1;
    l1.age = 5;
    l1.weight = 200;
    l1.name = "Simba";
    l1.eat();
    l1.sleep();

    Tiger t1;
    t1.age = 4;
    t1.weight = 150;
    t1.name = "Shere Khan";
    t1.eat();
    t1.sleep();
}

//Hybrid Inheritance
//It is a combination of two or more types of inheritance
class Animal{
    public:
    int age;
    int weight;
    string name;

    void eat(){
        cout<<"Animal Eating "<<endl;
    }

    void sleep(){
        cout<<"Animal Sleeping "<<endl;
    }
};
class Mammal : public Animal{
    public:
    int mammalAge;
    int mammalWeight;
    string name;

    void walk(){
        cout<<"Mammal Walking "<<endl;
    }
};

class Lion : public Animal{

};

class bigLion : public Lion{

};

class superLion : public bigLion{

};

int main(){
    superLion l1;
    l1.age = 5;
    l1.weight = 200;
    l1.name = "Simba";
    l1.eat();
    l1.sleep();
    l1.mammalAge = 5;
    l1.mammalWeight = 200;
    l1.walk();
}



//Polymorphism
//Compile time polymorphism
//Run time polymorphism

//Compile time polymorphism
//Function overloading
//Operator overloading


//Function Overloading
//Multiple functions with the same name but different parameters

class Calculator{
    public:
    int add(int a, int b){
        return a+b;
    }

    int add(int a, int b, int c){
        return a+b+c;
    }

    int add(float a, float b){
        return a+b;
    }
};

int main(){
    Calculator c1;
    cout<<c1.add(2,3)<<endl; //5
    cout<<c1.add(2,3,4)<<endl; //9
    cout<<c1.add(2.5f,3.5f)<<endl; //6
    return 0;
}

//Note : just change the paramenters with the diff data types dont change the return type as it will not work as the compiler will not be able to differentiate between the functions based on the return type

//Operator Overloading
//it means same operator can be used for different purposes by operloading manually

//eg overloading the + operator for performing minus operation


#include<iostream>
using namespace std;

class Calculator{
    public:
    int value ;

    //syntax 
    //returnType operator symbol (parameters){
    //function body
    //}

    void operator + (Calculator& c2){
        int value1 = this->value; //value of c1
        int value2 = c2.value; //value of c2
        cout<<value1 - value2<<endl; //performing minus operation
    }

};

int main(){
    Calculator c1;
    Calculator c2;
    c1.value = 10;
    c2.value = 5;

    c1+c2;


    return 0;
}

//Overloading the + operator for Printing the values of objects
#include<iostream>
using namespace std;

class Animal{
public:

    int age;
    int marks;
    string name;
    int roll;
    
    Animal(){
        
    }
    
    Animal(int age,int marks,string name,int roll){
        this->age = age;
        this->marks = marks;
        this->name = name;
        this->roll = roll;
    }
    

    void operator + (Animal& a){
        cout << this->age << endl;
        cout << this->marks << endl;
        cout << this->name << endl;
        cout << this->roll << endl;
    }

};

int main(){

    Animal a1(15,98,"Sanket",65);

    //Created the demo obj as + is binary operator and it takes two operands
    
    Animal a2;
    
    a1+a2;

    return 0;
}

//Unary operator overloading
//Only one operand is involved in the operation
//Use them before the obj for calling 
//eg --a1 
| Operator | Meaning     |
| -------- | ----------- |
| `++`     | Increment   |
| `--`     | Decrement   |
| `!`      | Logical NOT |
| `~`      | Bitwise NOT |
| `+`      | Unary Plus  |
| `-`      | Unary Minus |
| `*`      | Dereference |
| `&`      | Address Of  |


//Binary operator overloading
| Operator | Meaning        |
| -------- | -------------- |
| `+`      | Addition       |
| `-`      | Subtraction    |
| `*`      | Multiplication |
| `/`      | Division       |
| `%`      | Modulus        |
| `==`     | Equality       |
| `!=`     | Not Equal      |
| `<`      | Less Than      |
| `>`      | Greater Than   |
| `<=`     | Less Equal     |
| `>=`     | Greater Equal  |
| `&&`     | Logical AND    |
| `||`     | Logical OR     |
| `<<`     | Left Shift     |
| `>>`     | Right Shift    |
| `^`      | XOR            |


//Friend Keyword
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class A{
    int x;
    public:
    A(int _x):x(_x){};
    friend class B;
    friend void print(A & a);
    
};

class B{
    public:
    void print(A& a){
        cout<<a.x<<endl;
    }
};

void print(A&a){
    cout<<"From Fuction : "<<endl;
    cout<<a.x<<endl;
}

int main() {
    
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}