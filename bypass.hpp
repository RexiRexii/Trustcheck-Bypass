#pragma once
#include <Windows.h>

#include <cstdint>
#include <cstddef>

// i dont even know why some retards decided to visit this repository from 2021, and decide to criticize it, how low can you even be?
// i didnt update the address btw, just follow the guide i've put in readme and you should be fine
// requires memcheck bypass

// omg, you, like, shouldnt use 400k base, you know --iihero
// omg, you, like, shouldnt use macros, you know -cumstain

const auto base = reinterpret_cast<const std::uintptr_t>(GetModuleHandleA(nullptr));

void bypass_trust_check()
{
        const auto patch_addr = (base + 0x1ABE4AF);
	DWORD old;	

	VirtualProtect(reinterpret_cast<void*>(patch_addr), 1, PAGE_EXECUTE_READWRITE, &old);
	*reinterpret_cast<std::uint8_t*>(patch_addr) = 0xEB;
	VirtualProtect(reinterpret_cast<void*>(patch_addr), 1, old, &old);
}
