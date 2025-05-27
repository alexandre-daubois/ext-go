package ext_go

/*
#include <stdlib.h>
#include "ext-go.h"
*/
import "C"
import (
	"log/slog"
	"strings"
)

func init() {
	C.register_extension()
}

//export go_print_something
func go_print_something(s *C.go_string) *C.go_string {
	go func() {
		slog.Info(C.GoString(s.data) + " from a goroutine!")
	}()

	return s
}

//export go_upper
func go_upper(s *C.go_string) *C.go_string {
	data := C.GoStringN(s.data, C.int(s.len))
	upper := strings.ToUpper(data)

	result := (*C.go_string)(C.malloc(C.sizeof_go_string))
	result.data = C.CString(upper)
	result.len = C.size_t(len(upper))

	return result
}
