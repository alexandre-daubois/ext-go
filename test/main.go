package main

import (
	caddycmd "github.com/caddyserver/caddy/v2/cmd"

	_ "github.com/alexandre-daubois/ext-go"
	_ "github.com/caddyserver/caddy/v2/modules/standard"
	_ "github.com/dunglas/caddy-cbrotli"
	_ "github.com/dunglas/frankenphp/caddy"
)

func main() {
	caddycmd.Main()
}
