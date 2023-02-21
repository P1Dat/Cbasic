# How to use library
To run the program:
Step 1: translate .c files into .o files with the following command:
```sh
  gcc -c list.c
  gcc -c main.c
```
Step 2: Link the .o files to create a test file
```sh
  gcc -o test llist.o main.o
```

# Link list
You can change data types in the struct:
```sh
typedef struct data_s{

    int data;
} data_t;
```
> Note: in `typedef struct data_s` you can add some fields, like: `char StudentofName[11]`

> You need edit `ShowData()` function for new data types

# Queue and Stack

install by link list

# BST

```sh
typedef int key_t; 

typedef struct data_s{
    
    int key;
} data_t;
```
- You use `key_t` (a data type) to create the tree
- If your key is a string, comparison operators `== > < >= <=` will be replaced by using `strcmp()` fuction and assignment operator will be replaced by using `strcpy()` fuction
- In `typedef struct data_s` you can add some fields, like: `char StudentofName[11]`
