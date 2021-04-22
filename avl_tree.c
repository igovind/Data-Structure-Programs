#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

//NEw update
//defining node
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
    int balance;
};

//declaring functions
void inorder(struct node *ptr);
struct node *rotate_right(struct node *pptr);
struct node *rotate_left(struct node *pptr);
struct node *insert(struct node *pptr, int data);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_left_balance(struct node *pptr);
struct node *insert_right_balance(struct node *pptr);
struct node *del(struct node *pptr, int data);
struct node *del_left_check(struct node *pptr, int pshorter);
struct node *del_right_check(struct node *pptr, int pshorter);
struct node *del_left_balance(struct node *pptr);
struct node *del_right_balance(struct node *pptr);
void print_tree(struct node *ptr);
int main()
{

    int choice, key;
    struct node *root = NULL;
    while (1)
    {
        printf("AVL TREE\n\n");
        printf(" 1.INSERT\n");
        printf(" 2.TEST INSERT\n");
        printf(" 3.DELETE\n");
        printf(" 4.PRINT\n");
        printf(" 5.QUIT\n");
        printf("\n\n");
        printf(" Enter your choice....\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            root = insert(root, 5);
            root = insert(root, 10);
            root = insert(root, 15);
            root = insert(root, 20);
            root = insert(root, 25);
            root = insert(root, 30);
            root = insert(root, 6);
            root = insert(root, 12);
            root = insert(root, 35);
            root = insert(root, 26);
            root = insert(root, 40);
            break;
        case 3:
            printf("del\n");
            break;
        case 4:
            printf("print\n");
            print_tree(root);
            break;
        case 5:
            exit(1);
            break;

        default:
            printf("Incorrect choice\n");
            break;
        }
    }
    return 0;
}

struct node *insert(struct node *pptr, int data)
{
    static int taller;
    if (pptr == NULL)
    {
        pptr = (struct node *)malloc(sizeof(struct node));
        pptr->info = data;
        pptr->lchild = NULL;
        pptr->rchild = NULL;
        pptr->balance = 0;
        taller = TRUE;
    }
    else if (data < pptr->info)
    {
        pptr->lchild = insert(pptr->lchild, data);
        if (taller == TRUE)
            pptr = insert_left_check(pptr, &taller);
    }
    else if (data > pptr->info)
    {
        pptr->rchild = insert(pptr->rchild, data);
        if (taller == TRUE)
            pptr = insert_right_check(pptr, &taller);
    }
    else
    {
        printf("duplicate key");
        taller = FALSE;
    }
    return pptr;
}
struct node *insert_left_check(struct node *pptr, int *ptaller)
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = 1;
        break;
    case -1:
        pptr->balance = 0;
        *ptaller = FALSE;
        break;
    case 1:
        pptr = insert_left_balance(pptr);
        *ptaller = FALSE;
        break;
    }
    return pptr;
}
struct node *insert_right_check(struct node *pptr, int *ptaller)
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = -1;
        break;
    case 1:
        pptr->balance = 0;
        *ptaller = FALSE;
        break;
    case -1:
        pptr = insert_right_balance(pptr);
        *ptaller = FALSE;
    default:
        break;
    }
    return pptr;
}
struct node *insert_left_balance(struct node *pptr)
{
    struct node *aptr, *bptr;
    aptr = pptr->lchild;
    if (aptr->balance == 1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rotate_right(pptr);
    }
    else
    {
        bptr = aptr->rchild;
        switch (bptr->balance)
        {
        case -1:
            pptr->balance = 0;
            aptr->balance = 1;
            break;
        case 1:
            pptr->balance = -1;
            aptr->balance = 0;
            break;
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
            break;
        default:
            printf("Error in balancing 2");
            break;
        }
        bptr->balance = 0;
        pptr->lchild = rotate_left(aptr);
        pptr = rotate_right(pptr);
    }
    return pptr;
}
struct node *insert_right_balance(struct node *pptr)
{
    struct node *aptr, *bptr;
    aptr = pptr->rchild;
    if (aptr->balance == -1)
    {
        aptr->balance = 0;
        pptr->balance = 0;
        pptr = rotate_left(pptr);
    }
    else
    {
        bptr = aptr->lchild;
        switch (bptr->balance)
        {
        case -1:
            pptr->balance = 1;
            aptr->balance = 0;
            break;
        case 1:
            pptr->balance = 0;
            aptr->balance = -1;
            break;
        }
        bptr->balance = 0;
        pptr->rchild = rotate_right(aptr);
        pptr = rotate_left(pptr);
    }
    return pptr;
}
struct node *rotate_right(struct node *pptr)
{
    struct node *aptr;
    aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}
struct node *rotate_left(struct node *pptr)
{
    struct node *aptr;
    aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}
void print_tree(struct node *ptr)
{
    if (ptr == NULL)
        return;
    print_tree(ptr->lchild);
    printf("%d  ", ptr->info);
    print_tree(ptr->rchild);
}
// struct node *del(struct node *pptr,int data){}
// struct node *del_left_check(struct node *pptr,int pshorter){}
// struct node *del_right_check(struct node *pptr,int pshorter){}
// struct node *del_left_balance(struct node *pptr){}
// struct node *del_right_balance(struct node *pptr){}