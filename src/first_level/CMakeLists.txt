
add_library(
	first_level_lib
		first_level_main.cpp
)

target_include_directories(first_level_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(first_level_lib composer_lib)

target_link_libraries(composer_lib first_level_lib)
target_link_libraries(mainmenu_lib first_level_lib)
