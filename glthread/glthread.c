#include "glthread.h"

void init_glthread(glthread_t *glist, unsigned int offset)
{

    // error handling and initialization
    if(glist)
    {
        glist->head = NULL;
        glist->offset = offset;
    }
}

void  glthread_add(glthread_t *glist, glthread_node_t *glnode)
{
    glthread_node_t *ptr;

    // error handling
    if (glist == NULL || glnode == NULL)
    {
        printf("gEither glist or glnode is null\n");
        return;
    }

    // If list is empty assign the mode to head 
    // else assign to last node of the list
    glnode->right = NULL;
    if (glist->head == NULL) 
    {
        glnode->left = NULL;
        glist->head = glnode;
    } 
    else
    {
        ptr = glist->head;
        while (ptr->right != NULL)
        {
            ptr = ptr->right;
        }
        ptr->right = glnode;
        glnode->left = ptr;
    }
}


void glthread_remove(glthread_t *glist, glthread_node_t *glnode)
{
    glthread_node_t *head = glist->head, *left, *right;

    //error handling
    if(!glnode)
        return;

    // if node is head of the list
    if(glnode == head)
    {
        glist->head = head->right;
        glist->head->left = NULL;
    }
    else
    {

        left = glnode->left;
        right = glnode->right;
        if (left)
            left->right = glnode->right;
        if(right)
            right->left = glnode->left;
    }
}

