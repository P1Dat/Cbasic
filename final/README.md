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

You can change data types in the struct:
```sh
typedef struct data_s{

    int data;
} data_t;
```
> Note: in `typedef struct data_s` you can add some fields, like: `char StudentofName[11]`
> You need edit `ShowData()` function for new data types
