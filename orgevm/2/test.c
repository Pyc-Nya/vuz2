#include <conio.h>
#include <dos.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define BUFFER_SIZE ((MAX_WIDTH + 1) * (MAX_HEIGHT + 1) * 2 + 1)
int x1 = 20, y1 = 10, x2 = 60, y2 = 20;

void fillEmptyCellsWithColor(int background_color) {
    int x, y;
    char current_char;
    
    int width = x2 - x1 + 1;
    int height = y2 - y1 + 1;

    char buffer[BUFFER_SIZE] = {0};

    gettext(x1, y1, x2, y2, buffer);

    textbackground(background_color);
    window(x1, y1, x2, y2);
    gotoxy(1, 1);

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            current_char = buffer[(y * width + x) * 2];

            if (current_char == ' ') {
                gotoxy(x + 1, y + 1); 
                putch(' ');          
            }
        }
    }
}

void scrollWindow(int lines) {
    union REGS regs;

    regs.h.ah = 0x06;            // Scroll function (upwards)
    regs.h.al = lines;           // Number of lines to scroll
    regs.h.bh = 0x00;            // Attribute of blank lines (формирование атрибута из фона и текста)
    regs.h.ch = y1 - 1;          // Top-left row (adjusted for zero-based index)
    regs.h.cl = x1 - 1;          // Top-left column (adjusted for zero-based index)
    regs.h.dh = y2 - 1;          // Bottom-right row (adjusted for zero-based index)
    regs.h.dl = x2 - 1;          // Bottom-right column (adjusted for zero-based index)

    int86(0x10, &regs, &regs);   // BIOS interrupt 0x10 to perform the scroll
}

int main() {
    int text_color, background_color;

    // Clear the entire screen
    clrscr();
    
    // Set the window with coordinates (x1, y1) to (x2, y2)
    textbackground(0);
    textcolor(0);
    window(x1, y1, x2, y2);
    clrscr(); // Clear the newly defined window area

    for (text_color = 0; text_color < 16; text_color++) {  
        for (background_color = 0; background_color < 16; background_color++) {
            textcolor(text_color);            // Set text color
            textbackground(background_color); // Set background color

            // Print the line with the current color combination
            fillEmptyCellsWithColor(background_color);
            cprintf("Text color: %d, Background color: %d\r\n\r\n", text_color, background_color);

            getch();
            if (background_color % 5 == 0) {
              scrollWindow(5);
            }
        }  
    }

    getch(); // Wait for user before exiting
    return 0;
}