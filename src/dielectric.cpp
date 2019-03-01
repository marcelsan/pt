#include "dielectric.hpp"

bool dielectric::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
	vec3 outward_normal;
	vec3 reflected = reflect(r_in.direction(), rec.normal);
	float ni_over_nt;
	attenuation = vec3(1.0, 1.0, 1.0); 
	vec3 refracted;
	float reflect_prob;
	float cosine;

	if (dot(r_in.direction(), rec.normal) > 0) {
	    outward_normal = -rec.normal;
	    ni_over_nt = ref_idx;
	    cosine = dot(r_in.direction(), rec.normal) / r_in.direction().length();
	    cosine = sqrt(1 - ref_idx*ref_idx*(1-cosine*cosine));
	}
	else {
	    outward_normal = rec.normal;
	    ni_over_nt = 1.0 / ref_idx;
	    cosine = -dot(r_in.direction(), rec.normal) / r_in.direction().length();
	}

	if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted)) 
	   reflect_prob = schlick(cosine, ref_idx);
	else 
	   reflect_prob = 1.0;
	
	if (drand48() < reflect_prob) 
	   scattered = ray(rec.p, reflected, r_in.time());
	else 
	   scattered = ray(rec.p, refracted, r_in.time());

	return true;
}

bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted) {
    vec3 uv = unit_vector(v);
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt*ni_over_nt*(1-dt*dt);
    if (discriminant > 0) {
        refracted = ni_over_nt*(uv - n*dt) - n*sqrt(discriminant);
        return true;
    }
    else 
        return false;
}

float schlick(float cosine, float ref_idx) {
    float r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}