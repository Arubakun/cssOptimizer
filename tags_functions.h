#ifndef TAGS_FUNCTIONS_H_INCLUDED
#define TAGS_FUNCTIONS_H_INCLUDED

#include "main.h"

p_children matchTwinChildren(p_children, char*);
p_properties regroupProperties(p_properties, p_properties);
p_properties matchTwinProperties(p_properties);
p_properties factorizeProperties(p_children);

#endif // TAGS_FUNCTIONS_H_INCLUDED
