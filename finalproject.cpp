#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include <map>

using namespace std;

struct Question {
    string question;
    vector<string> options;
    char correctAnswer;
};

struct Quiz {
    string quizName;
    vector<Question> questions;
};

map<string, string> users; // Stores username-password pairs
vector<Quiz> quizzes;

void loadUsers() {
    ifstream file("users.txt");
    string username, password;
    while (file >> username >> password) {
        users[username] = password;
    }
    file.close();
}

void saveUser(const string &username, const string &password) {
    ofstream file("users.txt", ios::app);
    file << username << " " << password << "\n";
    users[username] = password;
    file.close();
}


vector<Quiz> loadQuizzes() {
    vector<Quiz> loadedQuizzes;

    map<string, vector<vector<Question>>> questionBank = {
        {"C++", {
            { // Quiz 1
                {"1. What is C++?", {" A programming language", " A database", " An OS", " A hardware"}, 'A'},
                {"2. Which keyword defines a class in C++?", {" function", " class", " struct", " namespace"}, 'B'},
                {"3. What is the extension of a C++ file?", {".txt", ".cpp", ".java", ".py"}, 'B'},
                {"4. Who developed C++?", {" Dennis Ritchie", " Bjarne Stroustrup", " James Gosling", " Guido van Rossum"}, 'B'},
                {"5. Which of these is not a C++ keyword?", {" new", " delete", " malloc", " class"}, 'C'},
                {"6. What is the output of 'cout << 5 + 10;'?", {" 5", " 10", " 15", " Error"}, 'C'},
                {"7. Which operator is used to allocate memory dynamically?", {" malloc", " alloc", " new", " create"}, 'C'},
                {"8. What is the extension of a C++ source file?", {" .c", " .cpp", " .java", " .py"}, 'B'},
                {"9. Which of these is an access specifier in C++?", {" private", " public", " protected", " All of the above"}, 'D'},
                {"10. What does 'OOP' stand for?", {" Object Oriented Programming", " Online Object Protocol", " Ordered Object Processing", " None of the above"}, 'A'},
                {"11. Which symbol is used for comments in C++?", {" //", " --", " ##", " **"}, 'A'},
                {"12. Which loop runs at least once in C++?", {" for", " while", " do-while", " None"}, 'C'},
                {"13. Which header file is required for input-output operations?", {" <iostream>", " <stdio.h>", " <string>", " <fstream>"}, 'A'},
                {"14. Which of these is used for exception handling?", {" throw", " catch", " try", " All of the above"}, 'D'},
                {"15. Which function is the entry point in a C++ program?", {" start()", " init()", " main()", " execute()"}, 'C'},
                {"16. What is the default return type of main()?", {" void", " int", " float", " char"}, 'B'},
                {"17. Which operator is used to access members of a class?", {" ->", " . (dot)", " :", " /"}, 'B'},
                {"18. Which keyword is used to define a constant in C++?", {" final", " const", " static", " define"}, 'B'},
                {"19. Which of these is a feature of OOP?", {" Encapsulation", " Inheritance", " Polymorphism", " All of the above"}, 'D'},
                {"20. Which function deallocates memory allocated by 'new'?", {" delete", " free", " dealloc", " remove"}, 'A'}
            },
            { // Quiz 2
                {"1. What is a pointer?", {" A reference", " A variable", " A function", " An integer"}, 'A'},
                {"2. Which operator is used for dynamic memory allocation?", {" malloc", " new", " alloc", " dynamic"}, 'B'},
                {"3. Which header file is needed for input-output operations?", {" <stdio.h>", " <iostream>", " <stdlib.h>", " <conio.h>"}, 'B'},
                {"4. What is the size of 'int' on most 64-bit systems?", {" 2 bytes", " 4 bytes", " 8 bytes", " 16 bytes"}, 'B'},
                {"5. What is the purpose of the 'this' pointer?", {" Refers to the current object", " Refers to a global object", " Refers to the previous object", " None of these"}, 'A'},
                {"6. Which of these is not a type of constructor in C++?", {" Default", " Parameterized", " Copy", " Friend"}, 'D'},
                {"7. What is function overloading?", {" Multiple functions with the same name but different parameters", " Defining a function inside another function", " Using a function as an argument", " Calling a function twice"}, 'A'},
                {"8. Which operator cannot be overloaded?", {" +", " =", " . (dot)", " []"}, 'C'},
                {"9. Which of these keywords is used for templates?", {" class", " template", " typename", " Both B and C"}, 'D'},
                {"10. What is a virtual function?", {" A function that is dynamically bound at runtime", " A function that cannot be used", " A function that runs in a separate thread", " A function that always returns void"}, 'A'},
                {"11. Which class can access private members of another class?", {" Inherited class", " Friend class", " Abstract class", " None"}, 'B'},
                {"12. What is the default access specifier for a class member?", {" public", " private", " protected", " static"}, 'B'},
                {"13. What is the difference between struct and class?", {" No difference", " struct has private members by default", " class has private members by default", " struct has methods, class does not"}, 'C'},
                {"14. What is an abstract class?", {" A class with at least one pure virtual function", " A class without a constructor", " A class that cannot be instantiated", " Both A and C"}, 'D'},
                {"15. What is the advantage of using references over pointers?", {" References cannot be NULL", " References require less memory", " References are faster", " All of the above"}, 'D'},
                {"16. How do you declare a pure virtual function?", {" virtual void f() {}", " virtual void f() = 0;", " void f() = 0;", " void f();"}, 'B'},
                {"17. What does the keyword 'mutable' do?", {" Allows modification of a member even in a const object", " Prevents modification", " Converts a variable to constant", " None of the above"}, 'A'},
                {"18. Which STL container does not allow duplicate elements?", {" vector", " map", " multiset", " deque"}, 'B'},
                {"19. Which operator is used to declare a smart pointer?", {" ->", " . (dot)", " &", " *"}, 'D'},
                {"20. Which feature allows multiple functions to have the same name but different implementations?", {" Inheritance", " Encapsulation", " Polymorphism", " Virtualization"}, 'C'}
            },
            { // Quiz 3
                {"1. Which concept allows function overloading?", {" Polymorphism", " Encapsulation", " Inheritance", " Abstraction"}, 'A'},
                {"2. What is 'cin' used for?", {" Output", " Input", " File handling", " Memory allocation"}, 'B'},
                {"3. Which keyword is used for a constant variable?", {" final", " static", " const", " define"}, 'C'},
                {"4. Which of the following statements about move semantics is true?",{" Move constructors prevent unnecessary copies"," Move constructors always copy objects"," Move semantics use deep copies"," Move semantics are identical to copy semantics"}, 'A'},
                {"5. What is the main purpose of the 'explicit' keyword in C++?",{" Prevents implicit type conversion"," Forces inline expansion"," Declares a variable as a constant"," Enables multithreading"}, 'A'},
                {"6. Which C++11 feature is used to ensure a class cannot be copied?",{" delete keyword", " static keyword", " constexpr keyword", " volatile keyword"}, 'A'},
                {"7. What is the output of the following code? \n\n"
                 "int x = 5;\n"
                 "auto lambda = [x]() mutable { x++; return x; };\n"
                 "cout << lambda() << endl;",{" 5", " 6", " Compilation error", " Undefined behavior"}, 'B'},
                {"8. Which type of inheritance can cause the ‘diamond problem’ in C++?",{" Single", " Multiple", " Multilevel", " Hybrid"}, 'B'},
                {"9. What is the advantage of emplace_back() over push_back() in vectors?",{" Constructs objects directly in-place"," Faster than push_back()"," Uses deep copy internally"," Reduces memory consumption"}, 'A'},
                {"10. Which of these is NOT a valid C++11 memory management feature?",{" std::unique_ptr", " std::shared_ptr", " std::weak_ptr", " std::garbage_collector"}, 'D'},
                {"11. Which exception will be thrown if ‘new’ fails to allocate memory?",{" std::bad_alloc", " std::overflow_error", " std::runtime_error", " std::invalid_argument"}, 'A'},
                {"12. Which of the following is the correct syntax to prevent object slicing?",{" Declare a virtual destructor"," Use the final keyword"," Declare a pure virtual function"," All of the above"}, 'D'},
                {"13. Which of these operators cannot be overloaded?",{" []", " ->", " ?: (ternary)", " ()"}, 'C'},
                {"14. Which of the following is true about ‘volatile’ keyword?",{" Prevents compiler optimizations"," Ensures atomic operations"," Used to declare static variables"," Improves execution speed"}, 'A'},
                {"15. Which of the following is NOT a valid way to prevent memory leaks?",{" Use smart pointers", " Use manual delete calls", " Implement RAII", " Use garbage collection"}, 'D'},
                {"16. Which standard library feature allows iteration over a container with range-based for loops?",{" begin() and end()", " rbegin() and rend()", " cbegin() and cend()", " front() and back()"}, 'A'},
                {"17. What will the following C++ code output? \n\n"
                 "struct Base { virtual void show() { cout << 'Base'; } };\n"
                 "struct Derived : Base { void show() override { cout << 'Derived'; } };\n"
                 "Base* obj = new Derived();\n"
                 "obj->show();",{" Base", " Derived", " Compilation Error", "Runtime Error"}, 'B'},
                {"18. Which type of polymorphism allows method calls to be determined at runtime?",{" Static", " Compile-time", " Runtime (dynamic)", " Function overloading"}, 'C'},
                {"19. Which of these statements is false regarding RAII (Resource Acquisition Is Initialization)?",{" It ensures proper resource management"," It eliminates the need for manual delete calls"," It is only applicable to memory management"," It relies on destructors to release resources"}, 'C'},
                {"20. Which of the following is an example of perfect forwarding in C++?",{" Using std::forward()"," Using std::move()"," Using copy constructors", " Using explicit constructors"}, 'A'}
            }
        }},
        {"Java", {
            { // Quiz 1 - Basics of Java
                {"1. What is Java?", {" A database", " A programming language", " An operating system", " A web browser"}, 'B'},
                {"2. Who developed Java?", {" Dennis Ritchie", " Bjarne Stroustrup", " James Gosling", " Guido van Rossum"}, 'C'},
                {"3. What is the extension of a Java source file?", {".java", ".class", ".cpp", ".py"}, 'A'},
                {"4. Which keyword is used to define a class in Java?", {" struct", " class", " function", " define"}, 'B'},
                {"5. Which of these is not a Java keyword?", {" new", " delete", " final", " static"}, 'B'},
                {"6. What is the default value of an uninitialized int variable in Java?", {" 0", " null", " garbage value", " None"}, 'A'},
                {"7. What is the output of 'System.out.println(5 + 10);'?", {" 5", " 10", " 15", " Error"}, 'C'},
                {"8. Which keyword is used to create an object in Java?", {" new", " malloc", " alloc", " create"}, 'A'},
                {"9. Which of these is a valid method declaration in Java?", {" int method();", " method int();", " void method[];", " declare method();"}, 'A'},
                {"10. What does JVM stand for?", {" Java Virtual Machine", " Java Variable Manager", " Java Version Method", " None of the above"}, 'A'},
                {"11. What is the correct way to start a single-line comment in Java?", {" //", " --", " ##", " **"}, 'A'},
                {"12. Which of these loops runs at least once?", {" for", " while", " do-while", " None"}, 'C'},
                {"13. Which access specifier allows access within the same package?", {" public", " private", " protected", " default"}, 'D'},
                {"14. What is the base class of all Java classes?", {" Object", " Main", " Base", " Parent"}, 'A'},
                {"15. What is the output of 'System.out.println(10/3);'?", {" 3.33", " 3", " 3.0", " Error"}, 'B'},
                {"16. Which of these is not a primitive data type in Java?", {" int", " float", " string", " char"}, 'C'},
                {"17. What does 'final' keyword do in Java?", {" Prevents method overriding", " Prevents variable modification", " Prevents class inheritance", " All of the above"}, 'D'},
                {"18. How do you take user input in Java?", {" Scanner", " InputReader", " System.in.read()", " cin>>"}, 'A'},
                {"19. Which method is called when an object is destroyed?", {" finalize()", " destructor()", " end()", " delete()"}, 'A'},
                {"20. Which package is imported by default in every Java program?", {" java.lang", " java.util", " java.io", " java.net"}, 'A'}
            },
            { // Quiz 2 - Intermediate Java
                {"1. What is method overloading?", {" Multiple methods with same name but different parameters", " Defining a method inside another method", " Using a method as an argument", " Calling a method twice"}, 'A'},
                {"2. What is the default access specifier of a class?", {" private", " protected", " public", " default"}, 'D'},
                {"3. Which data structure does a HashMap use internally?", {" Array", " LinkedList", " HashTable", " Tree"}, 'C'},
                {"4. What is the purpose of the 'this' keyword?", {" Refers to the current object", " Refers to a global object", " Refers to the previous object", " None of these"}, 'A'},
                {"5. Which class is the superclass for all exceptions?", {" Throwable", " Exception", " RuntimeException", " Error"}, 'A'},
                {"6. What is the output of 'Math.round(2.6)'?", {" 2", " 3", " 2.6", " Error"}, 'B'},
                {"7. What is a constructor in Java?", {" A method that initializes an object", " A method that destroys an object", " A static method", " A method that returns an object"}, 'A'},
                {"8. Which keyword is used to inherit a class?", {" implements", " extends", " inherits", " super"}, 'B'},
                {"9. Which Java collection allows storing unique elements in sorted order?", {" ArrayList", " HashSet", " TreeSet", " LinkedList"}, 'C'},
                {"10. Which of these statements is true about abstract classes?", {" They cannot have constructors", " They cannot have abstract methods", " They can have both abstract and non-abstract methods", " They cannot be inherited"}, 'C'},
                {"11. What does the 'super' keyword do?", {" Calls the parent class constructor", " Calls the child class constructor", " Creates a new object", " None of the above"}, 'A'},
                {"12. Which of these methods is used to check if a string contains another string?", {" contains()", " find()", " includes()", " match()"}, 'A'},
                {"13. What will happen if we call 'main()' method inside itself?", {" Infinite recursion", " Compilation error", " Runtime error", " Nothing happens"}, 'A'},
                {"14. Which interface is used for handling threads in Java?", {" Threadable", " Runnable", " Multithread", " Process"}, 'B'},
                {"15. What is the default value of a boolean variable?", {" true", " false", " null", " 0"}, 'B'},
                {"16. What is the use of the 'instanceof' keyword?", {" Checks if an object belongs to a class", " Declares an instance variable", " Creates a new object", " None of these"}, 'A'},
                {"17. What is the return type of the hashCode() method?", {" int", " float", " String", " Object"}, 'A'},
                {"18. Which of the following is not an OOP principle?", {" Encapsulation", " Inheritance", " Polymorphism", " Compilation"}, 'D'},
                {"19. What does 'static' keyword do?", {" Makes a variable constant", " Makes a method belong to the class instead of an object", " Prevents method overriding", " Creates a new instance"}, 'B'},
                {"20. What is the purpose of 'finally' block?", {" It executes after 'try' and 'catch' blocks", " It is used to catch exceptions", " It is used to throw exceptions", " It is optional and does nothing"}, 'A'}
            },
            { // Quiz 3 - Advanced Java
                {"1. Which Java memory area stores objects created using 'new'?", {" Stack", " Heap", " Method Area", " Registers"}, 'B'},
                {"2. What does the 'volatile' keyword ensure?", {" Method synchronization", " Variable visibility across threads", " Prevents deadlocks", " Makes a variable constant"}, 'B'},
                {"3. Which thread state occurs when a thread is waiting for a monitor lock?", {" BLOCKED", " WAITING", " TIMED_WAITING", " RUNNABLE"}, 'A'},
                {"4. What is the primary difference between 'wait()' and 'sleep()'?", {" wait() releases the lock, sleep() doesn’t", " sleep() releases the lock, wait() doesn’t", " Both release locks", " Both do not release locks"}, 'A'},
                {"5. What is the function of the 'ForkJoinPool' in Java?", {" Manages multithreading efficiently", " Divides tasks recursively for parallel processing", " Handles database transactions", " Manages memory"}, 'B'},
                {"6. Which of these is an immutable class in Java?", {" String", " StringBuilder", " HashMap", " ArrayList"}, 'A'},
                {"7. What does 'CompletableFuture' provide in Java?", {" Asynchronous computation", " Synchronous execution", " Reflection capabilities", " Garbage collection optimization"}, 'A'},
                {"8. Which feature was introduced in Java 8 for functional programming?", {" Streams", " Generics", " Synchronization", " Reflection"}, 'A'},
                {"9. What is the output of 'System.out.println(10 == 10.0);'?", {" true", " false", " Compilation error", " Runtime error"}, 'A'},
                {"10. How do you prevent object creation from a class?", {" Declare the class final", " Make the constructor private", " Use synchronized keyword", " Implement an interface"}, 'B'},
                {"11. Which design pattern is used in 'java.util.Observer'?", {" Singleton", " Factory", " Observer", " Adapter"}, 'C'},
                {"12. Which functional interface does 'forEach()' use in Java Streams?", {" Runnable", " Consumer", " Supplier", " Function"}, 'B'},
                {"13. How can we create a thread in Java?", {" Implement Runnable", " Extend Thread", " Use ExecutorService", " All of the above"}, 'D'},
                {"14. What is the return type of 'map()' in Java Streams?", {" Stream<T>", " List<T>", " void", " Collection<T>"}, 'A'},
                {"15. What does the 'Optional' class in Java help with?", {" Avoiding NullPointerException", " Performance optimization", " Memory management", " Type safety"}, 'A'},
                {"16. What is the difference between HashMap and ConcurrentHashMap?", {" ConcurrentHashMap allows thread-safe operations", " HashMap is faster", " HashMap uses synchronization", " Both are thread-safe"}, 'A'},
                {"17. What does 'javac' command do?", {" Runs Java programs", " Compiles Java source code", " Starts JVM", " Debugs code"}, 'B'},
                {"18. What is the difference between deep copy and shallow copy?", {" Deep copy clones all objects", " Shallow copy copies references", " Both A & B", " None"}, 'C'},
                {"19. What is a memory leak in Java?", {" Unused objects are not garbage collected", " Excessive recursion", " Too many synchronized threads", " Use of final variables"}, 'A'},
                {"20. Which of these is a thread-safe collection?", {" ArrayList", " HashMap", " CopyOnWriteArrayList", " LinkedList"}, 'C'}
            }
        }},
        {"Python", {
            { // **Python Quiz 1 (Basic)**
                {"1. What is Python?", {" A snake", " A programming language", " A database", " A hardware"}, 'B'},
                {"2. Which keyword is used to define a function in Python?", {" function", " def", " class", " lambda"}, 'B'},
                {"3. What is the extension of a Python file?", {".txt", ".cpp", ".java", ".py"}, 'D'},
                {"4. Who developed Python?", {" Dennis Ritchie", " Bjarne Stroustrup", " James Gosling", " Guido van Rossum"}, 'D'},
                {"5. Which of these is a valid Python variable name?", {" 2var", " _var", " var-name", " class"}, 'B'},
                {"6. What is the output of 'print(5 + 10)'?", {" 5", " 10", " 15", " Error"}, 'C'},
                {"7. Which function is used to get user input in Python?", {" scanf()", " gets()", " input()", " cin"}, 'C'},
                {"8. Which of these is a valid way to comment in Python?", {" //", " --", " #", " **"}, 'C'},
                {"9. Which data type is used to store multiple values in one variable?", {" list", " int", " float", " bool"}, 'A'},
                {"10. What will 'print(type(3.14))' output?", {" int", " float", " double", " string"}, 'B'},
                {"11. What is the result of '10 // 3'?", {" 3.33", " 3", " 3.0", " 4"}, 'B'},
                {"12. What is the default return type of a function that has no return statement?", {" void", " None", " int", " null"}, 'B'},
                {"13. Which keyword is used for loops in Python?", {" repeat", " for", " loop", " iterate"}, 'B'},
                {"14. What is the output of 'bool([])'?", {" True", " False", " None", " Error"}, 'B'},
                {"15. What is the correct syntax to declare a dictionary?", {" {}", " []", " dict()", " Both A and C"}, 'D'},
                {"16. How do you open a file in read mode?", {" open('file.txt', 'w')", " open('file.txt', 'r')", " open('file.txt', 'a')", " open('file.txt', 'x')"}, 'B'},
                {"17. Which of the following is immutable?", {" list", " dictionary", " set", " tuple"}, 'D'},
                {"18. What is the output of 'print(2 ** 3)'?", {" 5", " 6", " 8", " 9"}, 'C'},
                {"19. Which of these functions converts a string to an integer?", {" str()", " float()", " int()", " chr()"}, 'C'},
                {"20. What is the default value of an uninitialized variable in Python?", {" None", " 0", " Null", " Undefined"}, 'A'}
            },
            { // **Python Quiz 2 (Intermediate)**
                {"1. Which of the following is a valid way to define a function?", {" function myFunc():", " def myFunc():", " define myFunc():", " func myFunc():"}, 'B'},
                {"2. How do you write a lambda function?", {" lambda x: x+2", " lambda(x): x+2", " lambda x { return x+2 }", " def lambda x: x+2"}, 'A'},
                {"3. What is the difference between a list and a tuple?", {" Lists are mutable, tuples are immutable", " Lists store numbers, tuples store strings", " Tuples are always sorted", " No difference"}, 'A'},
                {"4. What does the 'finally' block do in Python exceptions?", {" Runs if an error occurs", " Runs after the 'try' block", " Skips the 'except' block", " Stops execution"}, 'B'},
                {"5. What will 'print(type({}))' output?", {" list", " dict", " set", " tuple"}, 'B'},
                {"6. What is a shallow copy?", {" A reference to the original object", " A deep copy of an object", " Copies only mutable objects", " Copies all nested objects"}, 'A'},
                {"7. How do you open a file in append mode?", {" open('file.txt', 'r')", " open('file.txt', 'a')", " open('file.txt', 'w')", " open('file.txt', 'x')"}, 'B'},
                {"8. What does 'zip()' do in Python?", {" Merges two iterables", " Compresses a file", " Converts a list to a tuple", " None of the above"}, 'A'},
                {"9. Which module is used for regular expressions?", {" re", " regex", " reg", " search"}, 'A'},
                {"10. What does the 'super()' function do?", {" Calls a parent class method", " Calls a child class method", " Declares a superclass", " None of the above"}, 'A'},
                {"11. Which function is used to remove an element from a set?", {" remove()", " pop()", " discard()", " Both A and C"}, 'D'},
                {"12. What is a generator in Python?", {" A function that returns an iterator", " A function that runs only once", " A function that executes instantly", " None of the above"}, 'A'},
                {"13. How do you define a class in Python?", {" class MyClass():", " define MyClass():", " struct MyClass():", " object MyClass():"}, 'A'},
                {"14. What is the purpose of '__init__' in a class?", {" It is a destructor", " It initializes objects", " It is a static method", " It deletes objects"}, 'B'},
                {"15. Which keyword is used to create an abstract class?", {" interface", " abstract", " class", " None of the above"}, 'D'},
                {"16. What does 'enumerate()' do?", {" Returns a tuple", " Adds a counter to an iterable", " Sorts a list", " None of the above"}, 'B'},
                {"17. What is the purpose of 'is' in Python?", {" Compares values", " Compares memory locations", " Assigns values", " Creates a list"}, 'B'},
                {"18. Which of these sorts a list in descending order?", {" sorted(list, reverse=True)", " list.sort(reverse=True)", " list[::-1]", " All of the above"}, 'D'},
                {"19. What is the difference between 'is' and '=='?", {" No difference", " 'is' compares values, '==' compares memory", " 'is' compares memory, '==' compares values", " None of the above"}, 'C'},
                {"20. Which function removes duplicates from a list?", {" set(list)", " list.remove_duplicates()", " unique(list)", " list.clear_duplicates()"}, 'A'}
            },
            { // **Python Quiz 3 (Advanced)**
                {"1. Which decorator is used to define a static method?", {" @staticmethod", " @classmethod", " @property", " @private"}, 'A'},
                {"2. What does 'deepcopy()' do?", {" Copies an object deeply", " Copies an object shallowly", " Copies only mutable parts", " None of the above"}, 'A'},
                {"3. What does 'yield' do in a function?", {" Returns a value", " Stops execution", " Creates a generator", " None of the above"}, 'C'},
                {"4. Which built-in function is used to check if an object is iterable?", {" iter()", " next()", " isinstance()", " hasattr()"}, 'A'},
                {"5. How do you declare a metaclass?", {" class Meta(type):", " def MetaClass():", " struct Meta():", " class Meta():"}, 'A'},
                {"6. What does '__call__' do?", {" Calls an object", " Creates an instance", " Calls a function", " None of the above"}, 'A'},
                {"7. What is monkey patching?", {" Modifying code at runtime", " Overwriting a class", " Debugging", " None of the above"}, 'A'},
                {"8. Which function in NumPy creates an array?", {" np.array()", " np.create()", " np.make()", " np.new()"}, 'A'},
                {"9. How do you serialize an object?", {" pickle.dump()", " json.dump()", " Both A and B", " None of the above"}, 'C'},
                {"10. What will be the output of the following code? \n\n"
                    "def func(lst=[]):\n"
                    "    lst.append(1)\n"
                    "    return lst\n"
                    "print(func())\n"
                    "print(func())",{" [1]", " [1, 1]", " [1] [1]", " [1, 1] [1, 1]"}, 'B'},
                {"11. What does the 'nonlocal' keyword do in Python?",{" Declares a global variable", " Declares a local variable", " Allows modification of a variable in an enclosing function", " Defines a constant"}, 'C'},
                {"12. Which of the following statements about Python generators is true?",{" Generators store all values in memory", " Generators use 'yield' instead of 'return'", " Generators cannot be iterated more than once", " Generators execute immediately"}, 'B'},
                {"13. What will be the output of the following code? \n\n"
                    "def f():\n"
                    "    return lambda x: x * 2\n"
                    "g = f()\n"
                    "print(g(5))",{" 10", " 5", " None", " Error"}, 'A'},
                {"14. What will be the output of the following code? \n\n"
                    "class A:\n"
                    "    def __init__(self):\n"
                    "        print('A')\n"
                    "class B(A):\n"
                    "    def __init__(self):\n"
                    "        print('B')\n"
                    "        super().__init__()\n"
                    "B()",{" A B", " B A", " A", " B"}, 'B'},
                {"15. Which of the following is true about Python's memory management?",{" Uses manual garbage collection", " Uses reference counting and a garbage collector", " Uses stack allocation only", " Does not support memory management"}, 'B'},
                {"16. What is the correct syntax for defining a metaclass in Python?",{" class Meta(type): pass", " class Meta(metaclass=type): pass", " class Meta(): pass", " class Meta(object): pass"}, 'A'},
                {"17. What will be the output of the following code? \n\n"
                    "def test():\n"
                    "    try:\n"
                    "        return 1\n"
                    "    finally:\n"
                    "        return 2\n"
                    "print(test())",{" 1", " 2", " None", " Error"}, 'B'},
                {"18. What does 'GIL' stand for in Python?",{" Global Integer Lock", " Global Interpreter Lock", " General Iteration Loop", " General Inheritance Library"}, 'B'},
                {"19. What does the 'inspect' module in Python allow you to do?",{" Modify bytecode", " Analyze code structure at runtime", " Manage virtual environments", " Optimize memory usage"}, 'B'},
                {"20. What will be the output of the following code? \n\n"
                    "from collections import Counter\n"
                    "c = Counter('aaabbc')\n"
                    "print(c.most_common(1))",{" [('a', 3)]", " [('b', 2)]", " [('a', 3), ('b', 2)]", " [('c', 1)]"}, 'A'}
            }
        }},
        {"MERN", {
            { // Quiz 1 - MERN Stack Basics
                {"1. What does MERN stand for?", {" MongoDB, Express, React, Node", " MySQL, Express, Redux, Node", " MongoDB, Ember, React, Node", " MongoDB, Express, React, NestJS"}, 'A'},
                {"2. What type of database is MongoDB?", {" Relational", " NoSQL", " Graph-based", " Key-Value Store"}, 'B'},
                {"3. Which command is used to install Express.js?", {" npm install express", " node install express", " install express.js", " npm add express"}, 'A'},
                {"4. Which of these is used to handle routes in Express.js?", {" Router", " Path", " Redirect", " Handler"}, 'A'},
                {"5. What is the purpose of React in the MERN stack?", {" Backend framework", " Frontend UI library", " Database management", " Server-side scripting"}, 'B'},
                {"6. Which hook is used for state management in React?", {" useState", " useEffect", " useContext", " useRef"}, 'A'},
                {"7. Which function in Express is used to handle HTTP requests?", {" app.listen()", " app.use()", " app.get()", " app.route()"}, 'C'},
                {"8. Which package is used to connect MongoDB with Node.js?", {" mongoose", " mongo-client", " mongodb", " mongoDB-connect"}, 'A'},
                {"9. What is the purpose of the virtual DOM in React?", {" Improves performance", " Provides backend logic", " Replaces Redux", " Stores real-time data"}, 'A'},
                {"10. Which of these is a valid state management solution in React?", {" Redux", " useState", " Context API", " All of the above"}, 'D'},
                {"11. How do you start a Node.js server?", {" node server.js", " start node", " run node", " node -server"}, 'A'},
                {"12. Which method is used to send a JSON response in Express?", {" res.send()", " res.json()", " res.write()", " res.end()"}, 'B'},
                {"13. What does JSX stand for in React?", {" JavaScript XML", " JSON Express", " JavaScript Express", " Java Syntax Extension"}, 'A'},
                {"14. Which of the following is a correct way to define a functional component in React?", {" function MyComponent() {}", " const MyComponent = () => {}", " class MyComponent extends React.Component {}", " Both A & B"}, 'D'},
                {"15. How do you pass data from a parent component to a child component in React?", {" Props", " Redux", " State", " Context API"}, 'A'},
                {"16. Which command is used to install dependencies listed in package.json?", {" npm install", " npm run install", " node install", " npm init"}, 'A'},
                {"17. What is the default port for a React development server?", {" 5000", " 3000", " 8000", " 8080"}, 'B'},
                {"18. How do you define a route parameter in Express?", {" /user/:id", " /user{id}", " /user?id", " /user&{id}"}, 'A'},
                {"19. Which HTTP method is used to update an existing resource?", {" GET", " POST", " PUT", " DELETE"}, 'C'},
                {"20. Which of these middleware functions is used for handling JSON requests in Express?", {" body-parser", " json-parser", " express.json()", " All of the above"}, 'C'}
            },
            { // Quiz 2 - Intermediate MERN
                {"1. What is the primary purpose of Mongoose in a MERN stack application?", {" To manage React state", " To simplify MongoDB interactions", " To handle Express routing", " To secure Node.js API"}, 'B'},
                {"2. How do you define a schema in Mongoose?", {" new Schema()", " new Model()", " new Document()", " new Collection()"}, 'A'},
                {"3. What is the purpose of `useEffect` in React?", {" Handle component rendering", " Handle side effects", " Manage global state", " Control event listeners"}, 'B'},
                {"4. Which method is used to fetch data from an API in React?", {" axios.get()", " fetch()", " useFetch()", " Both A & B"}, 'D'},
                {"5. What is the difference between `useState` and `useReducer`?", {" useReducer is for complex state logic", " useState is for local state only", " useReducer cannot update state", " Both A & B"}, 'D'},
                {"6. Which middleware function is used for handling JSON requests in Express?", {" express.json()", " body-parser.json()", " json-parser()", " Both A & B"}, 'D'},
                {"7. What is the purpose of `useMemo` in React?", {" To optimize performance", " To update the state", " To replace useState", " To define component props"}, 'A'},
                {"8. How do you create a protected route in React?", {" Using Redux", " Using React Router and authentication logic", " Using useState", " Using Express"}, 'B'},
                {"9. Which of the following is NOT a valid lifecycle method in a React class component?", {" componentDidMount", " componentWillUnmount", " useEffect", " componentDidUpdate"}, 'C'},
                {"10. What is `JWT` used for in MERN applications?", {" Frontend state management", " Backend logging", " User authentication", " API caching"}, 'C'},
                {"11. Which method is used to hash passwords in Node.js?", {" bcrypt.hash()", " hashPassword()", " encryptPassword()", " crypto.hash()"}, 'A'},
                {"12. What is the correct way to handle errors in Express middleware?", {" app.use((err, req, res, next) => {...})", " app.get(err, req, res, next) {...}", " handleError(err, req, res, next)", " throw new Error()"}, 'A'},
                {"13. What is the purpose of Redux in a React application?", {" Manages component lifecycle", " Handles backend API calls", " Manages global state", " Optimizes performance"}, 'C'},
                {"14. How do you create a virtual field in Mongoose?", {" Using `virtual` in schema", " Using `pre-save` hook", " Using a separate collection", " Not possible in Mongoose"}, 'A'},
                {"15. What is the role of `next()` in Express middleware?", {" Terminates the request", " Passes control to the next middleware", " Redirects to a new route", " Ends the server"}, 'B'},
                {"16. What is the difference between `sessionStorage` and `localStorage`?", {" sessionStorage persists even after closing browser", " localStorage is only available during session", " localStorage persists beyond session", " Both A & B"}, 'C'},
                {"17. What does `ObjectId` represent in MongoDB?", {" A unique ID for each document", " The ID of a collection", " A schema type", " A primary key in SQL"}, 'A'},
                {"18. How do you optimize performance in a React application?", {" Using React.memo", " Avoiding unnecessary re-renders", " Using useCallback and useMemo", " All of the above"}, 'D'},
                {"19. What is the purpose of `CORS` in Express?", {" Blocks frontend requests", " Allows cross-origin requests", " Prevents database access", " Encrypts API responses"}, 'B'},
                {"20. Which tool is commonly used for debugging Express applications?", {" React DevTools", " Mongoose Debugger", " Morgan", " Redux DevTools"}, 'C'}
            },
            { // Quiz 3 - Advanced MERN
                {"1. What is server-side rendering (SSR) in React?", {" Rendering components in the browser", " Rendering components on the server before sending them to the client", " Pre-fetching API calls", " Using React Hooks for rendering"}, 'B'},
                {"2. Which React framework is best for SSR?", {" Create React App", " Next.js", " Redux", " Express.js"}, 'B'},
                {"3. How can you improve MongoDB query performance?", {" Using indexes", " Using embedded documents", " Avoiding unnecessary fields", " All of the above"}, 'D'},
                {"4. What is the purpose of `lazy()` in React?", {" Code splitting and lazy loading", " Fetching data from an API", " Managing state in Redux", " Optimizing database queries"}, 'A'},
                {"5. How do you handle race conditions in async operations?", {" Using async/await", " Using Promises", " Using mutex locks", " All of the above"}, 'D'},
                {"6. What is the difference between `cluster` and `worker_threads` in Node.js?", {" Cluster runs multiple instances, worker_threads runs threads inside a process", " Cluster is synchronous, worker_threads is async", " Worker_threads are faster than clusters", " Cluster only works on Windows"}, 'A'},
                {"7. What is the purpose of `debouncing` in React?", {" Improves API call efficiency", " Reduces unnecessary renders", " Optimizes input handling", " All of the above"}, 'D'},
                {"8. How does WebSocket differ from HTTP?", {" WebSocket is persistent, HTTP is stateless", " WebSocket only works on localhost", " HTTP is faster than WebSocket", " Both are identical"}, 'A'},
                {"9. How can you prevent NoSQL injection in MongoDB?", {" Using parameterized queries", " Using Mongoose validation", " Sanitizing user input", " All of the above"}, 'D'},
                {"10. What is `helmet` used for in Express.js?", {" Secure HTTP headers", " Authentication", " Database security", " Logging"}, 'A'},
                {"11. What is the purpose of `next.config.js` in Next.js?", {" Customizing the Next.js build process", " Managing React state", " Configuring MongoDB", " Defining Express routes"}, 'A'},
                {"12. What is the purpose of `getServerSideProps` in Next.js?",{" Fetch data at build time"," Fetch data on each request for SSR"," Fetch data only on the client side"," Handle global state in Redux"},'B'},  
                {"13. What is the purpose of `React Profiler`?", {" Debugging Express API", " Measuring component rendering performance", " Managing Redux state", " Handling MongoDB queries"}, 'B'},
                {"14. How can you handle authentication in a MERN application?", {" JWT tokens", " OAuth", " Sessions & Cookies", " All of the above"}, 'D'},
                {"15. Which database scaling technique improves MongoDB read performance?", {" Replication", " Sharding", " Indexing", " All of the above"}, 'D'},
                {"16. What is the advantage of `Service Workers` in a MERN app?", {" Improves offline capabilities", " Enhances security", " Reduces API calls", " All of the above"}, 'D'},
                {"17. Which package is used for GraphQL API development in a MERN stack?", {" express-graphql", " mongoose", " next-auth", " redux-graphql"}, 'A'},
                {"18. How do you prevent memory leaks in a Node.js server?", {" Using event listeners correctly", " Avoiding global variables", " Managing database connections properly", " All of the above"}, 'D'},
                {"19. What is the primary advantage of using Redis in a MERN application?", {" Faster data retrieval", " Secure authentication", " Improved component reusability", " Managing frontend caching"}, 'A'},
                {"20. What is the purpose of `useTransition` in React 18?", {" Improves performance for UI state updates", " Handles routing in Next.js", " Fetches data from MongoDB", " Optimizes Express middleware"}, 'A'}
            }
        }} 
    };

    for (const auto &subject : questionBank) {
        for (int i = 0; i < 3; i++) { // Creating Quiz 1, 2, 3 for each subject
            Quiz quiz;
            quiz.quizName = subject.first + " Quiz " + to_string(i + 1);
            quiz.questions = subject.second[i];  // Assign different sets of questions
            loadedQuizzes.push_back(quiz);
        }
    }

    return loadedQuizzes;
}

