package ext_go

import "fmt"
import "C"

//export go_print_something
func go_print_something() {
	fmt.Println("Hello world!")
}
