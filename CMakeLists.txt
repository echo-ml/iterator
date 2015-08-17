cmake_minimum_required(VERSION 3.0)

project("echo-iterator")

enable_testing()

find_package(Echo)
include(Echo/Default)

ECHO_ADD_DEFAULT_TEST()
ECHO_INSTALL_DEFAULT_HEADERS()
