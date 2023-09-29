/** 
 * file:  fileInfo.c 
 * author:  Michael Mathews 
 * course: CSI 3336 
 * assignment:  project 6 
 * due date:  3/20/2023 
 * 
 * date modified:  3/20/2023 
 *      - file created 
 * 
 * This document will sort file names based on a user's choice by
 * implementing a linked list 
 */

#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char *path;
    struct stat info;
} FileInfo;

typedef struct {
    FileInfo file;
    struct Node *next;
} Node;

typedef struct {
    struct Node *head;
} List;

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
void push_front(List *list, FileInfo fileInfo);

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
void print(List *list);

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
void deleteList(List *list);

/** 
 * sortList  
 *
 * this function sorts a List of valid file names based on a valid user option
 * 
 * Parameters: 
 *      head:  front of linked list
 *      op: user chosen option for sort
 * 
 * Output:    
 *      none  
 *
 */
void sortList(List *list, char op);

int main(int argc, char **argv){
    if(argc <= 1) {
        write(2, "Error: no file given\n", 21);
    } else {
        write(1, "Choose your order:\n", 19);
        write(1, "1. by size\n", 11);
        write(1, "2. by access time\n", 18);
        write(1, "3. by modified time\n", 20);
        write(1, "4. by status change time\n", 25); 
        write(1, ": ", 2);
        
        char ch;
        read(1, &ch, 1);

        //create list
        List *list = createList();
        int i, j;
        for(i = 1; i < argc; i++){
            FileInfo fileInfo;
            if(stat(argv[i], &(fileInfo.info)) != -1){
                fileInfo.path = argv[i];
                push_front(list, fileInfo);
            } else {
                write(2, "Error: file path does not exist\n", 32);
                deleteList(list);
                return 1;
            }
        }

        //sort
        if(ch == '1' || ch == '2' || ch == '3' || ch == '4'){
            sortList(list, ch);
        } else {
            write(2, "Error: invalid choice\n", 22);
            deleteList(list);
            return 1;
        }  
        print(list);
        deleteList(list);
    }
    return 0;
}

List* createList(){
    //allocate memory for list
    List *list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void push_front(List *list, FileInfo fileInfo) {
    if(list == NULL){
        write(2, "List does not exist\n", 20);
    }
    else {
        //add value
        Node *node = malloc(sizeof(Node));
        node->file = fileInfo;
        node->next = list->head;
        list->head = node;
    }
}

void print(List *list) {
    if (list == NULL) {
        write(2, "List does not exist\n", 20);
    } else {
        if (list->head == NULL) {
            write(2, "List is empty\n", 14);
        } else {
            Node *node = list->head;
            //print each node's values
            int count;
            while (node->next != NULL) {
                count = 0;
                while (node->file.path[count] != '\0') {
                    count++;
                }
                count++;
                write(1, node->file.path, count);
                write(1, " ", 1);
                node = node->next;
            }
            count = 0;
            while (node->file.path[count] != '\0') {
                count++;
            }
            write(1, node->file.path, count);
            write(1, "\n", 1);
        }
    }
}

void deleteList(List *list) {
    if(list == NULL){
        write(2, "List does not exist\n", 20);
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

void sortList(List *list, char op) {
    Node *current, *index;
    FileInfo temp;

    for (current = list->head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (op == '1') {
                // sort by file size
                if (current->file.info.st_size > index->file.info.st_size) {
                    temp = current->file;
                    current->file = index->file;
                    index->file = temp;
                }
            } else if (op == '2') {
                // sort by access time (recent first)
                if (current->file.info.st_atime < index->file.info.st_atime) {
                    temp = current->file;
                    current->file = index->file;
                    index->file = temp;
                }
            } else if (op == '3') {
                // sort by modified time (recent first)
                if (current->file.info.st_mtime < index->file.info.st_mtime) {
                    temp = current->file;
                    current->file = index->file;
                    index->file = temp;
                }
            } else if (op == '4') {
                // sort by status change time (recent first)
                if (current->file.info.st_ctime < index->file.info.st_ctime) {
                    temp = current->file;
                    current->file = index->file;
                    index->file = temp;
                }
            } else {
                write(2, "Bad", 3);
            }
        }
    } 
}
