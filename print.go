package ext_go

// #include "ext-go.h"
// extern void CGOPHPRegisterModule(void *module_entry);
import "C"
import (
	"fmt"
	"unsafe"
)

//export go_print_something
func go_print_something() {
	fmt.Println("Hello world!")
}

func init() {
	C.CGOPHPRegisterModule(unsafe.Pointer(&C.ext_go_module_entry))
}
