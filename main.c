#include <stdio.h>
#include <stdlib.h>
/*---------------------------------------------------------*/
struct value{
    int number;
    char str[64];
};
typedef struct value value;
struct node{
    struct value key;
    struct node *next;
};
typedef struct node node;
/*---------------------------------------------------------*/
node * insert(node *head,value key){
    node *p,*q,*r; //工作指標
    p=(node *)malloc(sizeof(node));
    p->key=key;
    p->next=NULL;
    if(head==NULL){head=p;return head;}
    if(head->key.number>p->key.number){p->next=head; head=p;}
    q=head;r=q;
    while(q!=NULL&&q->key.number<=p->key.number){r=q;q=q->next;}
    r->next=p;
    p->next=q;
    return head;}
/*---------------------------------------------------------*/
void print_node(node *head){
    node *p;
    p=head;
    //printf("\n%s %s","Number","String");
    while(p!=NULL){
        //printf("\n");
        printf("{%d,%s} ",p->key.number,p->key.str);
        p=p->next;}
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
node *delete_node(node *head, value key){
    node *q,*p,*r;
    if(!head){printf("\nData does not exist");return head;}
    p=head;
    if(head->key.number==key.number){head=head->next;free(p);return head;}
    q=p;
    while(p&&p->key.number<key.number){
        q=p;
        p=p->next;}
    if(p&&p->key.number==key.number){
        q->next=p->next;
        free(p);
        return head;}
    else{printf("Could not find value\"%d\" \nPlease confirm the value is correct\n",key.number);}
    return head;
}
/*---------------------------------------------------------*/
int main(){
    node *head=NULL;
    value input;
    int opt=0;
    int i=0,j=0;
    while(1){
        printf("|1. insert %8s2. show table%8s3. delete|","","");
        printf("\n==============================================\n");
        printf("> ");
        scanf("%d",&opt);
        switch(opt){
            case 1:     //insert
                printf("/insert --number ");
                scanf("%d",&input.number);
                printf("%8s--string "," ");
                scanf("%s",input.str);
                head=insert(head,input);
                printf("node[0:%d]: ",count_node(head));
                print_node(head);
                break;
            case 2:     //print
                printf("\n- Sort by Number -\n");
                printf("/show \n");
                printf("node[%d]: ",count_node(head));
                print_node(head);
                break;
            case 3:     //insert
                printf("/delete --number ");
                scanf("%d",&input);
                head=delete_node(head,input);
                printf("node[%d]: ",count_node(head));
                print_node(head);
                break;
            default:system("cls");break;
        }
    printf("\n\n==============================================\n");}
return 0;}
