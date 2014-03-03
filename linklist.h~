#include <stdio.h>
#include <stdlib.h>
#include <string.h> // string operations
#include <stdint.h> // fixed width integers
#include <assert.h>
#include <sys/stat.h>  // to get the file status
#include <limits.h>
#include <limits>
#include <map>
#include <iostream>
using namespace std;

//Assume id of a link list will not be more than 50 digits (reasonable, you can also tune this )
#define ID_DIGIT_MAX_LIMIT 50   

//though INT_MAX can have at most 10 digits, keep some extra buffer to add delimeters 
#define INT_DIGIT_MAX_LIMIT 15 

//to store the long long value in char array
#define LONG_DIGIT_MAX_LIMIT 22

//structure of node
struct node { 
  int val;
  struct node *next;
};


// To count the list head or list_id
static int head_count=1;

// A map to store the lists
std::map<int, struct node*> head_list;  //list of link list 


/* A function to create new node for link list
     Arguments:
               val: Create a new node with this value.
     Return: 
              New node  
*/
struct node* newNode(int val);





/* Create a new list and put the entry in the map
     Arguments:
               list_count the head key value or list count value
     Return:   
               The created list id.
*/
int create_list(int list_count);




/* Display a particular list
   Argument: 
            list_id: To get the list head pointer 
*/ 
void display_list(int list_id);




/*  Remove a node from the list
    Arguments: 
               list_id: To get the list head pointer
                 value: which need to be deleted
*/
void remove_node(int list_id, int val);




/*
   Add a node with given to the given list 
   Arguments: 
             list_id: To get the list head
               value: To create a new node with this value
*/
void add_node(int list_id, int val);




/*
   Get the size of buffer which requires to copy the content of link list.
   Arguments: 
             head: List pointer
                c: Count number of nodes in link list(needed to add delimeter) 
   return:  The size required to copy the list
*/
long long getSize(struct node *head, int &c);




/*
    A function to delete the entire list 
      Arguments: 
                 list_id: To get the list head pointer
*/
void remove_list(int list_id);




/*
    A function which copy the content of link list into buffer
    Arguments:
              list_id: To get the list head pointer
               buffer: Copy the content of list into given buffer
    Return:
              The size required to copy the buffer.         
*/
int serializeList(int list_id, char *buffer);




/*
   Copy all the lists into file "List.data". 
   Put the delimeter among the nodes of link list 
*/
void serialize();




/*
    A function which walks through all the lists
*/
void walk_lists();




/*
    A function to calculate the size of file and check the file status
    Arguments:
               filename: File name 
    Return:
              The size of file. 
    Assuming that file is residing in the same directory        
*/
long long int fileSize(const char *filename);




/*
    A function to convert char array to numerical value
    Arguments:
               Character pointer
    Return:
               Numerical value calculated from caharacter value
*/
int myAtoi(char *str);




/*
    A function to build the in-memory structure after reading from a file.
    Arguments:
               buffer: It holds the content of a list
                 size: Size of the list 
*/
void constructLists(char *buffer, long long int size);




/*
    A function to deSerialize the file (ie read the file and construct the lists
*/
void deSerialize();




/*
  A function which check whether the list exist or not
  Arguments:
            list_id
  Return:
            1  if list exist
            0  if list doesn't exist 
*/

int check_list(int list_id);

