
add_library(
	mainmenu_lib
		mainmenu_main.cpp
)

target_include_directories(mainmenu_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mainmenu_lib composer_lib)
target_link_libraries(composer_lib mainmenu_lib)
