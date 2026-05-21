#include<iostream>
using namespace std;
class Student{

    //Access Modifier
    public:
    //Properties / State
    int roll;
    string name;
    float marks;


    //Behavior / Methods
    void walk(){
        cout<<"Student Walking "<<endl;
    }

    void sleep(){
        cout<<"Student Sleeping "<<endl;
    }
};

int main(){
    //Static Obj Creation
    Student s1;

    //Dynamic Obj Creation
    Student* s2 = new Student();
    
    //To access using static obj
    s1.roll = 10;
    s1.name = "Sanket";
    s1.marks = 78.9;
    s1.sleep();
    s1.walk();
    
    //To access using dynamic obj
    
    //Method 1
    (*s2).roll = 15;
    (*s2).name = "Bhavesh";
    (*s2).marks = 90;
    (*s2).sleep();
    (*s2).walk();
    
    //Method 2
    cout<<s2->roll<<endl;
    cout<<s2->name<<endl;
    cout<<s2->marks<<endl;
    s2->sleep();
    s2->walk();    
    

    return 0;
}



//Using Getter and setter for accessing private data members
#include<iostream>
using namespace std;
class Student{

    //Access Modifier
    private:
    int roll;
    public:
    //Properties / State
    string name;
    float marks;


    //Behavior / Methods
    void walk(){
        cout<<"Student Walking "<<endl;
    }

    void sleep(){
        cout<<"Student Sleeping "<<endl;
    }

    //Getter and setter

    void rollSetter(int roll){
        //usage of this keyword as it is pointer therefore it is traeted as a pointer
        this->roll = roll;
    }

    int rollGetter(){
        return roll;
    }
};

int main(){
    //Static Obj Creation
    Student s1;

    s1.rollSetter(10);

    cout<<s1.rollGetter()<<endl;

    return 0;
}


//Constructors
//Types default,parametrized,copy

#include<iostream>
using namespace std;
class Students{
    public :
    int roll;
    string name;
    float marks;

    //Default Constructor
    Students(){
        roll = 65;
        name = "Sanket";
        marks = 100;
    }

    //Parametrized Constructor 

    //Any one as the parameters matched will run
    Students(int roll){
        this->roll = roll;
        name = "Sanket";
        marks = 95;
    }

    Students(int roll,string name){
        this->roll = roll;
        this->name = name;
        marks = 95;
    }

    Students(int roll,string name,float marks){
        this->roll = roll;
        this->name = name;
        this->marks = marks;
    }

    //copy constructor
    //It called whenever the obj is copied
    //Remeber to pass by address else it will be stuck in infinite loop
    Students(Students& obj){
        this->roll = obj.roll;
        this->name = obj.name;
        this->marks = obj.marks;
    }

    
};

int main(){

    Students s1;
    Students s1(65); //roll will be 65 and rest will be default will call 1st constructor
    Students s1(65,"Sanket");//roll will be 65 and name will be sanket and marks will be default will call 2nd constructor
    Students s1(65,"Sanket",100);//roll will be 65 and name will be sanket and marks will be 100 will call 3rd constructor


    //Two methods to call copy constructor or to copy the obj
    Students s2 = s1; //copy constructor will be called
    Students s2(s1); //copy constructor will be called


    return 0;
};

//Deconstructor
#include<iostream>
using namespace std;
class Students{
    public :
    int roll;
    string name;
    float marks;
    
    //Automatically called when the obj is destroyed
    ~Students(){
        cout<<"Deconstructor called "<<endl;
    }
    
};

int main(){

    //Static Obj Creation
    Students s1;
    //it will automatically call the deconstructor when the obj is destroyed or goes out of scope

    //Dynamic Obj Creation
    Students* s2 = new Students();
    //it will not automatically call the deconstructor when the obj is destroyed or goes out of scope
    //we have to call it manually using delete keyword
    delete s2; //it will call the deconstructor and free the memory allocated for s2
}






