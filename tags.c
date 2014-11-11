#include "tags.h"
#include <stdio.h>

p_tag newTag(char* name)
{
    p_tag tmp = malloc(sizeof(tag));
    tmp->name = name;
    tmp->properties = initProperties(tmp->properties);
    tmp->children = initChildren(tmp->children);

    return tmp;
}

p_children initChildren(p_children p) {

    p = malloc(sizeof(children));
    p->listChildren = NULL;
    p->length = 0;

    return p;
}

p_children getChildIdChildren(p_children c, int id) {
    if(id < 0 || id >= c->length) {return NULL;}
    return c->listChildren[id]->children;
}

p_children getChildren(p_tag t) {
    return t->children;
}

p_children appendChild(p_children c, p_tag n_tag) {
    p_tag* tmp_list = NULL;

    c->length++;

    tmp_list = malloc(sizeof(p_tag)*(c->length));
    if(c->listChildren != NULL)
    {
        int i = 0; while(i<c->length - 1)
        {
            tmp_list[i] = c->listChildren[i];
            i++;
        }

        free(c->listChildren);
    }

    tmp_list[c->length - 1] = n_tag;
    c->listChildren = tmp_list;

    return c;
}

p_tag getChildById(p_children c, int id) {
    if(id < 0 || id >= c->length) {return NULL;}
    return c->listChildren[id];
}

p_children removeChildById(p_children c, int id)
{
    p_tag*  tmp_list;
    p_tag   tmp_tag;

    tmp_list = malloc(sizeof(p_tag)*(c->length - 1));
    int i = 0, j = 0; while(j<c->length)
    {
        if(j != id)
        {
            tmp_tag = c->listChildren[j];
            tmp_list[i] = tmp_tag;
            i++;
        }

        else { free(c->listChildren[j]); }

        j++;
    }

    free(c->listChildren);
    c->listChildren = tmp_list;
    c->length--;
    return c;
}

p_children removeChildByName(p_children c, char* name)
{
    p_tag*  tmp_list;
    p_tag   tmp_tag;

    tmp_list = malloc(sizeof(p_tag)*(c->length - 1));
    int i = 0, j = 0; while(j<c->length)
    {
        if(c->listChildren[j]->name != name)
        {
            tmp_tag = c->listChildren[j];
            tmp_list[i] = tmp_tag;
            i++;
        }
        else
        {
            freeProperties(c->listChildren[j]);
            free(c->listChildren[j]);
        }

        j++;
    }

    free(c->listChildren);
    c->listChildren = tmp_list;
    c->length--;
    return c;
}

p_children freeChildren(p_children c)
{
    if(c != NULL) {
        int i = 0; while(i<c->length)
        {
            getChildIdProperties(c, i);
            freeProperties(getChildIdProperties(c, i));
            free(getChildIdProperties(c, i));
            free(c->listChildren[i++]);
        }
        free(c->listChildren);
        free(c);
    }
    return c;
}

p_children emptyChildren(p_children c)
{
    if(c != NULL) {
        int i = 0; while(i<c->length)
        {
            getChildIdProperties(c, i);
            freeProperties(getChildIdProperties(c, i));
            free(getChildIdProperties(c, i));
            free(c->listChildren[i++]);
        }
        free(c->listChildren);
        initChildren(c);
    }
    return c;
}

void showChildren(p_children c)
{
    int i = 0; while(i<c->length)
    {
        printf("tag %d = %s\n", i, c->listChildren[i]->name);
        i++;
    }

    printf("\n");
}
