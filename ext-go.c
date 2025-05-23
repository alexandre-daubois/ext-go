#include <php.h>
#include <ext/standard/info.h>

#include "ext-go.h"
#include "ext-go_arginfo.h"
#include "_cgo_export.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    ZEND_PARSE_PARAMETERS_NONE();

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

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(ext_go)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "ext-go support", "enabled");
    php_info_print_table_row(2, "Version", PHP_EXT_GO_VERSION);
    php_info_print_table_end();
}
/* }}} */

/* {{{ ext_go_module_entry */
zend_module_entry ext_go_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_EXT_GO_EXTNAME,
    ext_functions,           /* Functions */
    PHP_MINIT(ext_go),      /* MINIT */
    PHP_MSHUTDOWN(ext_go),  /* MSHUTDOWN */
    NULL,                   /* RINIT */
    NULL,                   /* RSHUTDOWN */
    PHP_MINFO(ext_go),      /* MINFO */
    PHP_EXT_GO_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EXT_GO
ZEND_GET_MODULE(ext_go)
#endif