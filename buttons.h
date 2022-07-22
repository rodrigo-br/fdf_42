#ifndef BUTTONS_H
# define BUTTONS_H

/*-----------------------------------------------------------------\
|                   KEYBOARD AND MOUSE                             |
\-----------------------------------------------------------------*/
# define ESC                65307
# define LEFT               65361
# define UP                 65362
# define RIGHT              65363
# define DOWN               65364
# define SPACE              32
# define A_KEY              97
# define D_KEY              100
# define W_KEY              119
# define S_KEY              115
# define E_KEY              101
# define Q_KEY              113
# define Z_KEY              122
# define X_KEY              120
# define M_KEY              109
# define N_KEY              110
# define ENTER_KEY          65293
# define PLUS_KEY           65451
# define MINUS_KEY          65453

/*--------------------------------------------------------------------\
|                   MLX/X11 EVENTS AND MASKS                          |
\--------------------------------------------------------------------*/
# define KEY_PRESS_EVENT    02
# define MOUSE_PRESS_EVENT  04
# define DESTROY_EVENT      17
# define ENTER_EVENT        07
# define KEY_PRESS_MASK     1L<<0
# define MOUSE_PRESS_MASK   1L<<2
# define ENTER_WINDOW_MASK  1L<<04
#endif