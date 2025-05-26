package ext_go

//#include "ext-go.h"
import "C"
import (
	"log/slog"
)

func init() {
	C.register_extension()
}

//export go_print_something
func go_print_something() {
	go func() {
		slog.Info("Hello from a goroutine!")
	}()
}
