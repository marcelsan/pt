set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(pathtracer_SRCS main.cpp
	camera.cpp
	dielectric.cpp
	hitable_list.cpp
	lambertian.cpp
	metal.cpp
	raytrace.cpp
	sampling.cpp
	sphere.cpp
)

add_executable(pathtracer ${pathtracer_SRCS})