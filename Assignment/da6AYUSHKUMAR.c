
#include <stdio.h>
#include <stdlib.h>

struct TreeNode  //node of a binary tree
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode //node of a queue
{ 
    struct TreeNode *treeNode;
    struct QueueNode *next;
};


struct Queue //defining a queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};


struct TreeNode *createNode(int val) //creating node
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct QueueNode *createQueueNode(struct TreeNode *treeNode) //creating queue node
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

struct Queue *createQueue() //creating queue
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue *queue) //function to check if queue is empty
{
    return queue->front == NULL;
}

void enqueue(struct Queue *queue, struct TreeNode *treeNode)//enqueue treenode into queue
{
    struct QueueNode *newNode = createQueueNode(treeNode);
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// dequeue treenode from queue
struct TreeNode *dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;

    struct QueueNode *tempNode = queue->front;
    struct TreeNode *treeNode = tempNode->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(tempNode);
    return treeNode;
}
//construcitng the binary tree from level order traversal
struct TreeNode *constructTree(int levelOrder[], int size)
{
    if (size == 0 || levelOrder[0] == -1) //if the size is 0 or the first element is -1, return NULL
        return NULL;

    struct Queue *queue = createQueue();
    struct TreeNode *root = createNode(levelOrder[0]);
    enqueue(queue, root);

    int i = 1;
    while (i < size)
    {
        struct TreeNode *curnode = dequeue(queue);

        if (curnode == NULL)
        {
            i += 2;
            continue;
        }

        // Creating the left child
        if (levelOrder[i] != -1)
        {
            struct TreeNode *leftChild = createNode(levelOrder[i]);
            curnode->left = leftChild;
            enqueue(queue, leftChild);
        }
        else
        {
            curnode->left = NULL;
        }
        i++;

        // Creating the right child
        if (i < size && levelOrder[i] != -1)
        {
            struct TreeNode *rightChild = createNode(levelOrder[i]);
            curnode->right = rightChild;
            enqueue(queue, rightChild);
        }
        else
        {
            curnode->right = NULL;
        }
        i++;
    }

    return root;
}

// calculating the maximum amount of money the thief can robbed
int robbedamount(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = 0, right = 0;
    if (root->left != NULL)
        left = robbedamount(root->left->left) + robbedamount(root->left->right);
    if (root->right != NULL)
        right = robbedamount(root->right->left) + robbedamount(root->right->right);

    int robCurrent = root->val + left + right;
    int skipCurrent = robbedamount(root->left) + robbedamount(root->right);

    return (robCurrent > skipCurrent) ? robCurrent : skipCurrent;
}

int main()
{
    int levelOrder[100], n = 0;
    char temp;
    printf("Enter the array that is the level order traversal(Use -1 for null): ");
    while (temp != '\n')
    {
        scanf("%d%c", &levelOrder[n], &temp);
        n++;
    }

    // constructing the binary tree from the level order traversal
    struct TreeNode *root = constructTree(levelOrder, n);

    // Calculate the max amount 
    int maxAmount = robbedamount(root);

    // output
    printf("Maximum amount of money the thief can rob: %d\n", maxAmount);
    return 0;
}