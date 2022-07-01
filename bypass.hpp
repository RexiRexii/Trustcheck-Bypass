#pragma once
#include <Windows.h>

#include <cstdint>
#include <cstddef>

// i dont even know why some retards decided to visit this repository from 2021, and decide to criticize it, how low can you even be?
// i didnt update the address btw, just follow the guide i've put in readme and you should be fine
// requires memcheck bypass

template <typename addr = std::uintptr_t>
constexpr std::uintptr_t aslr(const addr x) // omg, macros are bad so dont use it! -cumstain, around 2019 or 2020 idk
{
    return (x - 0x400000 + reinterpret_cast<const std::uintptr_t>(GetModuleHandleW(nullptr)));
}

void bypass_trust_check()
{
        const auto patch_addr = aslr(0x1ABE4AF);
	DWORD old;	

	VirtualProtect(reinterpret_cast<void*>(patch_addr), 1, PAGE_EXECUTE_READWRITE, &old);
	*reinterpret_cast<std::uint8_t*>(patch_addr) = 0xEB;
	VirtualProtect(reinterpret_cast<void*>(patch_addr), 1, old, &old);
}
