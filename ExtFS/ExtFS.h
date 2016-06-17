#ifndef EXT_FS_H_4F5B28CE_34F2_4CBE_8382_6459FAD3E6AF
#define EXT_FS_H_4F5B28CE_34F2_4CBE_8382_6459FAD3E6AF
#include <wdm.h>

DRIVER_INITIALIZE DriverEntry;
DRIVER_UNLOAD ExtFSUnload;



NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
	);

VOID
ExtFSUnload(
	_In_ PDRIVER_OBJECT DriverObject
	);



#ifdef ALLOC_PRAGMA
	#pragma alloc_text(INIT, DriverEntry)
	#pragma alloc_text(PAGE, ExtFSUnload)
#endif


#endif // EXT_FS_H_4F5B28CE_34F2_4CBE_8382_6459FAD3E6AF
