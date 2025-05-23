#include <php.h>

#include "ext-go.h"
#include "_cgo_export.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    ZEND_PARSE_PARAMETERS_NONE();

    go_print_something();
}
/* }}} */
