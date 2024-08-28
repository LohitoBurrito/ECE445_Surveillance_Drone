import React from 'react';
import { useState, useEffect } from 'react';
import useWebSocket from 'react-use-websocket';

import './app.css';
import { IndexType } from 'typescript';

function App() {

  const { sendMessage } = useWebSocket('ws://127.0.0.1:5000', {
    shouldReconnect: () => true,
  });

  const [activeState, setActiveState] = useState<number[]>([0, 0, 0, 0, 0, 0, 0, 0]);

  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
      console.log(event.key);
      let index: number | undefined;
      switch (event.key) {
        case 'w': index = 0; break;
        case 'a': index = 1; break;
        case 'd': index = 2; break;
        case 's': index = 3; break;
        case 'ArrowUp': index = 4; break;
        case 'ArrowLeft': index = 5; break;
        case 'ArrowRight': index = 6; break;
        case 'ArrowDown': index = 7; break;
        default: return;
      }
      sendMessage(index.toString());
      setActiveState((prev) => {
        const newState = [...prev];
        newState[index!] = 1;
        return newState;
      });
    };

    const handleKeyUp = (event: KeyboardEvent) => {
      console.log(event.key);
      let index: number | undefined;
      switch (event.key) {
        case 'w': index = 0; break;
        case 'a': index = 1; break;
        case 'd': index = 2; break;
        case 's': index = 3; break;
        case 'ArrowUp': index = 4; break;
        case 'ArrowLeft': index = 5; break;
        case 'ArrowRight': index = 6; break;
        case 'ArrowDown': index = 7; break;
        default: return;
      }
      sendMessage(index.toString());
      setActiveState((prev) => {
        const newState = [...prev];
        newState[index!] = 0;
        return newState;
      });
    };

    window.addEventListener('keydown', handleKeyDown);
    window.addEventListener('keyup', handleKeyUp);

    return () => {
      window.removeEventListener('keydown', handleKeyDown);
      window.removeEventListener('keyup', handleKeyUp);
    };
  }, [sendMessage]);

  return (
    <div className="App">
      <div className="container_video">
        <div className="container_regular_feed"></div>
        <div className="container_annotated_feed"></div>
      </div>
      <div className="container_features">
        <div className="container_realtime_data"></div>
        <div className="roll_data"></div>
        <div className="pitch_data"></div>
        <div className="yaw_data"></div>
        <div className="container_controller">
          <div className='first_row'>
            <div className='up'>
              <button className={activeState[0] === 1 ? 'active' : ''} onClick={() => { sendMessage('0') }}>
                ▴
              </button>
            </div>
          </div>
          <div className='second_row'>
            <div className='left'>
              <button className={activeState[1] === 1 ? 'active' : ''} onClick={() => { sendMessage('1') }}>
                ◂
              </button>
            </div>
            <div className='right'>
              <button className={activeState[2] === 1 ? 'active' : ''} onClick={() => { sendMessage('2') }}>
                ▸
              </button>
            </div>
          </div>
          <div className='third_row'>
            <div className='down'>
              <button className={activeState[3] === 1 ? 'active' : ''} onClick={() => { sendMessage('3') }}>
                ▾
              </button>
            </div>
          </div>
        </div>
        <div className="container_controller">
          <div className='first_row'>
            <div className='up'>
              <button className={activeState[4] === 1 ? 'active' : ''} onClick={() => { sendMessage('4') }}>
                ▴
              </button>
            </div>
          </div>
          <div className='second_row'>
            <div className='left'>
              <button className={activeState[5] === 1 ? 'active' : ''} onClick={() => { sendMessage('5') }}>
                ◂
              </button>
            </div>
            <div className='right'>
              <button className={activeState[6] === 1 ? 'active' : ''} onClick={() => { sendMessage('6') }}>
                ▸
              </button>
            </div>
          </div>
          <div className='third_row'>
            <div className='down'>
              <button className={activeState[7] === 1 ? 'active' : ''} onClick={() => { sendMessage('7') }}>
                ▾
              </button>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;
