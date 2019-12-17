#include "clean.hpp"
extern "C" NTSTATUS DriverEntry(
	PDRIVER_OBJECT  driver_object,
	PUNICODE_STRING registry_path
)
{
	// These are invalid for mapped drivers.
	UNREFERENCED_PARAMETER(driver_object);
	UNREFERENCED_PARAMETER(registry_path);
	UNICODE_STRING driver_name = RTL_CONSTANT_STRING(L"Capcom.sys");//Capcom.sys 0x57cd1415
	log("Hello from Kernel Mode");
	clear::clearCache(driver_name, 0x57cd1415);
	FindMmDriverData();
	if (clear::ClearUnloadedDriver(&driver_name, true) == STATUS_SUCCESS) {
		log("ClearUnloadedDriver sucessful");
	}
	else {
		log("ClearUnloadedDriver failed (Not found) ");
	}
	return STATUS_SUCCESS;
}