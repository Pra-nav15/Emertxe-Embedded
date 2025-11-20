#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "edit.h"
#include "types.h"

Status read_and_validate_mp3_edit(char *argv[], EditInfo *eInfo) // Validates user input and stores edit option, new text, and filename
{
    strcpy(eInfo->option, argv[2]); // Store edit option to structure member after validation from main
    strncpy(eInfo->edit_content, argv[3], sizeof(eInfo->edit_content) - 1); // Copy user text from command line correctely
    eInfo->edit_content[sizeof(eInfo->edit_content) - 1] = '\0'; // Force null-termination
    char* extn = strstr(argv[4], ".mp3"); // Check for .mp3 extension
    if (extn != NULL && strcmp(extn, ".mp3") == 0)
    {
        strcpy(eInfo->audio_file_name,argv[4]);   // Save mp3 file name
        return success;
    }
    else
    {
        printf("\033[1;31mError: The Audio File Must be in .mp3 format\033[0m\n");
        return failure;
    }
}

Status open_files_edit(EditInfo* eInfo)
{
    eInfo->fptr_audiofile = fopen(eInfo->audio_file_name, "rb"); // Open Input MP3 File  in read-binary
    if (eInfo->fptr_audiofile == NULL)
    {
        perror("\033[1;31mfopen\033[0m");
        fprintf(stderr, "\033[1;31mERROR: Unable to Audio open file %s\033[0m\n", eInfo->audio_file_name);
        return failure;
    }
    //when edit option is chosen create a file for backup
    strcpy(eInfo->backup_file_name, "backup.mp3");  // Name backup file manually by default name
    eInfo->fptr_backupfile = fopen(eInfo->backup_file_name, "wb"); // Open backup in write-binary
    if (eInfo->fptr_backupfile == NULL)
    {
        perror("\033[1;31mfopen\033[0m");
        fprintf(stderr, "\033[1;31mERROR: Unable to Audio open file %s\033[0m\n", eInfo->audio_file_name);
        fclose(eInfo->fptr_audiofile);
        return failure;
    }
    return success;
}

