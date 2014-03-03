/* serialize.cpp
 linked list serialization example
*/


#include "linklist.h"

int main (void)
{
  printf("\n*******************************************************\n");
  deSerialize();
  bool run =  true;
  while(run) { 
  int n;
  printf("     LINK LIST SERIALIZATION !!!\n");
  printf("               MENU\n");
  printf("Press 1 to add a new list\n");
  printf("Press 2 to Display a given list\n");
  printf("Press 3 to add a node to any given list\n");
  printf("Press 4 to remove a node from a list\n");
  printf("Press 5 to remove a list\n");
  printf("Press 6 to Exit program\n");
  while(!(cin>>n)) 
  {
    cout << "Incorrect input. Please try again.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  if(!(1<=n && n<=6))
  {
    printf("Incorrect input. Please try again.\n");
    continue;
  }
  int list_id, val;
  switch(n)
  {

    case 1:  
            list_id = create_list(head_count);
            head_count++;
            printf("list %d has created\n",list_id);
            break;
    case 2: 
            list_id;
            printf("Enter the list id to be displayed\n");
            while(!(cin>>list_id)) 
            {
              cout << "Incorrect input. Please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            assert(0<=list_id && list_id<INT_MAX);
            display_list(list_id);
            break;
    
    case 3:
            printf("Enter the list id where you want to add a value\n");
            while(!(cin>>list_id)) 
            {
              cout << "Incorrect input. Please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            assert(0<=list_id && list_id<INT_MAX);
            if(!check_list(list_id))
            { 
              printf("List doesn't exist\n");
              continue;
            }
            printf("Enter the value\n");
            while(!(cin>>val)) 
            {
              cout << "Incorrect input. Please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            assert(INT_MIN<val && val<INT_MAX);        
            add_node(list_id, val);
            break;
   
    case 4: printf("Enter the list id where you want to delete a value\n");
            while(!(cin>>list_id)) 
            {
              cout << "Incorrect input. Please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            assert(0<=list_id && list_id<INT_MAX);
            if(!check_list(list_id))
            { 
              printf("List doesn't exist\n");
              continue;
            }
            printf("Enter the value to be removed from %d list\n", list_id);
            while(!(cin>>val)) 
            {
              cout << "Incorrect input. Please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            assert(INT_MIN<val && val<INT_MAX);        
            remove_node(list_id, val); 
            break;
   
    case 5: printf("Enter the list id which you want to delete\n");
            while(!(cin>>list_id)) 
            {
              cout << "Incorrect input. Please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            assert(0<=list_id && list_id<INT_MAX);
            remove_list(list_id);
            break;
    
    case 6: printf("Program exiting...\n");
            printf("Check List.data in your current directory\n");
            serialize();
            run = false; 
            break;
    
    default:
            printf("In valid option !!!\n");
            break; 
   }
  }
  return 0;
}


/*************** All function implementaion ************************/
/* A function to create new node for link list
     Arguments:
               val: Create a new node with this value.
     Return: 
              New node  
*/
struct node* newNode(int val)
{

  struct node* tmp =(struct node*)malloc(sizeof(struct node));
  if(tmp==NULL)
  {
    printf("Allocation failed\n");
    printf("Exiting...\n");
    exit(-1);
  }
  tmp->val = val;
  tmp->next = NULL;
  return tmp;
}


/* Create a new list and put the entry in the map
     Arguments:
               list_count the head key value or list count value
     Return:   
               The created list id.
*/
int create_list(int list_count)
{
  struct node* head=NULL;
  head_list[list_count] = head;
  return list_count;
}



/* Display a particular list
   Argument: 
            list_id: To get the list head pointer 
*/ 
void display_list(int list_id)
{
  
  if(head_list.find(list_id)==head_list.end())
  {
     printf("List doesn't exist\n");
     return;
  }
  else
  {
    struct node *head = head_list[list_id];
    if(head==NULL)
    {
      printf("Empty list\n");
      return;
    }
   printf("List %d: -> ",list_id);  
   while(head!=NULL)
    {
      printf("%d ", head->val);
      head = head->next;
    }
    printf("\n");
  }
}



/*  Remove a node from the list
    Arguments: 
               list_id: To get the list head pointer
                 value: which need to be deleted
*/
void remove_node(int list_id, int val)
{
    
  if(head_list.find(list_id)==head_list.end())
  {
     printf("List doesn't exist\n");
     return;
  }
  struct node *head = head_list[list_id];
  if(head==NULL)  //if list is empty 
  {
    printf("List is empty\n");
    return;
  }
  else if(head->val == val)  //if head needs to be deleted
  {
    struct node *tmp = head;
    head = head->next;
    free(tmp);  
  }
  else 
  {
    struct node *curr = head;
    while(curr->next && curr->next->val < val)
      curr = curr->next;
    if(curr->next==NULL)
    {
       printf("%d not found in the list %d\n", val, list_id);
       return;
    }
    if(curr->next->val==val)
    {
      struct node *tmp = curr->next;
      curr->next = curr->next->next;
      free(tmp);
    }
    else  //curr->next->val > val
    {
       printf("%d not found in the list %d\n", val, list_id);
       return;
    }
  }
  head_list[list_id] = head;
}



/*
   Add a node with given to the given list 
   Arguments: 
             list_id: To get the list head
               value: To create a new node with this value
*/
void add_node(int list_id, int val)
{

  if(head_list.find(list_id)==head_list.end())
  {
     printf("List doesn't exist\n\n");
     return;
  }

  struct node *head = head_list[list_id];
  struct node *tmp = newNode(val);
  struct node *curr;
  if(head==NULL)
  {
    head = tmp;
  }
  else if(head->val > val)
  {
    tmp->next =  head;
    head = tmp;
  }
  else
  {
    curr = head;
    while(curr->next && curr->next->val< val)
    {
      curr = curr->next;
    }
    tmp->next = curr->next;
    curr->next = tmp;
  }
  head_list[list_id] = head;
 // printf("List has been updated\n");
}   



/*
   Get the size of buffer which requires to copy the content of link list.
   Arguments: 
             head: List pointer
                c: Count number of nodes in link list(needed to add delimeter) 
   return:  The size required to copy the list
*/
long long getSize(struct node *head, int &c)
{
  long long ans = 0;
  struct node *curr=head;
  char tmp[INT_DIGIT_MAX_LIMIT];
  int k;
  while(curr)
  {
    memset(tmp,'\0',INT_DIGIT_MAX_LIMIT);  //we are just storing a value
    sprintf(tmp,"%d",curr->val); 
    for(k = 0; *(tmp+k); k++);
    ans += k;
    curr = curr->next;
    c++;
  }
  return ans;
}


/*
    A function to delete the entire list 
      Arguments: 
                 list_id: To get the list head pointer
*/
void remove_list(int list_id)
{

  if(head_list.find(list_id)==head_list.end())
  {
     printf("List doesn't exist\n\n");
     return;
  } 

  struct node *head = head_list[list_id];
  while(head)
  {
    struct node *tmp =  head;
    head =  head->next;
    free(tmp);
  }  
  //delete the entry from map
  head_list.erase(list_id);
}



/*
    A function which copy the content of link list into buffer
    Arguments:
              list_id: To get the list head pointer
               buffer: Copy the content of list into given buffer
    Return:
              The size required to copy the buffer.         
*/
int serializeList(int list_id, char *buffer)
{
   int seeker = 0;
   struct node *curr = head_list[list_id];
   char id[ID_DIGIT_MAX_LIMIT];
   char tmp[INT_DIGIT_MAX_LIMIT]; 
   sprintf(id,"%d", list_id);  //copy the id in temp buffer
   int k;
   int j=0;
   int notNull = false;
   //copy the id first
   for(k = 0; *(id+k); k++,j++)
     buffer[j] = id[k];
  
    buffer[j++] = ':';
 //  printf("buffer @ %s\n", buffer); 
   while(curr)
   {
     memset(tmp,'\0',INT_DIGIT_MAX_LIMIT);
     //this will never be more than no of digits in INT_MAX
     sprintf(tmp, "%d", curr->val);

     for(k = 0; *(tmp+k); k++,j++)
       buffer[j] = tmp[k];

     //put a delimeter
     buffer[j++] = ','; 
     curr = curr->next;
     notNull = true;
   } 
   //overwrite the last ','
   if(notNull)
     j--;
   buffer[j++] = ' ';
   buffer[j++] = 'N';
   buffer[j++] = 'U';
   buffer[j++] = 'L';
   buffer[j++] = 'L';
   buffer[j++] = '\n';
  /* These many bytes has been written to the buffer so don't waste the space of file, 
     only write these many bytes to the file 
  */
  // printf("buffer $ %s\n", buffer);
   return j;  
}


/*
   Copy all the lists into file "List.data". 
   Put the delimeter among the nodes of link list 
*/
void serialize()
{

  FILE *filePtr = fopen("List.data", "wb+");

  std::map<int, struct node*>::iterator it;
  char tmp[LONG_DIGIT_MAX_LIMIT];
  for(it = head_list.begin(); it!=head_list.end(); it++)  //walk through all list
  {
   // printf("list id %d\n", it->first);
    int c=0;  //no of nodes
    int list_id = it->first;  //we need to add this to the file as well 
    long long size = getSize(it->second,c); //get the size of link list 
   
    size += c; // to add ',' between numbers
    size += ID_DIGIT_MAX_LIMIT; //assuming that id will not be more than ID_DIGIT_MAX_LIMIT digits
    //write the delimeter to differentiate between two link list 
    size += sizeof("NULL"); //trying to add the NULL on each list end
    char *buffer = (char *)malloc(size);
    if(buffer==NULL)
    {
      printf("Allocation failed !!!\n");
      exit(-1);
    }

    size = serializeList(it->first, buffer); 
    //first write the size;
    memset(tmp,'\0',LONG_DIGIT_MAX_LIMIT);
  
//    printf("Size =%lld\n", size); 
    sprintf(tmp,"%lld", size);
    // write the size of list 
    fwrite(tmp,LONG_DIGIT_MAX_LIMIT,1,filePtr);
  //  printf("buffer %s\n", buffer);
    //then write the link list
    fwrite(buffer, size, 1, filePtr);
    free(buffer);
   }  
  fclose(filePtr);
  printf("File has been written\n");
  
  return;
}


/*
    A function which walks through all the lists
*/
void walk_lists()
{
   std::map<int, struct node*>::iterator it;
  for(it = head_list.begin(); it!=head_list.end(); it++)  //walk through all list
  {
    printf("%d:->", it->first);
    struct node* curr = it->second;
    while(curr)
    {
      printf("%d ", curr->val);
      curr = curr->next;
    }
    printf("\n");          
  }
}



/*
    A function to calculate the size of file and check the file status
    Arguments:
               filename: File name 
    Return:
              The size of file. 
    Assuming that file is residing in the same directory        
*/
long long int fileSize(const char *filename) {
  struct stat buffer;         /* sys/stat */
  char path[256];             /* buffer for saving filename with path */
  long long int size;         /* This will hold the size returned by this function */

  strcpy(path, "./");         /* assuming that example.data is in the same folder */
                              /* this program */
  strcat(path, filename);     /* append filename to after './' */

  if(stat(path, &buffer) < 0) /* get stat structure for example.data */
    return 0;
  else
    size = buffer.st_size;    /* st_size member of the stat structure holds */
                              /* the filesize */
  return size;
}



/*
    A function to convert char array to numerical value
    Arguments:
               Character pointer
    Return:
               Numerical value calculated from caharacter value
*/
int myAtoi(char *str)
{
    int res = 0; // Initialize result
 
    // Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if(str[i]>='0' && str[i]<='9')
         res = res*10 + str[i] - '0';
        else
         return res;
    }
    // return result.
    return res;
}



/*
    A function to build the in-memory structure after reading from a file.
    Arguments:
               buffer: It holds the content of a list
                 size: Size of the list 
*/
void constructLists(char *buffer, long long int size)  //reconstruct the lists
{
 // printf("Construct  %s\n", buffer);
  long long int i=0;
  //first get the id;
  int list_id = 0;
  while(i<size && (*(buffer+i) != ':')) 
  {
   if(buffer[i]>='0' && buffer[i]<='9') 
    list_id =list_id*10 + buffer[i]-'0';
    i++;
  }    
  if(buffer[i]==':')
    i++;  

  //update the head count
  if(list_id>=head_count)
  {
   head_count=list_id;
   head_count++;
  }
  //printf("$ list_id %d\n", list_id);
 // printf("head_count %d\n", head_count);
  list_id = create_list(list_id);

  //now parse the list and add the nodes into the list
  while(i<size && *(buffer+i) != 'N' && *(buffer+i) !=' ')  // at the end space or null 
  {
     int val = 0;
     int isNegative = 0;
     while(i<size && (*(buffer+i) != ',' && *(buffer+i) != 'N' && *(buffer+i) != ' '))
     {
       if(buffer[i]>='0' && buffer[i]<='9')
          val = val*10 + buffer[i] - '0';
       if(buffer[i]=='-')
          isNegative = 1;
       i++;
     }
   // if(list_id > 90)   
   //  printf("$ %d -> %d\n", list_id, val); 
     
   if(isNegative)
       val = val*(-1);
     add_node(list_id, val);
     if(i>=size || buffer[i]=='N'||buffer[i]==' ')
     {
   //    walk_lists();
       return;
     }
     else
      i++;
  }
 // walk_lists();
}


/*
    A function to deSerialize the file (ie read the file and construct the lists
*/
void deSerialize()
{
  FILE *filePtr;      /* filepointer for opening a file */
  const char *ptr = "List.data";
  long long int fSize = fileSize("List.data");
 // printf("File Size %lld\n", fSize);
  char tmp[LONG_DIGIT_MAX_LIMIT];  //to get the size of list
  if(fSize==0)
    return ;
  else               //open the file and construct the in memory structure
  {
    filePtr = fopen("List.data", "rb"); // read binary    
    int done = 0;
     
    while(done < fSize)  // read entire file
    {
       memset(tmp,'\0', LONG_DIGIT_MAX_LIMIT);
       fread(tmp, LONG_DIGIT_MAX_LIMIT, 1, filePtr);
       done += LONG_DIGIT_MAX_LIMIT;   //move the done pointer
       long long int lSize = myAtoi(tmp);
      // printf("List size %lld\n", lSize);
       char *buffer = (char *)malloc(lSize+1);
       if(buffer==NULL)
       {
          printf("Allocation Failed !!!\n");
          exit(-1);
       }
       fread(buffer, lSize, 1, filePtr);
       buffer[lSize] = '\0';
       //printf("List content %s\n", buffer);
       constructLists(buffer, lSize);

       done += lSize;
       free(buffer);
    }
   // printf("done %d\n", done);
    fclose(filePtr);  //close the file
    //add a function to print the lists, check to see if all lists has construct or not 
     printf("Available Lists\n");
     walk_lists();
  }
}

/*
  A function which check whether the list exist or not
  Arguments:
            list_id
  Return:
            1  if list exist
            0  if list doesn't exist 
*/

int check_list(int list_id)
{
  if(head_list.find(list_id)==head_list.end())
     return 0;
  else 
   return 1;
}



















