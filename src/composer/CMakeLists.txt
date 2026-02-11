
add_library(
	composer_lib
		composer.cpp
		sfml_actions.cpp
)

target_include_directories(composer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(composer_lib SFML::Graphics)
