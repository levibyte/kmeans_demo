#include "init.h"
#include "logic.h"

#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>


int main( int argc, char* args[] )
{
       if( !init() ) exit(1);
       if( !loadMedia() ) exit(1);

        bool quit = false;
        SDL_Event e;
        JManager j;

        j.init_data();
       
        SDL_RenderSetScale(gRenderer,6.0,6.0);
       
        while( !quit )
        {
                while( SDL_PollEvent( &e ) != 0 )
                {
                        if( e.type == SDL_QUIT ) quit = true;
                        if( e.type == SDL_MOUSEBUTTONDOWN ) j.set_classes();
                } 
 
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
               
                j.draw_classes();
                
                SDL_RenderPresent( gRenderer );
        }

        close();
        return 0;
}