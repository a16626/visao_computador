#include <stdio.h>
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main()
{
    IVC *image;
    int i;

    image = vc_read_image("../Images/FLIR/flir-01.pgm");

    if(image == NULL)
    {
        printf("ERROR -> vc_read_image():\n\tFile not found!\n");
        getchar();
        return 0;
    }

    vc_write_image("Results/vc-0001.pbm", image);

    vc_image_free(image);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}
