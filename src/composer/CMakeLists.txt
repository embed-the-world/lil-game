
add_library(
	composer
		composer.cpp
		sfml_actions.cpp
)

target_include_directories(composer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(composer SFML::Graphics)
