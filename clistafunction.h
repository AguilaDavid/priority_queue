#ifndef CLISTAFUNCTION_H
#define CLISTAFUNCTION_H

class Clistafunction;

class CNoFila {
    void (*data)(void);
    int priority;
    CNoFila *next;

    friend class Clistafunction; // allow this class to access private attributes
};

class Clistafunction
{
private:
    CNoFila *start, *end;
public:
    Clistafunction(void);
    ~Clistafunction(void);

    void insert(void (*item)(void), const int priority);
    bool checkEmpty(void) const { return (start == nullptr ); }
    void exe_sequence_loop() const;
    void exe_sequence() const;
};

#endif // CLISTAFUNCTION_H
