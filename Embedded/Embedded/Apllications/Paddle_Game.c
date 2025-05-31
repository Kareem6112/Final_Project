/*
 * Paddle_Game.c
 *
 * Created: 3/9/2025 6:51:58 PM
 *  Author: kareem
 */ 

/*

#define PADDLE_LEFT_X 0
#define PADDLE_RIGHT_X 15 // Adjusted for 20 columns
#define BALL_START_X 6
#define BALL_START_Y 0 // Ball starts in row 0
#define TCNT2 *((volatile u8*)0x44)
u8 ball_x = BALL_START_X;
u8 ball_y = BALL_START_Y; // Ball starts in row 0
s8 ball_dx = 1;
s8 ball_dy = 1;
u8 paddle_left_y = 0; // Paddle starts in row 0
u8 paddle_right_y = 0; // Paddle starts in row 0
u8 score = 1;
u8 last_score=0;
void update_screen() {
	LCD_voidLcdClear();

	// Display paddles (only on row 0 and row 1)
	LCD_voidGotoXY(paddle_left_y, PADDLE_LEFT_X);
	LCD_voidSendData('|');
	LCD_voidGotoXY(paddle_right_y, PADDLE_RIGHT_X);
	LCD_voidSendData('|');

	// Display ball (only on row 0 and row 1)
	LCD_voidGotoXY(ball_y, ball_x);
	LCD_voidSendData('o');

	// Display score on the third line (row index 2)
	LCD_voidGotoXY(2, 0); // Third row
	LCD_voidSendString("Score:");
	LCD_voidGotoXY(2, 10); // Third row, column 10
	LCD_voidIntDisplay(score-1);
}

void move_ball() {
	ball_x += ball_dx;

	if (rand() % 5 == 0) {
		ball_dy = (rand() % 2 == 0) ? 1 : -1;
	}

	ball_y += ball_dy;

	if (ball_y < 0) {
		ball_y = 0;
		ball_dy = 1;
	}
	if (ball_y > 1) {
		ball_y = 1;
		ball_dy = -1;
	}

	if ((ball_x == PADDLE_LEFT_X + 1 && ball_y == paddle_left_y) ||
	(ball_x == PADDLE_RIGHT_X - 1 && ball_y == paddle_right_y)) {
		ball_dx = -ball_dx;
		score++;
	}

	if (ball_x == 0 || ball_x == 19) {
		ball_x = BALL_START_X;
		ball_y = BALL_START_Y;
		score = 0;
	}
}

void move_paddles() {
	// Left paddle controls (Up: PD0, Down: PD1)
	if (!(PIND_Reg & (1 << DIO_PIN2)) && paddle_left_y > 0) { // Up button pressed
		paddle_left_y--;
	}
	if (!(PIND_Reg & (1 << DIO_PIN3)) && paddle_left_y < 1) { // Down button pressed
		paddle_left_y++;
	}

	// Right paddle controls (Up: PD2, Down: PD3)
	if (!(PIND_Reg & (1 << DIO_PIN7)) && paddle_right_y > 0) { // Up button pressed
		paddle_right_y--;
	}
	if (!(PIND_Reg & (1 << DIO_PIN4)) && paddle_right_y < 1) { // Down button pressed
		paddle_right_y++;
	}
}

int main(void) {
	DDRD_Reg = 0x00; // Set PORTD as input for paddle switches
	PORTD_Reg = 0xFF; // Enable pull-up resistors
	LCD_voidInit();
	LCD_voidSendCommand(LCD_CURSOR_OFF);
	KEYPAD_voidInit();
	srand(TCNT2);
	while (1) {
		move_paddles();
		move_ball();
		update_screen();
		_delay_ms(200);
		if (score==0)
		{
			LCD_voidLcdClear();
			LCD_voidSendString("score= ");
			LCD_voidIntDisplay(last_score);
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("reset the game ");
			while(1);
		}
		last_score=score-1;
	}
	return 0;
}

*/