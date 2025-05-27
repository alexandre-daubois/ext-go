#include <php.h>

#include "_cgo_export.h"
#include "ext-go.h"
#include "ext-go_arginfo.h"

static int (*original_php_register_internal_extensions_func)(void) = NULL;

PHP_FUNCTION(go_print) {
  if (zend_parse_parameters_none() == FAILURE) {
    RETURN_THROWS();
  }

  go_print_something();
}

zend_module_entry ext_go_module_entry = {STANDARD_MODULE_HEADER,
                                         "ext_go",
                                         ext_functions, /* Functions */
                                         NULL,          /* MINIT */
                                         NULL,          /* MSHUTDOWN */
                                         NULL,          /* RINIT */
                                         NULL,          /* RSHUTDOWN */
                                         NULL,          /* MINFO */
                                         "0.1.1",
                                         STANDARD_MODULE_PROPERTIES};

PHPAPI int register_internal_extensions(void) {
  if (original_php_register_internal_extensions_func != NULL &&
      original_php_register_internal_extensions_func() != SUCCESS) {
    return FAILURE;
  }

  zend_module_entry *module = &ext_go_module_entry;
  if (zend_register_internal_module(module) == NULL) {
    return FAILURE;
  };

  return SUCCESS;
}

void register_extension() {
  original_php_register_internal_extensions_func =
      php_register_internal_extensions_func;
  php_register_internal_extensions_func = register_internal_extensions;
}
