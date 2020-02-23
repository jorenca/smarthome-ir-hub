import React from 'react';

const necSend = (address, byte) => {
  const codeArray = [
    (address & 0xff00) >> 8,
    address & 0xff,
    byte,
    ~byte
  ];
  var result = "";
  for (var i = 0; i < codeArray.length; i++) {
    result += codeArray[i];
    if (i !== codeArray.length - 1) result += '/'
  }
  fetch(`/nec/${result}`);
}

export default ({ address = 0x00ff, byte, children }) =>
  <button onClick={() => necSend(address, byte)}>
    {children}
  </button>;
