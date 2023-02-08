add_subdirectory(config)

add_library(common "")

target_link_libraries(common
    PUBLIC
    config
)

set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX)