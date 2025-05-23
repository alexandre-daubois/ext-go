#include <php.h>

#include "_cgo_export.h"
#include "ext-go.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    go_print_something();
}
/* }}} */