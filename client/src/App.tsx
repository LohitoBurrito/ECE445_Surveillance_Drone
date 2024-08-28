import React from 'react';
import { useEffect } from 'react'
import useWebSocket from 'react-use-websocket'

import './app.css'

function App() {

  const { sendMessage, lastMessage, readyState, getWebSocket } = useWebSocket('ws://127.0.0.1:5000', {
    shouldReconnect: (closeEvent) => true
  });

  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
      switch(event.key) {
        case 'w': 
          sendMessage('0');
          break;
        case 'a':
          sendMessage('1');
          break;
        case 'd':   
          sendMessage('2');
          break  
        case 's':
          sendMessage('3');
          break;
        case 'ArrowUp':
          sendMessage('4') 
          break;  
        case 'ArrowLeft':
          sendMessage('5') 
          break;    
        case 'ArrowRight':
          sendMessage('6') 
          break;          
        case 'ArrowDown':
          sendMessage('7') 
          break;   
        default:
          break;               
      }
    };

    window.addEventListener('keydown', handleKeyDown);

    return () => {
      window.removeEventListener('keydown', handleKeyDown);
    };
  }, []);

  return (
    <div className="App">
      <div className="container_video">
        <div className="container_regular_feed">

        </div>
        <div className="container_annotated_feed">

        </div>
      </div>
      <div className="container_features">
        <div className="container_realtime_data">

        </div>
        <div className="roll_data">

        </div>
        <div className="pitch_data">

        </div>
        <div className="yaw_data">

        </div>
        <div className="container_controller">
          <div className='first_row'>
            <div className='up'>
              <button className='btn_up' onClick={() => { sendMessage('0') }}>
                ▴
              </button>
            </div>
          </div>
          <div className='second_row'>
            <div className='left'>
              <button className='btn_left' onClick={() => { sendMessage('1') }}>
                ◂
              </button>
            </div>
            <div className='right'>
              <button className='btn_right' onClick={() => { sendMessage('2') }}>
                ▸
              </button>
            </div>
          </div>
          <div className='third_row'>
            <div className='down'>
              <button className='btn_down' onClick={() => { sendMessage('3') }}>
                ▾
              </button>
            </div>
          </div>
        </div>
        <div className="container_controller">
          <div className='first_row'>
            <div className='up'>
              <button className='btn_up' onClick={() => { sendMessage('4') }}>
                ▴
              </button>
            </div>
          </div>
          <div className='second_row'>
            <div className='left'>
              <button className='btn_left' onClick={() => { sendMessage('5') }}>
                ◂
              </button>
            </div>
            <div className='right'>
              <button className='btn_right' onClick={() => { sendMessage('6') }}>
                ▸
              </button>
            </div>
          </div>
          <div className='third_row'>
            <div className='down'>
              <button className='btn_down' onClick={() => { sendMessage('7') }}>
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
