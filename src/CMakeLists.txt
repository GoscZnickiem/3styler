set(SOURCES

	main.cpp

	scramble.cpp
	scramble.hpp
	move.cpp
	move.hpp
	cube.hpp
	cube.cpp

)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
