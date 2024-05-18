#include "chip8keyboard.h"
#include <assert.h>
static void chip8_keyboard_ensure_in_bounds(int key)
{
    assert(key >= 0 && key <= CHIP8_TOTAL_KEYS);
}

void chip8_keyboard_set_map(struct chip8_keyboard* keyboard, const char* map)
{
    keyboard->keyboard_map = map;
}

int chip8_keyboard_map(struct chip8_keyboard* keyboard, char key)
{
    int n = CHIP8_TOTAL_KEYS;
    int s = 0;
    int e = n - 1;

    while (s<=e)
    {
        int mid = (s+e)/2;
        if (keyboard->keyboard_map[mid]==key)
        {
            return mid;
        } else if (keyboard->keyboard_map[mid]>key)
        {
            e = mid - 1;
        } else if (keyboard->keyboard_map[mid]<key)
        {
            s = mid + 1;
        }
    }

    /*for (int i = 0; i < CHIP8_TOTAL_KEYS; i++)
    {
        if (map[i] == key)
        {
            return i;
        }
    }*/

    return -1;
}

void chip8_keyboard_down(struct chip8_keyboard* keyboard, int key)
{
    keyboard->keyboard[key] = true;
}

void chip8_keyboard_up(struct chip8_keyboard* keyboard, int key)
{
    keyboard->keyboard[key] = false;
}

bool chip8_keyboard_is_down(struct chip8_keyboard* keyboard, int key)
{
    return keyboard->keyboard[key];
}