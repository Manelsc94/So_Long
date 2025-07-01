# So Long

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/macOS-000000?style=for-the-badge&logo=apple&logoColor=white)
![42](https://img.shields.io/badge/42-Project-00BABC?style=for-the-badge)
![Score](https://img.shields.io/badge/Score-125%25-brightgreen?style=for-the-badge)

## 📋 Project Overview

So Long is a 2D game developed as part of the 42 school curriculum, utilizing the MiniLibX graphical library. The objective is to guide a player character through a map, collecting all collectibles and reaching the exit while avoiding walls. This project enhances skills in window management, event handling, texture rendering, and basic game mechanics, providing a foundation for computer graphics programming.

This implementation features a custom theme with a player navigating a maze-like environment, collecting items, and escaping to the exit, with additional bonus features like enemy patrols and on-screen movement display.

## ✨ Key Features

- **2D Gameplay**: Top-down view with smooth player movement using W, A, S, D keys (or arrow keys).
- **Map Parsing**: Reads `.ber` map files with walls (`1`), empty spaces (`0`), collectibles (`C`), exits (`E`), and player start (`P`).
- **Game Mechanics**:
  - Collect all items before exiting.
  - Prevents movement into walls.
  - Displays movement count in real-time (bonus: on-screen display).
- **Bonus Features**:
  - Enemy patrols that cause the player to lose upon contact.
  - Sprite animations for enhanced visuals.
  - On-screen movement counter instead of shell output.
- **Smooth Window Management**: Handles window resizing, minimizing, and clean exit via ESC or window close.
- **Norm Compliance**: Adheres to 42's strict coding standards with no memory leaks or undefined behaviors.

## 🛠️ Prerequisites

- **Operating System**: UNIX-based (Linux, macOS, etc.).
- **Compiler**: `gcc`.
- **Build Tool**: `make`.
- **Library**: MiniLibX (school version or source-installed) and `libft` (included).
- **Dependencies**: Math library (`-lm`) and X11 libraries for MiniLibX.

## 🚀 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Manelsc94/So_Long.git
   cd So_Long
   ```

2. Compile the game:
   ```bash
   make
   ```
   This creates the `so_long` executable, compiling the source files and `libft`.

3. (Optional) Compile with bonus features:
   ```bash
   make bonus
   ```

## 📖 Usage

1. Run the game with a `.ber` map file:
   ```bash
   ./so_long maps/valid_map.ber
   ```

2. **Controls**:
   - **W/Up**: Move up
   - **A/Left**: Move left
   - **S/Down**: Move down
   - **D/Right**: Move right
   - **ESC**: Quit the game
   - **Window Close**: Click the window's close button to exit

3. **Gameplay**:
   - Collect all collectibles (`C`) on the map.
   - Reach the exit (`E`) to win.
   - Avoid enemy patrols (bonus feature) to prevent losing.
   - Movement count is displayed on-screen (bonus) or in the terminal.

### Example Map (`maps/valid_map.ber`)
```
1111111111
1P00000C01
1C0000CE01
1111111111
```

### Example Gameplay
- Start the game: `./so_long maps/valid_map.ber`
- Move the player to collect all `C` items, avoid enemies, and reach `E`.
- The movement count updates with each move.

## 📂 Project Structure

```
so_long/
├── foundation/         # Initializer of maps and parser
├── maps/               # Example .ber map files
├── texture/            # Sprite and texture files
├── main.c              # Main function
├── so_long.h           # Header file
└── so_long             # Compiled executable (generated)
```

```
so_long_bonus/
├── foes/               # Enemies
├── foundation/         # Initializer of maps and parser
├── maps/               # Example .ber map files
├── texture/            # Sprite and texture files
├── main.c              # Main function
├── so_long_bonus.h     # Header file
└── so_long_bonus       # Compiled executable (generated)
```

## 🛠️ Makefile Commands

| Command       | Description                                    |
|---------------|------------------------------------------------|
| `make`        | Builds the mandatory `so_long` executable.     |
| `make bonus`  | Builds `so_long` with bonus features.          |
| `make clean`  | Removes object files.                          |
| `make fclean` | Removes object files and `so_long`.            |
| `make re`     | Rebuilds the project from scratch.             |

## 🔍 Technical Details

- **Program Name**: `so_long`
- **External Functions**:
  - Allowed: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`, math library functions (`-lm`), MiniLibX functions, and `ft_printf`.
- **Map Requirements**:
  - Valid characters: `0`, `1`, `C`, `E`, `P`.
  - Must be enclosed by walls (`1`).
  - Must have at least one `C`, one `E`, and one `P`.
  - Must be rectangular and valid (checked during parsing).
- **Graphics**:
  - Uses MiniLibX for window creation, image rendering, and event handling.
  - Textures are sourced from platforms like itch.io, respecting artist credits.
- **Bonus Features**:
  - Enemy patrols with collision detection.
  - Animated sprites for player and/or collectibles.
  - On-screen movement counter display.
- **Constraints**:
  - Compiled with `-Wall -Wextra -Werror`.
  - No memory leaks or undefined behaviors.
  - Smooth window management (resize, minimize, close).
  - All files organized as per repository structure, with no unused files.

## 📝 Notes

- Ensure MiniLibX is installed or use the school-provided version.
- Maps must follow the `.ber` format and be valid to avoid errors.
- Bonus features are evaluated only if the mandatory part is flawless.
- Test maps are provided in the `maps/` directory for development.
- Respect the licensing of any textures or sprites used.

## 📜 License

This project is licensed under the [MIT License](LICENSE).

## 👤 Author

**Manelsc94**  
GitHub: [Manelsc94](https://github.com/Manelsc94)

---

⭐️ If you find this project useful, consider giving it a star on GitHub!
