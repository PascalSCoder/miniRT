/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   datatypes.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:31:17 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:29:52 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

# include "gmath.h"
# include "collections.h"

typedef enum e_obj_type
{
	obj_sphere,
	obj_plane,
	obj_square,
	obj_cylinder,
	obj_triangle
}	t_obj_type;

typedef enum e_light_type
{
	lt_spot,
	lt_dir
}	t_lt_type;

typedef struct s_physmat
{
	double		roughness;
}	t_physmat;

typedef struct s_res
{
	int			width;
	int			height;
}	t_res;

typedef struct s_ambient
{
	double		luminosity;
	t_frgb		rgb;
}	t_ambient;

typedef struct s_camera
{
	t_vector3		position;
	t_vector3		orientation;
	unsigned char	fov;
	double			focal_len;
}	t_camera;

typedef struct s_lightsrc
{
	t_lt_type		type;
	t_vector3		position;
	double			luminosity;
	t_frgb			rgb;
}	t_spotlight;

typedef struct s_dirlight
{
	t_lt_type		type;
	double			luminosity;
	t_frgb			rgb;
	t_vector3		dir;
}	t_dirlight;

typedef struct s_sphere
{
	t_obj_type	obj;
	t_frgb		rgb;
	t_physmat	*physmat;
	t_vector3	position;
	double		diameter2;
}	t_sphere;

typedef struct s_plane
{
	t_obj_type	obj;
	t_frgb		rgb;
	t_physmat	*physmat;
	t_vector3	position;
	t_vector3	orientation;
}	t_plane;

typedef struct s_circle
{
	t_plane		pl;
	double		r;
}	t_circle;

typedef struct s_square
{
	t_obj_type	obj;
	t_frgb		rgb;
	t_physmat	*physmat;
	t_vector3	position;
	t_vector3	orientation;
	int			size;
	t_vector3	adjdir;
}	t_square;

typedef struct s_cylinder
{
	t_obj_type	obj;
	t_frgb		rgb;
	t_physmat	*physmat;
	t_vector3	position;
	t_vector3	orientation;
	double		diameter;
	double		height;
}	t_cylinder;

typedef struct s_triangle
{
	t_obj_type	obj;
	t_frgb		rgb;
	t_physmat	*physmat;
	t_vector3	p0;
	t_vector3	p1;
	t_vector3	p2;
}	t_triangle;

typedef struct s_filedata
{
	char			*filename;
	int				fd;
}	t_filedata;

typedef struct s_image
{
	void			*image;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				endian;
}	t_image;

typedef struct s_mlxdata
{
	void			*mlx;
	void			*window;
}	t_mlxdata;

typedef struct s_ray
{
	void			*obj;
	double			t;
	t_vector3		p;
	t_vector3		origin;
	t_vector3		dir;
	t_vector3		n;
}	t_ray;

typedef struct s_aa
{
	t_vector2		*subdiv_table;
	unsigned char	samplec;
	unsigned char	subdivc;
}	t_aalias;

typedef struct s_scene
{
	t_res			res;
	t_frgb			bg_color;
	t_ambient		ambient;
	t_list			*cameras;
	t_list			*objects;
	t_list			*lightsrcs;
	t_camera		*active_cam;
	t_mlxdata		*mlxdata;
	t_aalias		aalias;
	unsigned char	threadc;
	unsigned char	max_depth;
	t_rgb			*active_frame;
	char			debug;
}	t_scene;

typedef struct s_thread
{
	t_scene	*scene;
	t_frgb	*frame;
	char	id;
}	t_thread;

#endif
