#include <cmath>
#include <iostream>
#include <SDL/SDL.h>
#include "graphoscope.h"

#ifndef M_PI
	#define M_PI           3.14159265358979323846
#endif

#define SQRT2_2 0.707107

int main(int num_args, const char * const args[] )
{
if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    return 1;
    }

gos_powerup();

gos_handle handle = gos_open();
while(1)
	{
	gos_wait_for_buffer( handle );

	gos_move( handle,  0.0f,  -0.1f );

	//leg
	gos_line_rel( handle,  0.3f, -0.5f );
	gos_line_rel( handle,  0.1f,  0.0f );
	gos_line_rel( handle,  0.0f,  0.1f );
	gos_line_rel( handle, -0.3f,  0.5f );

	//torso
	gos_line_rel( handle,  0.0f,  0.3f );

	//arm
	gos_line_rel( handle,  0.4f,  0.3f );
	gos_line_rel( handle,  0.0f,  0.1f );
	gos_line_rel( handle, -0.1f,  0.0f );
	gos_line_rel( handle, -0.4f, -0.3f );

	//neck
	gos_line_rel( handle,  0.0f,  0.2f );

	//head
	gos_line_rel( handle,  0.1f,  0.1f );
	gos_line_rel( handle,  0.0f,  0.1f );
	gos_line_rel( handle, -0.1f,  0.1f );
	gos_line_rel( handle, -0.1f,  0.0f );
	gos_line_rel( handle, -0.1f, -0.1f );
	gos_line_rel( handle,  0.0f, -0.1f );
	gos_line_rel( handle,  0.1f, -0.1f );

	//neck
	gos_line_rel( handle,  0.0f, -0.2f );

	//arm
	gos_line_rel( handle, -0.4f,  0.3f );
	gos_line_rel( handle, -0.1f,  0.0f );
	gos_line_rel( handle,  0.0f, -0.1f );
	gos_line_rel( handle,  0.4f, -0.3f );

	//torso
	gos_line_rel( handle,  0.0f, -0.3f );

	//leg
	gos_line_rel( handle, -0.3f, -0.5f );
	gos_line_rel( handle,  0.0f, -0.1f );
	gos_line_rel( handle,  0.1f,  0.0f );
	gos_line_rel( handle,  0.3f,  0.5f );

	//butt
	gos_line_rel( handle,  0.1f,  0.0f );
	gos_render( handle );
	}

gos_close( &handle );
gos_powerdown();
SDL_Quit();
}
