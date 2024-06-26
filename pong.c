#include "pong.h"
#include "tui.h"

#define PADDLE_HEIGHT 3
#define PADDLE_WIDTH 1
#define BALL_SIZE 1
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define WHITE_ON_BLACK 0x07

int paddle1_y;
int paddle2_y;
int ball_x;
int ball_y;
int ball_dx;
int ball_dy;

void pong_init() {
    paddle1_y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    paddle2_y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    ball_x = SCREEN_WIDTH / 2;
    ball_y = SCREEN_HEIGHT / 2;
    ball_dx = 1;
    ball_dy = 1;
}

void pong_draw() {
    tui_clear();
    
    // Draw paddles
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        tui_print("|", paddle1_y + i, 0, WHITE_ON_BLACK);
        tui_print("|", paddle2_y + i, SCREEN_WIDTH - 1, WHITE_ON_BLACK);
    }

    // Draw ball
    tui_print("O", ball_y, ball_x, WHITE_ON_BLACK);
}

void pong_update() {
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Ball collision with paddles
    if ((ball_x == 1 && ball_y >= paddle1_y && ball_y < paddle1_y + PADDLE_HEIGHT) ||
        (ball_x == SCREEN_WIDTH - 2 && ball_y >= paddle2_y && ball_y < paddle2_y + PADDLE_HEIGHT)) {
        ball_dx = -ball_dx;
    }

    // Ball collision with walls
    if (ball_y == 0 || ball_y == SCREEN_HEIGHT - 1) {
        ball_dy = -ball_dy;
    }

    // Ball out of bounds
    if (ball_x == 0 || ball_x == SCREEN_WIDTH - 1) {
        pong_init();
    }
}

void pong_loop() {
    char key;

    while (1) {
        pong_draw();
        pong_update();
        key = get_key();

        if (key == 'w' && paddle1_y > 0) {
            paddle1_y--;
        } else if (key == 's' && paddle1_y < SCREEN_HEIGHT - PADDLE_HEIGHT) {
            paddle1_y++;
        } else if (key == 'i' && paddle2_y > 0) {
            paddle2_y--;
        } else if (key == 'k' && paddle2_y < SCREEN_HEIGHT - PADDLE_HEIGHT) {
            paddle2_y++;
        }
    }
}
