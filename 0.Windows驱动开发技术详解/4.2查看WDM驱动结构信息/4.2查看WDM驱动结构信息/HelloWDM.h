#ifdef __cplusplus
extern "C"
{
#endif
#include  <wdm.h>
#ifdef __cplusplus
}
#endif

typedef struct _DEVICE_EXTENSION
{
	PDEVICE_OBJECT	fdo;
	PDEVICE_OBJECT	NextStackDevice;
	UNICODE_STRING	ustrDeviceName;		//设备名
	UNICODE_STRING	ustrSymLinkName;	//符号链接名
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

#define arraysize(p)	(sizeof(p)/sizeof((p)[0]))

NTSTATUS HelloWDMAddDevice(IN PDRIVER_OBJECT DriverObject,
	IN PDEVICE_OBJECT PhysicalDeviceObject);
NTSTATUS HelloWDMPnp(IN PDEVICE_OBJECT fdo,
	IN PIRP pIrp);
NTSTATUS HelloWDMDispatchRoutine(IN PDEVICE_OBJECT fdo,
	IN PIRP Irp);
void HelloWDMUnload(IN PDRIVER_OBJECT DriverObject);

extern "C"
NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject,
	IN PUNICODE_STRING RegistryPath);



