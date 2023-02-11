add_library(scheduler "")

target_sources(scheduler
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc/scheduler_if.h
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal/scheduler.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/scheduler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/scheduler_if.cpp
  )

target_include_directories(scheduler
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/inc_internal
)

set_target_properties(scheduler PROPERTIES LINKER_LANGUAGE CXX)

add_executable(test_scheduler
    test/main.cpp
    test/scheduler_test.cpp
)
target_compile_options(test_scheduler PRIVATE -Werror -Wall -Wextra -Wconversion)

# Link the test executable
target_link_libraries(test_scheduler 
    PRIVATE 
        gtest 
        gmock
        zlog
        scheduler
)