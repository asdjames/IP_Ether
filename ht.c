#include "ht.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

ht_t* ht_ctor(int capacity){
	ht_t* ht=malloc(sizeof(ht_t));
	ht->capacity=capacity;
	ht->bucket=malloc(sizeof(bucket_t)*capacity);	//TODO temporary for debuggin
	/*TODO the for loop in ctor and dtor are not very efficient,
	 * maybe I could implement this differently to make this more efficient
	*/
	/*TODO check if ptr is initialized as NULL, if not specified*/
/*
	int i;
	for(i=0;i<capacity;i++){
        bucket_t* tmp=&(ht->bucket[i]);
		tmp->next=NULL;
	}
*/
	return ht;
}

void ht_dtor(ht_t* ht){
	/*free each collision list in bucket*/
	int capacity=ht->capacity;
/*
	int i;
    for(i=0;i<capacity;i++){
		bucket_t* pbucket=&(ht->bucket[i]);
		if(pbucket->next!=NULL){
			pbucket=pbucket->next;
			while(pbucket->next!=NULL){
				bucket_t* tmp=pbucket;
				pbucket=pbucket->next;
				free(tmp);
			}
		}
	}
*/
	free(ht->bucket);
	free(ht);
}

int ht_hash_mac(int mac){

}

int32_t get_last_32_bit(int64_t in){
    int32_t result=0x00000000;
    int32_t last_32_bit=0xFFFFFFFF;
    result = in & last_32_bit;/*getting the last 4 bits*/
    return result;
}

/*TODO create a user int48_t */
int32_t convert_mac_to_ip(int64_t mac){
	int32_t result=get_last_32_bit(mac);
	return result;
}

/*TODO for now, use MAC as key, and store IP in the table*/
/*return type is for error report*/
int ht_insert(ht_t* ht, int IP, int MAC){
	
}

/*return type is for error report*/
int ht_search(ht_t* ht, int key){
	
}

/*return type is for error report*/
int ht_delete(ht_t* ht, int IP, int MAC){
	
}


