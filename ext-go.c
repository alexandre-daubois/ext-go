#include <SAPI.h>
#include <Zend/zend_alloc.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <Zend/zend_types.h>
#include <php.h>

#include "_cgo_export.h"
#include "ext-go.h"

PHP_FUNCTION(go_print) /* {{{ */
{
    go_print_something();
}
/* }}} */