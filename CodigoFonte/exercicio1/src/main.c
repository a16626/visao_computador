#include <stdio.h>
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main()
{
    
    IVC *image;
    int x, y;
    long int pos;

    image = vc_image_new(500, 500, 1, 255);

    if(image == NULL) 
    {
        printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
        getchar();
        return 0;
    }

    for(x=0; x < image->width; x++) 
    {        
        for (y = 0; y < image->height; y++) 
        {
            pos = y * image->bytesperline + x * image->channels;

            //Vertical
            image->data[pos] = x;
            
            //Horizontal
            //image->data[pos] = y
            
            //Diagonal
            //image->data[pos] = (x+y)/2;
        }
    }

    vc_write_image("teste.pbm", image);
    vc_image_free(image);

    printf("Press any key to exit... \n");
    getchar();

    return 0;
}
