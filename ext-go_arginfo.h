/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 76b4b777ef5009ceb47f814d39b74fc4be91b92a */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_go_print, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_go_upper, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(go_print);
ZEND_FUNCTION(go_upper);


// clang-format off
static const zend_function_entry ext_functions[] = {
	ZEND_FE(go_print, arginfo_go_print)
	ZEND_FE(go_upper, arginfo_go_upper)
	ZEND_FE_END
};
// clang-format on
