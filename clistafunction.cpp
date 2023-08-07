#include <iostream>
#include <conio.h>
#include "clistafunction.h"
using namespace std;

Clistafunction::Clistafunction()
{
    start = nullptr;
    end = nullptr;
}

/**
 * @brief
 * Class destroyer. clear memory on exit
 *
 * @param
 * void
 * @return
 * void
 */
Clistafunction::~Clistafunction(void) {
    CNoFila *incoming;

    while (start != nullptr) {
        incoming = start->next;    // next element
        delete start;              // delete element at the beginning of the queue
        start = incoming;          // define new queue head
    }
    end = nullptr;
}

/**
 * @brief
 * sequentially execute list of functions in loop
 * @param
 * void
 * @return
 * void
 */
void Clistafunction::exe_sequence_loop() const{
    if ( start == nullptr )
        cout << "Queue empy..." << endl;
    else {
        CNoFila * aux;
        while(!_kbhit()) // press any key to exit
        {
            aux = start;
            while( aux != nullptr ) {
                aux->data();
                aux = aux->next;
            }
        }
    }
}

/**
 * @brief
 * sequentially execute the list of functions once
 * @param
 * void
 * @return
 * void
 */
void Clistafunction::exe_sequence() const{
    if ( start == nullptr )
        cout << "Queue empy..." << endl;
    else {
        CNoFila * aux;
        aux = start;
        while( aux != nullptr ) {
            aux->data();
            aux = aux->next;
        }
    }
}

/**
 * @brief
 * insert a new element in the list according to its priority.
 * Consider the high value priorities as most relevant.
 * The most recent items will always be found first, also considering their priority
 *
 * @param
 * const int item: is the element to be inserted
 * const int priority: is the priority value. Remembering that the high the more, the higher is the priority
 * @return void
 */
void Clistafunction::insert(void (*item)(), const int priority)
{
    // create element to be placed at the tail of the list
    CNoFila *_new = new CNoFila;
    CNoFila *beforeN = nullptr;
    CNoFila *current;
    CNoFila *N;

    _new->data = item;
    _new->priority = priority;
    _new->next = nullptr;

    // insert new element at the tail of the list
    if( start == nullptr )
    {
        start = _new;
        _new->next = end;
    }
    else
    {
        current= start;

        //Search for the place to insert
        while(current->next != nullptr)
        {
            /*
             * the insertion always has to be before all the other elements with the same priority so
             * that the new elements always appear first.
             */
            if(current->next!= nullptr && current->next->priority<=_new->priority) break;
            current=current->next;
        }

        beforeN = current;

        // general case
        if(beforeN != start)
        {
            //If you have to modify the end of the list
            if(beforeN == end)
            {
                end->next=_new;
                end=_new;
                end->next=nullptr;
            }
            else
            {
                N=beforeN->next;
                beforeN->next=_new;
                _new->next=N;
            }
        }
        // Case if you have to modify the beginning
        else
        {
            _new->next=start;
            start = _new;
        }
    }
}
