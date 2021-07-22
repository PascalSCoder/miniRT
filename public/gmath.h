/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:37:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 14:09:39 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMATH_H
# define GMATH_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef union u_rgb
{
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
	unsigned int		rgb;
}	t_rgb;

typedef struct s_frgb
{
	float	r;
	float	g;
	float	b;
}	t_frgb;

typedef struct s_vector2
{
	double	x;
	double	y;
}	t_vector2;

typedef struct s_vector3
{
	double		x;
	double		y;
	double		z;
}	t_vector3;

typedef union u_matrix4
{
	double		map[4][4];
	struct
	{
		t_vector3	right;
		double		x;
		t_vector3	up;
		double		y;
		t_vector3	forward;
		double		z;
		t_vector3	origin;
		double		w;
	};
}	t_matrix4;

typedef union u_matrix3
{
	double		map[3][3];
	struct
	{
		t_vector3	x;
		t_vector3	y;
		t_vector3	z;
	};
}	t_matrix3;

typedef struct s_quaternion
{
	double		s;
	t_vector3	vect;
}	t_quat;

char			solve_quadr_eq(double a, double b, double c, double *t);
unsigned char	int_to_uchar(int i);

t_quat			quat_new(t_vector3 vect, double s);
t_quat			quat_mult_scalar(t_quat q1, double scalar);
t_quat			quat_mult(t_quat q1, t_quat q2);
t_quat			quat_add(t_quat q1, t_quat q2);
t_quat			quat_subtract(t_quat q1, t_quat q2);
t_quat			quat_normalize(t_quat q1);
t_quat			quat_unit_normalize(t_quat q1);
t_quat			quat_conjugate(t_quat q1);
t_quat			quat_inverse(t_quat q1);
double			quat_magnitude(t_quat q1);
t_vector3		quat_mult_v3(t_vector3 vect, t_quat quat_in);

double			deg_to_rad(double deg);
double			rad_to_deg(double rad);

t_frgb			frgb_new(float r, float g, float b);
t_frgb			frgb_mix(t_frgb *colors, int n);
t_frgb			frgb_mult(t_frgb rgb, float f);
t_frgb			frgb_add(t_frgb rgb1, t_frgb rgb2);
t_frgb			frgb_mult_frgb(t_frgb rgb1, t_frgb rgb2);

t_vector3		v3_new(double x, double y, double z);
t_vector3		v3_cross(t_vector3 vect_a, t_vector3 vect_b);
double			v3_dot(t_vector3 vect_a, t_vector3 vect_b);
t_vector3		v3_scale(t_vector3 vect_a, t_vector3 vect_b);
double			v3_magnitude(t_vector3 vect);
t_vector3		v3_multiply(t_vector3 vect, double scalar);
t_vector3		v3_divide(t_vector3 vect, double n);
t_vector3		v3_abs(t_vector3 vect);
t_vector3		v3_subtract(t_vector3 vect_a, t_vector3 vect_b);
t_vector3		v3_add(t_vector3 vect_a, t_vector3 vect_b);
t_vector3		v3_normalize(t_vector3 vect);
double			v3_to_scalar(t_vector3 vect);
char			v3_isequal(t_vector3 vect_a, t_vector3 vect_b);
t_vector3		v3_reflect(t_vector3 in, t_vector3 n);
t_vector3		v3_rotate(t_vector3 vect, double angle, t_vector3 axis);
t_vector3		v3_move(t_vector3 forward, t_vector3 pos, t_vector3 move);
void			v3_pitch(double angle, t_vector3 *vect);
void			v3_yaw(double angle, t_vector3 *vect);
void			v3_roll(double angle, t_vector3 *vect);

t_matrix4		m4_add(t_matrix4 a, t_matrix4 b);
t_matrix4		m4_mult(t_matrix4 a, t_matrix4 b);
t_vector3		v3_transform_m4(t_vector3 vect, t_matrix4 mtrx);
t_matrix4		m4_identity(void);
t_matrix4		m4_set(t_vector3 rt, t_vector3 up, t_vector3 fw, t_vector3 o);
t_matrix4		m4_from_orient(t_vector3 orient, t_vector3 origin);
t_matrix3		m3_set(t_vector3 forward, t_vector3 right, t_vector3 up);
t_vector3		m3_transform_v3(t_matrix3 mtrx, t_vector3 vect);

#endif