// Get today's date as a string
string getTodayDate() {
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm *ltm = localtime(&now);
    stringstream dateStream;
    dateStream << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday;
    return dateStream.str();
}

// Get current time as a string (HH:MM:SS)
string getCurrentTime() {
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm *ltm = localtime(&now);
    stringstream timeStream;
    timeStream << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    return timeStream.str();
}

// Count previous attempts for a specific quiz by a user
int getAttemptCount(const string &username, const string &quizName) {
    ifstream file("leaderboard.txt");
    string line, user, quiz, date;
    int attempt, score, count = 0;

    while (file >> user >> quiz >> date >> attempt >> score) {
        if (user == username && quiz == quizName) {
            count = attempt; // Keep track of last attempt number
        }
    }
    file.close();
    return count + 1; // Next attempt number
}

void playQuiz(const Quiz &quiz, const string &username) {
    int score = 0;
    cout << "\nStarting quiz: " << quiz.quizName << "\n";
    for (const auto &q : quiz.questions) {
        cout << "\n" << q.question << "\n";
        for (int i = 0; i < 4; i++) {
            cout << char('A' + i) << ". " << q.options[i] << "\n";
        }
        
        cout << "Your answer (A/B/C/D): ";
        char answer;
        auto start = chrono::steady_clock::now();
        cin >> answer;
        auto end = chrono::steady_clock::now();
        
        chrono::duration<double> elapsed = end - start;
        if (elapsed.count() > 30.0) {
            cout << "Time's up! Moving to the next question.\n";
            continue;
        }
        
        if (toupper(answer) == q.correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer was " << q.correctAnswer << "\n";
        }
    }
    
    string date = getTodayDate();
    int attemptNumber = getAttemptCount(username, quiz.quizName);

    ofstream leaderboard("leaderboard.txt", ios::app);
    leaderboard << username << " " << quiz.quizName << " " << date << " " << attemptNumber << " " << score << "\n";
    leaderboard.close();
    
    cout << "\nQuiz Over! Your score: " << score << "\n";
}

