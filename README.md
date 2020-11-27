# IOOM_Assignment-2

**Assignment on Operator Overloading and Templates**

Every class is having a default constructor, a parameterized constructor, a copy constructor and a destructor.

**Q1.**

Header Files- Student.h, StudentArray.h

.cpp files- Student.cpp, StudentArray.cpp, main1.cpp

Driver file- main1.cpp

**Description**

Student.h- This file contains the definition of class Student,which contains name,branch and roll no as data members and the required member functions.

StudentArray.h-This file contains the definition of class StudentArray, which contains an array of Student pointers of size 5 and some member functions.This acts basically as the database of 5 students.

Student.cpp- This file contains the definitions of the member functions of Student class.

StudentArray.cpp- This file contains the definitions of the member functions of StudentArray class.

main1.cpp- This file demonstrates the creation of db, deletion of db and the use of overloaded operators.

**How to execute?**

Run **make main1** for compiling the files and then run **./main1**

**Or if make dint work** run g++ Student.h 

    then g++ StudentArray.h

    then g++ main1.cpp Student.cpp StudentArray.cpp

    then ./a.out

**Q2.**

Header Files-Polar.h

.cpp files- Polar.cpp, main2.cpp

Driver file- main2.cpp

**Description**

Polar.h- This file contains the definition of class Polar, which contains radius and angle as data members and the required member functions.

Polar.cpp-This file contains the definitions of the member functions of Polar class.

main2.cpp- This file demonstrates the addition of two Polar objects using the overloaded operator.

**How to execute?**

Run **make main2** for compiling the files and then run **./main2**

**Or if make dint work** run g++ Polar.h 

    then g++ main2.cpp Polar.cpp

    then ./a.out

**Q3.**

Header Files- DNode.h, DoublyLinkedList.h

.cpp files- DNode.cpp, DoublyLinkedList.cpp, main3.cpp

Driver file- main3.cpp

**Description**

DNode.h- This file contains the definition of a template class DNode, which represents one node of the DLL, contains data and two pointers as data members.

DoublyLinkedList.h- This file contains the definition of a template class DoublyLinkedList, which contains two DNode pointers and current size as data members and the member functions required to do insertion and deletion operation in the DLL.

DNode.cpp- This file contains the definitions of the member functions of DNode class.

DoublyLinkedList.cpp- This file contains the definitions of the member functions(which throw exceptions) of DoublyLinkedList class.

main3.cpp- This file demonstrates the creation of two DLLs one of decimal(float) datatype and another of string datatype and insertion, deletion operations on them, enclosing them with the try catch blocks.

**How to execute?**

Run **make main3** for compiling the files and then run **./main3**

**Or if make dint work** run g++ DNode.h 

    then g++ DoublyLinkedList.h

    then g++ main3.cpp DNode.cpp DoublyLinkedList.cpp

    then ./a.out

**Q4.**

Header Files- Complex.h

.cpp files- Complex.cpp, main4.cpp

Driver file- main4.cpp

**Description**

Complex.h- This file contains the definition of class Polar, which contains real and imaginary as data members and the required functions. 

Complex.cpp- This file contains the definitions of the member functions(which throw exceptions) of Complex class.

main4.cpp- This file demonstrates the division of two Complex numbers with exception handling. 

**How to execute?**

Run **make main4** for compiling the files and then run **./main4**

**Or if make dint work** run g++ Complex.h 

    then g++ main4.cpp Complex.cpp

    then ./a.out

Lastly run **make clean** to delete the generated files.
