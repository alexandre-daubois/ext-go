package ext_go

// #include "ext-go.h"
import "C"

//export go_print_something
func go_print_something() {
	println("Hello world from Go extension!")
}
