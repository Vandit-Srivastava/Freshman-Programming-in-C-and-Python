#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

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
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
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

//Helper function.
struct Employee* helper_pointer(struct Employee* ceo, int emp_id){
    if (ceo){
        if (ceo->emp_id==emp_id){
            return ceo;
        }
        else{
            if (helper_pointer(ceo->subordinate_1, emp_id)!=NULL){
                return helper_pointer(ceo->subordinate_1, emp_id);
            }
            if (helper_pointer(ceo->subordinate_2, emp_id)!=NULL){
                return helper_pointer(ceo->subordinate_2, emp_id);
            }
            return NULL;
        }
    }
    return NULL;
}

//Helper function.
struct Employee* employee_pointer(int emp_id){
    return helper_pointer(CEO, emp_id);
}

//Helper function.
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

//Helper function
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

//Helper function
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

//Helper function
// The following function returns the level of a employee with the given emp_id
int Level(int emp_id) {
    return helper_Level(CEO,-1,emp_id);
    // Note that ceo has level 0
}

// The below function returns the employee id of the first common boss
int get_first_common_boss(int emp_id1,int emp_id2){
    int id1=emp_id1;
    int id2=emp_id2;
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
        }
        return id1;
    }
    else{
        return Boss(id1);
    }
}

// Helper function.
void list_maker(char* name, struct Employee* ceo){
    if(ceo){
        if (strcmp(ceo->emp_name, name)==0){
            append(ceo->emp_id);
        }
        list_maker(name, ceo->subordinate_1);
        list_maker(name, ceo->subordinate_2);
    }
}

// Helper function.
void Level_sort() {
    int n = len();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            int x = get_node_at_pos(j)->data;
            int y = get_node_at_pos(j+1)->data;
            if(Level(x) > Level(y)) swap(j);
        }
    }
}
//Print the employees with the same last name sperated by a space in the order of their level
void same_last_names(int emp_id){
    char* name = employee_pointer(emp_id)->emp_name;
    list_maker(name, CEO);
    Level_sort();
    for (int i=0;i<len();i++){
        printf("%d ", getitem(i));
    }
    clear();
    return;
}

//Helper function.
void boss_list_maker(int id){
    id=Boss(id);
    if (id==-1){
        return;
    }
    else{
        append(id);
        boss_list_maker(id);
    }
}

// Print the bosses of the given employee in the order from CEO to immediate boss
void get_all_bosses(int emp_id){
    if (CEO->emp_id==emp_id){
        printf("%d", -1);
    }
    else{
        boss_list_maker(emp_id);
        for (int i=len()-1;i>=0;i=i-1){
            printf("%d ", getitem(i));
        }
        clear();
    }
    return;
}

int n;
int sum;
//Helper function.
void helper_avg(struct Employee* ceo){
    if (ceo){
        sum=sum+ceo->emp_salary;
        n=n+1;
        helper_avg(ceo->subordinate_1);
        helper_avg(ceo->subordinate_2);
    }
}

// Return the average salary of the team with the given employee as head
double get_average_salary(int emp_id){
    struct Employee* head = employee_pointer(emp_id);
    n=0;
    sum=0;
    helper_avg(head);
    return ((double)sum)/((double)n);
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

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}
