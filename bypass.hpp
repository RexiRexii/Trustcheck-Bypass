void InitializeTrustcheck()
{
	DWORD EXECUTE;
	const auto TRUSTCHECKJNZ = (0x182194F - 0x400000 + reinterpret_cast<std::uintptr_t>(GetModuleHandleA(0)));

	VirtualProtect(reinterpret_cast<void*>(TRUSTCHECKJNZ), 1, PAGE_EXECUTE_READWRITE, &EXECUTE);
	*reinterpret_cast<byte*>(TRUSTCHECKJNZ) = 0xEB;
	VirtualProtect(reinterpret_cast<void*>(TRUSTCHECKJNZ), 1, EXECUTE, &EXECUTE);
}

void RevertTrustcheck()
{
	DWORD EXECUTE;
	const auto TRUSTCHECKJNZ = (0x182194F - 0x400000 + reinterpret_cast<std::uintptr_t>(GetModuleHandleA(0)));

	VirtualProtect(reinterpret_cast<void*>(TRUSTCHECKJNZ), 1, PAGE_EXECUTE_READWRITE, &EXECUTE);
	*reinterpret_cast<byte*>(TRUSTCHECKJNZ) = 0x74;
	VirtualProtect(reinterpret_cast<void*>(TRUSTCHECKJNZ), 1, EXECUTE, &EXECUTE);
}

// REQUIRES A MEMCHECK BYPASS, I SUGGEST YOU USE GOGO'S AUTOUPDATING MEMCHECK BYPASS AT: https://github.com/AmJayden/auto-updating-memcheck/tree/main/AUMB
