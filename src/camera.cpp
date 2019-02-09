#include "camera.hpp"
#include "sampling.hpp"

camera::camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist) {
	// vfov is top to bottom in degrees.
	lens_radius = aperture/2.0;
	const float theta = vfov * M_PI/180.;
	const float half_height = tan(theta/2);
	const float half_width = aspect*half_height;
	origin = lookfrom;
	w = unit_vector(lookfrom - lookat);
	u = unit_vector(cross(vup, w));
	v = cross(w, u);		
	lower_left_corner = origin - half_width*focus_dist*u - half_height*focus_dist*v - focus_dist*w; 
	horizontal = 2*half_width*focus_dist*u;
	vertical = 2*half_height*focus_dist*v;
}

ray camera::getray(float s, float t) {
	vec3 rd = lens_radius * random_in_unit_disc();
	vec3 offset = u * rd.x() + v * rd.y();
	return ray(origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset); 
}