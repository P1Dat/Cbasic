main: test.o hash.o
	gcc -o a test.o hash.o

test.o: test.c hash.h
	gcc -c test.c

# bst.o: bst.c bst.h
# 	gcc -c bst.c

# llist.o: llist.c llist.h
# 	gcc -c llist.c

hash.o: hash.c hash.h
	gcc -c hash.c