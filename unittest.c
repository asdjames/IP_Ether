#include <stdio.h>
#include "ht.h"
#include <stdlib.h>
#include <assert.h>

void test_ht_ctor(){
	ht_t* ht=ht_ctor(20);

	bucket_t* tmp=ht->bucket;
	tmp[0].data=1;
    tmp[1].data=2;

	assert((ht->bucket)->data==1);
	assert((ht->bucket[0]).data==1);
	printf("ht->bucket->data: %i\n", (ht->bucket)->data);	

	assert((ht->bucket[1]).data==2); 
    printf("ht->bucket->data: %i\n", (ht->bucket[1]).data);

	assert(ht->capacity==20);
    printf("ht->capacity: %i\n", ht->capacity);

    ht_dtor(ht);
	printf("end of test_ht_ctor() -----\n");
}

void test_ht_dtor(){
    ht_t* ht=ht_ctor(20);

	bucket_t* tmp=ht->bucket;
    tmp[0].data=1;

	ht_dtor(ht);
    printf("end of test_ht_dtor() -----\n");
}

void test_convert_mac_to_ip(){
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
    printf("end of test_convert_mac_to_ip() -----\n");
}


void test_ht_insert(){
    ht_t* ht=ht_ctor(20);
	ht_insert(ht, 0, 0);
    ht_insert(ht, 1, 1);
    ht_insert(ht, 2, 2);
    ht_insert(ht, 3, 3);
    ht_insert(ht, 4, 4);
    ht_insert(ht, 5, 5);
    ht_insert(ht, 6, 6);
    ht_insert(ht, 7, 7);
    ht_insert(ht, 8, 8);
    ht_insert(ht, 9, 9);
    ht_insert(ht, 10,10);
    ht_insert(ht, 11,11);
    ht_insert(ht, 12,12);
    ht_insert(ht, 13,13);
    ht_insert(ht, 14,14);
    ht_insert(ht, 15,15);
    ht_insert(ht, 16,16);
    ht_insert(ht, 17,17);
    ht_insert(ht, 18,18);
    ht_insert(ht, 19,19);

	int i;
	for(i=0; i<20; i++){
		assert((ht->bucket[i]).data==i);
	}


    for(i=0; i<20; i++){
        printf("i: %i, content: %i \n", i, (ht->bucket[i]).data );
    }


    ht_dtor(ht);
    printf("end of test_ht_insert() -----\n");
}

void test_ht_search(){
    ht_t* ht=ht_ctor(20);
    ht_insert(ht, 0, 0);
    ht_insert(ht, 1, 1);
    ht_insert(ht, 2, 2);
    ht_insert(ht, 3, 3);
    ht_insert(ht, 4, 4);
    ht_insert(ht, 5, 5);
    ht_insert(ht, 6, 6);
    ht_insert(ht, 7, 7);
    ht_insert(ht, 8, 8);
    ht_insert(ht, 9, 9);
    ht_insert(ht, 10,10);
    ht_insert(ht, 11,11);
    ht_insert(ht, 12,12);
    ht_insert(ht, 13,13);
    ht_insert(ht, 14,14);
    ht_insert(ht, 15,15);
    ht_insert(ht, 16,16);
    ht_insert(ht, 17,17);
    ht_insert(ht, 18,18);
    ht_insert(ht, 19,19);

    int i;
    for(i=0; i<20; i++){
		int a=ht_search(ht, i);
        assert(a==i);
    }

    for(i=0; i<20; i++){
        int a=ht_search(ht, i);
        printf("i: %i, ht_search(): %i \n", i, a);
    }

    ht_dtor(ht);
    printf("end of test_ht_search() -----\n");	
}

void test_ht_delete(){
    ht_t* ht=ht_ctor(20);
    ht_insert(ht, 0, 0);
    ht_insert(ht, 1, 1);
    ht_insert(ht, 2, 2);
    ht_insert(ht, 3, 3);
    ht_insert(ht, 4, 4);
    ht_insert(ht, 5, 5);
    ht_insert(ht, 6, 6);
    ht_insert(ht, 7, 7);
    ht_insert(ht, 8, 8);
    ht_insert(ht, 9, 9);
    ht_insert(ht, 10,10);
    ht_insert(ht, 11,11);
    ht_insert(ht, 12,12);
    ht_insert(ht, 13,13);
    ht_insert(ht, 14,14);
    ht_insert(ht, 15,15);
    ht_insert(ht, 16,16);
    ht_insert(ht, 17,17);
    ht_insert(ht, 18,18);
    ht_insert(ht, 19,19);

    int i;
    for(i=0; i<20; i++){
    }

    ht_dtor(ht);
    printf("end of test_ht_delete() -----\n");
}

int main(){
	test_ht_ctor();
    test_ht_dtor();
	test_convert_mac_to_ip();
	test_ht_insert();
	test_ht_search();
	printf("end of main()! \n");	
	return 0;
}


