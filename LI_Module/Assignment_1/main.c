/*
 * A01 - Implement a cp(copy) command with –p option
 *
 * Usage:
 *   ./my_copy source dest
 *   ./my_copy -p source dest
 *
 * Requirements:
 * - If dest exists: ask confirmation "File dest-file already exists. Do you want to overwrite (Y/n)"
 *   If 'n'/'N' => don't overwrite and exit.
 *   If 'Y'/'y' or Enter => overwrite.
 * - Copy should preserve size including 0-sized files.
 * - -p should copy permissions from source to dest (use fstat + fchmod / open mode logic).
 * - Implement: int my_copy(int source_fd, int dest_fd);
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int my_copy(int source_fd, int dest_fd) 
{
    // TODO: implement read/write loop; return 0 on success, -1 on failure
    // Hint: handle partial writes.
    char ch;
    while(read(source_fd,&ch,1) != 0)
    {
        write(dest_fd,&ch,1);
    }
    return -1;
}

static void usage(const char *prog) 
{
    fprintf(stderr, "Usage:- %s [option]\n", prog);
    fprintf(stderr, "  %s source_file dest_file\n", prog);
    fprintf(stderr, "  %s -p source_file dest_file\n", prog);
}

int main(int argc, char *argv[]) 
{
    // TODO: parse args, validate, implement overwrite prompt, create/open files,
    // call my_copy(), optionally copy permissions when -p is given.
    // Make sure to handle errors and print meaningful messages to stderr
    if (argc < 2)
    {
        usage("my_copy");
        return -1;
    }
    int src_fd, dest_fd;
    src_fd = open(argv[1], O_RDONLY, 0600);
    if (src_fd == -1)
    {
        perror("ERROR");
        return -1;
    }
    char* dest_file;
    if (argc >= 3)
    {
        dest_file = argv[2];
    }
    else
    {
        dest_file = "dest.txt";
    }
    dest_fd = open(dest_file, O_CREAT | O_EXCL | O_WRONLY, 0600);
    if (dest_fd == -1)
    {
        if (errno == EEXIST)
        {
            dest_fd = open(dest_file, O_CREAT | O_TRUNC | O_WRONLY, 0600);
            my_copy(src_fd, dest_fd);
        }
        else
        {
            perror("open");
            return -1;
        }
    }
    else
    {
        my_copy(src_fd, dest_fd);
    }
}