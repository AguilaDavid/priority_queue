# Priority queue

This code was created to test the suitability of a row with ordered insertion according to the priorities. This row arming function pointers. The higher priorities have higher value. Being that when we have two insertions with the same priority, the first place will be given to the most resent insertion.

This code has a class class that offers the following methods

The ``insert method`` Receive as a parameter a pointer to a function of type void and that does not receive arguments like that, as well as the priority of the element.
```cpp
insert(void (*item)(void), const int priority);
```

The ``checkEmpty method``. Check if the list is empty,
```cpp
checkEmpty(void) const;
```

The ``exe_sequence_loop method``. This method executes in sequence all the functions stored in the list in loop.
```cpp
exe_sequence_loop() const;
```

The ``exe_sequence method``. This method executes in sequence all the functions stored in the list. The difference with the previous method is that this one only executes the list once.
```cpp
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

In this case, when we run the exe_sequence() method, we will wait for the following behavior:

```cpp
Executing: readfile
Executing: lowercase
Executing: removeSpaces
Executing: uppercase
Executing: deletefile
Executing: statistics
```

Using a ``.txt`` file to prove with the name ``note``. Whose content is the string ``Hello world 2023``. We have the following results:

![Captura de Ecrã (2387)](https://github.com/AguilaDavid/priority_queue/assets/125582704/b28cd653-87a0-4da7-b93b-09471c76cfa5)

As expected, we first run the read file function. After getting the whole string, all the characters are passed to lowercase and the spacing is removed. Then the characters are converted to lower case and the resulting string is parsed. As expected all characters are in uppercase and there are no spaces.
