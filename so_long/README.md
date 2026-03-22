*This project has been created as part of the 42 curriculum by qijin*

# Description

## so_long

The objective of `so-long` is to create a simple graphical game using the `MiniLibX` library.

The goal of the game is simple: player(`P`) moves on a map, collects all the collectibles(`C`) on the map and escapes through the exit(`E`) while minizing the number of moves. The game reads the map from a `.ber` file and validates it before lauching.

## Features

* Rendering a 2D game window
* Loading textures and displaying tiles
* Map parsing from `.ber` files
* Validation of map structure and characters
* Movement system with collision detection
* Collectible tracking
* Exit unlocking after collecting all items
* Movement counter displayed in the terminal
* Clean program exit when pressing `ESC` or closing the window

## Map Format

Maps are provided as `.ber` files and must follow strict rules.

Allowed character:

| Character | Meaning |
| ---------- | --------|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |

**Map rules:**

* The map must be **rectangular**
* The map must be **completely** surrounded by walls
* There must be exactly **one** play(`P`)
* There must be exactly **one** exit(`E`)
* There must be at least **one** collectible(`C`)
* A valid path must exit

### Path Validation

A **flood fill algorithm** is used to verify that:

* all collectibles are reachable
* the exit is reachable

## Controls

| Key | Action |
| -----| ----- |
| **W / ↑** | Move Up |
| **A / ←** | Move Left |
| **S / ↓** | Move Down |
| **D / →** | Move Right |
| **ESC** | Exit the game |

Each movement increments a displayed in the terminal.

# Instructions

Run the program by providing a valid map file :

```
make
./so_long maps/map.ber
```

if the map contains errors, the program exits with:

```
Error
<description>
```

# Resources

## Documentation and resources

* MiniLibX documentation
* Game asset platform **itch.io**

The textures used is from [Free Dungeon Tileset 16x16 Pixelart](https://elvgames.itch.io/free-fantasy-dreamland-dungeon).

## AI Usage

AI tools were used during development for:

* understanding graphics concepts
* improving documentation
* brainstorming algorithms and debugging strategies

All generated content was reviewed, understood, and adated before using.
