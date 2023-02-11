add_library(config "")

target_sources(config
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/config_if.h
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal/config.h
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/config.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/config_if.cpp
  )

target_include_directories(config
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal
)

target_compile_definitions(config PRIVATE 
  DEBUG=1
)

set_target_properties(config PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(config
    PUBLIC
    logging
)

add_executable(test_config
    test/main.cpp
    test/config_test.cpp
)

target_compile_options(test_config PRIVATE -Werror -Wall -Wextra -Wconversion)

# Link the test executable
target_link_libraries(test_config 
    PRIVATE 
        gtest 
        gmock
        logging
        config
)