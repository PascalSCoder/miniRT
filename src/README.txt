On Linux:
	If the dependencies are not yet installed, run:
		sudo apt-get install gcc make xorg libxext-dev libbsd-dev

./minirt [*.rt]
	--save			save scene to BMP format instead of opening a window

Key bindings:
	escape			exit program
	WASD			move forward/backward or left/right
	ZX				move up/down
	QE				rotate left or right
	RF				rotate up or down
	spacebar		next camera
	B				save current scene as BMP

.rt file:
	resolution	R	[width]	[height]
	camera		c	[pos] [orientation] [fov]

	ambient		A	[intensity] [color]
	spot light	l	[pos] [intensity] [color]
	dir. light	dl	[pos] [orientation]	[intensity]	[color]

	plane		pl	[pos] [orientation] [color] [optional: roughness]
	sphere		sp	[pos] [diameter] [color] [optional: roughness]
	square		sq	[pos] [orientation] [side size] [color] [optional: roughness]
	cylinder	cy	[pos] [orientation] [diameter] [height] [color] [optional: roughness]
	triangle	tr	[pos1] [pos2] [pos3] [color] [optional: roughness]

	anti alias	aa	[amount]
		Set traces per pixel (samples per pixel). Higher value means more accurate colors.
		Default = 1
	threads		t	[amount]
		Set amount of threads used to render the frames.
		Default = 1
	max depth	md	[amount]
		Set maximum depth for reflective surfaces.
		Default = 0
	background	bg	[color]
		Set background color for rendering (i.e. the void)
		Default = 0,0,0
	ENABLE_DEBUG
		Enables debug mode, which involves printing coordinates when moving the camera
		and a debug ray, send to mouse x and y on lmb pressed.