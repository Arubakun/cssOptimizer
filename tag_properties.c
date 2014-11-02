#include "tag_properties.h"

p_properties addProperty(p_properties p, char* p_name, char* p_value)
{
    p_properties    tmp_p;
    char**          n_prop = malloc(sizeof(char*)*2);
    n_prop[0] = p_name;
    n_prop[1] = p_value;

    if(p == NULL)
    {
        printf("\t\tnew prop\n");
        p = malloc(sizeof(properties));
        p->nb = 0;
    }

    p->nb++;

    tmp_p = malloc(sizeof(char**)*(p->nb));

    int i = 0; while(i<p->nb)
    {
        tmp_p->listProps[i] = malloc(sizeof(char*)*2);
        tmp_p->listProps[i] = p->listProps[i];

        i++;
    }

    printf("\nDebut %i", i-1);
    tmp_p->listProps[p->nb-1] = malloc(sizeof(char*)*2);
    printf("\tname %s", n_prop[0]);
    tmp_p->listProps[p->nb-1] = n_prop;
    printf("\tFin\n");

    p = tmp_p;
    return p;
}
