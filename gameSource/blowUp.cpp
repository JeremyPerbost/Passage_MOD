#include "blowUp.h"

#include <string.h>



void blowupOntoScreen( Uint32 *inImage, int inWidth, int inHeight,
                       int inBlowFactor, SDL_Surface *inScreen ) {
    
    int newWidth = inBlowFactor * inWidth;
    int newHeight =  inBlowFactor * inHeight;
    
    int yOffset = ( inScreen->h - newHeight ) / 2;
    int xOffset = ( inScreen->w - newWidth ) / 2;
    
    // pitch is in bytes
    // convert to width in pixels
    int scanlineWidth = inScreen->pitch / 4;
    
    Uint32 *pixels = (Uint32 *)( inScreen->pixels );
    

    // Taille maximale du buffer (traitement par blocs)
    const int MAX_BUFFER_SIZE = 10000;
    Uint32 buffer[MAX_BUFFER_SIZE];
    
    for( int y=0; y<inHeight; y++ ) {
        for( int x=0; x<inWidth; x++ ) {

            Uint32 pixelValue = inImage[ y * inWidth + x ];
            
            // Coordonnées de destination
            int destX = xOffset + x * inBlowFactor;
            int destY = yOffset + y * inBlowFactor;
            
            // Remplir chaque bloc de pixels
            for( int dy=0; dy<inBlowFactor; dy++ ) {
                int rowIndex = ( destY + dy ) * scanlineWidth + destX;
                
                // Remplir horizontalement
                for( int dx=0; dx<inBlowFactor; dx++ ) {
                    pixels[ rowIndex + dx ] = pixelValue;
                }
            }
        }
    }
}
