# bankers_algorithm

In this programming assignment, you are required to provide the source codes, documents, and examples in details on github. You only need to submit your github project to me.  

 

Requirements:

You are required to use C/C++ in Linux/Unix. You can consider install virtualBox in your non-Linux environment.
Programs must succeed in compilation and execute as required (80 points)
Readme, documentation and example are required (20 points).
 

Banker’s Algorithm for deadlock avoidance.

 

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:

<img width="468" alt="Project2Details" src="https://user-images.githubusercontent.com/47755334/202937821-66a4ea15-3af6-4617-bde4-b5ec9fb6e58c.png">

Implement the Banker’s algorithm to answer the following question：

        Is the system in a safe state? 
        If Yes, then what is the safe sequence?

 

What should be included in the submission:

        Source codes (C/C++)
        Input file (you should create an input file with your customized format that store the data that is provided in the table).
        Your code should print out the safe sequence if the system is safe.
        Documents and readme.
        
How to Run:

        g++ main.cpp
        ./a.out
