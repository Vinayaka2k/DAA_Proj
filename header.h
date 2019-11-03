/* LINKED LIST IMPLEMENTATION */

typedef struct node
{
char key[10];
char value[10];
struct node* next; 
}node;

typedef struct table_node
{
node* head;
}table_node;

typedef struct table
{
int capacity;
int size;
table_node *tnode;
}table;


table* hashmap_create_ll(int my_capacity);
int hash_func_ll(char* my_key,table* h);
void hashmap_insert_ll(char* my_key,char* my_value,table* h);			
int hashmap_search_ll(char* my_key,table* h);
int hashmap_delete_ll(char* my_key,table *h);
void hashmap_rehash_ll(table* h);
float hashmap_loadfactor(table* h);

/* ARRAY IMPLEMENTATION */


typedef struct hashtable{
	int p;
	char key[10];
	char value[10];
}hash;

hash* hashmap_create_array(int capacity);
int  hash_func_array(char *my_key,int capacity);
hash* hashmap_insert_array(hash *t,int* capacity,char*my_key,char*value);
int hashmap_delete_array(hash*t,int capacity,char* my_key);
hash* hashmap_rehash_array(hash *p,int* capacity);
int hashmap_search_array(hash*t,int capacity,char* my_key);
