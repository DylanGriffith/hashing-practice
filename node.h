typedef struct node {
    int data;
}* Node;

int nodeEquals(Node node, Node other);
int nodeHashKey(Node node);
Node newNode(int data);
