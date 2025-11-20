#ifndef TYPES_H
#define TYPES_H

/* User defined types */
typedef unsigned int uint;

/* Status will be used in fn. return type */
typedef enum
{
    success,
    failure,
} Status;

typedef enum
{
    mp3_help,
    mp3_view,
    mp3_edit,
    mp3_unsupported,
} OperationType;
/* OperationType will be used in fn. return type in main fn */

#endif
