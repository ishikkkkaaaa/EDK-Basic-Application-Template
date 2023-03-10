#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>

#include <Protocol/CalculationAppProtocol.h>

EFI_STATUS
EFIAPI
CalculationAppEntry(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )

{
    EFI_STATUS Status = EFI_NOT_FOUND;
    CALCULATION_APP_PROTOCOL *CalculationAppProtocol = NULL;
    Print(L"Welcome to my First Training Application\n");  //CHAR 16

    Status = gBS->LocateProtocol(
        &gCalculationAppGuid,
        NULL,
        &CalculationAppProtocol
    );

    if(EFI_ERROR(Status))
    {
        Print(L"Error in locating the protocol %r\n", Status);
        return Status;
    }

    Status = CalculationAppProtocol->PrintGivenString(L"Calculation App");
    if(EFI_ERROR(Status))
    {
        Print(L"Error while PrintStrinbg %r\n", Status);
        return Status;
    }

    Status = CalculationAppProtocol->PrintGivenString(NULL);
    if(EFI_ERROR(Status))
    {
        Print(L"Error while PrintStrinbg NULL %r\n", Status);
        return Status;
    }

    return EFI_SUCCESS;
}