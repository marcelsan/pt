#include "raytrace.hpp"

namespace raytrace {
	vec3 color(const ray& r, hitable* world, int depth) {
		hit_record rec;
		if (world->hit(r, 0.001, MAXFLOAT, rec)) {
			ray scattered;
			vec3 attenuation;

			if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
				return attenuation*color(scattered, world, depth+1);
			else 
				return vec3(0,0,0);
		}
		else {
			vec3 unit_dir = unit_vector(r.direction());
			const float t = 0.5 * (unit_dir.y() + 1);
			return (1-t)*vec3(1,1,1)+t*vec3(0.5,0.7,1.0);
		}
	}

	void render(std::ofstream& out, hitable* world, camera& cam, const int nx, const int ny, const int spp) {
		out << "P3\n" << nx << " " << ny << "\n255\n";
		for (int j = ny-1; j >= 0; j--) {
			for (int i = 0; i < nx; i++) {
				vec3 col(0,0,0);
				for (int s = 0; s < spp; s++) {
					const float u = float(i + drand48())/nx;
					const float v = float(j + drand48())/ny;
					col += color(cam.getray(u,v), world, 0);	
				}

				col /= float(spp);
				
				// Gamma correction
				col = vec3( sqrt(col.r()), sqrt(col.g()), sqrt(col.b()) );

				int ir = int(255.99*col.r());
				int ig = int(255.99*col.g());
				int ib = int(255.99*col.b());
				out << ir << " " << ig << " " << ib << "\n";
			}
		}
	}
}