cmake_minimum_required(VERSION 3.5.0)
project(Mentoring VERSION 0.1.0 LANGUAGES C CXX)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(mentoring_inc)

file(GLOB_RECURSE mentoring_src CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Mentoring ${mentoring_src})

target_include_directories(Mentoring PUBLIC ${mentoring_inc})