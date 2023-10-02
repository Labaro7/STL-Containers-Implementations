# Description
Possible implementations of the STL Containers.

It was made using templates in order to make the containers generic for any C++ or custom types.

The classes throw exceptions that terminate the process that called them when encountering bad conditions.

## Vector
Dynamic array. It is given a certain capacity and when it is full, it allocates two times the current capacity and deallocates the previous one.

Methods:
- empty()
- at
- reallocate_and_push_back
- push_back()
- pop_back()
- front()
- back()
- size()


## Queue
Doubly linked list following a FIFO (First In First Out) order.

Methods:
- empty()
- push()
- pop()
- front()
- back()
- size()

