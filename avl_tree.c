#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
//defining node 
struct node{
struct node *lchild;
int info;
struct node *rchild;
int balance;
};
//declaring functions 
void inorder(struct node *ptr);
struct node *rotate_right(struct node *pptr);
struct node *rotate_left(struct node *pptr);
struct node *insert(struct node *pptr,int data);
struct node *insert_left_check(struct node *pptr,int ptaller);
struct node *insert_right_check(struct node *pptr,int ptaller);
struct node *insert_left_balance(struct node *pptr);
struct node *insert_right_balance(struct node *pptr);
struct node *del(struct node *pptr,int data);
struct node *del_left_check(struct node *pptr,int pshorter);
struct node *del_right_check(struct node *pptr,int pshorter);
struct node *del_left_balance(struct node *pptr);
struct node *del_right_balance(struct node *pptr);
int main(){
    printf("AVL TREE\n\n\n");
    int choice,key;
    struct node *root=NULL;
    while(1){
        printf("\n\n");
        printf(" 1.INSERT\n");
        printf(" 2.TEST INSERT\n");
        printf(" 3.DELETE\n");
        printf(" 4.P1RINT\n");
        printf(" 5.QUIT\n");
        printf("\n\n");
        printf(" Enter your choice....\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("insert\n");
            break;
        case 2:
            printf("test insert");
            break;
        case 3:
            printf("del\n");
            break;
        case 4:
            printf("print\n");
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
// void inorder(struct node *ptr){}
// struct node *rotate_right(struct node *pptr){}
// struct node *rotate_left(struct node *pptr){}
// struct node *insert(struct node *pptr,int data){}
// struct node *insert_left_check(struct node *pptr,int ptaller){}
// struct node *insert_right_check(struct node *pptr,int ptaller){}
// struct node *insert_left_balance(struct node *pptr){}
// struct node *insert_right_balance(struct node *pptr){}
// struct node *del(struct node *pptr,int data){}
// struct node *del_left_check(struct node *pptr,int pshorter){}
// struct node *del_right_check(struct node *pptr,int pshorter){}
// struct node *del_left_balance(struct node *pptr){}
// struct node *del_right_balance(struct node *pptr){}