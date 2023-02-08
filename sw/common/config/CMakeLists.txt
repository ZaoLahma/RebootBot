add_library(config "")

target_sources(config
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/config_if.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal/config.h
    ${CMAKE_CURRENT_LIST_DIR}/src/config.cpp
  )

target_include_directories(config
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal
)

set_target_properties(config PROPERTIES LINKER_LANGUAGE CXX)