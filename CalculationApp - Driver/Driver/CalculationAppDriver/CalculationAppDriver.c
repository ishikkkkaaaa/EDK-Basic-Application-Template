#include <Uefi.h>          
#include <Library/BaseLib.h>    // for StrCmp
#include <Library/UefiLib.h>  // for Print
#include <Library/UefiDriverEntryPoint.h> 
#include <Library/MemoryAllocationLib.h> // for AllocateZeroPool
#include <Library/BaseMemoryLib.h> // for SetMem
#include <Library/UefiBootServicesTableLib.h> // for gBS

#include <Protocol/CalculationAppProtocol.h> // for CALCULATION_APP_PROTOCOL

/* Creating a function which is going to be exposed */
EFI_STATUS      
EFIAPI 
PrintGivenString(
    IN CHAR16 *InputString
)
{
    if(InputString == NULL)
    {
        return EFI_INVALID_PARAMETER;
    }

    Print(L"Input String is %s\n", InputString);
    return EFI_SUCCESS;
}

EFI_STATUS      
EFIAPI          
CalculationAppDriverEntry(
  IN EFI_HANDLE        ImageHandle, 
  IN EFI_SYSTEM_TABLE  *SystemTable     
  )
{
    EFI_STATUS Status = EFI_NOT_FOUND;  
/*  for creating a protocol we need to have the initial class defined*/

    CALCULATION_APP_PROTOCOL *CalculationAppProtocol = NULL;

    CalculationAppProtocol = AllocateZeroPool(sizeof(CALCULATION_APP_PROTOCOL));
    if(CalculationAppProtocol == L("NULL"))
    {
        return EFI_OUT_OF_RESOURCES;   // if the memory is not available
    }

    CalculationAppProtocol->PrintGivenString = PrintGivenString; // assigning the function to the protocol

    Status = gBS->InstallProtocolInterface(
        &ImageHandle,
        &gCalculationAppGuid,
        EFI_NATIVE_INTERFACE,
        CalculationAppProtocol
    );
    return Status;
}