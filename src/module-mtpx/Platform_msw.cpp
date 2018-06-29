#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
Device::Device(LPCWSTR deviceID) : _cntRef(1), _deviceID(deviceID)
{
}

bool Device::Open(Signal &sig)
{
	if (_pPortableDevice.Get() != nullptr && _pPortableDeviceContent.Get() != nullptr) return true;
	ComPtr<IPortableDeviceValues> pClientInfo;
	do {
		if (CatchErr(sig, ::CoCreateInstance(CLSID_PortableDeviceValues, nullptr,
					CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pClientInfo)))) return false;
		if (CatchErr(sig, pClientInfo->SetStringValue(WPD_CLIENT_NAME, L"Gura mtp Module"))) return false;
		if (CatchErr(sig, pClientInfo->SetUnsignedIntegerValue(
					WPD_CLIENT_MAJOR_VERSION, GURA_VERSION_MAJOR))) return false;
		if (CatchErr(sig, pClientInfo->SetUnsignedIntegerValue(
					WPD_CLIENT_MINOR_VERSION, GURA_VERSION_MINOR))) return false;
		if (CatchErr(sig, pClientInfo->SetUnsignedIntegerValue(
					WPD_CLIENT_REVISION, GURA_VERSION_PATCH))) return false;
	} while (0);
	if (CatchErr(sig, ::CoCreateInstance(CLSID_PortableDeviceFTM, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_pPortableDevice)))) return false;
	if (CatchErr(sig, _pPortableDevice->Open(_deviceID.c_str(), pClientInfo.Get()))) return false;
	if (CatchErr(sig, _pPortableDevice->Content(&_pPortableDeviceContent))) return false;
	return true;
}

//-----------------------------------------------------------------------------
// DeviceOwner
//-----------------------------------------------------------------------------
DeviceOwner::~DeviceOwner()
{
	Clear();
}

void DeviceOwner::Clear()
{
	foreach (DeviceOwner, ppDevice, *this) {
		Device *pDevice = *ppDevice;
		Device::Delete(pDevice);
	}
	clear();
}

bool DeviceOwner::EnumerateDevices(Signal &sig)
{
	HRESULT hr;
	ComPtr<IPortableDeviceManager> pPortableDeviceManager;
	if (CatchErr(sig, ::CoCreateInstance(CLSID_PortableDeviceManager, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceManager)))) return false;
	DWORD nDeviceIDs = 0;
	if (CatchErr(sig, pPortableDeviceManager->GetDevices(nullptr, &nDeviceIDs))) return false;
	std::unique_ptr<LPWSTR []> deviceIDs(new LPWSTR[nDeviceIDs]);
	if (CatchErr(sig, pPortableDeviceManager->GetDevices(deviceIDs.get(), &nDeviceIDs))) return false;
	for (DWORD i = 0; i < nDeviceIDs; i++) {
		AutoPtr<Device> pDevice(new Device(deviceIDs[i]));
		::CoTaskMemFree(deviceIDs[i]);
		LPCWSTR deviceID = pDevice->GetDeviceID();
		do {
			DWORD len = 0;
			if (CatchErr(sig, pPortableDeviceManager->GetDeviceFriendlyName(deviceID, nullptr, &len))) return false;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			if (CatchErr(sig, pPortableDeviceManager->GetDeviceFriendlyName(deviceID, wstr.get(), &len))) return false;
			pDevice->SetFriendlyName(WSTRToString(wstr.get()));
		} while (0);
		do {
			DWORD len = 0;
			if (CatchErr(sig, pPortableDeviceManager->GetDeviceManufacturer(deviceID, nullptr, &len))) return false;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			if (CatchErr(sig, pPortableDeviceManager->GetDeviceManufacturer(deviceID, wstr.get(), &len))) return false;
			pDevice->SetManufacturer(WSTRToString(wstr.get()));
		} while (0);
		do {
			DWORD len = 0;
			if (CatchErr(sig, pPortableDeviceManager->GetDeviceDescription(deviceID, nullptr, &len))) return false;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			if (CatchErr(sig, pPortableDeviceManager->GetDeviceDescription(deviceID, wstr.get(), &len))) return false;
			pDevice->SetDescription(WSTRToString(wstr.get()));
		} while (0);
		push_back(pDevice.release());
	}
	return true;
}

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
Storage::Storage(Device *pDevice, LPCWSTR objectID) :
	_cntRef(1), _pDevice(pDevice), _objectID(objectID),
	_pStorageType(Symbol::Empty), _pFilesystemType(Symbol::Empty), _pAccessCapability(Symbol::Empty),
	_maxCapacity(0), _freeSpaceInBytes(0), _freeSpaceInObjects(0)
{
}

