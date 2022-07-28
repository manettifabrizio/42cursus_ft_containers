<h1 align="center">
	ft_containers 
</h1>

<p align="center">
	<b><i>CURSUS: 2019 - AUTHOR: fmanetti - GRADE: 100 - FINISHED: 04/11/2021</i></b><br>
</p>

<p align="center">
	The standard C++ containers have all a specific usage. To make sure you understand them, let’s re-implement them!
</p>

![image](https://github.com/manettifabrizio/42cursus_srcs/blob/main/images/ft_containers.gif)

## Introduction

In this project, you will implement the various container types of the C++ standard
template library. For each container, turn in the appropriately named class files. The namespace will always be ft and your containers will be tested using ft::<container>.
You need to respect the structure of the reference container. If it’s missing a part of the orthodox canonical form, do not implement it. As a reminder, we are coding in C++98, so any new feature of the containers MUST NOT be implemented, but every old feature (even deprecated) is expected.

### Disclaimer

At 42 school when we program in C we are subject to a set of rules called [**the norm**](https://github.com/manettifabrizio/42cursus_srcs/blob/main/subjects/norm/en.norme_v2.pdf), so if the code is not 100% optimized this is the reason. This project was coded following norminette v2.

## Implemented Containers Functions

### Vector

- [x] constructor
- [x] destructor
- [x] operators

- Iterators
    - [x] begin
    - [x] end
    - [x] rbegin
    - [x] rend

- Capacity
    - [x] size
    - [x] max_size 
    - [x] resize
    - [x] capacity 
    - [x] empty
    - [x] reserve

- Element access
    - [x] operator[]
    - [x] at
    - [x] front
    - [x] back

- Modifiers
    - [x] assign
    - [x] push_back
    - [x] pop_back
    - [x] insert
    - [x] erase
    - [x] swap
    - [x] clear

- Allocator
    - [x] get_allocator

- Non-member function overloads
    - [x] relational operators
    - [x] swap


### Map

- [x] constructor
- [x] destructor
- [x] operator=

- Iterators
    - [x] begin
    - [x] end
    - [x] rbegin
    - [x] rend

- Capacity
    - [x] empty
    - [x] max_size 
    - [x] size

- Element access
    - [x] operator[]

- Modifiers
    - [x] insert
    - [x] erase
    - [x] swap
    - [x] clear

- Observers
    - [x] key_comp
    - [x] value_comp

- Operations
    - [x] find
    - [x] count
    - [x] lower_bound
    - [x] upper_bound
    - [x] equal_range

- Allocator
    - [x] get_allocator

### Stack

- Member function
    - [x] constructor
    - [x] size
    - [x] empty
    - [x] top
    - [x] push
    - [x] pop

- Non-member function overloads
    - [x] relational operators
    - [x] swap

## Usage

### Requirements

The containers are written in C++ language and thus needs the **`clang++` compiler** and some standard **C++ libraries** to run.

**Using it in your code**

To use the containers in your code, simply include them:

```C++
#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"
```
And use the ft namespace:

```C++
ft::vector<int> myvector;
```

### Tester

I've included a tester for this project that can be used in the following ways:

All containers
```s
./test.sh
```

Specific containers
```
./test.sh <container> <container1>
```

One test
```
./test.sh -o <container> <file>
```

Clean files
```
./test.sh -c
```

## Sources

* [cplusplus.com](https://www.cplusplus.com/)
* [cppreference.com](https://en.cppreference.com/w/)
* [Iterators Traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)
* [std::iterator](https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/)
