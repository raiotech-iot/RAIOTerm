# RAIOTerm

**RAIOTerm** is a lightweight Arduino helper library designed to simplify serial communication using the `[FEND][ID]:[VAL][FEND]` protocol. It handles packet framing, parsing, and transmission automatically.

## ✨ Features
* **Protocol Automation:** Automatically wraps data with start/end markers (`0xC0`).
* **Flexible Stream Support:** Works with `Serial`, `Serial1` (Hardware), and `SoftwareSerial`.
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
