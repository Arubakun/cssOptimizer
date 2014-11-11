#ifndef TAGS_H_INCLUDED
#define TAGS_H_INCLUDED

typedef struct properties properties;
typedef struct properties* p_properties;
typedef struct p_tag* children;
typedef struct children* p_children;
typedef struct tag tag;
typedef struct tag* p_tag;

struct properties
{
    int     length;
    char*** listProps;
};

struct tag
{
    char*           name;
    p_properties    properties;
    p_children      children;
};

struct children
{
    int     length;
    p_tag*  listChildren;
};

p_children initChildren(p_children);
p_tag newTag(char*/*, properties, children, tag*/);
p_children appendChild(p_children, p_tag);
p_tag getChildById(p_children, int);
p_children removeChildById(p_children, int);
p_children removeChildByName(p_children, char*);
p_children freeChildren(p_children);
void showChildren(p_children);

#endif


