/** 
 * file:  driver.c 
 * author:  Michael Mathews 
 * course: CSI 3336 
 * assignment:  homework 6 
 * due date:  2/24/2023 
 * 
 * date modified:  2/24/2023 
 *      - file created 
 * 
 * This document will test the functionality of a linked list. 
 */

#include <stdio.h>
#include "list.h"

int main(){
    List *list = createList();

    push_front(list, 't');
    push_front(list, 'a');
    push_front(list, 'c');

    print(list);
    printReverse(list);

    pop_front(list);
    pop_front(list);

    print(list);

    deleteList(list);

    return 0;
}
