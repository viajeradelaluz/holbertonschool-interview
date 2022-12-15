# Insert in sorted linked list

## Requirements

### General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `lists.h`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Don’t forget to push your header file
- All your header files should be include guarded

## Tasks

### 0. Insert in sorted linked list

**Technical interview preparation:**

- You are not allowed to google anything
- Whiteboard first

Write a function in C that inserts a number into a sorted singly linked list.

- Prototype: `listint_t \*insert_node(listint_t \*\*head, int number);`
- Return: the address of the new node, or `NULL` if it failed

```c
carrie@ubuntu:0x01$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
carrie@ubuntu:0x01$ ./insert
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
carrie@ubuntu:0x01$ 
```

