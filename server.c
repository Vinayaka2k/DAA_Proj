#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"




/* ARRAY IMPLEMENTATION */


hash* hashmap_create_array(int capacity)
{
	hash *t=(hash*)malloc(sizeof(hash)*capacity);
	for(int i=0;i<capacity;i++)
	{
		
		t[i].p=0;
	}
	return t;
}

int  hash_func_array(char *my_key,int capacity)
{
int sum=0;
for(int i=0;i<strlen(my_key);++i)
	{
	int ascii = my_key[i];
	sum=sum+ascii;
	}
int t1 = sum%(capacity);
return(t1);
}


hash* hashmap_insert_array(hash *t,int* capacity,char*my_key,char*value)
{
	
	
	int hkey;
	hkey=hash_func_array(my_key,*capacity);
	int i=hkey;
	while(t[i].p==1)
	{
		if(!strcmp(t[i].key,my_key))
		{
			strcpy(t[i].value,value);							// If key already exists, updates
			return t;
		}
		i=(i+1)%(*capacity);
		
		
		if(i==hkey)
		{

			printf("HASHMAP IS FULL\n");
			printf("REHAHSING\n");
			t=hashmap_rehash_array(t,capacity);			
			hashmap_insert_array(t,capacity,my_key,value);
			return t;
		}
	}
	t[i].p=1;
	strcpy(t[i].value,value);
	strcpy(t[i].key,my_key);
	return t;
}


hash* hashmap_rehash_array(hash *p,int* capacity)
{
	int o=(*capacity);
	*capacity=(*capacity)*2;
	hash *p1=hashmap_create_array(*capacity);
	for(int i=0;i<o;i++)
	{
	
		hashmap_insert_array(p1,capacity,p[i].key,p[i].value);
		
	}
	
	
	
	return p1;	
	
}


int hashmap_search_array(hash*t,int capacity,char* my_key)
{
	int hkey=hash_func_array(my_key,capacity);
	int i=hkey;
	while(t[i].p!=0)
	{
		if(t[i].p==1 && !strcmp(t[i].key,my_key))
		{
			printf("The value is : %s\n",t[i].value);
			return 1;
			
		}
		i=(i+1)%(capacity);
		if(i==hkey)
		{
			return 0;
		}
	}
}


int hashmap_delete_array(hash*t,int capacity,char* my_key)
{
	int hkey=hash_func_array(my_key,capacity);
	int i=hkey;
	while(t[i].p!=0)
	{
		if(t[i].p==1 && !strcmp(t[i].key,my_key))
		{
				
			t[i].p=0;
			strcpy(t[i].key,"#");
			return 1;			
	
		}
		i=(i+1)%(capacity);
		if(i==hkey)
		{
			return 0;
		}
	}
	
}


	








/* LINKED LIST IMPLEMENTATION */

table* hashmap_create_ll(int my_capacity)
{
table* h;
h = (table*)malloc(sizeof(table));
h->size = 0;
h->capacity = my_capacity;
h->tnode = (table_node*)malloc(sizeof(table_node) * (my_capacity));
for(int i=0;i<my_capacity;++i)
	{
	h->tnode[i].head = NULL;
	}
printf("Load Factor: %f\n",hashmap_loadfactor(h));			
return h;
}

int hash_func_ll(char* my_key,table* h)
{
int sum=0;
for(int i=0;i<strlen(my_key);++i)
	{
	int ascii = my_key[i];
	sum=sum+ascii;
	}

int t = sum%(h->capacity);
return(t);
}



void hashmap_insert_ll(char* my_key,char* my_value,table* h)			// inserts or updates
{
node* temp;
node* temp1;
int index = hash_func_ll(my_key,h);
temp = (h->tnode[index]).head;
temp1 = temp;
while(temp)
	{
	if(strcmp(temp->key,my_key) == 0)			// key already there, update
		{
		strcpy(temp->value,my_value);
		return;	
		}	
	temp = temp->next;
	}
node* new;								// key not there, insert
new = (node*)malloc(sizeof(node));
strcpy(new->key , my_key);
strcpy(new->value , my_value);
new->next = temp1;
h->tnode[index].head = new;
h->size++;
}


void hashmap_rehash_ll(table* h)
{
node* temp;
table_node* oldtable;
oldtable = h->tnode;
int old_capacity = h->capacity;
h->capacity = h->capacity * 2;
h->size = 0;
h->tnode = (table_node*)malloc(sizeof(table_node) * h->capacity);
for(int i=0;i<(h->capacity);++i)
	{
	h->tnode[i].head = NULL;
	}
for(int i=0;i<(old_capacity);++i)
	{
	temp = oldtable[i].head;
	if(temp != NULL)
		{	
		while(temp)	
			{
			hashmap_insert_ll(temp->key,temp->value,h);
			temp = temp->next;
			}
		}	
	}
free(oldtable);
}


/* returns -1 if no str present*/

int hashmap_search_ll(char* my_key,table* h)
{
node* temp;
int index = hash_func_ll(my_key,h);
temp = h->tnode[index].head;
while(temp)
	{
	if(strcmp(temp->key,my_key) == 0)
		{
		printf("The value is: %s\n",temp->value);
		return 1;
		}
	temp = temp->next;
	}
return -1;
}

/* returns -1 if ele to be deleted is not present*/

int hashmap_delete_ll(char* my_key,table* h)
{
node* temp;
node* prev;
int index = hash_func_ll(my_key,h);
temp = h->tnode[index].head;
prev = NULL;
while(temp)
	{
	if(strcmp(temp->key,my_key) == 0)
		{
		if(prev == NULL)					// node to be deleted is 1st node
			{
			h->tnode[index].head = temp->next;
			}
		else
			{	
			prev->next = temp->next;
			}
		free(temp);
		h->size--;
		return 1;		
		}
	prev=temp;
	temp = temp->next;	
	}
return -1;
}


float hashmap_loadfactor(table* h)
{
float loadfactor;
loadfactor = ((1.0 * h->size) / h->capacity);
return loadfactor;
}

