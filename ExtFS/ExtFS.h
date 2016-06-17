#ifndef EXT_FS_H_4F5B28CE_34F2_4CBE_8382_6459FAD3E6AF
#define EXT_FS_H_4F5B28CE_34F2_4CBE_8382_6459FAD3E6AF
#include <wdm.h>

DRIVER_INITIALIZE DriverEntry;

#ifdef ALLOC_PRAGMA
	#pragma alloc_text(INIT, DriverEntry) 
#endif


NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
	);



#endif // EXT_FS_H_4F5B28CE_34F2_4CBE_8382_6459FAD3E6AF
