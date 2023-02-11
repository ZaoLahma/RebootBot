add_subdirectory(config)
add_subdirectory(scheduler)
add_subdirectory(logging)

add_library(common "")

target_link_libraries(common
    PUBLIC
    config
    scheduler
    logging
)

set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX)