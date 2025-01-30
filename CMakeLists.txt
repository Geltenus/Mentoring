cmake_minimum_required(VERSION 3.5.0)
project(Mentoring VERSION 0.1.0 LANGUAGES C CXX)

macro(header_directories return_list)
    file(GLOB_RECURSE new_list *.h)
    set(dir_list "")
    foreach(file_path ${new_list})
        get_filename_component(dir_path ${file_path} PATH)
        set(dir_list ${dir_list} ${dir_path})
    endforeach()
    list(REMOVE_DUPLICATES dir_list)
    set(${return_list} ${dir_list})
endmacro()

header_directories(mentoring_inc)

file(GLOB_RECURSE mentoring_src CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Mentoring ${mentoring_src})

target_include_directories(Mentoring PUBLIC ${mentoring_inc})
