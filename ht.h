#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>


/*this is a hashtable, that stores mac address, 
*and uses seudo ip address to look up the mac address.
the seudo ip address is just last 32 bit of mac address
If the size of capacity of hashtable is initialized to 2^32, 
the hashtable would not need to be expanded. 
The reason is that hash function in this case would be a perfect hash fucntion,
because there would be a one-to-one mapping of seudo ip and mac address.
*/

typedef struct bucket{
	int data;
	int key; /*ip would be the key here. -1 would be uninialized*/
	struct bucket* next;
}bucket_t;


typedef struct ht{
    int count; /*count the number of buckets being used; 
	            TODO dont need this for static ht
				For dynamic ht, will need to update this*/	
    int capacity;/*number of buckets*/

    /*array holding value*/
	bucket_t* bucket;
}ht_t;


ht_t* ht_ctor(int capacity);

void ht_dtor(ht_t* ht);

int32_t convert_mac_to_ip(int64_t mac);

/*return type is for error report*/
int ht_insert(ht_t* ht, int key, int MAC);

/*return type is for error report*/
int ht_search(ht_t* ht, int key);

/*return type is for error report*/
int ht_delete(ht_t* ht, int key);

#endif