#if 0
bool Storage::Open(Signal &sig)
{
	if (_pEnumPortableDeviceObjectIDs.Get() != nullptr) return true;
	IPortableDeviceContent *pPortableDeviceContent = _pDevice->GetPortableDeviceContent();
	if (CatchErr(sig, pPortableDeviceContent->EnumObjects(
			0, _objectID.c_str(), nullptr, &_pEnumPortableDeviceObjectIDs))) return false;
	return true;
}
#endif

//-----------------------------------------------------------------------------
// StorageOwner
//-----------------------------------------------------------------------------
StorageOwner::~StorageOwner()
{
	Clear();
}

void StorageOwner::Clear()
{
	foreach (StorageOwner, ppStorage, *this) {
		Storage *pStorage = *ppStorage;
		Storage::Delete(pStorage);
	}
	clear();
}

bool StorageOwner::EnumerateStorages(Signal &sig, Device *pDevice)
{
	if (!pDevice->Open(sig)) return false;
	IPortableDeviceContent *pPortableDeviceContent = pDevice->GetPortableDeviceContent();
	ComPtr<IEnumPortableDeviceObjectIDs> pEnumPortableDeviceObjectIDs;
	ComPtr<IPortableDeviceProperties> pPortableDeviceProperties;
	ComPtr<IPortableDeviceKeyCollection> pPortableDeviceKeyCollection;
	if (CatchErr(sig, pPortableDeviceContent->EnumObjects(
			0, WPD_DEVICE_OBJECT_ID, nullptr, &pEnumPortableDeviceObjectIDs))) return false;
	if (CatchErr(sig, pPortableDeviceContent->Properties(&pPortableDeviceProperties))) return false;
	if (CatchErr(sig, ::CoCreateInstance(CLSID_PortableDeviceKeyCollection,
			nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceKeyCollection)))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_TYPE))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_FILE_SYSTEM_TYPE))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_CAPACITY))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_FREE_SPACE_IN_BYTES))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_FREE_SPACE_IN_OBJECTS))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_DESCRIPTION))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_SERIAL_NUMBER))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_MAX_OBJECT_SIZE))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_CAPACITY_IN_OBJECTS))) return false;
	if (CatchErr(sig, pPortableDeviceKeyCollection->Add(WPD_STORAGE_ACCESS_CAPABILITY))) return false;
	LPWSTR objectIDs[32];
	HRESULT hr;
	do {
		DWORD nObjectIDs = 0;
		hr = pEnumPortableDeviceObjectIDs->Next(ArraySizeOf(objectIDs), objectIDs, &nObjectIDs);
		if (CatchErr(sig, hr)) return false;
		for (DWORD i = 0; i < nObjectIDs; i++) {
			AutoPtr<Storage> pStorage(new Storage(pDevice->Reference(), objectIDs[i]));
			::CoTaskMemFree(objectIDs[i]);
			LPCWSTR objectID = pStorage->GetObjectID();
			ComPtr<IPortableDeviceValues> pPortableDeviceValues;
			if (CatchErr(sig, pPortableDeviceProperties->GetValues(
				objectID, pPortableDeviceKeyCollection.Get(), &pPortableDeviceValues))) return false;
			do { // WPD_STORAGE_TYPE: VT_UI4
				ULONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedIntegerValue(
									WPD_STORAGE_TYPE, &value))) return false;
				pStorage->SetStorageType(
					(value == WPD_STORAGE_TYPE_FIXED_ROM)? Gura_UserSymbol(FixedROM) :
					(value == WPD_STORAGE_TYPE_REMOVABLE_ROM)? Gura_UserSymbol(RemovableROM) :
					(value == WPD_STORAGE_TYPE_FIXED_RAM)? Gura_UserSymbol(FixedRAM) :
					(value ==  WPD_STORAGE_TYPE_REMOVABLE_RAM)? Gura_UserSymbol(RemovableRAM) :
					Gura_UserSymbol(Undefined));
			} while (0);
			do { // WPD_STORAGE_FILE_SYSTEM_TYPE: VT_LPWSTR
				LPWSTR value = nullptr;
				if (CatchErr(sig, pPortableDeviceValues->GetStringValue(
									WPD_STORAGE_FILE_SYSTEM_TYPE, &value))) return false;
				::CoTaskMemFree(value);
			} while (0);
			do { // WPD_STORAGE_CAPACITY: VT_UI8
				ULONGLONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedLargeIntegerValue(
									WPD_STORAGE_CAPACITY, &value))) return false;
				pStorage->SetMaxCapacity(value);
			} while (0);
			do { // WPD_STORAGE_FREE_SPACE_IN_BYTES: VT_UI8
				ULONGLONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedLargeIntegerValue(
									WPD_STORAGE_FREE_SPACE_IN_BYTES, &value))) return false;
				pStorage->SetFreeSpaceInBytes(value);
			} while (0);
			do { // WPD_STORAGE_FREE_SPACE_IN_OBJECTS: VT_UI8
				ULONGLONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedLargeIntegerValue(
									WPD_STORAGE_FREE_SPACE_IN_OBJECTS, &value))) return false;
				pStorage->SetFreeSpaceInObjects(value);
			} while (0);
			do { // WPD_STORAGE_DESCRIPTION: VT_LPWSTR
				LPWSTR value = nullptr;
				if (CatchErr(sig, pPortableDeviceValues->GetStringValue(
									WPD_STORAGE_DESCRIPTION, &value))) return false;
				pStorage->SetStorageDescription(WSTRToString(value).c_str());
				::CoTaskMemFree(value);
			} while (0);
			do { // WPD_STORAGE_SERIAL_NUMBER: VT_LPWSTR
				LPWSTR value = nullptr;
				if (CatchErr(sig, pPortableDeviceValues->GetStringValue(
									WPD_STORAGE_SERIAL_NUMBER, &value))) return false;
				pStorage->SetVolumeIdentifier(WSTRToString(value).c_str());
				::CoTaskMemFree(value);
			} while (0);
