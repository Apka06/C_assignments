#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int data;
    int parent_data;
    char which_child;
    struct node * right_child;
    struct node * left_child;
};
struct node * root = NULL;

void insert(struct node ** root, int id, int data){
    char left = 'L';
    char right = 'R';
    struct node * ptr = NULL;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->id = id;
    newnode -> data = data;
    if(*root == NULL){
        *root = newnode;
    }
    else{
        ptr = *root;
        while(ptr -> left_child != NULL || ptr->right_child != NULL){
            if (ptr->data > newnode ->data){
                if(ptr->left_child == NULL){
                    break;
                }
                ptr = ptr ->left_child;
            }
            else{
                if(ptr->right_child == NULL){
                    break;
                }
                ptr = ptr->right_child;
            }
        }
        if (ptr -> data > newnode -> data){
            if(ptr->left_child == NULL){
                newnode ->which_child = left;
                newnode->parent_data = ptr->data;
                ptr->left_child = newnode;
            }
            else{
                ptr = ptr -> left_child;
                if(ptr -> data > newnode -> data){
                    newnode ->which_child = left;
                    newnode->parent_data = ptr->data;
                    ptr->left_child = newnode;
                }
                else{
                    newnode ->which_child = right;
                    newnode->parent_data = ptr->data;
                    ptr->right_child = newnode;
                }
            }
        }
        else{
            if(ptr->right_child == NULL){
                newnode ->which_child = right;
                newnode->parent_data = ptr->data;
                ptr->right_child = newnode;
            }
            else{
                ptr = ptr -> right_child;
                if(ptr -> data > newnode -> data){
                    newnode ->which_child = left;
                    newnode->parent_data = ptr->data;
                    ptr->left_child = newnode;
                }
                else{
                    newnode ->which_child = right;
                    newnode->parent_data = ptr->data;
                    ptr->right_child = newnode;
                }
            }
        }
    }
}

int level_counter(struct node* root){
    if(root != NULL){
        int left_depth = 1 + level_counter(root->left_child);
        int right_depth = 1 + level_counter(root->right_child);
        if (left_depth < right_depth){
            return right_depth;
        }
        return left_depth;
    }
}

void level_printer(struct node* root, int depth){
    int old_depth;
    if (root != NULL && depth == 0){
        if (root->which_child == '\0'){
            printf("\n%d %d",root->id, root->data);
        }
        else{ 
            printf("%d %d (%d %c) ",root->id, root->data, root->parent_data, root->which_child);
        }
    }
    else if(root != NULL){
        level_printer(root->left_child, depth - 1);
        level_printer(root->right_child, depth - 1);
    }
}

void print_tree(struct node* root){
    int depth = level_counter(root);
    for (int i = 0; i < depth; i++)
    {
        level_printer(root, i);
        printf("\n");
    }
}

void in_order(struct node* root){
    if(root != NULL){
        in_order(root->left_child);
        printf("%d %d\n",root->id ,root->data);
        in_order(root->right_child);
    }
}

int main(){
    int id, grade;
    scanf("%d", &id);
    scanf("%d", &grade);
    while(id != -1){
        insert(&root, id, grade);
        scanf("%d", &id);
        if(id == -1){break;}
        scanf("%d", &grade);
    }
    in_order(root);
    print_tree(root);
}
