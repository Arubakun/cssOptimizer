#include "main.h"

char* my_striconcat(char* v1, char* v2, int start) {

    int i;
    char* p=malloc(sizeof(char)*(start + strlen(v2) +1));
    p[start + strlen(v2)]='\0';

    for(i=0;i<start;i++){
        p[i]=v1[i];
    }

    for(i=start;i<start + strlen(v2);i++){
        p[i]=v2[i-start];
    }

    return p;
}

int main()
{
    p_children list = NULL;
    p_properties p1 = NULL, p2 = NULL;
    p_tag t1 = NULL;

    list = initChildren(list);
    appendChild(list, newTag("test"));
    appendChild(list, newTag("test2"));
    appendChild(list, newTag("test3"));
    appendChild(list, newTag("test2"));

    showChildren(list);

    t1 = getChildIdChildren(list, 0);
    appendChild(t1, newTag("test_1"));
    appendChild(t1, newTag("test_1"));

    showChildren(t1);

    p1 = getChildIdProperties(list, 1);
    appendProperty(p1, "p1", "v1");

    p2 = getChildIdProperties(list, 3);
    appendProperty(p2, "p2", "v2");
    appendProperty(p2, "p1", "v3");
    appendProperty(p2, "p1", "v1");
    appendProperty(p2, "p2", "v2");
    appendProperty(p2, "p3", "v3");

    matchTwinChildren(list, "test2");
    factorizeProperties(list);
    showChildren(list);

    freeChildren(list);
    free(p1); free(p2);

    return 0;
}

