#include "ExtFS.h"


NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
	)
{
	NTSTATUS status = STATUS_SUCCESS;
	UNICODE_STRING deviceName;

	UNREFERENCED_PARAMETER(RegistryPath);

	DBG_PRINT(PTDBG_TRACE_ROUTINES,
		("ExtFS: DriverEntry: Entered\n"));

	RtlInitUnicodeString(&deviceName, EXT_FS_DEVICE_NAME);
	status = IoCreateDevice(DriverObject,
		0,
		&deviceName,
		FILE_DEVICE_DISK_FILE_SYSTEM,
		0,
		FALSE,
		&ExtFSDeviceObject);
	if (!NT_SUCCESS(status))
	{
		DBG_PRINT(PTDBG_TRACE_OPERATION_STATUS,
			("ExtFS: DriverEntry: Unable to create device. Status: %08x\n", status));
		return status;
	}

	DriverObject->DriverUnload = ExtFSUnload;

	DriverObject->MajorFunction[IRP_MJ_CREATE] = ExtFSCreate;

	IoRegisterFileSystem(ExtFSDeviceObject);
	ObReferenceObject(ExtFSDeviceObject);

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

NTSTATUS
ExtFSCreate(
	_In_ PDEVICE_OBJECT DeviceObject,
	_In_ PIRP           Irp
	)
{
	NTSTATUS status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(DeviceObject);

	DBG_PRINT(PTDBG_TRACE_ROUTINES,
		("ExtFS: ExtFSCreate: Entered\n"));

	Irp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	return status;
}

