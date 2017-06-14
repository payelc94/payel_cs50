/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>


const int size = 512;
// 
int main(int argc, char* argv[])
{
    
    FILE *file, *file_w = NULL;
    char file_new[8];
    
    
    
     if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image \n");
        return 1;
    }
    
  
  
    if((file = fopen(argv[1], "r"))==NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 2;
    }
   
    
    uint8_t buf[size];
    int c = 0;
    
    
    while(fread(buf, size, 1, file))
    {
        if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] == 0xe0 || buf[3] == 0xe1))
        {
            if(file_w != NULL)
            {
                fclose(file_w);
            }
            
            
            sprintf(file_new, "%03d.jpg", c);
            file_w = fopen(file_new,"w");
            c++;
        }
        
        if(file_w != NULL)
        {
            fwrite(buf, size, 1, file_w);
        }
    }
    if(file_w != NULL)
    {
        fclose(file_w);
    }
        
        
        
    fclose(file);
    return 0;
}
