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

PHP_FUNCTION(go_upper)
{
    char *str;
    size_t string_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(str, string_len)
    ZEND_PARSE_PARAMETERS_END();

    go_string param = {string_len, str};
    go_string *result = go_upper(&param);

    RETVAL_STRINGL(result->data, result->len);

    cleanup_go_string(result);
}

void cleanup_go_string(go_string *s) {
    if (s && s->data) {
        free(s->data);
        free(s);
    }
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
