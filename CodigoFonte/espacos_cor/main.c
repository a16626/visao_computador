#include <stdio.h>
#include "../src/vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main()
{

    IVC *image;
    
    
    image = vc_read_image("../../Images/Classic/airplane.ppm");

    if(image == NULL)
    {
        printf("ERROR -> vc_read_image():\n\tFile not found!\n");
        getchar();
        return 0;
    }

    vc_rgb_negative(image);

    vc_write_image("../Results/negativeImage.pgm", image);

    vc_image_free(image);

    return 0;
}