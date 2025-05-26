package ext_go

// #include "ext-go.h"
import "C"
import "github.com/caddyserver/caddy/v2"

//export go_print_something
func go_print_something() {
	go func() {
		caddy.Log().Info("Hello from a goroutine!")
	}()
}
