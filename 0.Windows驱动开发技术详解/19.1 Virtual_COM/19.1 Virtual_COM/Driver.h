
#ifdef __cplusplus
extern "C" {
#endif

#include <wdm.h>
#include <ntddser.h>

#ifdef __cplusplus
}
#endif

#define COMBUFLEN	50000

typedef struct _DEVICE_EXTENSION
{
	PDEVICE_OBJECT fdo;
	PDEVICE_OBJECT NextStackDevice;
	UNICODE_STRING ustrDeviceName;		//设备名
	UNICODE_STRING ustrSymLinkName;		//符号链接名

	KSPIN_LOCK	IoctlSpinLock;
	KSPIN_LOCK	WriteSpinLock;

	ULONG EventMask;
	ULONG HistoryEvents;

	ULONG BaudRate;
	ULONG RTSstate;
	ULONG DTRstate;

	SERIAL_TIMEOUTS	Timeouts;
	SERIAL_LINE_CONTROL	Lc;

	CHAR Buffer[COMBUFLEN];

	struct _SERIAL_DEVICE_EXTENSION* pOther;

	PIRP pWaitIrp;
	PIRP pReadIrp;

	int IsOpen;
	ULONG uReadWrite;
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

#define PAGEDCODE code_seg("PAGE")
#define LOCKEDCODE code_seg()
#define INITCODE code_seg("INIT")

#define PAGEDDATA data_seg("PAGE")
#define LOCKEDDATA data_seg()
#define INITDATA data_seg("INIT")

#define arraysize(p)	(sizeof(p)/sizeof((p)[0]))

NTSTATUS HelloWDMAddDevice(IN PDRIVER_OBJECT pDriverObject, PDEVICE_OBJECT PhysicalDeviceObject);
NTSTATUS HelloWDMPnp(IN PDEVICE_OBJECT fdo,IN PIRP Irp);
NTSTATUS HelloWDMDispatchRoutine(IN PDEVICE_OBJECT fdo,IN PIRP Irp);
NTSTATUS HelloWDMDispatchControlp(IN PDEVICE_OBJECT fdo,IN PIRP Irp);
NTSTATUS HelloWDMCreate(IN PDEVICE_OBJECT fdo,IN PIRP Irp);
void HelloWDMUnload(IN PDRIVER_OBJECT DriverObject);

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING RegistryPath);

NTSTATUS HelloWDMClose(PDEVICE_OBJECT fdo, PIRP pIrp);

NTSTATUS HelloWDMRead(PDEVICE_OBJECT fdo, PIRP pIrp);
NTSTATUS HelloWDMWrite(PDEVICE_OBJECT fdo, PIRP pIrp);
