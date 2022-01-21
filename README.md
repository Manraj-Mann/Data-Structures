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
4. [Chapter 4 Queues](#queues)
5. [Chapter 5 Trees](#trees)

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
- [Dynamic Circular Array Implementation](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%205%20Queues/dynamicCircularArrayImplementation.cpp)
- [Linked List Implementation](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%205%20Queues/linkedListImplementation.cpp)
- [Double Ended Queue](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%205%20Queues/double_ended_queue.cpp)
- [Dynamic Circular Double Ended Queue](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%205%20Queues/dynamic_circular_double_ended_queue.cpp)

![image](https://user-images.githubusercontent.com/81899682/149733271-c9348b0f-d96f-44cf-91d2-6a5e34bdfb28.png)

> [Practise Questions with solutions (Including Interview Questions)](https://github.com/Manraj-Mann/Data-Sructures/tree/main/Chapter%205%20Queues/Questions)  


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

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Trees

A tree is a data structure similar to a linked list but instead of each node pointing simply to the next node in a linear fashion, each node points to a number of nodes. Tree is an example of a non-linear data structure. A tree structure is a way of representing the hierarchical nature of a structure in a graphical form.

In trees ADT (Abstract Data Type), the order of the elements is not important. If we need ordering
information, linear data structures like linked lists, stacks, queues, etc. can be used.


![image](https://user-images.githubusercontent.com/81899682/150085325-cbc5c9c4-afa8-4c5e-851f-36691674d481.png)

## 1.Binary Trees
A tree is called binary tree if each node has zero child, one child or two children. Empty tree is also a valid binary tree. We can visualize a binary tree as consisting of a root and two disjoint binary trees, called the left and right subtrees of the root.

- [Structre of binary Trees](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%206%20Trees/binary_trees.cpp)
- [Preorder Traversal](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%206%20Trees/preorder_traversal.cpp)
- [Inorder Traversal](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%206%20Trees/postorder_traversal.cpp)
- [Postorder Traversal](https://github.com/Manraj-Mann/Data-Sructures/blob/main/Chapter%206%20Trees/preorder_traversal.cpp)

> [Practise Questions with solutions (Including Interview Questions)]()  

## Applications of Binary Trees

> Following are the some of the applications where binary trees play an important role:

- Expression trees are used in compilers.
- Huffman coding trees that are used in data compression algorithms.
- Binary Search Tree (BST), which supports search, insertion and deletion on a
collection of items in O(logn) (average).
- Priority Queue (PQ), which supports search and deletion of minimum (or maximum)
on a collection of items in logarithmic time (in worst case).



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
