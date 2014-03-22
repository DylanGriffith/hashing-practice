#include "node.h"

typedef struct hash {
    Node *nodes;
    int maxSize;
}* Hash;

Hash newHash();
Hash newHashWithMaxSize(int maxSize);
int addToHash(Hash hash, Node node);
int hashContains(Hash hash, Node node);
