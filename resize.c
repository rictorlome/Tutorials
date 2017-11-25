/**
 * Resizes a standard 24-bit BMP file. This resize file is built off a pre-existing program called copy.c, which copies bitmaps byte by byte.
 * Given a command line argument 'n', resize.c increases the bitmap's height and width each by n times. if n=3, 3x3 pixel BMP -> 9x9.
 * Most of the original implementation is between lines 69 and 138.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember filenames (must convert string input of n into and int.)
    char *ptr;
    int n;
    n = strtol(argv[1], &ptr, 10);
    if (n < 1)
    {
        fprintf(stderr, "Please input int n of 1 or greater\n");
        return 1;
    }
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    //test of datatype in BITMAPFILEHEADER...
    //printf("bfSize is: %i\n", bf.bfSize);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    //change values of bfSize, biWidth, biHeight, and biSizeImage. but first, i need to save these values. for when i iterate ove the original bmp.
    int oWidth = bi.biWidth;
    int oHeight = bi.biHeight;

    // determine padding for scanlines. save this old variable.
    int oPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //multiply biWidth by n
    bi.biWidth = bi.biWidth * n;

    //multiply biHeight by n
    bi.biHeight = bi.biHeight * n;

    //after i change biWidth and biHeight, do oWidth and oHeight change?
    printf("oWidth is %i,\n oHeight is %i,\n bi.biWidth is %i,\n, bi.biHeight is %i.\n", oWidth, oHeight, bi.biWidth, bi.biHeight);
    //no.

    // determine padding for new scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //bfSize = size in bytes of file. (header + 3*number of pixels + padding*height)
    bf.bfSize = 54 + (3 * bi.biWidth * abs(bi.biHeight)) + (padding * abs(bi.biHeight));

    //biSizeImage = size of file - size of header.
    bi.biSizeImage = bf.bfSize - 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines. for each scanline...
    for (int i = 0, Height = abs(oHeight); i < Height; i++)
    {
        //repeat n times. for each repetition...
        for (int q=0; q<n; q++)
        {
            //go back to the start of the row...(this does not change current position on the first repetion of the row.)
            int row_start = 54 + (oWidth * 3 * i) + oPadding*i;
            fseek(inptr, row_start, SEEK_SET);

            // iterate over pixels in scanline
            for (int j = 0; j < oWidth; j++)
            {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    // write RGB triple to outfile (n times)
                    for (int k = 0; k < n; k++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
            }

            // skip over padding, if any
            fseek(inptr, oPadding, SEEK_CUR);

            // then add back any new padding
            for (int m = 0; m < padding; m++)
            {
                fputc(0x00, outptr);
            }

        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
