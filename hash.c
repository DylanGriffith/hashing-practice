#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

#define DEFAULT_MAX_SIZE 3571
#define TRUE 1
#define FALSE 0

int slotNumber(Hash hash, Node node);

Hash newHash() {
    return newHashWithMaxSize(DEFAULT_MAX_SIZE);
}

Hash newHashWithMaxSize(int maxSize) {
    Hash hash = malloc(sizeof(struct hash));
    hash->nodes = malloc(maxSize *sizeof(Node));
    for(int i=0; i<maxSize; i++) {
        *(hash->nodes + i) = NULL;
    }
    hash->maxSize = maxSize;
    return hash;
}

int addToHash(Hash hash, Node node) {
    int position = slotNumber(hash, node);
    int i = position;
    Node *slot = NULL;
    for(i = position; i < hash->maxSize; i++) {
        slot = (hash->nodes + i);
        if(*slot == NULL) {
            break;
        }
    }
    if(*slot == NULL) {
        *slot = node;
        return TRUE;
    }else {
        return FALSE;
    }
}

int hashContains(Hash hash, Node node) {
    int position = slotNumber(hash, node);
    Node nodeAtPosition;
    int i;
    for(i = position; i < hash->maxSize; i++) {
        nodeAtPosition = *(hash->nodes + i);
        if(nodeAtPosition == NULL) {
            return FALSE;
        }else if(nodeEquals(node, nodeAtPosition)) {
            return TRUE;
        }
    }
    return FALSE;
}

int slotNumber(Hash hash, Node node) {
    int result = nodeHashKey(node) % hash->maxSize;
    return result;
}
