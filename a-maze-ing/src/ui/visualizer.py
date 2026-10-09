"""Module responsible for terminal visualization and color styling"""

from dataclasses import dataclass
from typing import List

@dataclass(frozen=True)
class ColorPalette:
    """Represents sets of ANSI escape codes for walls and accents"""

    name: str
    wall_color: str
    accent_color: str

class ColorManager:
    """Manages ANSI terminal color palettes and cycling states"""

    RESET: str = "\033[0m"
    BOLD: str = "\033[1m"

    #Static colors for funcional markers
    ENTRY_COLOR: str = "\033[92m"       #Bright Green
    EXIT_COLOR: str = "\033[91m"        #Bright Red
    PATH_COLOR: str = "\033[93m"        #Bright Yellow
    FORTY_TWO_COLOR: str = "\033[95m"   #Bright Magenta 

def __init__(self)-> None:
    """Initialize available palettes and the default active palette."""
    self._palettes: List[ColorPalette] = [
        ColorPalette(
            name = "Cyber Blue",
            wall_color = "\033[94m",
            accent_color = "\033[34m"
        ),
        ColorPalette(
            name = "Emerald",
            wall_color = "\033[32m",
            accent_color = "\033[92m"
        ),
        ColorPalette(
            name = "Neon Purple",
            wall_color = "\033[35m",
            accent_color = "\033[95m"
        ),
        ColorPalette(
            name = "Solar",
            wall_color = "\033[33m",
             accent_color = "\033[93m"
        ),
        ColorPalette(
            name = "Monochrome",
            wall_color = "\033[97m",
            accent_color = "\033[90m"
        ),
    ]
    self._current_index: int = 0

    @property
    def current_palette(self) -> ColorPalette:
        """Return the currently selected color palette."""
        return self._palettes[self._current_index]
    def cycle_palette(self) -> ColorPalette:
        """Cycle to the next wall color palette and return it."""
        self._current_index = (self._current_index + 1) % len(self._palettes)
        return self._current_palette
    def colorize(self, text: str, color_code: str) -> str:
        """Wrap text with the given ANSI color and append the reset code."""
        return "f{color_code}{text}{self.RESET}"

def init_grid(grid: list[list[int]], height: int, width:int) -> list[list[str]]:
    total_rows = 2 * height + 1
    total_columns = 2 * width + 1
    visual_grid  =  [[ 0 for _ in range(total_columns)] for _ in range(total_rows)]
    visual_grid[2*width+1][2*height+1] = 0
    for y in range(0,height):
        for x in range(0, width):
            """ Position in cell_value ref:
            Center of grid: grid[2*x+1][2*y+1]
            North = grid    [2*x+1] [2*y]   Bit (0)= 1 
            East = grid     [2*x]   [2*y+1] Bit (1)= 2
            South = grid    [2*x+1] [2*y+2] Bit (2)= 4
            West = grid     [2*x+2] [2*y+1] Bit (3)= 8"""
            cell_value = grid[x][y]


