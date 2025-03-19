#include "babydriver.h"
#include "kuromi.h"

int main() {

	bd_draw_bitmap(20, 0, KUROMI_SMALL_WIDTH, KUROMI_SMALL_HEIGHT, kuromi_small);

	//bd_draw_rectangle(40, 105, 20, 20);
	//bd_draw_rectangle(170, 80, 20, 20);
	//bd_draw_triangle(130, 80, 10, 2);

	bd_draw_text(0, 40, 16, "https://trent.surf");

	//bd_draw_rdiagonal(0, 105, 2, 20);
	//bd_draw_ldiagonal(50, 105, 2, 20);

	bd_print_framebuffer();
}
