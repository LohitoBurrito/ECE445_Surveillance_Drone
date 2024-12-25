import React from 'react';
import { useState, useEffect, useRef } from 'react';
import useWebSocket from 'react-use-websocket';
import MapComponent from './components/map/map';

import './app.css';

function App() {

  const [activeState, setActiveState] = useState<number[]>([0, 0, 0, 0, 0, 0, 0, 0]);
  const [IP_Temp, setIP_Temp] = useState('');
  const [IP, setIP] = useState('127.0.0.1');

  const { sendMessage: sendMessage } = useWebSocket(`ws://${IP}:5000`, {
    shouldReconnect: () => true,
  });

  const { lastMessage: recieveMessage } = useWebSocket(`ws://${IP}:5001`, {
    shouldReconnect: () => true,
  });

  const [altitude, setAltitude] = useState<string | null>(null);
  const [longitude, setLongitude] = useState<string | null>(null);
  const [latitude, setLatitude] = useState<string | null>(null);
  const [image, setImage] = useState<string>("");
  const [roll, setRoll] = useState<number>(0);
  const [pitch, setPitch] = useState<number>(0);
  const [yaw, setYaw] = useState<number>(0);
  const [acceleration, setAcceleration] = useState<number>(0);
  const [motorSpeed, setMotorSpeed] = useState<number>(15);

  const lastKeyPressTime = useRef<Date | null>(null); 

  useEffect(() => {

    const handleKeyDown = (event: KeyboardEvent) => {
      const currentTime = new Date(); 
      if (lastKeyPressTime.current && currentTime.getTime() - lastKeyPressTime.current.getTime() < 3000) { 
        return;
      }
      console.log(event.key)
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

      sendMessage('servo_cmd: ' + index.toString() + ', motor_speed: -1');
      setActiveState((prev) => {
        const newState = [...prev];
        newState[index!] = 1;
        return newState;
      });
      lastKeyPressTime.current = currentTime;

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

  useEffect(() => {
    if (recieveMessage) {
      const jsonRecievedMessage = JSON.parse(recieveMessage.data)["documents"]["0"]["fields"];
      setAltitude(jsonRecievedMessage["BMP280"]["stringValue"]);
      setLongitude(jsonRecievedMessage["SIM7600"]["mapValue"]["fields"]["Longitude"]["stringValue"]);
      setLatitude(jsonRecievedMessage["SIM7600"]["mapValue"]["fields"]["Latitude"]["stringValue"]);
      setImage("data:image/jpg;base64," + jsonRecievedMessage["Image"]["stringValue"]);
      setRoll(Number(jsonRecievedMessage["MPU6050"]["mapValue"]["fields"]["Roll"]["stringValue"]));
      setPitch(-1 * Number(jsonRecievedMessage["MPU6050"]["mapValue"]["fields"]["Pitch"]["stringValue"]));
      setYaw(Number(jsonRecievedMessage["MPU6050"]["mapValue"]["fields"]["Yaw"]["stringValue"]));
      setAcceleration(Number(jsonRecievedMessage["MPU6050"]["mapValue"]["fields"]["linear_accel"]["stringValue"]));
    }
    console.log(recieveMessage);
  }, [recieveMessage]);
  

  return (
    <div className="App">
      <div className='leftPanel'>
        <div className='drones'>

        </div>
        <div className="set_ip">
          <input
            className='ip_input'
            type="text"
            id="inputBox"
            placeholder='Enter IP Address'
            value={IP_Temp}
            onChange={(event) => { setIP_Temp(event.target.value) }}
          />
          <button className='ip_submit' onClick={() => { setIP(IP_Temp) }}>SET IP ADDRESS</button>
        </div>
      </div>
      <div className='middle'>
        <div className="abort_mission">
          <button className='abort_button' onClick={() => { sendMessage('servo_cmd: 8, motor_speed: -1') }}>Abort Mission</button>
        </div>
        <div className="container_map">
          <MapComponent lat={Number(latitude)} lng={Number(longitude)} yaw={yaw}/>
        </div>
        <div className="container_feed">
          <img src={image} width="100%" height="100%" alt="Base64 Image" />
        </div>
        <div className="container_feed2">
          <p>
            Roll: { String(roll) } deg <br></br>
            Pitch: { String(pitch) } deg <br></br>
            Yaw: { String(yaw) } deg <br></br>
            Acceleration: { String(acceleration) } m/s^2<br></br>
            Longitude: { longitude } deg <br></br>
            Latitude: { latitude } deg <br></br>
            Altitude: { altitude } m <br></br>
          </p>
        </div>
      </div>
      <div className='rightPanel'>
        <div className="roll_data">
          <svg width="200" height="200" transform={`rotate(${roll})`}>
            <circle cx="100" cy="100" r="95" fill="none" stroke="white" stroke-width="2" />
            <line x1="5" y1="100" x2="195" y2="100" stroke="white" stroke-width="2" />
          </svg>
        </div>
        <div className="pitch_data">
          <svg width="200" height="200" transform={`rotate(${pitch})`}>
            <circle cx="100" cy="100" r="95" fill="none" stroke="white" stroke-width="2" color='white'/>
            <line x1="5" y1="100" x2="195" y2="100" stroke="white" stroke-width="2" />
          </svg>
        </div>
        <div className='controller'>
          <div className="container_controller">
            <div className="motor_controller">
            <input
              type="range"
              min="0"
              max="100"
              value={motorSpeed}
              onChange={ (event: React.ChangeEvent<HTMLInputElement>) => { setMotorSpeed(Number(event.target.value)) } }
              onMouseUp={ () => { sendMessage('servo_cmd: -1, motor_speed: ' + String(motorSpeed)) }}
              style={{
                transform: "rotate(-90deg)", // Rotate the slider to make it vertical
                width: "150px", // Set a fixed width for the height after rotation
                height: "10px", // Slider thickness
                marginLeft: "20px", // Space for slider handle
                marginTop: "120px"
              }}
            />
            </div>
          </div>
          <div className="container_controller">
            <div className='first_row'>
              <div className='up'>
                <button className={activeState[0] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 0, motor_speed: -1') }}>
                  ▴
                </button>
              </div>
            </div>
            <div className='second_row'>
              <div className='left'>
                <button className={activeState[1] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 1, motor_speed: -1') }}>
                  ◂
                </button>
              </div>
              <div className='right'>
                <button className={activeState[2] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 2, motor_speed: -1') }}>
                  ▸
                </button>
              </div>
            </div>
            <div className='third_row'>
              <div className='down'>
                <button className={activeState[3] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 3, motor_speed: -1') }}>
                  ▾
                </button>
              </div>
            </div>
          </div>
          <div className="container_controller">
            <div className='first_row'>
              <div className='up'>
                <button className={activeState[4] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 4, motor_speed: -1') }}>
                  ▴
                </button>
              </div>
            </div>
            <div className='second_row'>
              <div className='left'>
                <button className={activeState[5] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 5, motor_speed: -1') }}>
                  ◂
                </button>
              </div>
              <div className='right'>
                <button className={activeState[6] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 6, motor_speed: -1') }}>
                  ▸
                </button>
              </div>
            </div>
            <div className='third_row'>
              <div className='down'>
                <button className={activeState[7] === 1 ? 'active' : ''} onClick={() => { sendMessage('servo_cmd: 7, motor_speed: -1') }}>
                  ▾
                </button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;
