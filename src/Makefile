# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pspijkst <pspijkst@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/06 20:27:43 by pspijkst      #+#    #+#                  #
#    Updated: 2021/04/09 11:38:25 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
FTDIR	=	libft
FTLIB	=	$(FTDIR)/libft.a
SRC_C	=	errors.c			minirt.c\
			bmp.c				window.c			debug.c\
			list.c				dict.c				init_scene.c\
			frgb_to_rgb.c		events.c			display_image.c\
			init_mlx.c
PARSE_C	=	parse_a.c 			parse_c.c			parse_cy.c\
			parse_l.c			parse_pl.c			parse_r.c\
			parser.c			parse_sp.c			parse_sq.c\
			parse_tr.c			parse_dl.c			check_scene.c\
			checks.c			parse_types.c		parse_tools.c\
			parse_physmat.c		parse_t.c			parse_aa.c\
			parse_md.c			parse_bg.c			enable_debug.c
GNL_C	=	get_next_line.c		get_next_line_utils.c
RT_C	=	render.c			cam_control.c		trace.c\
			intersections.c		plane_is.c			sphere_is.c\
			square_is.c			triangle_is.c		cylinder_is.c\
			obj_distr.c			shading.c			get_obj_data.c\
			set_obj_data.c		circle_is.c			calc_normaldir.c\
			view_to_world.c
GMATH_C	=	deg_to_rad.c		quat_magnitude.c	v3_multiply.c\
			v3_new.c			int_to_uchar.c		quat_mult.c\
			solve_quadr_eq.c	v3_normalize.c		m3_set.c\
			quat_mult_v3.c		v3_abs.c			v3_reflect.c\
			m4_add.c			quat_new.c			v3_add.c\
			v3_rotate.c			m4_from_orient.c	quat_normalize.c\
			v3_cross.c			v3_scale.c			m4_identity.c\
			quat_scalar_mult.c	v3_divide.c			v3_subtract.c\
			m4_mult.c			quat_subtract.c		v3_dot.c\
			v3_to_scalar.c		m4_set.c			quat_unit_normalize.c\
			v3_isequal.c		v3_transform_m4.c	quat_add.c\
			rad_to_deg.c		v3_isgreater.c		quat_conjugate.c\
			v3_magnitude.c		quat_inverse.c		frgb_add.c\
			frgb_new.c			frgb_mult.c			frgb_mult_frgb.c\
			frgb_mix.c			v3_move.c			m3_transform_v3.c\
			v3_yaw.c			v3_pitch.c			v3_roll.c\
			m3_mult.c			m3_from_orient.c

RT_O	=	$(RT_C:%.c=src/rt/%.o)
SRC_O	=	$(SRC_C:%.c=src/%.o)
PARSE_O	=	$(PARSE_C:%.c=src/parse/%.o)
GNL_O	=	$(GNL_C:%.c=src/gnl/%.o)
GMATH_O	=	$(GMATH_C:%.c=src/gmath/%.o)
HEADERS	=	public/minirt.h
CFLAGS	=	-Wall -Wextra -Werror
OS		=	$(shell uname)

ifeq ($(OS),Linux)
	MLXDIR = minilibx_linux
	MLXLIB = $(MLXDIR)/libmlx.a
	LINKERS = -Lminilibx_linux -lmlx -lXext -lX11 -lm -lbsd
else
	MLXDIR = minilibx_mac
	MLXLIB = libmlx.dylib
	LINKERS = -L. -lmlx -framework OpenGL -framework AppKit
	CFLAGS += -D MACOS==1
endif

ifeq ($(BONUS),1)
	LINKERS += -pthread
	TORM = threading.o
	SRC_C += threading_bonus.c
else
	TORM = threading_bonus.o
	SRC_C += threading.c
endif

mandatory:
	rm -f src/threading_bonus.o
	$(MAKE) all

all: mlx libft $(NAME)

bonus:
	rm -f src/threading.o
	$(MAKE) all -e BONUS=1

$(NAME): $(MLXLIB) $(FTLIB) $(SRC_O) $(PARSE_O) $(GNL_O) $(RT_O) $(GMATH_O)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_O) $(PARSE_O) $(GNL_O) $(RT_O) $(GMATH_O)\
	 -L$(FTDIR) -lft $(LINKERS)

ifeq ($(OS),Darwin)
$(MLXLIB): minilibx_mac/$(MLXLIB)
	cp minilibx_mac/$(MLXLIB) .
endif

mlx:
	$(MAKE) -C $(MLXDIR)

libft:
	$(MAKE) all -C $(FTDIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SRC_O) $(PARSE_O) $(GNL_O) $(RT_O) $(GMATH_O)\
	 src/threading_bonus.o src/threading.o

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FTDIR)

re: fclean all

.PHONY: all libft clean fclean re