// Function to display past scores with date & time
void showLeaderboard(const string &username) {
    ifstream file("leaderboard.txt");
    string name, quizName, date;
    int attempt, score;
    bool found = false;

    cout << "\n===== Your Past Quiz Scores =====\n";
    while (file >> name >> quizName >> date >> attempt >> score) {
        if (name == username) {
            cout << quizName << " | Attempt: " << attempt
                 << " | Date: " << date
                 << " | Score: " << score << "\n";
            found = true;
        }
    }
    file.close();

    if (!found) {
        cout << "No past quiz attempts found.\n";
    }
}

void mainMenu();

void userMenu(const string &username) {
    while (true) {
        cout << "\n1. Select Programming Language\n2. View Past Scores\n3. Logout\nChoose an option: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            vector<string> subjects = {"C++", "Java", "Python", "MERN", "C"};
            cout << "Choose a programming language:\n";
            for (size_t i = 0; i < subjects.size(); i++) {
                cout << i + 1 << ". " << subjects[i] << "\n";
            }
            int subjectChoice;
            cin >> subjectChoice;
            
            if (subjectChoice > 0 && subjectChoice <= subjects.size()) {
                string selectedSubject = subjects[subjectChoice - 1];
                cout << "Choose a quiz:\n";
                for (int i = 1; i <= 3; i++) {
                    cout << i << ". " << selectedSubject << " Quiz " << i << "\n";
                }
                int quizChoice;
                cin >> quizChoice;
                
                if (quizChoice > 0 && quizChoice <= 3) {
                    playQuiz(quizzes[(subjectChoice - 1) * 3 + (quizChoice - 1)], username);
                }
            }
        } else if (choice == 2) {
            showLeaderboard(username);
        } else if (choice == 3) {
            cout << "Logging out...\n";
            mainMenu();
            return;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}

void mainMenu() {
    loadUsers();
    quizzes = loadQuizzes();
    
    cout << "\n1. Login\n2. Signup\n3. Exit\nChoose an option: ";
    int choice;
    cin >> choice;
    
    string username, password;
    if (choice == 1) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        if (users.find(username) != users.end() && users[username] == password) {
            cout << "Login Successful!\n";
            userMenu(username);
        } else {
            cout << "Invalid Credentials! Try Again.\n";
            mainMenu();
        }
    } else if (choice == 2) {
        cout << "Choose a Username: ";
        cin >> username;
        cout << "Choose a Password: ";
        cin >> password;
        saveUser(username, password);
        cout << "Signup Successful! You can now log in.\n";
        mainMenu();
    } else if (choice == 3) {
        cout << "Exiting...\n";
        exit(0);
    } else {
        cout << "Invalid choice! Try again.\n";
        mainMenu();
    }
}

int main() {
    mainMenu();
    return 0;
}