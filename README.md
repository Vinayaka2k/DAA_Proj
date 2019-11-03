# DAA_Proj
Implementing HASHMAP using linked-lists and arrays

    1. NAME AND SRN :
PES1201701634 :  P SUDHAMSHU RAO
PES1201701600 :  VINAYAKA M HEGDE

    2. TOPIC : HASHMAPS

    3. PROPOSAL : 

OVERVIEW OF HASHMAP:
HashMap is a Map based collection class that is used for storing Key & value pairs,
The purpose of a map is to store items based on a key that can be used to retrieve the item at a later point. 

PROPERTIES:
    1. Contains unique keys.
    2. The order of retrieval is not guaranteed. i.e., order of retrieval is not same as the order in which elements get into the hashmap.
    3. The value can be retrieved using the key.



IMPLEMENTATION:
Hash map implemented by a linked list and an array. The user can choose the implementation. Each node of linked list consists of four parts : hash value, key ,value and address of the next node. If the load factor of array increases above a certain value, then we rehash and continue. Keys and values will be taken strings and hashed to integers  

FUNCTIONS:
1. INSERT : Inserts a new key-value pair to hash map.
2. DELETE : deletes a key-value pair from the hashmap.
3. UPDATE : updates the value based on the given key.
4. HASH : function to hash the input string to an integer and handle collissions.
5. SEARCH : search for the given key and gives the corresponding value. If key is not present, returns -1.
