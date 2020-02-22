import React from 'react';

let toggleBit = true;
const buildCode = (address, command) => {
  let code = 0b11; // header and toggle bit
  code |= (toggleBit << 2);
  toggleBit = !toggleBit;
  for(let i=0; i<5; i++) {
    const bit = !!(address & (1<<4-i));
    code |= bit << (3+i);
  }
  for(let i=0; i<6; i++) {
    const bit  = !!(command & (1<<5-i));
    code |= bit << (8+i);
  }
  return code;
};

const rc5Send = (address, command) =>
  fetch(`/rc5/${buildCode(address, command)}`);

export default ({ address, command, children }) =>
  <button onClick={() => rc5Send(address, command)}>
    {children}
  </button>;
