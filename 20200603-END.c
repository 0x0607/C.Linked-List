#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------*/
struct node{
    int key;
    struct node *next;
};
typedef struct node node;
/*---------------------------------------------------------*/
node * insert(node *head,int key){
    node *p,*q,*r; //�u�@����
    p=(node *)malloc(sizeof(node));
    p->key=key;
    p->next=NULL;
    if(head==NULL){head=p;return head;}
    if(head->key>p->key){p->next=head; head=p;}
    q=head;r=q;
    while(q!=NULL&&q->key<=p->key){r=q;q=q->next;}
    r->next=p;
    p->next=q;
    return head;}
/*---------------------------------------------------------*/
void print_node(node *head){
    node *p;
    p=head;
    while(p!=NULL){printf("%4d",p->key);p=p->next;}
    printf("\n");
return ;}
/*---------------------------------------------------------*/
int count_node(node *head){
    node *p;
    int i=0;
    p=head;
    while(p!=NULL){p=p->next;i++;}
    printf("\n");
return i;}
/*---------------------------------------------------------*/
node *delete_node(node *head, int key){
    node *q,*p,*r;
    if(!head){printf("��ƭȤ��s�b");return head;}
    p=head;
    if(head->key==key){head=head->next;free(p);return head;}
    q=p;
    while(p&&p->key<key){
        q=p;
        p=p->next;}
    if(p&&p->key==key){
        q->next=p->next;
        free(p);
        return head;}
    else{printf("�䤣���\"%d\" �нT�{��J�ȬO�_�T\n",key);}
    return head;
}
/*---------------------------------------------------------*/
int main(){
    node *head=NULL;
    int input=0;
    int opt=0;
    while(1){
        printf("| 1. ���J��%8s2. �C�X��%8s3. �R����|","","");
        printf("\n==============================================\n");
        printf("����J���O:");
        scanf("%d",&opt);
        switch(opt){
            case 1:     //insert
                printf("/insert ");
                scanf("%d",&input);
                head=insert(head,input);
                printf("node[%d]: ",count_node(head));
                print_node(head);
                break;
            case 2:     //print
                printf("/show \n");
                printf("node[%d]: ",count_node(head));
                print_node(head);

            break;
            case 3:     //insert
                printf("/delete ");
                scanf("%d",&input);
                head=delete_node(head,input);
                printf("node[%d]: ",count_node(head));
                print_node(head);
                break;
            default:system("cls");break;
        }
    printf("\n\n==============================================\n");}



return 0;}
