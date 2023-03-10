#ifndef _CALCULATION_APP_PROTOCOL_H_
#define _CALCULATION_APP_PROTOCOL_H_

#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

typedef struct _CALCULATION_APP_PROTOCOL CALCULATION_APP_PROTOCOL;

typedef EFI_STATUS (*PRINT_INPUT_STRING)(IN CHAR16 *InputString);

struct _CALCULATION_APP_PROTOCOL
{
    PRINT_INPUT_STRING PrintGivenString;                    // Function pointer to print input string
} ;

#endif /*_CALCULATION_APP_PROTOCOL_H*/