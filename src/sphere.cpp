#include "sphere.hpp"

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center;
	const float a = dot(r.direction(), r.direction());
	const float b = dot(oc, r.direction());
	const float c = dot(oc, oc) - radius * radius;
	const float discriminant = b*b - a*c;

	if (discriminant > 0) {
		float temp = (-b-sqrt(discriminant))/a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.at(temp);
			rec.mat_ptr = mat_ptr;
			rec.normal = (rec.p-center)/radius;
			return true;
		}

		temp = (-b+sqrt(discriminant))/a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.at(temp);
			rec.mat_ptr = mat_ptr;
			rec.normal = (rec.p-center)/radius;
			return true;
		}
	}
	
	return false;
}