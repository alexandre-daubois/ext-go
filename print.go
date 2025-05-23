package ext_go

// #include "ext-go.h"
import "C"
import (
	"fmt"
)

//export go_print_something
func go_print_something() {
	fmt.Println("Hello world!")
}
