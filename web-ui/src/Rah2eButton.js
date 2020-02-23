import React from 'react';


const rah2eSend = (codeArray) => { // code is array of bytes
  var result = "";
  for (var i = 0; i < codeArray.length; i++) {
    result += codeArray[i];
    if (i !== codeArray.length - 1) result += '/'
  }

  fetch(`/rah2e/${result}`);
}

export default ({ code, children }) =>
  <button onClick={() => rah2eSend(code)}>
    {children}
  </button>;

export const Rah2eCommands = {
  OFF: [
        0x14, 0x63, 0x00, 0x10, 0x10, // header
        0x02, // turn off (short command)
        ~2 // The last byte is the inverse of penultimate byte
      ],
};
