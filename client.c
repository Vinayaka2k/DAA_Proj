#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"
#define LOAD 0.75

void main()
{
int isll;
printf("Enter the Implementation:\n0. Array\n1.Linked List\n");
scanf("%d",&isll);
float lf;
int res;
char my_key[10];
char my_value[10];
int my_capacity;
printf("Enter Capacity\n");
scanf("%d",&my_capacity);
table *h = hashmap_create_ll(my_capacity);
int ch=1;
hash *ha;
ha=hashmap_create_array(my_capacity);

while(ch!=4)
	{
	printf("\n1. insert or update key\n2. search\n3. delete");
	printf("\nEnter Your Choice:\n");
	scanf("%d",&ch);
	switch(ch)
		{
		case 1:
			{	
				if(isll == 1)
				{	
					printf("Enter key\n");
					scanf("%s",my_key);
					printf("Enter value\n");
					scanf("%s",my_value);
					hashmap_insert_ll(my_key,my_value,h);
					lf = hashmap_loadfactor(h);
					printf("Load Factor: %f\n",lf);
					if(lf >= LOAD)
						{
						printf("REHASHING\n");
						hashmap_rehash_ll(h);	
						lf = hashmap_loadfactor(h);		
						printf("Load Factor after Rehashing: %f\n",lf);
						}	
					break;
				}
				else
				{		
					printf("Enter key\n");
					scanf("%s",my_key);
					printf("Enter value\n");
					scanf("%s",my_value);
					int* ptr = &my_capacity;
					ha=hashmap_insert_array(ha,ptr,my_key,my_value);
					break;
				}
			
			}

		case 2:
			{
			if(isll == 1)
				{
					printf("Enter key to search\n");
					scanf("%s",my_key);
					res = hashmap_search_ll(my_key,h);
					if(res == -1)
						printf("Key is not present in HashMap\n");
					printf("Load Factor: %f\n",hashmap_loadfactor(h));			
					break;
					}
			else
				{
					printf("Enter key to search\n");
					scanf("%s",my_key);
					res=hashmap_search_array(ha,my_capacity,my_key);
					if(res == 0)
						printf("Key is not present in HashMap\n");
					
								
					break;
				}
			}
	
		case 3:
			{
			
			if(isll == 1)
				{
					printf("Enter key to delete\n");
					scanf("%s",my_key);
					res = hashmap_delete_ll(my_key,h);	
					if(res == -1)
						printf("Key is not present in HashMap\n");			
					printf("Load Factor: %f\n",hashmap_loadfactor(h));			
					break;
					}
			else
				{
					printf("Enter key to delete\n");
					scanf("%s",my_key);
					res = hashmap_delete_array(ha,my_capacity,my_key);
					if(res == 0)
						printf("Key is not present in HashMap\n");
					else 
						printf("Key is Deleted\n");					
					break;
					}			
			}
		
		}
	}
}
