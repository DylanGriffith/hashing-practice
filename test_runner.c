#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "hash.h"

void runTests(void);
void runTest1(void);
void runTest2(void);
void runTest3(void);
void runTest4(void);
void runTest5(void);
void runTest6(void);
void runTest7(void);
void runTest8(void);

int main(void) {
    runTests();
    return 0;
}

void runTests(void) {
    runTest1();
    runTest2();
    runTest3();
    runTest4();
    runTest5();
    runTest6();
    runTest7();
    runTest8();
    printf("All tests passed!!!\n");
}

void runTest1(void) {
    printf("Running test 1: Node works\n");
    Node myNode = malloc(sizeof(struct node));
    assert(myNode != NULL);
    myNode->data = 5;
    assert(myNode->data == 5);
    printf("passed\n");
}

void runTest2(void) {
    printf("Running test 2: Hash works\n");
    Hash myHash = malloc(sizeof(struct hash));
    assert(myHash != NULL);
    printf("passed\n");
}

void runTest3(void) {
    printf("Running test 3: nodeEquals\n");
    Node myNode1 = malloc(sizeof(struct node));
    Node myNode2 = malloc(sizeof(struct node));
    Node myNode3 = malloc(sizeof(struct node));
    myNode1->data = 5;
    myNode2->data = 5;
    myNode3->data = 4;
    assert(nodeEquals(myNode1, myNode2));
    assert(!nodeEquals(myNode1, myNode3));
    printf("passed\n");
}

void runTest4(void) {
    printf("Running test 4: nodeHashKey\n");
    Node myNode = malloc(sizeof(struct node));
    myNode->data = 7;
    assert(nodeHashKey(myNode) == 7);
    printf("passed\n");
}

void runTest5(void) {
    printf("Running test 5: newHash\n");
    Hash hash = newHash();
    assert(hash != NULL);
    printf("passed\n");
}

void runTest6(void) {
    printf("Running test 6: newHashWithMaxSize(1000)\n");
    Hash hash = newHashWithMaxSize(1000);
    assert(hash != NULL);
    printf("passed\n");
}

void runTest7(void) {
    printf("Running test 7: addToHash AND hashContains\n");
    Hash hash = newHashWithMaxSize(1000);
    Node node = newNode(55555);
    Node node2 = newNode(56655);
    assert(hash != NULL);
    addToHash(hash, node);
    assert(hashContains(hash, node));
    assert(!hashContains(hash, node2));
    printf("passed\n");
}

void runTest8(void) {
    printf("Running test 8: addToHash AND hashContains with possible collision\n");
    Hash hash = newHashWithMaxSize(1000);
    Node node = newNode(55555);
    Node node2 = newNode(65555);
    assert(hash != NULL);
    addToHash(hash, node);
    assert(hashContains(hash, node));
    assert(!hashContains(hash, node2));
    addToHash(hash, node2);
    assert(hashContains(hash, node));
    assert(hashContains(hash, node2));
    printf("passed\n");
}
