#include <php.h>

#include "_cgo_export.h"
#include "ext-go.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    ZEND_PARSE_PARAMETERS_NONE();

    go_print_something();
}
/* }}} */