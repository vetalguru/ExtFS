#include "ExtFS.h"



NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
	)
{
	NTSTATUS status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	return status;
}


VOID
ExtFSUnload(
	_In_ PDRIVER_OBJECT DriverObject
	)
{
	UNREFERENCED_PARAMETER(DriverObject);
}