Status ID3_Validate_edit(EditInfo* eInfo)
{
    if (fread(eInfo->header, 1, 10, eInfo->fptr_audiofile) != 10) // Read 10-byte ID3 header
    {
        printf("\033[1;31mError: Could not read header\033[0m\n");
        return failure;
    }
    if (strncmp(eInfo->header, "ID3", 3) == 0)   // Check "ID3"
    {
        printf("\033[1;33mHeader ID: %s\033[0m\n", eInfo->header); 
        if (eInfo->header[3] == 3 && eInfo->header[4] == 0) // Validate version 2.3
        {
            printf("\033[1;33mID3 Version: %d.%d\033[0m\n", eInfo->header[3], eInfo->header[4]);
            rewind(eInfo->fptr_audiofile); // Go back to start of file
            fwrite(eInfo->header, 1, 10, eInfo->fptr_backupfile); // After validation copy 10 bytes of ID3 header directly to backup file
            fseek(eInfo->fptr_audiofile, 10, SEEK_SET);  // Skip past header
            return success;
        }
        else
        {
            printf("\033[1;31mError: Not a valid MP3 Version,ID3 Version Should be 2.3\033[0m\n");
            return failure;
        }
    }
    else
    {
        printf("\033[1;31mID3 Tag Not Found,Not a valid MP3 file\033[0m\n");
        return failure;
    }
}
Status edit_frame(EditInfo *eInfo, const char *target_frame)
{
    uint new_content_size = strlen(eInfo->edit_content);  // New text length
    uint temp, size;
    int flag = 0; // Flag to track frame found
    while (1)
    {
        if (fread(eInfo->frame_id, 1, 4, eInfo->fptr_audiofile) != 4 || eInfo->frame_id[0] == 0x00) //Read 4 bytes of Frame id
        {
            break;  // Stop when frames end or padding begins
        }
        eInfo->frame_id[4] = '\0';  // Add '\0' to make it a string
        if (strcmp(eInfo->frame_id, target_frame) == 0)  // Check if this is the frame to edit
        {
            printf("\033[1;34mEditing %s.......\n", target_frame);
            //Reading
            flag = 1;   // Set found flag
            fread(&temp, 1, 4, eInfo->fptr_audiofile); //Read 4 bytes of Frame id size
            size_convert(&temp, sizeof(temp)); // Convert big-endian to little-endian
            size = temp;  // Store it to size
            fread(eInfo->frame_flags, 1, 2, eInfo->fptr_audiofile); // Read 2 bytes flags
            fread(eInfo->frame_encoding, 1, 1, eInfo->fptr_audiofile); // Read encoding byte
            //Writing
            fwrite(eInfo->frame_id, 1, 4, eInfo->fptr_backupfile); // Write 4 bytes Frame id to backup file
            uint new_size = 1 + new_content_size;  // New size = encoding byte + text
            uint temp_new_size = new_size; // Store it to temp variable
            size_convert(&temp_new_size, sizeof(temp_new_size)); // Convert little endian to big-endian
            fwrite(&temp_new_size, 1, 4, eInfo->fptr_backupfile); // Write 4 bytes Frame id size to backup file
            fwrite(eInfo->frame_flags, 1, 2, eInfo->fptr_backupfile); // Write 2 bytes Frame flags to backup file
            fwrite(eInfo->frame_encoding, 1, 1, eInfo->fptr_backupfile); // Write 1 byte Encoding byte to backup file
            fwrite(eInfo->edit_content, 1, new_content_size, eInfo->fptr_backupfile); // Write updated text
            fseek(eInfo->fptr_audiofile, size - 1, SEEK_CUR); // Skip old content in original file
            printf("\033[1;36m%s is Now Updated with %s\n", eInfo->frame_id, eInfo->edit_content);
        }
        else
        {
            fwrite(eInfo->frame_id, 1, 4, eInfo->fptr_backupfile); // Copy frame ID unchanged directly
            fread(&temp, 1, 4, eInfo->fptr_audiofile); //Read 4 bytes of frame id size from input file
            size_convert(&temp, 4); // Convert big-endian to little-endian
            uint frame_size = temp; // Store original frame size
            uint new_frame_size = temp; // Copy frame size for conversion
            size_convert(&new_frame_size, 4); // Convert little-endian to big-endian
            fwrite(&new_frame_size, 1, 4, eInfo->fptr_backupfile); // Write updated size to backup file
            // Read and Write 2-byte frame flags directly
            fread(eInfo->frame_flags, 1, 2, eInfo->fptr_audiofile);
            fwrite(eInfo->frame_flags, 1, 2, eInfo->fptr_backupfile);
            // Read and Write 1-byte encoding byte directly
            fread(eInfo->frame_encoding, 1, 1, eInfo->fptr_audiofile);
            fwrite(eInfo->frame_encoding, 1, 1, eInfo->fptr_backupfile);
            uint content_size = frame_size - 1;  // Actual text size = frame size - encoding byte
            char *buffer = malloc(content_size); // Allocate buffer for content
            fread(buffer, 1, content_size, eInfo->fptr_audiofile); // Read frame content from input file
            fwrite(buffer, 1, content_size, eInfo->fptr_backupfile); // Write frame content to backup file
            free(buffer);
        }
    }
    // Copy remaining audio data after frame processing
    unsigned char buffer[4096]; // 4KB block buffer
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), eInfo->fptr_audiofile)) > 0)
    {
        fwrite(buffer, 1, bytes, eInfo->fptr_backupfile); // Write each remaining byte to backup file
    }
    fclose(eInfo->fptr_audiofile); //close input mp3 file
    fclose(eInfo->fptr_backupfile); //close backup file
    if (flag == 0)  // Frame not found check
    {
        printf("\033[1;31m%s frame not found\033[0m\n", target_frame);
        return failure;
    }
    remove(eInfo->audio_file_name);  // Delete original input mp3 file
    rename(eInfo->backup_file_name, eInfo->audio_file_name); // Rename our backup mp3 file with the input file name
    return success;
}

