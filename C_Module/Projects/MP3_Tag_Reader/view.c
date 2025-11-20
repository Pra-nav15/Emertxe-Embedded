#include <stdio.h>
#include <string.h>
#include "view.h"
#include "types.h"

Status read_and_validate_mp3_view(char *argv[], ViewInfo *vInfo) //validate command line arguments for view
{
    char* extn = strstr(argv[2], ".mp3"); // Searches for ".mp3" extension in the filename.
    if (extn != NULL && strcmp(extn, ".mp3") == 0) // Checks if extension exists and is exactly ".mp3".
    {
        strcpy(vInfo->audio_file_name,argv[2]); // Stores valid MP3 filename to a structure member.
        return success;
    }
    else
    {
        printf("\033[1;31mError! The Audio File Must be in .mp3 format\033[0m\n");
        return failure;
    }
}

Status open_files_view(ViewInfo *vInfo) // Function to open MP3 file for reading.
{
    vInfo->fptr_audiofile = fopen(vInfo->audio_file_name, "r");  // Opens the file in read mode.
    if (vInfo->fptr_audiofile == NULL)
    {
        perror("\033[1;31mfopen\033[0m");
        fprintf(stderr, "\033[1;31mERROR: Unable to open mp3 file %s\033[0m\n", vInfo->audio_file_name);
        return failure;
    }
    return success;
}

Status ID3_Validate_view(ViewInfo *vInfo)  // Function to validate ID3 header
{   //First 10 bytes is the header
    fread(vInfo->header, 1, 3, vInfo->fptr_audiofile);  // Reads first 3 bytes to check for "ID3".
    if (strcmp(vInfo->header, "ID3")== 0)
    {
        printf("\033[1;36mHeader ID: \033[1;33m%s\033[0m\n", vInfo->header);
        fread(vInfo->version, sizeof(char), 2, vInfo->fptr_audiofile); // Reads next 2 bytes to check for version.(2.3)
        if (vInfo->version[0] == 3 && vInfo->version[1] == 0)  // Checks if version is 2.3.
        {
            printf("\033[1;36mVersion:\033[1;33m %d.%d\033[0m\n", vInfo->version[0],vInfo->version[1]);
            fseek(vInfo->fptr_audiofile, 5, SEEK_CUR); // Skips 5 bytes of from 10 bytes of header (1 byte flag + 4 bytes size)
            return success;
        }
        else
        {
            printf("\033[1;31mNot a valid MP3 Version,ID3 Version Should be 2.3\033[0m\n");
            return failure;
        }
    }
    else
    {
        printf("ID3 Tag Not Found,Not a valid MP3 file\033[0m\n");
        return failure;
    }
} 

Status view_frame(ViewInfo *vInfo) // Function to read and print contents of each frames
{
    uint temp,size;
    fread(&temp, 1, 4, vInfo->fptr_audiofile); // Reads 4 bytes of frame size
    big2little_convert(&temp, 4); // Converts big-endian to little-endian
    size = temp; // Stores converted size
    fseek(vInfo->fptr_audiofile, 3, SEEK_CUR); // Skips encoding byte + 2 byte , total 3 bytes
    for (int i = 0;i < size - 1;i++) // Loops through characters in frame
    {
        char ch;
        fread(&ch, 1, 1, vInfo->fptr_audiofile); // Reads one character from file
        printf("\033[1;33m%c\033[0m", ch);
    }
    printf("\n\033[1;35m---------------------------------------------------------------\n");
    return success;
}

void big2little_convert(void* n, int size) // Converts byte-order from big-endian to little-endian
{
    char *ptr = (char *)n; // Converts generic pointer to char pointer
    for (int i = 0; i < size / 2; i++) // Swaps bytes from both ends
    {
        char temp = *(ptr + i);
        *(ptr + i) = *(ptr + size - 1 - i);
        *(ptr + size - 1 - i) = temp;
    }
}

