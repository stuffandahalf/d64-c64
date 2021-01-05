cmake_minimum_required(VERSION 3.1)
project(d64-c64 C)

add_executable(d64_c64
	src/main.c
)

set_property(
	TARGET d64_c64 PROPERTY
		C_STANDARD 99
		C_EXTENSIONS OFF
)

