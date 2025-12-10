/*
  RAIOTerm.h - Library for RAIOT Protocol.
  Handles the [FEND][ID]:[VAL][FEND] protocol automatically.
*/
#ifndef RAIOTerm_h
#define RAIOTerm_h

#include "Arduino.h"

#define RAIOT_FEND 0xC0

class RAIOTerm {
  public:
    RAIOTerm();

    // Option 1: Default (Uses standard USB Serial)
    void begin(long baud);

    // Option 2: Specific Hardware Serial (Serial1, Serial2, etc.)
    void begin(HardwareSerial& port, long baud);

    // Template function to send data (Must remain in header)
    template <typename T>
    void send(String id, T value) {
      if (!_stream) return; // Safety check
      
      _stream->write(RAIOT_FEND); 
      _stream->print(id + ":" + String(value)); 
      _stream->write(RAIOT_FEND);
    }
    
    // Listen for incoming commands
    bool listen(String &cmdId, String &val);

  private:
    Stream* _stream; // Pointer to the generic Serial object
    String _buffer;
};

// Create a global instance so user can just call raiot.begin()
extern RAIOTerm raiot;

#endif