import React from 'react';
import './App.css';

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

class App extends React.Component {
  render() {
    return (
      <div className="App">
        <button onClick={() => rc5Send(1, 12)}>Power</button>
        <button onClick={() => rc5Send(1, 0x10)}>V+</button>
        <button onClick={() => rc5Send(1, 0x11)}>V-</button>
      </div>
    );
  }
}

export default App;
