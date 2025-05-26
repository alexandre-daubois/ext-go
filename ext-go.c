#include <php.h>
#include <ext/standard/info.h>

#include "ext-go.h"
#include "ext-go_arginfo.h"
#include "_cgo_export.h"
#include "ext/standard/info.h"
#include "zend_API.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    if (zend_parse_parameters_none() == FAILURE) {
        RETURN_THROWS();
    }

    go_print_something();
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(ext_go)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(ext_go)
{
    return SUCCESS;
}
/* }}} */

/* {{{ ext_go_module_entry */
zend_module_entry ext_go_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_EXT_GO_EXTNAME,
    ext_functions,          /* Functions */
    PHP_MINIT(ext_go),      /* MINIT */
    PHP_MSHUTDOWN(ext_go),  /* MSHUTDOWN */
    NULL,                   /* RINIT */
    NULL,                   /* RSHUTDOWN */
    NULL,      /* MINFO */
    PHP_EXT_GO_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

void auto_register_ext_go() {
     zend_module_entry *module = &ext_go_module_entry;
     zend_register_module_ex(module, MODULE_PERSISTENT);
     //zend_register_internal_module(module);
}