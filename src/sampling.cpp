#include "sampling.hpp"

vec3 random_dir_in_unit_sphere() {
	vec3 p;

	do {
		p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
	} while (p.squared_length() >= 1.0);

	return p;
}

vec3 random_in_unit_disc() {
	vec3 p;
	do {
		p = 2.0*vec3(drand48(), drand48(), 0) - vec3(1,1,0);
	} while (dot(p,p) >= 1.0);
	return p;
}