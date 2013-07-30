#include <stdio.h>
#include "ht.h"
#include <stdlib.h>
#include <assert.h>

void test_ht_ctor(){
	ht_t* ht=ht_ctor(20);

	bucket_t* tmp=ht->bucket;
	tmp[0].data=1;
    tmp[1].data=2;


//	bucket_t* tmp=ht->bucket;
//	tmp->data=1;

	printf("ht->bucket->data: %i\n", (ht->bucket)->data);	
//    printf("ht->bucket->data: %i\n", (ht->bucket[1])->data);
 
    printf("ht->bucket->data: %i\n", (ht->bucket[1]).data);


    printf("ht->capacity: %i\n", ht->capacity);

//	assert(ht->bucket.data==1);//not helpful anymore
//    free(ht->bucket);
	free(ht);	
}

void test_ht_dtor(){
/*
    ht_t* ht=ht_ctor(20);
    (&(ht->bucket[1]))->data=1;

    assert((&(ht->bucket[1]))->data==1);//not helpful anymore
	ht_dtor(ht);
*/
}

void test_convert_mac_to_ip(){
    printf("test_convert_mac_to_ip(): \n");
	int32_t result;
	result = convert_mac_to_ip(0x0000000000000001);
	assert(result==0x00000001);
    result = convert_mac_to_ip(0x0000000000000002);
    assert(result==0x00000002);
    result = convert_mac_to_ip(0x0000000000000003);
    assert(result==0x00000003);
    result = convert_mac_to_ip(0x0000000000000004);
    assert(result==0x00000004);

    result = convert_mac_to_ip(0x0000FFFF00000004);
    assert(result==0x00000004);
}


void test_ht_insert(){
	
}

void test_ht_search(){
	
}

void test_ht_delete(){
	
}

int main(){
	test_ht_ctor();
    test_ht_dtor();
	test_convert_mac_to_ip();
	printf("end of main()! \n");	
	return 0;
}


