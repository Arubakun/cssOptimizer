#ifndef TAG_PROPERTIES_H_INCLUDED
#define LIST_H_INCLUDED

#include "tags.h"
#include <stdio.h>

p_properties getChildIdProperties(p_children c, int id);
void showProperties(p_properties p);
p_properties appendProperty(p_properties p, char* p_name, char* p_value);
p_properties removePropertyById(p_properties p, int id);
p_properties freeProperties(p_properties p);

#endif // TAG_PROPERTIES_H_INCLUDED

