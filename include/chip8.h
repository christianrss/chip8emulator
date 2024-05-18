#ifndef CHIP8_H
#define CHIP8_H

// http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"
#include "chip8keyboard.h"
#include "chip8screen.h"
#include <stddef.h>

struct chip8
{
    struct chip8_memory memory;
    struct chip8_stack stack;
    struct chip8_registers registers;
    struct chip8_keyboard keyboard;
    struct chip8_screen screen;
};

void chip8_init(struct chip8* chip8);
void chip8_load(struct chip8* chip8, const char* buf, size_t size);
void chip8_exec(struct chip8* chip8, unsigned short opcode);
static void chip8_exec_extended(struct chip8* chip8, unsigned short opcode);
static void chip8_exec_extended_F(struct chip8*, unsigned short opcode);
#endif