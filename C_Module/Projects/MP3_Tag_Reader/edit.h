#ifndef EDIT_H
#define EDIT_H
#include <stdio.h>
#include <stdint.h>

#include "types.h" // Contains user defined types

typedef struct _EditInfo
{
    FILE* fptr_audiofile;       // Input MP3 file pointer
    FILE *fptr_backupfile;      // Output Backup MP3 file pointer
    char audio_file_name[100];  // Input filename
    char backup_file_name[100]; // Output Backup filename
    char header[10];            // 10 bytes of ID3 header
    char frame_flags[2];        // Frame flags (2 bytes)
    char frame_encoding[1];     // Encoding Byte (1 byte)
    char option[3];             // User option (e.g. -t, -a)
    char edit_content[100];     // New text to write
    char frame_id[5];           // Frame ID
} EditInfo;

/* Edit function prototype */
Status read_and_validate_mp3_edit(char* argv[], EditInfo* eInfo);
Status open_files_edit(EditInfo *eInfo);
Status ID3_Validate_edit(EditInfo *eInfo);
Status edit_frame(EditInfo *eInfo, const char *id);
void size_convert(void* n, int size);
Status edit(char* argv[], EditInfo* eInfo);
#endif