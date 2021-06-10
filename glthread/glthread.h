
#ifndef __GLTHREAD__
#define __GLTHREAD__

#include <stdio.h>
#include <stdlib.h>

#define offsetof(struct_name, field_name) (unsigned int)&((struct_name*)0)->field_name

typedef struct glthread_node_ {
    struct glthread_node_ *left;
    struct glthread_node_ *right;
} glthread_node_t;

typedef struct glthread_ {
    glthread_node_t *head;
    unsigned int offset;
} glthread_t;


void init_glthread(glthread_t *glist, unsigned int offset);

void glthread_add(glthread_t *glist, glthread_node_t *glnode);

void glthread_remove(glthread_t *glist, glthread_node_t *glnode);

#endif

