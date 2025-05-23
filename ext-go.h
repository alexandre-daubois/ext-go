#ifndef _EXTGO_H
#define _EXTGO_H

typedef struct go_string {
  size_t len;
  char *data;
} go_string;

PHP_FUNCTION(go_print);

#endif