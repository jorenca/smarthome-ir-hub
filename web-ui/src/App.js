import React from 'react';
import './App.scss';

import Rc5Button from './Rc5Button';
import Rah2eButton, { Rah2eCommands } from './Rah2eButton';
import NecButton from './NecButton';

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
          <div className="group-header">TV Box</div>
          <table align="center">
            <tbody>
              <tr>
                <td><NecButton byte={64}>Off</NecButton></td>
              </tr>
              <tr><td colspan="3"><hr /></td></tr>
              <tr>
                <td><NecButton byte={0b1001100}>Back</NecButton></td>
                <td><NecButton byte={0b1000}>^</NecButton></td>
                <td><NecButton byte={0b1010110}>Menu</NecButton></td>
              </tr>
              <tr>
                <td><NecButton byte={0b1001000}>&lt;</NecButton></td>
                <td><NecButton byte={0b100100}>OK</NecButton></td>
                <td><NecButton byte={0b1001010}>&gt;</NecButton></td>
              </tr>
              <tr>
                <td/>
                <td><NecButton byte={0b10100}>Down</NecButton></td>
              </tr>
              <tr><td colspan="3"><hr /></td></tr>
              <tr>
                <td><NecButton byte={0b10000}>&lt;&lt;</NecButton></td>
                <td><NecButton byte={0b1000100}>||&gt;</NecButton></td>
                <td><NecButton byte={0b1000110}>&gt;&gt;</NecButton></td>
              </tr>
            </tbody>
          </table>
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
