#include "tags_functions.h"

p_children matchTwinChildren(p_children c, char* t_name) {

    p_properties p1, p2;
    int id1 = -1;
    int i = 0; while(i < c->length)
    {
        if( c->listChildren[i]->name == t_name )
        {
            if(id1 == -1)   { id1 = i; p1 = getChildIdProperties(c, id1);}
            else
            {
                p2 = getChildIdProperties(c, i);
                regroupProperties(p1, p2);

                removeChildById(c, i--);
            }
        }
        i++;
    }
    matchTwinProperties(getChildIdProperties(c, id1));

    return -1;
}

p_properties regroupProperties(p_properties p1, p_properties p2) {

    char*** tmp_list = malloc(sizeof(char**)*(p1->length+p2->length));

    int i = 0; while(i<p1->length)
    {
        tmp_list[i] = p1->listProps[i];
        i++;
    }

    i = 0; while(i<p2->length)
    {
        tmp_list[p1->length + i] = p2->listProps[i++];
    }

    free(p1->listProps);
    p1->listProps = tmp_list;
    p1->length += p2->length;

    return p1;
}

p_properties matchTwinProperties(p_properties p) {

    int i = 0, j; while(i<p->length-1)
    {
        j = i+1; while(j<p->length)
        {
            if(p->listProps[i][0] == p->listProps[j][0])
            {
                p->listProps[i][1] = p->listProps[j][1];
                p = removePropertyById(p, j--);
            }
            j++;
        }
        i++;
    }

    return p;
}

p_properties factorizeProperties(p_children c) {

    p_properties tmp = initProperties(tmp);

    int i = 0, j, k, t = 0;
    p_properties tmp_p = NULL;

    while(i<c->length)   { regroupProperties(tmp, getChildIdProperties(c, i++)); }
    matchTwinProperties(tmp);

    printf("PROPS FACTORIZE\n");
    showProperties(tmp);

    i = 0; while(i<tmp->length)
    {
        j = 0; while(j<c->length)
        {
            k = t = 0;
            tmp_p = getChildIdProperties(c, j);

            k = 0; while(k < tmp_p->length)
            {
                printf("\t%s %s\n", tmp->listProps[i][0], tmp_p->listProps[k][0]);
                if(tmp->listProps[i][0] == tmp_p->listProps[k][0] && tmp->listProps[i][1] == tmp_p->listProps[k][1])
                {
                    t++;
                }

                k++;
            }

            printf("\t\tt: %d\n", t);

            j++;
        }
        i++;
    }

    free(tmp_p);
    return tmp;
}
