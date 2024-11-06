#ifndef ANSI_HPP
#define ANSI_HPP

// Reset
#define RESET "\033[0m"

// Text styles
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m" //
#define RAPID_BLINK "\033[6m" //
#define INVERSE "\033[7m"
#define HIDDEN "\033[8m" //
#define STRIKETHROUGH "\033[9m"

// Reset text styles
#define RESET_BOLD "\033[21m"
#define RESET_DIM "\033[22m"
#define RESET_ITALIC "\033[23m"
#define RESET_UNDERLINE "\033[24m"
#define RESET_BLINK "\033[25m" //
#define RESET_RAPID_BLINK "\033[26m" //
#define RESET_INVERSE "\033[27m"
#define RESET_HIDDEN "\033[28m" //
#define RESET_STRIKETHROUGH "\033[29m"

// Regular colors
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[39m"
#define RESET_COLOR DEFAULT

// Background colors
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"
#define GREEN_BACKGROUND "\033[42m"
#define YELLOW_BACKGROUND "\033[43m"
#define BLUE_BACKGROUND "\033[44m"
#define MAGENTA_BACKGROUND "\033[45m"
#define CYAN_BACKGROUND "\033[46m"
#define WHITE_BACKGROUND "\033[47m"
#define DEFAULT_BACKGROUND "\033[49m"
#define RESET_BACKGROUND DEFAULT_BACKGROUND

// Bright colors. They may not work on all terminals.
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

// Bright background colors
#define BRIGHT_BLACK_BACKGROUND "\033[100m"
#define BRIGHT_RED_BACKGROUND "\033[101m"
#define BRIGHT_GREEN_BACKGROUND "\033[102m"
#define BRIGHT_YELLOW_BACKGROUND "\033[103m"
#define BRIGHT_BLUE_BACKGROUND "\033[104m"
#define BRIGHT_MAGENTA_BACKGROUND "\033[105m"
#define BRIGHT_CYAN_BACKGROUND "\033[106m"
#define BRIGHT_WHITE_BACKGROUND "\033[107m"

// More colors
#define ANSI_COLOR(x) "\033[38;2;" #x "m"
#define ANSI_BACKGROUND(x) "\033[48;2;" #x "m"
#define ANSI_BG(x) ANSI_BACKGROUND(x)

// RGB colors. They may not work on all terminals.
#define ANSI_RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
#define ANSI_RGB_BACKGROUND(r, g, b) "\033[48;2;" #r ";" #g ";" #b "m"
#define ANSI_RGB_BG(r, g, b) ANSI_RGB_BACKGROUND(r, g, b)

// Screen modes
// #define SCREEN_MODE(x) "\033[" #x "h"
// #define SCREEN_40X25_MONOCHROME "\033[0h"

// Cursor
// #define INVISIBLE_CURSOR "\033[?25l"
// #define VISIBLE_CURSOR "\033[?25h"
// #define RESTORE_SCREEN "\033[?47l"
// #define SAVE_SCREEN "\033[?47h"
// #define ENABLE_ALT_BUFFER "\033[?1049h" // ???
// #define DISABLE_ALT_BUFFER "\033[?1049l" // ???

#endif // ANSI_HPP