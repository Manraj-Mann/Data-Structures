# Data-Sructures & Algorithms

Data structure is a particular way of storing and
organizing data in a computer so that it can be used efficiently. A data structure is a special
format for organizing and storing data. General data structure types include arrays, files, linked
lists, stacks, queues, trees, graphs and so on.
Depending on the organization of the elements, data structures are classified into two types:

1) Linear data structures: Elements are accessed in a sequential order but it is not
compulsory to store all elements sequentially. Examples: Linked Lists, Stacks and
Queues.

2) Non – linear data structures: Elements of this data structure are stored/accessed in a
non-linear order. Examples: Trees and graphs. 

This repository is contatining all the data structures available in detail as per book DSA made easy.

# Table of Contents

1. [Chapter 1 Introduction]()
2. [Chapter 2 Linked Lists](#linked-lists)
3. [Chapter 3 Stacks](#stacks)
4. [Chpater 4 Queues](#queues)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Linked Lists

A linked list is a data structure used for storing collections of data. A linked list has the following
properties.Successive elements are connected by pointers , last element points to NULL , can grow or shrink in size during execution of a program , can be made just as long as required (until systems memory exhausts) and does not waste memory space (but takes some extra memory for pointers). It
allocates memory as list grows.

- [Singly Linked Lists](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/Singly%20Linked%20List)
- [Doubly Linked Lists](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/Doubly%20Linked%20List)
- [Circular Linked Lists](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/Circular%20LinkedList)                    
- [Xor Linked Lists](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/XOR%20Memory%20Efficient%20LinkedList)
- [Unrolled Linked Lists](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/Unrolled%20Linked%20Lists)
- [Skip Lists](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/Skip%20Lists)

 ![image](https://user-images.githubusercontent.com/81899682/149673271-6fc2b68e-063e-435b-9863-618a44f94641.png)


> [Practise Questions with solutions (Including Interview Questions)](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%203%20Linked%20List/Questions)  


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Stacks

Definition: A stack is an ordered list in which insertion and deletion are done at one end, called
top. The last element inserted is the first one to be deleted. Hence, it is called the Last in First out
(LIFO) or First in Last out (FILO) list.

- [Array Implementation]()
- [Dynamic Array Implementation (Resizable)]()                                                                                           
- [Linked List Implementation]()

![image](https://user-images.githubusercontent.com/81899682/149706453-6b7a47e3-8459-415c-addf-ce2720ac58a5.png)

> [Practise Questions with solutions (Including Interview Questions)](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%204%20Stacks/Questions)  

# Applications

> Following are some of the applications in which stacks play an important role.

Direct applications
- Balancing of symbols
- Infix-to-postfix conversion
- Evaluation of postfix expression
- Implementing function calls (including recursion)
- Finding of spans (finding spans in stock markets, refer to Problems section)
- Page-visited history in a Web browser [Back Buttons]
- Undo sequence in a text editor
- Matching Tags in HTMLand XML

Indirect applications
- Auxiliary data structure for other algorithms (Example: Tree traversal algorithms)
- Component of other data structures (Example: Simulating queues, refer Queues
chapter)


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Queues

A queue is an ordered list in which insertions are done at one end (rear) and
deletions are done at other end (front). The first element to be inserted is the first one to be
deleted. Hence, it is called First in First out (FIFO) or Last in Last out (LILO) list.

- [Simple Array Implementation](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%205%20Queues/simpleArrayImplementation.cpp)
- [Circular Array Implementation](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%205%20Queues/circularArrayImplementation.cpp)

# Applications

> Following are some of the applications that use queues.

Direct Applications

- Operating systems schedule jobs (with equal priority) in the order of arrival (e.g., a
print queue).
- Simulation of real-world queues such as lines at a ticket counter or any other first come first-served scenario requires a queue.
- Multiprogramming.
- Asynchronous data transfer (file IO, pipes, sockets).
- Waiting times of customers at call center.
- Determining number of cashiers to have at a supermarket.

Indirect Applications

- Auxiliary data structure for algorithms
- Component of other data structures

![image](https://user-images.githubusercontent.com/81899682/149732851-d195597c-6713-44d3-98dc-f7f21d8c2517.png)