#if 0
			do { // WPD_STORAGE_MAX_OBJECT_SIZE: VT_UI8
				ULONGLONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedLargeIntegerValue(
									WPD_STORAGE_MAX_OBJECT_SIZE, &value))) return false;
				::printf("max object size: %lld\n", value);
			} while (0);
#endif
#if 0
			do { // WPD_STORAGE_CAPACITY_IN_OBJECTS: VT_UI8
				ULONGLONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedLargeIntegerValue(
									WPD_STORAGE_CAPACITY_IN_OBJECTS, &value))) return false;
				::printf("capacity in obj: %lld\n", value);
			} while (0);
#endif
			do { // WPD_STORAGE_ACCESS_CAPABILITY: VT_UI4
				ULONG value = 0;
				if (CatchErr(sig, pPortableDeviceValues->GetUnsignedIntegerValue(
									WPD_STORAGE_ACCESS_CAPABILITY, &value))) return false;
				pStorage->SetAccessCapability(
					(value == WPD_STORAGE_ACCESS_CAPABILITY_READWRITE)? Gura_UserSymbol(ReadWrite) :
					(value == WPD_STORAGE_ACCESS_CAPABILITY_READ_ONLY_WITHOUT_OBJECT_DELETION)? Gura_UserSymbol(ReadOnly) :
					(value == WPD_STORAGE_ACCESS_CAPABILITY_READ_ONLY_WITH_OBJECT_DELETION)? Gura_UserSymbol(ReadOnlyWithObjectDeletion) :
					Gura_UserSymbol(Undefined));
			} while (0);
			push_back(pStorage.release());
		}
	} while (hr == S_OK);
	return true;
}

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr)
{
	// cnt includes null-terminater
	int cnt = ::WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	char *psz = new char [cnt + 1];
	::WideCharToMultiByte(CP_UTF8, 0, wstr, -1, psz, cnt, nullptr, nullptr);
	psz[cnt] = '\0';
	return String(psz);
}

//********************
String HRESULTToString(HRESULT hr)
{
	String rtn;
	PVOID wstr;
	::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				nullptr, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				reinterpret_cast<LPTSTR>(&wstr), 0, nullptr);
	//::wprintf(L"[%S]\n", reinterpret_cast<LPWSTR>(wstr));
	if (wstr != nullptr) rtn = WSTRToString(reinterpret_cast<LPWSTR>(wstr));
	::LocalFree(wstr);
	return rtn;
}

//********************
bool CatchErr(Signal &sig, HRESULT hr)
{
	if (FAILED(hr)) {
		sig.SetError(ERR_RuntimeError, "%s", HRESULTToString(hr).c_str());
		return true;
	}
	return false;
}

Gura_EndModuleScope(mtp)
