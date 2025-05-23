#include <php.h>

#include "ext-go.h"
#include "ext-go_arginfo.h"
#include "_cgo_export.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    ZEND_PARSE_PARAMETERS_NONE();

    go_print_something();
}
/* }}} */

static const zend_function_entry ext_go_functions[] = {
    PHP_FE(go_print, arginfo_go_print)
    PHP_FE_END
};

zend_module_entry ext_go_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_EXT_GO_EXTNAME,
    ext_go_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_EXT_GO_VERSION,
    STANDARD_MODULE_PROPERTIES
};
