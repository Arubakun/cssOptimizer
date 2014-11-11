#include "tag_properties.h"

p_properties getChildIdProperties(p_children c, int id) {
    if(id < 0 || id >= c->length) {return NULL;}
    return c->listChildren[id]->properties;
}

p_properties getProperties(p_tag t) {
    return t->properties;
}

void showProperties(p_properties p)
{
    int i = 0; while(i<p->length)
    {
        printf("property %s = %s\n", p->listProps[i][0], p->listProps[i][1]);
        i++;
    }

    printf("\n");
}

p_properties initProperties(p_properties p) {

    p = malloc(sizeof(properties));
    p->length = 0;
    p->listProps = NULL;

    return p;
}

p_properties appendProperty(p_properties p, char* p_name, char* p_value)
{
    char*** tmp_p;

    p->length++;
    tmp_p = malloc(sizeof(char**)*(p->length));

    int i = 0; while(i<p->length-1)
    {
        tmp_p[i] = malloc(sizeof(char*)*2);
        tmp_p[i] = p->listProps[i++];
    }

    tmp_p[p->length-1] = malloc(sizeof(char*)*2);
    tmp_p[p->length-1][0] = p_name;
    tmp_p[p->length-1][1] = p_value;

    free(p->listProps);
    p->listProps = tmp_p;

    return p;
}

p_properties removePropertyById(p_properties p, int id)
{
    char***  tmp_list;

    tmp_list = malloc(sizeof(char**)*(p->length - 1));
    int i = 0, j = 0; while(j<p->length)
    {
        if(j != id)
        {
            tmp_list[i] = p->listProps[j];
            i++;
        }

        else { free(p->listProps[j]); }

        j++;
    }

    free(p->listProps);
    p->listProps = tmp_list;
    p->length--;
    return p;
}

p_properties removePropertyByName(p_properties p, char* name)
{
    char***  tmp_list;

    tmp_list = malloc(sizeof(char**)*(p->length - 1));
    int i = 0, j = 0; while(j<p->length)
    {
        if(p->listProps[j][0] != name)
        {
            tmp_list[i] = p->listProps[j];
            i++;
        }
        else { free(p->listProps[j]); }

        j++;
    }

    free(p->listProps);
    p->listProps = tmp_list;
    p->length--;
    return p;
}

p_properties freeProperties(p_properties p)
{
    if(p != NULL) {
        int i = 0; while(i < p->length)
        {
            free(p->listProps[i][0]);
            free(p->listProps[i][1]);
            free(p->listProps[i++]);
        }

        p->length = 0;
        free(p->listProps);
        free(p);
    }

    return p;
}
