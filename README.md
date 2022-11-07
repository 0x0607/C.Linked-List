
## 連結串列範本 zh_TW
1. 插入值(排序依據 `number`)
2. 印出表
3. 刪除值

## Linked-List Example en_US
1. Insert (sort by `number`)
2. Print table
3. Delete   
```c
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
```
