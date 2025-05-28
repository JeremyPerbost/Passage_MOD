
#include <SDL_video.h>
#include <SDL.h>


/**
 * Blows an image up onto the screen using nearest neighbor (pixelated)
 * interpolation.
 */
void blowupOntoScreen( Uint32 *inImage, int inWidth, int inHeight,
                       int inBlowFactor, SDL_Surface *inScreen );
