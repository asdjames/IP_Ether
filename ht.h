#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>

typedef struct bucket{
	int data;
	struct bucket* next;
}bucket_t;


typedef struct ht{
    int count; /*count the number of buckets being used; 
	            TODO dont need this for static ht
				For dynamic ht, will need to update this*/	
    int capacity;/*number of buckets*/

    /*array holding value*/
	bucket_t* bucket;/*TODO For array in C, ther is a limit of how many elements could be stored. not sure if this would affect me*/
}ht_t;


ht_t* ht_ctor(int capacity);

void ht_dtor(ht_t* ht);

int32_t convert_mac_to_ip(int64_t mac);

/*TODO for now, only store IP address, and use MAC to look up and search*/
/*return type is for error report*/
int ht_insert(ht_t* ht, int IP, int MAC);

/*return type is for error report*/
int ht_search(ht_t* ht, int key);

/*return type is for error report*/
int ht_delete(ht_t* ht, int IP, int MAC);

#endif
