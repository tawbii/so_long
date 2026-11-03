*This project has been created as part of the 42 curriculum by atawbi.*

# so_long

## Description

so_long is part of the 42 curriculum and is a small **2D game** written in C with the school's graphics library, **MiniLibX** (MLX), on top of X11.

The player moves around a map, collects every collectible, and then reaches the exit to win. The map is read from a text file, validated, and drawn tile by tile with XPM textures. The number of moves is printed to the terminal after every step.

### Gameplay

| Key   | Action          |
|-------|-----------------|
| `W`   | move up         |
| `A`   | move left       |
| `S`   | move down       |
| `D`   | move right      |
| `Esc` | quit            |

Closing the window with the cross also quits cleanly. Walls block movement. The exit only opens once **all** collectibles have been picked up; stepping onto it before that does nothing. When you win, the game prints `You win!` and exits.

### Map format

The map is a rectangular grid of these characters:

| Char | Meaning        | Texture          |
|------|----------------|------------------|
| `1`  | wall           | `xpms/11.xpm`    |
| `0`  | empty floor    | `xpms/00.xpm`    |
| `P`  | player start   | `xpms/p.xpm`     |
| `C`  | collectible    | `xpms/c.xpm`     |
| `E`  | exit           | `xpms/e.xpm`     |

A map is accepted only if:

- all lines have the same length;
- it is surrounded by walls (first and last row, first and last column);
- it contains exactly one `P`, exactly one `E` and at least one `C`;
- it contains no other characters;
- a path exists from `P` to `E` (checked with a depth-first flood fill on a copy of the map).

Otherwise the program prints an error and exits.

Example (`output.txt`):

```
1111111111111111111111
1P000000000000000000C1
10000000000000E00000C1
10000000000000000000C1
10000000000000000000C1
100000000000000000C0C1
1111111111111111111111
```

### Project layout

```
so_long/
├── Makefile
├── so_long.h            structures and prototypes
├── main.c               entry point, map loading and validation flow
├── map2matrix.c         reads the map file into a char matrix
├── valid*.c             map validation and path check
├── game_utils*.c        MLX setup, texture loading, rendering, movement
├── game_keys.c          key handling
├── clean.c              freeing resources
├── ft_printf.c, ft_put.c, ft_split.c   helper functions
├── xpms/                textures
├── output.txt           the map that is loaded
└── mlx/                 MiniLibX (see below)
```

## Instructions

### Requirements

- Linux with an X server
- `gcc` and `make`
- X11 development libraries: `libx11-dev`, `libxext-dev`
- **MiniLibX** placed in the `mlx/` directory. It is not bundled in this repository: download the Linux version of MiniLibX and extract it so that `mlx/Makefile` and `mlx/mlx.h` exist. The project Makefile builds it automatically.

### Compilation

```bash
make
```

Built with `-Wall -Wextra -Werror -g`. Object files go into `obj/`.

| Target       | Effect                                          |
|--------------|-------------------------------------------------|
| `make`       | build MiniLibX and `so_long`                    |
| `make clean` | remove the object files and clean MiniLibX      |
| `make fclean`| also remove the `so_long` binary               |
| `make re`    | rebuild from scratch                            |

### Execute

```bash
./so_long
```

The program currently takes **no arguments**: it always loads the map `output.txt` from the current directory, and the textures from `xpms/`, so run it from the project root. To play another map, edit `output.txt` or change the filename in `main()` ([main.c](main.c)).

## Resources

- [MiniLibX documentation / tutorial](https://harm-smits.github.io/42docs/libs/minilibx)
- [Flood fill algorithm](https://en.wikipedia.org/wiki/Flood_fill)
- [X11 / Xlib manual](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html)

### AI Usage

AI (Claude) was used to draft this README from the source code. The game itself was written and tested by the author.
