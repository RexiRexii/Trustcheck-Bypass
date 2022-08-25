## What is a Trustcheck?
Roblox has a check to see if the URL that was inputted is trusted by them or not, this can be bypassed via 2 options.
You can either use the Trustcheck1 / Trustcheck2 address (im sure this is patched) or you can use a simple address which requires an integrity check bypass, the way we'll be bypassing Trustcheck will be via the use of integrity check bypass.

## Grabbing the address
Locate "Trust check failed" string in IDA, then find the patch, which in this case:
![image](https://user-images.githubusercontent.com/68111233/143783856-a65484bb-72c0-4bb0-bc6c-2a10ad71ca37.png)

## Installation
Literally paste the code, and initialize it

## Usage
```
// Initialize your memcheck before initializing your trustcheck bypass
bypass_trust_check();
```

## Contributing
You can contribute to this release by forking the repo or giving this repo a star!
