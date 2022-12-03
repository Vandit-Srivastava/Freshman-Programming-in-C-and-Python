#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;


// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    if (PythonListHead==NULL){
        PythonListHead=create_node(x);
    }
    else{
        struct Node* cur = PythonListHead;
        while (cur){
            if (cur->next==NULL){
                cur->next=create_node(x);
                break;
            }
            cur=cur->next;
        }
    }
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    if (PythonListHead!=NULL){
        struct Node* k = create_node(x);
        if (position==0){
            k->next = PythonListHead;
            PythonListHead = k;
        }
        else {
            struct Node* cur = PythonListHead;
            int pos = 0;
            while(pos<=position-1 && cur->next!=NULL){
                if (pos==position-1){
                    k->next=cur->next;
                    cur->next=k;
                    break;
                }
                cur = cur->next;
                pos=pos+1;
            }
        }
    }    
}


// Remove the item at the end of the list
void pop() {
    if (PythonListHead!=NULL){
        if (PythonListHead->next==NULL){
            delete_node(PythonListHead);
            PythonListHead=NULL;            
        }
        else{
            struct Node* cur = PythonListHead;
            while(cur){
                if (cur->next->next==NULL){
                    delete_node(cur->next);
                    cur->next=NULL;
                }
                cur=cur->next;
            }    
        }    
    }
}


// Remove all items from the list
void clear() {
    while(PythonListHead!=NULL){
        pop();
    }
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    struct Node* cur = PythonListHead;
    int counter=0;
    while(cur) {
        if (cur->data==x){
            counter = counter + 1;
        }
        cur=cur->next;
    }
    return counter;
}
//Helper function. /first node has index 0/
struct Node* pointer(int pos){
    struct Node* cur = PythonListHead;
    int num=0;
    while(num<=pos){
        if (num==pos){
            return cur;
        }
        cur=cur->next;
        num=num+1;
    }
}

int len();
// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    if (len()>=2){
        struct Node* k = pointer(len()-1);
        for (int i=len()-2;i>=0;i=i-1){
            pointer(i+1)->next=pointer(i);
        }
        pointer(0)->next=NULL;
        PythonListHead=k;
    }
}


// Return the number of elements in the list
int len() {
    // your code goes here
    struct Node* cur=PythonListHead;
    int counter=0;
    while(cur){
        cur=cur->next;
        counter=counter+1;
    }
    return counter;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    int num=0;
    struct Node* cur=PythonListHead;
    while(cur){
        if (num==position){
            cur->data=x;
            break;
        }
        cur=cur->next;
        num=num+1;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    int num=0;
    struct Node* cur = PythonListHead;
    while(cur){
        if (num==position){
            return cur->data;
        }
        cur=cur->next;
        num=num+1;
    }
    return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    if (position==0){
        if(PythonListHead!=NULL){
            struct Node* k=PythonListHead;
            PythonListHead=k->next;
            delete_node(k);
        }
    }
    else{
        struct Node* cur=PythonListHead;
        int num=0;
        while(cur){
            if (num==position-1 && cur->next!=NULL){
                struct Node* k=cur->next;
                cur->next=k->next;
                delete_node(k);
                break;
            }
            cur=cur->next;
            num=num+1;
        }
    }
}



// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* index_into(int *positions, int n) {
    // your code goes here
    if (n>0){
        struct Node* cur = NULL;
        int i=0;
        struct Node* k=NULL;
        while (i<n){
            if (positions[i]<len() && positions[i]>-1){
                if (cur==NULL){
                    cur=create_node(getitem(positions[i]));
                    k=cur;
                }
                else{
                    cur->next=create_node(getitem(positions[i]));
                    cur=cur->next;
                }
            }
            i=i+1;
        }
        return k;
    }
    return NULL;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    if (position+1<=len()-1){
        if (position==0){
            struct Node* k1 = pointer(0);
            struct Node* k2 = pointer(1);
            struct Node* k3 = k2->next;
            k2->next=k1;
            k1->next=k3;
            PythonListHead=k2;
        }
        if(position>0){
            struct Node* k1=pointer(position-1);
            struct Node* k2=pointer(position);
            struct Node* k3=pointer(position+1);
            struct Node* k4=k3->next;
            k1->next=k3;
            k3->next=k2;
            k2->next=k4;
        }
    }
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    struct Node* cur = PythonListHead;
    int pos = 0;
    while (cur && cur->next!=NULL){
        if (cur->data>cur->next->data){
            swap(pos);
            sort();
        }
        cur=cur->next;
        pos=pos+1;
    }
}


// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}