# RAIOTerm
**RAIOTerm** is the official Arduino library for USB/BLUETOOTH SPP the **[RAIOTerm.cc IoT Platform](https://raioterm.cc)**. 
<img width="1919" height="914" alt="image" src="https://github.com/user-attachments/assets/a122963a-ca2b-46a8-9b80-5aeeebdc54b1" />
<img width="1914" height="975" alt="image" src="https://github.com/user-attachments/assets/80404820-abae-4247-a449-bc971b3267dc" />
<img width="1909" height="977" alt="image" src="https://github.com/user-attachments/assets/6d136ea8-756a-4329-b9f3-37ed10fe1c4d" />
<img width="1917" height="977" alt="image" src="https://github.com/user-attachments/assets/8713c151-d495-4681-8366-be8d73a9b24d" />
<img width="1919" height="968" alt="image" src="https://github.com/user-attachments/assets/5cfc9c5c-bdce-460d-b0d8-c05c547aa6da" />
<img width="1915" height="971" alt="image" src="https://github.com/user-attachments/assets/9fe4930d-fc1c-41ee-9728-b39c00df8665" />

**RAIOTerm** is a lightweight Arduino helper library designed to simplify serial communication using the `[FEND][ID]:[VAL][FEND]` protocol. It handles packet framing, parsing, and transmission automatically.

## ✨ Features
* **Protocol Automation:** Automatically wraps data with start/end markers (`0xC0`).
* **Flexible Stream Support:** Works with `Serial`, `Serial1` (Hardware).
* **Easy Data Handling:** Simple `send` and `listen` commands.

## 📦 Installation
1.  Open Arduino IDE.
2.  Go to **Sketch > Include Library > Manage Libraries**.
3.  Search for **RAIOTerm**.
4.  Click **Install**.

## 🛠 Usage
```cpp
#include <RAIOTerm.h>

void setup() {
  raiot.begin(115200);
}

void loop() {
  raiot.send("temp", 24.5);
  delay(1000);
}
