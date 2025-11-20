/*
                                  Project Documentation- MP3 Tag Reader
Name: Pranav Prasad
Date: 18/11/2025
Description:
• This project is an Command Line Based MP3 Tag Reader and Editor Software made in C.
• MP3 tag reader is a software which will read and display MP3 (ID3) tag information from MP3 files.
• The system operates with : View Mode to show existing tags, Edit Mode to update tag information, and Help Mode to provide instructions.
• During view operation, it reads the ID3 header, checks ID3 version, and displays details like Title, Artist, Album, Year, Content, and Comments.
• During edit operation, it updates selected frames such as TIT2, TPE1, TALB, TYER, TCON, and COMM with new user-given text via command line.
• This project supports only ID3 Version 2.3 because its frame structure is simple and consistent to parse.
• The program validates file format (.mp3), checks header bytes, identifies frame IDs, and handles endianness conversion.
• It creates a backup file during editing, writes updated metadata into it, and safely replaces the original file.
• Error handling is included for missing tags, invalid MP3 files, unsupported versions, and incorrect command-line arguments.
• This system is mainly used for maintaining music libraries, correcting metadata, organizing songs, and learning audio tag formats.
• Advantages include easy metadata viewing, safe editing, modular code structure, and complete control over tag frames.
• File handling, pointers, structures, dynamic memory allocation, and command-line arguments are used in this project.
• This project helps in understanding how MP3 ID3 tags work internally and how text metadata is stored and edited inside audio files.
*/

#include <stdio.h>
#include <string.h>
#include "view.h"
#include "edit.h"
#include "types.h"

ViewInfo vInfo; // Structure to store MP3 view information.
EditInfo eInfo; // Structure to store MP3 edit information.
OperationType check_operation_type(char*); // Function prototype to determine operation type
int main(int argc, char* argv[])
{
    if (argc < 2)  // If no argument is given (only ./a.out).
    {
        printf("\033[1;31mERROR: ./a.out : INVALID ARGUMENTS\033[0m\n");
        printf("\033[1;33mUSAGE :\033[0m\n");
        printf("\033[1;33mTo view please pass like:  ./a.out -v mp3filename\033[0m\n");
        printf("\033[1;33mTo edit please pass like:  ./a.out -e -t/-a/-A/m/-y/-c changing_text mp3filename\033[0m\n");
        printf("\033[1;33mTo help please pass like:  ./a.out -help\033[0m\n");
        return failure;
    }
    
    if (check_operation_type(argv[1]) == mp3_help) // If first argument is -help
    {
        printf("\033[1;35m====================================================\033[0m\n");
        printf("\033[1;33m              MP3 TAG READER - HELP MENU        \033[0m\n");
        printf("\033[1;35m====================================================\033[0m\n");

        printf("\033[1;36m %-11s | %20s \033[0m\n", "OPTION", "DESCRIPTION");
        printf("\033[1;35m----------------------------------------------------\033[0m\n");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-v", "View MP3 file contents");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-e", "Edit MP3 file contents");
        printf("\033[1;35m----------------------------------------------------\033[0m\n");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-t", "Edit Song Title");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-a", "Edit Artist Name");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-A", "Edit Album Name");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-y", "Edit Year");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-m", "Edit Content/Genre");
        printf("\033[1;33m| %-10s | %-35s |\033[0m\n", "-c", "Edit Comment");
        printf("\033[1;35m----------------------------------------------------\033[0m\n");

    }
    else if(check_operation_type(argv[1]) == mp3_view) // If first argument is -v
    {
        if (argc==3)  // View requires exactly 3 arguments.
        {
            if (read_and_validate_mp3_view(argv, &vInfo) == success) //validate the command line arguments
            {
                if (view(&vInfo) == success) //view mp3 tags
                {
                    printf("\033[1;32mAll Song Details Displayed Successfully\033[0m\n");
                    return success;
                }
            }
            else
            {
                printf("\033[1;31mUnable to View Song Details\033[0m\n");
                return failure;
            }
        }
        else
        {
            printf("\033[1;31mError! 3 Arguments are required for MP3 View\033[0m\n");
            return failure;
        }

    }
    else if(check_operation_type(argv[1]) == mp3_edit) // If first argument is -e
    {
        if (argc == 5)  // Edit requires exactly 5 arguments.
        {
            if (strcmp(argv[2], "-t") == 0 || strcmp(argv[2], "-a") == 0 || strcmp(argv[2], "-A") == 0 || strcmp(argv[2], "-y") == 0 || strcmp(argv[2], "-c") == 0 || strcmp(argv[2], "-m") == 0) // Check if valid edit option is given
            {
                if (read_and_validate_mp3_edit(argv, &eInfo) == success) //validate the command line arguments
                {
                    if (edit(argv, &eInfo) == success) //edit mp3 tags
                    {
                        return success;
                    }
                }
                else
                {
                    printf("\033[1;31mUnable to Edit Song Details\033[0m\n");
                    return failure;
                }
            }
            else
            {
                printf("\033[1;31mInvalid Edit Option Entered.Check Help Menu\033[0m\n");
                return failure;
            }
        }
        else
        {
            printf("\033[1;31mError! 5 Arguments are required for MP3 Edit\033[0m\n");
            return failure;
        }
    }
    else // If argument is neither -v, -e, nor -help.
    {
        printf("\033[1;31mError! Invalid Operation Type.Check Help Menu\033[0m\n");
        return failure;
    }
}
OperationType check_operation_type(char* symbol)
{
    if (strcmp(symbol, "-help") == 0)
    {
        return mp3_help; //Check symbol is -help or not, true->selected help menu
    }
    else if (strcmp(symbol, "-v") == 0)
    {
        return mp3_view; //Check symbol is -v or not, true->selected view mp3 tags
    }
    else if (strcmp(symbol, "-e") == 0)
    {
        return mp3_edit;  //Check symbol is -e or not, true->selected edit mp3 tags
    }
    else
    {
        return mp3_unsupported; //if symbol other than -help,-v and -e, true->unsupported 
    }
}

   
