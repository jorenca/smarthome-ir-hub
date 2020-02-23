import React from 'react';
import './App.scss';

import Rc5Button from './Rc5Button';
import Rah2eButton, { Rah2eCommands } from './Rah2eButton';

class App extends React.Component {
  render() {
    return (
      <div className="App">
        <div className="button-group">
          <div className="group-header">TV</div>
          <Rc5Button address={1} command={12}>Power</Rc5Button>
          <Rc5Button address={1} command={0x10}>V+</Rc5Button>
          <Rc5Button address={1} command={0x11}>V+</Rc5Button>
        </div>
        <div className="button-group">
          <div className="group-header">A/C</div>
          <Rah2eButton code={Rah2eCommands.OFF}>Off</Rah2eButton>
        </div>
      </div>
    );
  }
}

export default App;
