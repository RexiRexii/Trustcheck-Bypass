	void InitializeTrustcheck()
	{
		DWORD EXECUTE;
		const auto TRUSTCHECKJNZ = aslr(0x182194F);

		VirtualProtect(reinterpret_cast<LPVOID>(TRUSTCHECKJNZ), 1, PAGE_EXECUTE_READWRITE, &EXECUTE);
		*reinterpret_cast<byte*>(TRUSTCHECKJNZ) = 0xEB;
		VirtualProtect(reinterpret_cast<LPVOID>(TRUSTCHECKJNZ), 1, EXECUTE, &EXECUTE);
	}
