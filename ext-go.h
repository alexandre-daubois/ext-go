#ifndef _EXTGO_H
#define _EXTGO_H

#include <php.h>

#define PHP_EXT_GO_VERSION "0.1.0"
#define PHP_EXT_GO_EXTNAME "ext_go"

extern zend_module_entry ext_go_module_entry;
void auto_register_ext_go();

#endif