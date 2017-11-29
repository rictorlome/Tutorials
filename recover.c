/*
This program reads a block of memory and pulls out the JPEGs. The idea is that this is a forensic tool, which can access deleted
JPEGs by reading the underlying bytes. It works using two assumptions:
1.) that JPEGs start with the same header 0xffd8ffe
2.) that JPEGs are written onto memory in contiguous blocks of size 512 bytes, so that you can iterate(read/write) block by block
(this means that the start of a JPEG will only fall on byte 512, 1024, etc..)

the data sample that this was tested on was provided by the cs50 ide. I think the file at the below link is identical.
https://github.com/CoreData/cs50/blob/master/pset4/jpg/card.raw

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        //ensure proper usage.
        fprintf(stderr, "Usage: ./recover recoveryfile\n");
        return 1;
    }
    //remember input filename.
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");

    // if it cannot open, print an error message.
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //get size of file by seeking the end of the file, storing byte position in an int, and then rewinding
    fseek(inptr, 0L, SEEK_END);
    int sz = ftell(inptr);
    rewind(inptr);

    //create boolean which will be used in test conditions to determine whether or not to write block into outfile.
    bool in_JPEG = false;

    //create a name for the 1st output file.
    char outfile[50];
    int jpeg_num = 0;
    sprintf(outfile,"%03i.JPG", jpeg_num);

    // create and open output file
    FILE *outptr = fopen(outfile, "w");
    // if it doesn't open, print an error message.
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    /*the 1st file is not a jpg and needs to be deleted. I don't know how to avoid creating it
    up here, even though I don't really need it because of the logic in the for-loop, which closes
    the previous file if it is the start of a new one. i cannot close outptr without first declaring it.
    */
    remove(outfile);

    //loop through input file's blocks. for each block...
    for (int i = 0; i < sz/512; i++)
    {
        // create temporary storage for and then read infile's block into an array called buffer.
        unsigned char* buffer = malloc(512);
        fread(buffer, 512, 1, inptr);

        //if you are already in a JPEG, but it is not the start of a new one, keep adding to it.
        if (in_JPEG)
        {
            fwrite(buffer, 512, 1, outptr);
        }

        //check whether the current block is the start of a new JPG.
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //if so, set in_JPEG to true, close previous/make new output, write block to new output
            in_JPEG = true;

            //close the current output file, and create the name for the new one.
            fclose(outptr);
            jpeg_num++;
            sprintf(outfile,"%03i.JPG", jpeg_num);

            // create and open output file
            outptr = fopen(outfile, "w");
            // if it doesn't open, print an error message.
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", outfile);
                return 3;
            }
            // write the block(s) to the output file.
            fwrite(buffer, 512, 1, outptr);
        }
        //after each iteration, free buffer so that the next block can be written into it.
        free(buffer);
    }
    //close input file
    fclose(inptr);

    //close last output file
    fclose(outptr);

    //success
    return 0;
}
