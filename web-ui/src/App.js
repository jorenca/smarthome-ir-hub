import React from 'react';
import './App.css';

import Rc5Button from './Rc5Button';

class App extends React.Component {
  render() {
    return (
      <div className="App">
        <Rc5Button address={1} command={12}>Power</Rc5Button>
        <Rc5Button address={1} command={0x10}>V+</Rc5Button>
        <Rc5Button address={1} command={0x11}>V+</Rc5Button>
      </div>
    );
  }
}

export default App;
