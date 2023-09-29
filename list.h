 /** 
 * file:  list.h 
 * author:  Michael Mathews 
 * course: CSI 3336 
 * assignment:  homework 6 
 * due date:  2/24/2023 
 * 
 * date modified: 2/24/2023 
 *      - file created 
 * 
 * This document will define the functions to be used by a Linked List 
 */

#ifndef LIST_H
#define LIST_H

#include <sys/stat.h>

typedef struct {
    struct List *head;
} List;

typedef struct {  
    char *path;  
    struct stat info; 
} FileInfo;

typedef struct {
    FileInfo file;
    struct Node *next;
} Node;

/** 
 * createList 
 * 
 * creates a list and allocates memory for the list
 * 
 * Parameters:
 *      none 
 * 
 * Output: 
 *      return:  pointer to the created list 
 */ 
List* createList();

/** 
 * push_front 
 *
 * this function adds a value to the front of a linked list 
 * 
 * Parameters: 
 *      head:  front of linked list
 *      data:  character to insert 
 * 
 * Output: 
 *      none
 */ 
void push_front(List *head, FileInfo fileInfo);

/** 
 * pop_front  
 *
 * this function removes a value from the front of a linked list 
 * 
 * Parameters: 
 *      head:  front of linked list
 *      data:  character to insert 
 * 
 * Output:    
 *      none  
 */
void pop_front(List *head);

/** 
 * print  
 *
 * this function prints a linked list forward 
 * 
 * Parameters: 
 *      head:  front of linked list
 * 
 * Output:    
 *      linked list values to stdout  
 */
void print(List *head);

/** 
 * printReverse  
 *
 * this function prints a linked list backward 
 * 
 * Parameters: 
 *      head:  front of linked list
 * 
 * Output:    
 *      linked list values in reverse to the screen  
 */
void printReverse(List *head);

/** 
 * deleteList  
 *
 * this function deletes all values from list and list itself 
 * 
 * Parameters: 
 *      head:  front of linked list
 * 
 * Output:    
 *      none  
 */
void deleteList(List *head);

#endif
