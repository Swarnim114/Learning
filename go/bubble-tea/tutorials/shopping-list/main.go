package main

import (
	"fmt"
	"github.com/charmbracelet/bubbletea"
	"os"
)

type model struct {
	choises  []string
	cursor   int
	selected map[int]struct{}
}
