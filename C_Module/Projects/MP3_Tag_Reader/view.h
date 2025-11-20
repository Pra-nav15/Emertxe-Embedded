#ifndef VIEW_H
#define VIEW_H
#include <stdio.h>

#include "types.h" // Contains user defined types

typedef struct _ViewInfo
{
    FILE *fptr_audiofile;          // Audio file pointer
    char audio_file_name[100];     // Input MP3 filename
    char header[4];                // Store ID3 Header
    char version[3];               // Store ID3 Version e.g. 03 00
    char frame_id[5];              // Store Frame id + '\0'
    uint frame_id_size;            // Store size of Frame id
} ViewInfo;

/* View function prototype */
Status read_and_validate_mp3_view(char* argv[], ViewInfo* vInfo);
Status open_files_view(ViewInfo *vInfo);
Status ID3_Validate_view(ViewInfo *vInfo);
Status view_frame(ViewInfo* vInfo);
void big2little_convert(void *n, int size);
Status view(ViewInfo *vInfo);

#endif