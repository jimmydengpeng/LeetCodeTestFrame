cmake_minimum_required (VERSION 2.6)
project (hello)
aux_source_directory(. src_list)
add_executable(hello ${src_list})