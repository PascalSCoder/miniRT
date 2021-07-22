/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 16:42:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/03 15:00:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "datatypes.h"
# include "libft.h"
# include "errors.h"

char		trace(t_list *objects, t_ray *hit);
t_frgb		shade(t_scene *scene, t_ray *hit, int depth);
void		*render_thread(void *ptr);
void		create_threads(t_scene *scene, t_frgb *frame);
t_vector3	view_to_world(t_scene *scene, double x, double y);
t_ray		ray_new(t_scene *scene, t_vector2 p);

char		intersections(t_vector3 origin, t_vector3 dir,
				void *obj, double *t);
char		solve_quadr_eq(double a, double b, double c, double *t);
char		sphere_geometric(t_vector3 origin, t_vector3 dir,
				t_sphere *sphere, double *t);

char		sphere_is(t_vector3 origin, t_vector3 dir, t_sphere *sphere,
				double *t);
char		plane_is(t_vector3 origin, t_vector3 dir, t_plane *plane,
				double *t);
char		square_is(t_vector3 origin, t_vector3 dir, t_square *square,
				double *t);
char		cylinder_is(t_vector3 origin, t_vector3 dir, t_cylinder *cy,
				double *t);
char		triangle_is(t_vector3 origin, t_vector3 dir, t_triangle *tr,
				double *t);
char		circle_is(t_vector3 origin, t_vector3 dir, t_circle *circle,
				double *t);

t_vector3	calc_normaldir(t_vector3 n, t_vector3 dir);

t_vector3	sphere_normal(t_ray *hit);
t_vector3	plane_normal(t_ray *hit);
t_vector3	square_normal(t_ray *hit);
t_vector3	cylinder_normal(t_ray *hit);
t_vector3	triangle_normal(t_ray *hit);

t_camera	*get_next_camera(t_list *cameras);

void		display_image(t_scene *scene, t_rgb *frame);

void		set_obj_color(void *obj, t_frgb rgb);
t_frgb		get_obj_color(void *obj);
t_vector3	get_obj_normal(t_obj_type type, t_ray *ray);
t_obj_type	get_obj_type(void *obj);
t_vector3	get_obj_position(void *obj);
t_physmat	*get_obj_physmat(void *obj);

void		*get_intersectf(t_obj_type type);
void		*get_normalf(t_obj_type type);

int			mb_pressed(int button, int x, int y, void *param);
int			key_pressed(int keycode, void *param);

#endif
