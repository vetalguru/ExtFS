#include "ExtFS.h"



NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
	)
{
	NTSTATUS status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	DBG_PRINT(PTDBG_TRACE_ROUTINES,
		("ExtFS: DriverEntry: Entered\n"));

	return status;
}


VOID
ExtFSUnload(
	_In_ PDRIVER_OBJECT DriverObject
	)
{
	UNREFERENCED_PARAMETER(DriverObject);

	DBG_PRINT(PTDBG_TRACE_ROUTINES,
		("ExtFS: ExtFSUnload: Entered\n"));
}
