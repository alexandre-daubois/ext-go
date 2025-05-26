package ext_go

import (
	"fmt"
	"github.com/caddyserver/caddy/v2"
	"github.com/caddyserver/caddy/v2/caddyconfig"
	"github.com/caddyserver/caddy/v2/caddyconfig/caddyfile"
	"github.com/caddyserver/caddy/v2/caddyconfig/httpcaddyfile"
	"go.uber.org/zap"
	frankenphpCaddy "github.com/dunglas/frankenphp/caddy"
)

// #include "ext-go.h"
import "C"

func init() {
	caddy.RegisterModule(ExtGoApp{})
	httpcaddyfile.RegisterGlobalOption("ext_go", parseGlobalOption)
}

type ExtGoApp struct {
	frankenphpApp *frankenphpCaddy.FrankenPHPApp
	logger        *zap.Logger
}

func (ExtGoApp) CaddyModule() caddy.ModuleInfo {
	return caddy.ModuleInfo{
		ID:  "ext_go",
		New: func() caddy.Module { return new(ExtGoApp) },
	}
}

func (m *ExtGoApp) Provision(ctx caddy.Context) error {
	f, err := ctx.App("frankenphp")
	if err != nil {
		return fmt.Errorf("error getting the frankenphp app: %v", err)
	}

	m.logger = ctx.Logger(m)
	m.frankenphpApp = f.(*frankenphpCaddy.FrankenPHPApp)

	return nil
}

func (m *ExtGoApp) Start() error {
	if err := m.frankenphpApp.Start(); err != nil {
		return fmt.Errorf("error starting frankenphp app: %v", err)
	}
	m.logger.Info("ext_go PHP extension started")

	C.auto_register_ext_go()

	return nil
}

func (_ *ExtGoApp) Stop() error {
	return nil
}

func parseGlobalOption(d *caddyfile.Dispenser, _ interface{}) (interface{}, error) {
	app := &ExtGoApp{}

	return httpcaddyfile.App{
		Name:  "ext_go",
		Value: caddyconfig.JSON(app, nil),
	}, nil
}

var (
	_ caddy.App         = (*ExtGoApp)(nil)
	_ caddy.Provisioner = (*ExtGoApp)(nil)
)
