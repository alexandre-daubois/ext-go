#ifndef _EXTGO_H
#define _EXTGO_H

typedef struct go_string {
  size_t len;
  char *data;
} go_string;

void register_extension();
void cleanup_go_string(go_string*);

#endif
