# Priority queue

This code was created to test the suitability of a row with ordered insertion according to the priorities. This row arming function pointers. The higher priorities have higher value. Being that when we have two insertions with the same priority, the first place will be given to the most resent insertion.

This code has a class class that offers the following methods

The ``insert method`` Receive as a parameter a pointer to a function of type void and that does not receive arguments like that, as well as the priority of the element.
```c
insert(void (*item)(void), const int priority);
```

The ``checkEmpty method``. Check if the list is empty,
```c
checkEmpty(void) const;
```

The ``exe_sequence_loop method``. This method executes in sequence all the functions stored in the list in loop.
```c
exe_sequence_loop() const;
```

The ``exe_sequence method``. This method executes in sequence all the functions stored in the list. The difference with the previous method is that this one only executes the list once.
```c
exe_sequence_loop() const;
```

Verification test

Suppose we have a file and we want to read this file. And perform typical tasks such as read file, delete file and or format output string such as delete spaces from string, capitalize everything, ets.
```c
    Clistafunction a;

    a.insert(uppercase,0);
    a.insert(removeSpaces,1);
    a.insert(deletefile,-1);
    a.insert(statistics,-2);
    a.insert(lowercase,0);
    a.insert(readfile,1);
```
