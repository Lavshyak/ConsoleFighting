cmake_minimum_required(VERSION 3.6.0)
project(ConsoleFighting)
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/vendor
	${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
	"${PROJECT_SOURCE_DIR}/include/*"
	"${PROJECT_SOURCE_DIR}/vendor/*"
	"${PROJECT_SOURCE_DIR}/src/*"
)
add_executable(ConsoleFighting ${SRCS})

