/** 
 * file:  list.c 
 * author:  Michael Mathews 
 * course: CSI 3336 
 * assignment:  homework 6 
 * due date:  2/24/2023 
 * 
 * date modified: 2/24/2023 
 *      - file created 
 * 
 * This document will implement the functions to be used for a Linked List 
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List* createList(){
    //allocate memory for list
    List *list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void push_front(List *list, FileInfo fileInfo) {
    if(list == NULL){
        write(2, "List does not exist", 19);
    }
    else {
        //add value
        Node *node = malloc(sizeof(Node));
        node->fileInfo = data;
        node->next = list->head;
        list->head = node;
    }
}

void pop_front(List *list) {
    if(list == NULL){
        write(2, "List does not exist", 19);
    }
    else {
        //make sure not deleting from empty list
        if (list->head == NULL) {
            write(2, "List is empty\n", 14);
        }
        Node *node = list->head;
        list->head = node->next;
        free(node);
    }
}

void print(List *list) {
    if(list == NULL){
        write(2, "List does not exist", 19);
    }
    else {
        Node *node = list->head;
        //print each node's values
        int count;
        while (node->next != NULL) {
            count = 0;
            while(node->file->path != '\0'){
                count++;
            }
            write(1, node->file.path, count);
            node = node->next;
        }
        count = 0;
        while(node->file->path != '\0'){
            count++;
        }
        write(1, node->file.path, count);
    }
}

void deleteList(List *list) {
    if(list == NULL){
        write(2, "List does not exist", 19);
    }
    else {
        Node *node = list->head;
        Node *next = NULL;
        //delete each node
        while (node != NULL) {
            next = node->next;
            free(node);
            node = next;
        }

        list->head = NULL;
        free(list);
    }
}
