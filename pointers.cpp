//to create a pointer
int* ptr;
//point : dont make pointer like this do assign it a zero value or nullptr
int* ptr = nullptr;
//to assign it a address
int a = 5;
ptr = &a; //& is address of operator
//to access the value at the address the pointer is pointing to
cout<<*ptr; //* is dereference operator
//Imp points and outputs
cout<<"Address of a is "<<ptr<<endl;
cout<<"Value at address ptr is "<<*ptr<<endl;
cout<<"Address of pointer ptr is "<<&ptr<<endl;
cout<<"Address of a is "<<&a<<endl;