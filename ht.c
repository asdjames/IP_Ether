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
	int i;
	for(i=0;i<capacity;i++){
        bucket_t* tmp=&(ht->bucket[i]);
		tmp->next=NULL;
		tmp->key=-1;
	}
	return ht;
}

void ht_dtor(ht_t* ht){
	/*free each collision list in bucket*/
	int capacity=ht->capacity;
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
	free(ht->bucket);
	free(ht);
}

/* hashing seudo ip
TODO current version is static hashtable, one-to-one mapping, and no hash collision
*/

/*
TODO plan of implementation:
1. dynamic ht: assume uniform distribution: simple mod by capacity
2. dynamic ht: assume lower bits are more used: based on capcity, use the number lower bits starting from the lowest bits
3. dynamic ht/static ht: assume lower bits are more used: use one-to-one mapping. if static, the size has to be 2^32. if dynamic, will increase the ht when needed.
*/
int ht_hash(int in){
	return in;
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

/*for now, use IP as key, and store MAC in the table
@return: error code
0: normal
*/
int ht_insert(ht_t* ht, int IP, int MAC){
	/*TODO for current version, IP is the index in hashtable*/
	int index=ht_hash(IP);
    bucket_t* tmp=ht->bucket;
	if(tmp[index].key==-1&&tmp->next==NULL){
    	tmp[index].data=MAC;
    	tmp[index].key=IP;
	}
	else{
		tmp=&(tmp[index]);//TODO this syntax might be wrong. might need the macro I used to get the specific area of a C struct
		while(tmp->key!=-1&&tmp->next!=NULL){
			if(tmp->key!=-1&&tmp->next==NULL){
				tmp->next=malloc(sizeof(bucket_t));	
				tmp=tmp->next;
				/*update the values*/
				tmp->data=MAC;
        		tmp->key=IP;
				tmp->next=NULL;
				return 0;
			}
			tmp=tmp->next;
		}
	}

	return 0;
}

/*TODO need to decide if function will return the content OR just if the item is in ht*/
    //TODO actually, if hash collision happens, there would be a list of results, and I cannot tell which one is correct 
/*@return: return content in the hashtable
	return -1 if item not in hashtable
*/

int ht_search(ht_t* ht, int IP){
	int index=ht_hash(IP);
    bucket_t* tmp=ht->bucket;

	if(tmp[index].next==NULL){
		int returnTmp;
    	bucket_t* tmp=ht->bucket;
    	int data=tmp[index].data;
        int key=tmp[index].key;

		if(key==IP){
			return data;
		}
		else{
			//printf("warning: ht_search: value not found\n");
			return -1;
		}
	}
	else{
		printf("warning:  ht_search: there is hash collision for given key: %i \n", IP);
	}	
}

/*return type is for error report*/
//int ht_delete(ht_t* ht, int IP, int MAC){
int ht_delete(ht_t* ht, int IP){
    int index=ht_hash(IP);
    bucket_t* tmp=ht->bucket;
	
	bucket_t* p=tmp[index].next;
    bucket_t* q=&(tmp[index]);//TODO check this syntax if there is a bug


	while(p!=NULL){


	}		

}


