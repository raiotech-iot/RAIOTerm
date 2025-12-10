/*
  RAIOTerm.cpp - Library for RAIOT Protocol.
*/

#include "RAIOTerm.h"

// Constructor
RAIOTerm::RAIOTerm() {
  _stream = NULL; 
  _buffer = "";
}

// Option 1: Default to Standard Serial
void RAIOTerm::begin(long baud) {
  Serial.begin(baud);
  _stream = &Serial; 
}

// Option 2: Use specific Hardware Serial
void RAIOTerm::begin(HardwareSerial& port, long baud) {
  port.begin(baud);
  _stream = &port;   
}

// Listen implementation
bool RAIOTerm::listen(String &cmdId, String &val) {
  if (!_stream) return false; 

  while (_stream->available()) {
    char c = _stream->read();
    
    if (c == RAIOT_FEND) {
      if (_buffer.length() > 0) {
        int split = _buffer.indexOf(':');
        if (split > 0) {
          cmdId = _buffer.substring(0, split);
          val = _buffer.substring(split + 1);
          _buffer = ""; 
          return true;
        }
      }
      _buffer = "";
    } else { 
      _buffer += c; 
    }
  }
  return false;
}

// Instantiate the global object
RAIOTerm raiot;