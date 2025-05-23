#ifndef _EXTGO_H
#define _EXTGO_H

#include <php.h>

extern zend_module_entry ext_go_module_entry;

#define phpext_ext_go_ptr &ext_go_module_entry

#define PHP_EXT_GO_VERSION "0.1.0"
#define PHP_EXT_GO_EXTNAME "ext_go"

#endif