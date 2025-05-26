package ext_go

import (
	"github.com/caddyserver/caddy/v2"
)

// #include "ext-go.h"
// #include <php.h>
//
// extern zend_module_entry ext_go_module_entry;
// extern void auto_register_ext_go();
import "C"

func init() {
	caddy.RegisterModule(ExtGoApp{})
}

type ExtGoApp struct{}

func (ExtGoApp) CaddyModule() caddy.ModuleInfo {
	return caddy.ModuleInfo{
		ID:  "ext_go",
		New: func() caddy.Module { return new(ExtGoApp) },
	}
}

func (m *ExtGoApp) Provision(ctx caddy.Context) error {
	caddy.Log().Info("Provisioning ext_go PHP extension")
	C.auto_register_ext_go()

	return nil
}