void size_convert(void* n, int size) // Convert byte order (endian swap) (little to big and big to little)
{
    char *ptr = (char *)n; // generic pointer to char pointer
    for (int i = 0; i < size / 2; i++) // Swap bytes from both ends
    {
        char temp = *(ptr + i);
        *(ptr + i) = *(ptr + size - 1 - i);
        *(ptr + size - 1 - i) = temp;
    }
}

Status edit(char* argv[], EditInfo* eInfo)
{
    if (open_files_edit(eInfo) == success)
    {
        printf("\033[1;32mMP3 Audio File Opened Successfully\033[0m\n");
        if (ID3_Validate_edit(eInfo) == success)
        {
            printf("\033[1;32mMP3 Header ID and Version Validated Successfully\033[0m\n");
            if (strcmp(eInfo->option, "-t") == 0) // If user selected -t (edit title)
            {
                if (edit_frame(eInfo, "TIT2") == success) // Edit the title frame (TIT2)
                {
                    printf("\033[1;32mTitle Edited Successfully\033[0m\n");
                    return success;
                }
                else
                {
                    printf("\033[1;31mTitle Edit Failed\033[0m\n");
                    return failure;
                }
            }
            if (strcmp(eInfo->option, "-a") == 0) // If user selected -a (edit artist)
            {
                if (edit_frame(eInfo, "TPE1") == success) // Edit the artist frame (TPE1)
                {
                    printf("\033[1;32mArtist Name Edited Successfully\033[0m\n");
                    return success;
                }
                else
                {
                    printf("\033[1;31mArtist Name Edit Failed\033[0m\n");
                    return failure;
                }
            }
            if (strcmp(eInfo->option, "-A") == 0) // If user selected -A (edit album)
            {
                if (edit_frame(eInfo, "TALB") == success) // Edit the album frame (TALB)
                {
                    printf("\033[1;32mAlbum Name Edited Successfully\033[0m\n");
                    return success;
                }
                else
                {
                    printf("\033[1;31mAlbum Name Edit Failed\033[0m\n");
                    return failure;
                }
            }
            if (strcmp(eInfo->option, "-y") == 0) // If user selected -y (edit year)
            {
                if (edit_frame(eInfo, "TYER") == success) // Edit the year frame (TYER)
                {
                    printf("\033[1;32mYear Edited Successfully\033[0m\n");
                    return success;
                }
                else
                {
                    printf("\033[1;31mYear Edit Failed\033[0m\n");
                    return failure;
                }
            }
            if (strcmp(eInfo->option, "-c") == 0) // If user selected -c (edit content)
            {
                if (edit_frame(eInfo, "TCON") == success) // Edit the content frame (TCON)
                {
                    printf("\033[1;32mContent Type Edited Successfully\033[0m\n");
                    return success;
                }
                else
                {
                    printf("\033[1;31mContent Type Edit Failed\033[0m\n");
                    return failure;
                }
            }
            if (strcmp(eInfo->option, "-m") == 0) // If user selected -m (edit comment)
            {
                if (edit_frame(eInfo, "COMM") == success) // Edit the comment frame (COMM)
                {
                    printf("\033[1;32mComments Edited Successfully\033[0m\n");
                    return success;
                }
                else
                {
                    printf("\033[1;31mComments Edit Failed\033[0m\n");
                    return failure;
                }
            }
        }
        else
        {
            printf("\033[1;31mError! Invalid ID3 header\033[0m\n");
            return failure;
        }
    }
    else
    {
        printf("\033[1;31mError! Files Couldn't be Opened\033[0m\n");
        return failure;
    }
}

