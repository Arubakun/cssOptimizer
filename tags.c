#include "tags.h"
#include <stdio.h>

p_tag newTag(char* name/*, properties pr, children c, tag p*/)
{
    p_tag tmp = malloc(sizeof(tag));
    tmp->name = name;
    tmp->properties = NULL;
    /*tmp->children = &c;
    tmp->parent = &p;*/

    return tmp;
}

p_children addChild(p_children c, p_tag n_tag) {

    p_tag tmp_tag = NULL;
    p_tag* tmp_list = NULL;

    if(c == NULL)
    {
        c = malloc(sizeof(children));
        c->length = 0;
    }
    c->length++;

    tmp_list = malloc(sizeof(p_tag)*(c->length));
    int i = 0; while(i<c->length)
    {
        tmp_tag = c->listChildren[i];
        tmp_list[i] = tmp_tag;
        i++;
    }

    tmp_list[c->length - 1] = n_tag;
    c->listChildren = tmp_list;

    free(tmp_tag);
    return c;
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

        j++;
    }

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

        j++;
    }

    c->listChildren = tmp_list;
    c->length--;
    return c;
}

p_children freeChildren(p_children c)
{
    int i = 0; while(i<c->length)
    {
        free(c->listChildren[i]->properties);
        free(c->listChildren[i++]);
    }
    free(c->listChildren);
    c->length = 0;

    printf("Fin\n");
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
