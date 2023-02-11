add_library(logging "")

target_sources(logging
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/log.h
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/log.cpp
  )

target_include_directories(logging
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(logging
    PUBLIC
    zlog
)

set_target_properties(logging PROPERTIES LINKER_LANGUAGE CXX)