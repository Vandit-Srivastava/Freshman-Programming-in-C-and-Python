#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d ", ceo->emp_id);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

// ///////////////////////////////////////////////PYTHON LISTS CODE STARTS HERE////////////////////////////////////////////////////////

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


// helper function that returns pointer to `Node` at `position`
// if there is no such position, it returns NULL
struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        if(pos == position) return cur;
        pos++;
        cur = cur->next;
    }
    return NULL;
}


// Return the number of elements in the list
int len() {
    int length = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        length++;
        cur = cur->next;
    }
    return length;
}


// Add an item to the end of the list
void append(int x) {
    struct Node* cur = PythonListHead;
    if(cur == NULL) {
        // no list exists, we have to create one
        PythonListHead = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int n = len();
    if(position >= n) return;
    struct Node* node_at_position = get_node_at_pos(position);
    // 2 cases now
    // if node_at_position is the first node
    if(position == 0) {
        struct Node* new_node = create_node(x);
        new_node->next = node_at_position;
        PythonListHead = new_node;
    }
    else { // node_at_position is not the first node
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = create_node(x);
        previous_node->next->next = node_at_position;
    }
}


// Remove the item at the end of the list
void pop() {
    int n = len();
    if(n == 0) return;

    if(n == 1) {
        delete_node(PythonListHead);
        PythonListHead = NULL;
    }
    else {
        struct Node* second_last_node = get_node_at_pos(n-2);
        delete_node(second_last_node->next);
        second_last_node->next = NULL;
    }
}


// Remove all items from the list
void clear() {
    struct Node* cur = PythonListHead;
    PythonListHead = NULL;
    while(cur) {
        struct Node* next_node = cur->next;
        delete_node(cur);
        cur = next_node;
    }
}


// Return the number of times x appears in the list.
int count(int x) {
    struct Node* cur = PythonListHead;
    int cnt = 0;
    while(cur) {
        if(cur->data == x) cnt++;
        cur = cur->next;
    }
    return cnt;
}

struct Node* reverse_helper(struct Node* cur_node) {
    if(cur_node == NULL) return NULL;

    if(cur_node->next == NULL) {
        // this is the first node of the reversed list
        PythonListHead = cur_node;
        return cur_node;
    }

    // recursively solve for the next node
    struct Node* next_node = reverse_helper(cur_node->next);

    // set the next of next_node to cur_node
    next_node->next = cur_node;

    // also make the cur_node->next as NULL, since cur_node is the last node of the list
    cur_node->next = NULL;

    return cur_node;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* last_node = reverse_helper(PythonListHead);
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        node_at_pos->data = x;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        return node_at_pos->data;
    }
    else return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(!node_at_pos) return;

    // 2 cases now
    // if node_at_pos is the first node
    if(node_at_pos == PythonListHead) {
        PythonListHead = PythonListHead->next;
        delete_node(node_at_pos);
    }
    else {
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = node_at_pos->next;
        delete_node(node_at_pos);
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
    struct Node* new_list_head = NULL;
    struct Node* new_list_tail = NULL;
    for(int i=0;i<n;i++) {
        struct Node* node_at_pos = get_node_at_pos(positions[i]);

        if(!node_at_pos) continue;

        if(new_list_tail) {
            new_list_tail->next = create_node(node_at_pos->data);
            new_list_tail = new_list_tail->next;
        }
        else {
            new_list_head = create_node(node_at_pos->data);
            new_list_tail = new_list_head;
        }
    }
    return new_list_head;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    struct Node* next_node = get_node_at_pos(position+1);
    if(!node_at_pos || !next_node) return;

    // 2 cases 
    if(node_at_pos == PythonListHead) {
        PythonListHead = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
    else {
        struct Node* prev_node = get_node_at_pos(position-1);
        prev_node->next = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    int n = len();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            int x = get_node_at_pos(j)->data;
            int y = get_node_at_pos(j+1)->data;
            if(x > y) swap(j);
        }
    }
}

///////////////////////////////////////////////////////PYTHON LIST CODE ENDS HERE////////////////////////////////////////////////////////

/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */

int Level(int);

void helper_EmployeesAtSameLevel(struct Employee* ceo, int level){        //Helper function for Employees at same level.
    if (ceo){
        if (Level(ceo->emp_id)==level){
            printf("%d ", ceo->emp_id);
        }
        helper_EmployeesAtSameLevel(ceo->subordinate_1, level);
        helper_EmployeesAtSameLevel(ceo->subordinate_2, level);
    }
}
void EmployeesAtSameLevel(int level){     // The level may be any integer
    helper_EmployeesAtSameLevel(CEO, level);
}

// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers

void get_employees_helper(struct Employee* ceo){        //helper function
    if(!ceo) {
        return;
    }
    printf("%d ", ceo->emp_id);
    get_employees_helper(ceo->subordinate_1);
    get_employees_helper(ceo->subordinate_2);
    return;
}

void get_employees() {
    get_employees_helper(CEO);
    return;
}

/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */
int Boss(int);
struct Employee* helper_Boss(struct Employee*, int);
void ImmediateTeam(int emp_id) {
    if (Boss(emp_id)!=-1){
        printf("%d ", Boss(emp_id));
        struct Employee* k;
        if (helper_Boss(CEO, emp_id)->subordinate_1!=NULL){
            if (helper_Boss(CEO, emp_id)->subordinate_1->emp_id==emp_id){
                k=helper_Boss(CEO, emp_id)->subordinate_1;
            }
        }
        if (helper_Boss(CEO, emp_id)->subordinate_2!=NULL){
            if (helper_Boss(CEO, emp_id)->subordinate_2->emp_id==emp_id){
                k=helper_Boss(CEO, emp_id)->subordinate_2;
            }
        }
        if (k->subordinate_1!=NULL){
            printf("%d ", k->subordinate_1->emp_id);
        }
        if (k->subordinate_2!=NULL){
            printf("%d ", k->subordinate_2->emp_id);
        }
    }
    else{
        if (CEO->subordinate_1!=NULL){
            printf("%d ", CEO->subordinate_1->emp_id);
        }
        if (CEO->subordinate_2!=NULL){
            printf("%d ", CEO->subordinate_2->emp_id);
        }
    }
}

int helper_Level(struct Employee* ceo, int counter, int emp_id){        //helper function for Level.
    if (ceo){
        counter=counter+1;
        if (ceo->emp_id==emp_id){
            return counter;
        }
        if (helper_Level(ceo->subordinate_1, counter, emp_id)>helper_Level(ceo->subordinate_2, counter, emp_id)){
            return helper_Level(ceo->subordinate_1, counter, emp_id);
        }
        else{
            return helper_Level(ceo->subordinate_2, counter, emp_id);
        }
    }
    return 0;
}

// The following function returns the level of a employee with the given emp_id
int Level(int emp_id) {
    return helper_Level(CEO,-1,emp_id);
    // Note that ceo has level 0
}

// The following function gives the distance between employees with emp_id1 and emp_id2
int Distance(int emp_id1, int emp_id2) {
    // If emp_id1 and emp_id2 are equal the distance is 0, both emp_id's will exist in the organisation
    int id1=emp_id1;
    int id2=emp_id2;
    int counter=0;
    if (id1!=id2){
        int a = Level(id1)-Level(id2);
        if (a>0){
            for (int i=0;i<a;i++){
                id1=Boss(id1);
            }
        }
        else {
            a=(-1)*a;
            for (int i=0;i<a;i++){
                id2=Boss(id2);
            }
        }
        while(id1!=id2){
            id1=Boss(id1);
            id2=Boss(id2);
            counter=counter+1;
        }
        return 2*counter+a;
    }
    else{
        return 0;
    }
}

struct Employee* helper_Boss(struct Employee* ceo, int emp_id){      // Helper for Boss
    if (ceo){
        if (ceo->subordinate_1!=NULL && ceo->subordinate_2!=NULL){
            if (ceo->subordinate_1->emp_id==emp_id || ceo->subordinate_2->emp_id==emp_id){
                 return ceo;
            }
        }
        if (ceo->subordinate_1!=NULL && ceo->subordinate_2==NULL){
            if (ceo->subordinate_1->emp_id==emp_id){
                return ceo;
            }
        }
        if (ceo->subordinate_1==NULL && ceo->subordinate_2!=NULL){
            if (ceo->subordinate_2->emp_id==emp_id){
                return ceo;
            }
        }
        if (helper_Boss(ceo->subordinate_1, emp_id)!=NULL){
            return helper_Boss(ceo->subordinate_1, emp_id);
        }
        if (helper_Boss(ceo->subordinate_2, emp_id)!=NULL){
            return helper_Boss(ceo->subordinate_2, emp_id);
        }
    }
    return NULL;        //ceo has no boss.
}
/* The following function takes an emp_id this will belong to a employee in the organisation and your task is to return the emp_id of its boss
Note: If the boss does not exit return -1 */
int Boss(int emp_id) {
    if (helper_Boss(CEO, emp_id)==NULL){
        return -1;
    }
    else{
        return helper_Boss(CEO, emp_id)->emp_id;
    }
}

void form_list(struct Employee* ceo){       //Helper function for Diameter. Forms a list with emp_ids of CEO and interns.
    if (ceo){
        if (ceo==CEO){
            append(ceo->emp_id);
        }
        if (ceo->subordinate_1==NULL && ceo->subordinate_2==NULL){
            append(ceo->emp_id);
        }
        form_list(ceo->subordinate_1);
        form_list(ceo->subordinate_2);
    }
}

/* The following function returns the diameter of a Organisation - 
a diameter is the maximum distance between any two emp_ids in the organisation. You can use the distance function implemented above */

int Diameter() {
//    return helper_Diameter2(CEO,0);
//    return 0;
    form_list(CEO);
    int dia=0;
    for (int i=0;i<len();i++){
        for (int j=i+1;j<len();j++){
            if (dia<Distance(getitem(i),getitem(j))){
                dia=Distance(getitem(i),getitem(j));
            }
        }
    }
    return dia;
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */

int TeamSize(int emp_id) {
    int counter=0;
    if (Boss(emp_id)!=-1){
        counter=counter+1;
        struct Employee* k;
        if (helper_Boss(CEO, emp_id)->subordinate_1!=NULL){
            if (helper_Boss(CEO, emp_id)->subordinate_1->emp_id==emp_id){
                k=helper_Boss(CEO, emp_id)->subordinate_1;
            }
        }
        if (helper_Boss(CEO, emp_id)->subordinate_2!=NULL){
            if (helper_Boss(CEO, emp_id)->subordinate_2->emp_id==emp_id){
                k=helper_Boss(CEO, emp_id)->subordinate_2;
            }
        }
        if (k->subordinate_1!=NULL){
            counter=counter+1;
        }
        if (k->subordinate_2!=NULL){
            counter=counter+1;
        }
    }
    else{
        if (CEO->subordinate_1!=NULL){
            counter=counter+1;
        }
        if (CEO->subordinate_2!=NULL){
            counter=counter+1;
        }
    }
    return counter;
}

// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[50];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "level") == 0) {
            int x;
            scanf("%d", &x);
            int d = Level(x);
            printf("%d\n", d);
        } 

        if(strcmp(operation_type, "distance") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int d = Distance(x, y);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "employees_at_same_level") == 0) {
            int x;
            scanf("%d", &x);
            EmployeesAtSameLevel(x);
            printf("\n");
        }

        if(strcmp(operation_type, "get_employees") == 0) {
            get_employees();
            printf("\n");
        }

        if(strcmp(operation_type, "boss") == 0) {
            int x;
            scanf("%d", &x);
            int d = Boss(x);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "diameter") == 0) {
            int d = Diameter();
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "immediate_team") == 0) {
            int x;
            scanf("%d", &x);
            ImmediateTeam(x);
            printf("\n");
        }

        if(strcmp(operation_type, "team_size") == 0) {
            int x;
            scanf("%d", &x);
            int d = TeamSize(x);
            printf("%d\n", d);
        }
    }

    return 0;
}
