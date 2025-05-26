package ext_go

//#include "ext-go.h"
import "C"

func init() {
	C.register_ext_go()
}
