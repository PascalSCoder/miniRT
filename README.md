# miniRT
A beautiful but mini ray-tracer

On Linux:
	If the dependencies are not yet installed, run:
		```sudo apt-get install gcc make xorg libxext-dev libbsd-dev```

##### ./minirt [*.rt]
- --save: saves rendered image to BMP format instead of opening a window


## Keybindings
| Key | Action |
|-----|--------|
| escape | exit program |
| WASD | move forward/backward or left/right |
| ZX | move up/down |
| QE | rotate left or right |
| RF | rotate up or down |
| spacebar | next camera |
| B | save current scene as BMP |

## Scene configuration file
If an argument consists of multiple values, supply one ',' comma between the values. See an example: ```c 0.5,0,-10 1,0,1 60``` where ```c``` means camera, on pos ```0.5,0,-10``` with orientation ```1,0,1``` and a field of view of ```60``` degrees.

Syntax / some constraints:
- Light intensity = float between 0 and 1.
- Roughness = float between 0 and 1.
- Pos = vector3 of floats.
- Color = vector3 of ints, between 0 and 255.
- Orientation = vector3 of floats, gets normalized at runtime.

| Name | Keyword | Arguments |
|------|---------|-----------|
| resolution	| R	| ```[int width] [int height]``` *Large sizes result in large render time.* |
| camera	| c	| ```[pos] [orientation] [int fov]``` *Fov should be set to around 60 to prevent too much deforming.* |
| ambient	| A	| ```[intensity] [color]``` |
| spot light	| l	| ```[pos] [intensity] [color]``` |
| dir. light	| dl	| ```[pos] [orientation] [intensity] [color]``` |
| plane		| pl	| ```[pos] [orientation] [color] [optional: roughness]``` |
| sphere	| sp	| ```[pos] [float diameter] [color] [optional: roughness]``` |
| square	| sq	| ```[pos] [orientation] [float side size] [color] [optional: roughness]``` |
| cylinder	| cy	| ```[pos] [orientation] [float diameter] [float height] [color] [optional: roughness]``` |
| triangle	| tr	| ```[pos1] [pos2] [pos3] [color] [optional: roughness]``` |

| Name | Keyword | Arguments | Description |
|------|---------|-----------|-------------|
| anti alias	| aa	| [int amount] | Set traces per pixel (samples per pixel). Higher value means more accurate colors. *Higher value increases render time* |
| threads	| t	| [int amount] | Set amount of threads used to render the frames. *Higher value decreases render time* |
| max depth	| md	| [int amount] | Set maximum depth for reflective surfaces. ```Default = 0``` which implicitly disables reflections. |
| background	| bg	| [color]| Set background color for rendering. (i.e. the void) |
| enable debug mode | ENABLE_DEBUG | | Enables debug mode, which involves printing coordinates when moving the camera and a debug ray, send to mouse x and y on ```lmb pressed```. |

## Improvements / Issues
- Cylinder does not always render the correct order with caps, resulting in the nearest cap being invisible.
- Plane is rendering on the whole screen if the camera is positioned exactly at the plane's axis.
