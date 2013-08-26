#include "ht.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

ht_t* ht_ctor(int capacity){
	ht_t* ht=malloc(sizeof(ht_t));
	ht->capacity=capacity;
	ht->bucket=malloc(sizeof(bucket_t)*capacity);
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

int ht_hash(int in){
	return in;
}

int32_t get_last_32_bit(int64_t in){
    int32_t result=0x00000000;
    int32_t last_32_bit=0xFFFFFFFF;
    result = in & last_32_bit;/*getting the last 4 bits*/
    return result;
}

/*function to convert from real mac to pseudo ip address

*/
int32_t convert_mac_to_ip(int64_t mac){
	int32_t result=get_last_32_bit(mac);
	return result;
}

/*for now, use IP as key, and store MAC in the table
@return: error code
0: normal
*/
int ht_insert(ht_t* ht, int IP, int MAC){
	/*for current version, IP is the index in hashtable*/
	int index=ht_hash(IP);
    bucket_t* tmp=ht->bucket;
	if(tmp[index].key==-1&&tmp->next==NULL){
    	tmp[index].data=MAC;
    	tmp[index].key=IP;
	}
	else{
		tmp=&(tmp[index]);
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

/*@return: return content in the hashtable
	return -1 if item not in backet
	return 2 if item not in the list
*/
int ht_search(ht_t* ht, int IP){
	int index=ht_hash(IP);
    bucket_t* tmp=ht->bucket;
//TODO better add check error cases as in delete()
	if(tmp[index].next==NULL){
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
	else{/*case for hash collision*/
		bucket_t* p=&(tmp[index]);	
		p=p->next;
		while(p!=NULL){
			if(p->key==IP){
				return p->data;
			}
			p=p->next;
		}
		return 2;
	}	
}

/*return type is for error and function condition report
  	@return 0: normal exit
	return -1: trying to delete a data not in the list for index (computed by hash function)
	return 2: only one element at given index, 
				but this is not the key that the program wants to delete
	return 3: reached the end of list, given key still not found
	return 4: reached end of function, which SHOULD NEVER HAPPEN
*/
//int ht_delete(ht_t* ht, int IP, int MAC){
int ht_delete(ht_t* ht, int key){
    int index=ht_hash(key);
    bucket_t* tmp=ht->bucket;
	
	bucket_t* p=&(tmp[index]);
    bucket_t* q=&(tmp[index]);

	if(tmp[index].key==-1){
		printf("ERROR: ht_delete(): trying to delete a data not in the list for index (computed by hash function) \n");
		return -1;
	}

	if(p->key!=-1&&p->next==NULL){/*this is very first element in the list for given index, dont need to free, because dtor will take care of this.*/
		if(p->key==key){
			p->key=-1;
			return 0;
		}
		else{
			return 2;
		}
	}
	else{
		p=p->next;
		while(p!=NULL){
			if(p->key==key){
				if(p->next==NULL){/*matching element being end of the list*/
					q->next=NULL;
					free(p);
					return 0;
				}
				else{
					q->next=p->next;
					free(p);
					return 0;
				}
			}
			q=p;
			p=p->next;
		}
		return 3;
	}
	return 4;
}