Status view(ViewInfo *vInfo) // Main function for viewing all MP3 tag values
{
    int title_found = 0, album_found = 0, artist_found = 0, year_found = 0, content_found = 0, comment_found = 0; // Flags for each tag
    printf("\033[1;35m===============================================================\n");
    printf("\033[1;33m             MP3 TAG DETAILS VIEW FOR ID3 V2.3     \033[0m\n");
    printf("\033[1;35m===============================================================\n");
    if (open_files_view(vInfo) == success)
    {
        printf("\033[1;32mMP3 Audio File Opened Successfully\033[0m\n");
        if (ID3_Validate_view(vInfo) == success)
        {
            printf("\033[1;32mMP3 Header ID and Version Validated Successfully\033[0m\n");
            printf("\033[1;35m---------------------------------------------------------------\n");
            uint frame_size;
            while (1) // Infinite loop to read all frames
            {
                fread(vInfo->frame_id, 1, 4, vInfo->fptr_audiofile); // Reads frame ID (4 bytes) - 4 chars
                vInfo->frame_id[4]='\0'; // Null-terminates frame ID string.
                if(vInfo->frame_id[0]==0) // If zero padding --> indicates end of frames
                {
                    break;
                }
                if(strcmp(vInfo->frame_id,"TIT2")==0)  // Checks Title frame
                {
                    printf("\033[1;36mTitle        : \033[0m");
                    if (view_frame(vInfo) == success)
                    {
                        title_found = 1;
                    }
                }
                else if(strcmp(vInfo->frame_id,"TPE1")==0)  // Checks Artist frame
                {
                    printf("\033[1;36mArtist       : \033[0m");
                    if (view_frame(vInfo) == success)
                    {
                        artist_found = 1;
                    }
                }
                else if(strcmp(vInfo->frame_id,"TALB")==0)  // Checks Album frame
                {
                    printf("\033[1;36mAlbum        : \033[0m");
                    if (view_frame(vInfo) == success)
                    {
                        album_found = 1;
                    }
                }
                else if(strcmp(vInfo->frame_id,"TYER")==0)  // Checks Year frame
                {
                    printf("\033[1;36mYear         : \033[0m");
                    if (view_frame(vInfo) == success)
                    {
                        year_found = 1;
                    }
                }
                else if(strcmp(vInfo->frame_id,"TCON")==0)  // Checks Content frame
                {
                    printf("\033[1;36mContent      : \033[0m");
                    if (view_frame(vInfo) == success)
                    {
                        content_found = 1;
                    }
                }
                else if(strcmp(vInfo->frame_id,"COMM")==0)  // Checks Comment frame
                {
                    printf("\033[1;36mComments     : \033[0m");
                    if (view_frame(vInfo) == success)
                    {
                        comment_found = 1;
                    }
                } 
                else  // Unknown frame.
                {
                    fread(&frame_size, 1, 4, vInfo->fptr_audiofile); // Reads its size
                    big2little_convert(&frame_size,4); // Convert its size to little endian
                    fseek(vInfo->fptr_audiofile, 2 + frame_size, SEEK_CUR); // Skips frame data
                }
            }
            // if any of the frames are not found
            if (!title_found)
            {
                printf("\033[1;31mTitle frame not found\033[0m\n");
            }
            if (!artist_found)
            {
                printf("\033[1;31mArtist frame not found\033[0m\n");
            }
            if (!album_found)
            {
                printf("\033[1;31mAlbum frame not found\033[0m\n");
            }
            if (!year_found)
            {
                printf("\033[1;31mYear frame not found\033[0m\n");
            }
            if (!content_found)
            {
                printf("\033[1;31mContent Type not found\033[0m\n");
            }
            if (!comment_found)
            {
                printf("\033[1;31mComment frame not found\033[0m\n");
            }
            return success;
        }
        else
        {
            printf("\033[1;31mError! Invalid ID3 header\033[0m\n");
            return failure;
        }
    }
    else
    {
        printf("\033[1;31mError! FIles Couldn't be Opened\033[0m\n");
        return failure;
    }
}


