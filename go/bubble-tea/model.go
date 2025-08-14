package main

const (
	listview uint = iota
	titleview
	bodyview
)

type model struct {
	state uint
}
