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

    list = addChild(list, newTag("test"));
    showChildren(list);

    list = addChild(list, newTag("test2"));
    showChildren(list);

    list = addChild(list, newTag("test3"));
    list->listChildren[2]->properties = addProperty(list->listChildren[2]->properties, "testp", "rien");
    list->listChildren[2]->properties = addProperty(list->listChildren[2]->properties, "testp2", "rien2");

    showChildren(list);

    list = removeChildById(list, 1);

    showChildren(list);

    freeChildren(list);
    list = addChild(list, newTag("test5"));

    showChildren(list);
    freeChildren(list);

    free(list);
    return 0;
}

