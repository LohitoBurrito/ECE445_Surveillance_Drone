# ECE445_Surveillance_Drone

## Abstract

The Early Response Drone aims to be a cost-effective drone system for early emergency reconnaissance. This drone, equipped with a camera and sensors, transmits real-time data such as video frames, altitude, and orientation to a user-friendly frontend interface via cellular connectivity. The system comprises four key components: a drone, backend, frontend, and cloud storage. Data captured by the drone is temporarily stored and processed for visual and analytical feedback. By integrating rapid deployment and reliable communication, the drone can assist in crime monitoring, fire hazard assessment, and medical triage, providing first responders with the critical information needed to make timely, informed decisions and improve overall emergency response outcomes. Although in-air trials were not performed to validate flight performance, the drone’s core software and electronics were thoroughly tested and demonstrated reliable functionality.

[Report](https://docs.google.com/document/d/1GGGv41obI-07fPF-_esPq27CqVMIz6DOAviRRR1eaIU/edit?tab=t.0)

## Installation

#### Initial Server Build

From your root directory of the project, run the following commands.

```
 cd server
```

Create and run a docker container by building a docker image, create a docker network, and building a docker container. Make sure to replace {filepath} with the filepath to the project on your system. After running "docker run," a bash terminal corresponding to the docker container should open. 

```
 docker build -t drone_server_image .
```
```
 docker network create drone_network 
```
```
 docker run --name drone_server --network drone_network -p 5000:5000 -p 5001:5001 -v {filepath}\ECE445_SURVEILLANCE_DRONE:/workspace -it drone_server_image /bin/bash
```

Run the following commands to build the project.
```
 mkdir build
 cd build
```
```
 cmake ..
```
```
 make
```
```
 ./drone_server 0.0.0.0 5000 5001
```

#### Future Server Build

Assuming that you already have the docker container, run the following commands from the root directory to re-run the server code. 
```
 cd server
```
```
 docker start -ai drone_server
```
```
 rm -rf build
 mkdir build
 cd build
```
```
 cmake ..
```
```
 make
```
```
 ./drone_server 0.0.0.0 5000 5001
```

#### Client Run

Ensure that you have installed nodeJS on your machine. On a seperate terminal from root directory of project, run the following commands to run the client application on your web browser.

```
 cd client
 npm install
 npm start
```

## Some Test Videos:
[Sensor Test](https://drive.google.com/file/d/1JHddWSbrLJgTwXRT1GT1PC6u4QnlyP4Z/view?usp=sharing)

[Command Test](https://drive.google.com/file/d/1ZHc8pTtDRF40xnmZzDQPJSrRR4m5kNAQ/view?usp=sharing)
