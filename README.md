# ECE445 Notebook - Lohit Muralidharan

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 08/31/24: Created Baseline Boost ASIO C++ Backend and TypeScript Frontend](#08/26/24---08/31/24:-Created-Baseline-Boost-ASIO-C++-Backend-and-TypeScript-Frontend)
* [09/01/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#08/26/24---09/15/24:-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#09/16/24:-Working-on-Project-Proposal)
* [09/17/24: Completed Project Proposal](#09/17/24:-Completed-Project-Proposal)
* [09/18/24: Completed Team Contract](#09/18/24:-Completed-Team-Contract)
* [09/30/24: Worked on Design Document](#09/30/24-worked-on-design-document)
* [10/03/24: Design Document](#10/03/24-design-document)
* [10/08/24: TA Meeting and Design Review Feedback](#10/08/24-ta-meeting-and-design-review-feedback)
* [10/09/24: Started Building Drone](#10/09/24-started-building-drone)
* [10/11/24: PCB Review and Wing Completion](#10/11/24-pcb-review-and-wing-completion)
* [10/12/24: Drone Body Completion](#10/12/24-drone-body-completion)
* [10/14/24: DRC Warnings and Obtained ESP32 Devboard](#10/14/24-drc-warnings-and-obtained-esp32-devboard)
* [10/15/24: Attempted PCB Order and Began Programming ESP32 Devkit](#10/15/24-attempted-pcb-order-and-began-programming-esp32-devkit)
* [10/16/24: Ordered SIM7600 and Servos](#10/16/24-ordered-sim7600-and-servos)
* [10/21/24: Revised PCB and Ordered Image Sensors](#10/21/24-revised-pcb-and-ordered-image-sensors)
* [10/23/24: Researched Encoders and JPEG Compression](#10/23/24-researched-encoders-and-jpeg-compression)
* [10/31/24: Tested Servo Control with SIM7600](#10/31/24-tested-servo-control-with-sim7600)
* [11/02/24: Began Soldering PCB and Coded Camera](#11/02/24-began-soldering-pcb-and-coded-camera)
* [11/03/24: Worked on Camera Software Integration](#11/03/24-worked-on-camera-software-integration)
* [11/05/24: Camera Software Development Continued](#11/05/24-camera-software-development-continued)
* [11/08/24: Got the Camera to Work](#11/08/24-got-the-camera-to-work)
* [11/12/24: Software Update and Cleaned up Soldering](#11/12/24-software-update-and-cleaned-up-soldering)
* [11/13/24: Completed Soldering and Attempted to Flash Board (Didn't Work)](#11/13/24-completed-soldering-and-attempted-to-flash-board-didnt-work)
* [11/15/24: Began Programming Board and Removed BME280](#11/15/24-began-programming-board-and-removed-bme280)
* [11/19/24: Completed Production of Functional PCB](#11/19/24-completed-production-of-functional-pcb)
* [11/28/24: Ordered Motor, Battery, ESC](#11/28/24-ordered-motor-battery-esc)
* [11/29/24: Continued working on Drone Pipeline Optimization](#11/29/24-continued-working-on-drone-pipeline-optimization)
* [12/01/24: Soldered New PCB](#12/01/24-soldered-new-pcb)
* [12/02/24: Tested Motor, Battery, and Prepared Drone for Installation](#12/02/24-tested-motor-battery-and-prepared-drone-for-installation)
* [12/03/24: Completed Production of Drone](#12/03/24-completed-production-of-drone)


## 08/26/24 - 08/31/24: Created Baseline Boost ASIO C++ Backend and TypeScript Frontend

Before ECE445 got into details into the idea stage and the RFA, I decided that I should at least get some code working. This is mainly just to expand our toolset for whatever the project may be. I started off by created a C++ backend that recieves datapackets from a TypeScript Frontend using websockets. Regardless of what robotics project we are doing, this is mainly to see if I could send and queue command signals from my frontend. The keys that are associated with commands in the codebase are WASD and ↑←↓→.

## 09/01/24 - 09/15/24: Logging Work Completed Before Starting Notebook

Coming into the semester, we had already narrowed down the general project idea we wanted to pursue as a team and began some initial research and development. We knew that, in some capacity, we wanted to build a drone that had a camera and a sophisticated software suite. Through our findings, we determined the basic hardware requirments for the drone, such as the array of sensors, microcontroller, motor controls, and internet connectivity. Originally, we wanted the drone to be a device that our local UIUC police force could use on campus for surveillance, and as such as we planned to communicate with the drone via (IllinoisNet) WiFi. This was the major reason why we chose to go with an ESP32 microcontroller in our design, as even through STM32 chips are more powerful, they lack WiFi capabilities. However, it through the RFA process, it became apparent that our intended usecase was not good enough and that we needed to broaden our scope. We decided to pivot our a idea slightly, still serving first responders but this time acting as an early response drone. This, however, meant that we could no longer rely on WiFi as a means for communication. We debated using long-range radio, but powerful receiver/transmitters are too expensive for this project. So, we chose to use a cellular module (SIM7600) and implement cellular connectivity. Theoretically, then, the range of our drone will purely be limited by it's battery life. As the first few weeks of the semester progressed and we completed various tasks such as the CAD and Soldering assignments for ECE 445, we also produced a first draft of the circuit schematic.

## 09/16/24: Working on Project Proposal

Today, I spent most of my time working on the Project Proposal. I mainly worked on the block diagram, subsystem overview, and subsystem requirements. This consists of providing an overall view of how our entire drone system commications with our applications which are locally stored on an external machine. It is important to note that we made the block diagram have 2 seperate potential solutions. Our backup solution involves a cloud storage, but our team is looking into methods to completely remove it. It is important to note that Firebase is free for development, but in terms of production settings, there is a monthly fees to it, which is mainly why we are trying to avoid it at all costs. I also wrote out a barebone parts list with important components that our design may require such as an IMU (MPU6050) and Barometer (BMP280).

## 09/17/24: Completed Project Proposal

After meeting with our TA and receiving some feedback on our Project Proposal, we were able to complete it and submit within a few more hours of work. I ended up keeping the high-level requirments with what I had originally written, as I felt they were the best quantifiable measures for our project that were not related to the drone itself. With clarification from our TA, we completed the Tolerance Analysis section by analyzing data transmission rates with the SIM7600.

## 09/18/24: Completed Team Contract

Today, our group met at and completed the Team Contract. We had some discussion with regards to how we planned to handle conflict, make decisions, and keep ourselves accountable during the completion of this project, but other than that we completed the document with relative ease. I worked primarily on the group expectations, conflict resolution, and project planning sections. 

## 09/24/24: Wrote Baseline Schematic

Today, I wrote a baseline schematic of how the esp32 board should look like. This is essentially a breakout board with no sensors on it. We are planning on discussing whether or not we are allowed to buy the sensor breakout boards for the MPU6050 and BMP280, but according to previous years, it the pcb is complex enough, we are allowed to, but it is very likely that we are not allowed to. It is important to mention that we sourced out circuit schematics for the sensor breakout boards as well so in theory, we can just place it on our original esp32 schematic. 

## 9/30/24: Worked on Design Document


## 10/3/24: Design document


## 10/8/24: TA Meeting and Design Review feedback


## 10/9/24: Started constructing drone


## 10/11/24: PCB Review and Wing Design

Kevin and I went to the PCB review session to recieve feedback on our design. However, the one main issue we ran into was that our PCB needed to pass a DRC check. Since we utilized EasyEDA as our PCB design tool, we had slightly different DRC rule checks. This posed to be an issue so we converted our schematic from EasyEDA to Kicad and ran a DRC check from there. We did recieve some feedback in terms of our design, but there were issues that came with implementing the feedback. One of the feedbacks we recieved was to use a 40 Mhz crystal oscillator, but the ESP32 S3 Wroom 1 already has this in-built. We were also asked why we could not just buy a drone shell. The main issue is that quadcopter shells tend to be a lot cheaper than fixed wing drones. A quadcopter also tends to require more motors and escs to be fully functions and utilize more battery.

Our entire group then went to Siebel Center of Design to construct the second drone wing. To do this, we simply had to replicate our first drone wing using our dollar tree foamboard. 

## 10/12/24: Drone Fuselage Completion


## 10/14/24: Obtained ESP32 Devboard and Kicad DRC Check

We met with our TA during the scheduled weekly meeting to talk about the DRC check. When we ran our DRC check on our Kicad schematic, we were able to remove all of the bugs, but there was approximately over 300 warnings. We also realized we could get a devkit for our ESP32 so we checked one out since the PCB wasn't going to come in for a while.

## 10/15/24: Attempted PCB Order and Began Programming ESP32 Devkit


## 10/16/24: Ordered SIM7600 and Servos


## 10/21/24: Revised PCB and Ordered Image Sensors


## 10/23/24: Researched Encoders and JPEG Compression


## 10/31/24: Tested Servo with SIM7600


## 11/02/24: Began Soldering PCB and Programmed Camera


## 11/03/24: Worked on Camera Software


## 11/05/24: Camera Software Development testing update


## 11/08/24: Camera Worked


## 11/12/24: Software Update and Cleaned up Soldering


## 11/13/24: Completed Soldering and attemped to flash board (didnt work)


## 11/15/24: Began Programming board and removed BME280


## 11/19/24: Functional PCB with BME280
Today, during our meeting with our TA, we were able to completely solder the BME280 and test the chip out with our testing code. We also completely replaced the ESP32 S3 Wroom 1 with a new ESP32 chip with PSRAM. This means that our board completely works now and that we are ready to completely switch over from our dev board to our PCB. From this chip, we were able to attain pressure, temperature, and estimated altitude using sea-level-pressure-HPA. 

## 11/28/24: Ordered Motor, Battery, ESC

To complete the drone, we needed to have a battery, ESC, and motor. The motor would act as our main source of thrust while the ESC controls the brushless motor. The battery would be there to power our motor while its voltages gets dropped to 5V by our ESC. Our ESC would then power our entire PCB and the SIM7600. Therefore, these parts were extremely necessary to the succesful completion of our project. Below shows the links of the ESC and Motor combo pack we bought and the battery. We also made the big decision of not making our drone fly as that would result in a hefty expense from our side. One thing to note is that our combo pack uses an ESC with a T-connector which makes the 2200mAh 3S LiPo battery we bought completely compatible since it also utilizes a T-connected.

Link: https://www.amazon.com/abcGoodefg-Brushless-Propeller-Accessories-Quadcopter/dp/B08DXYLFQQ?crid=BMRTHCMCWNH9&dib=eyJ2IjoiMSJ9.JntwHLhnCboXlpKIAsr43_YDrZUKtGF4cnhptSxuZvYIHTJSKzYlUtAE4qCpVHrfRVMdmmvQ0FKj645M_6sHLOnVYctmEIgMqAT91PNLk2VCR1rfwa5xUnlvx4YGv-g9vgZ-NDsn5uZSgxIVMlDqktdA6olIA3q4dFwpuDI5-zQQhpPqOgR12cBxA7xajhYz0JURzMbyZ80iUj9KfL3OAAjfuhltb1Y59KkR66E2h23asFpNghiLfPW7dXYI-KKd2qSuv4-p1Ocjoqx-ctWMiNc6Zzn4wymGeb_sdOZ2Vwo.MLJCt6ehMJtpJkNjKv9tkxXw_WHxGnjhi2vj8blet30&dib_tag=se&keywords=esc+with+motor&qid=1732854615&sprefix=esc+with+moto%2Caps%2C152&sr=8-8

Link: https://www.amazon.com/2200mAh-Connector-Airplane-Quadcopter-Helicopter/dp/B08CZF373Y/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.1bfb7020-bc2b-4494-b17e-0160f1a71ab1%3Aamzn1.sym.1bfb7020-bc2b-4494-b17e-0160f1a71ab1&crid=17HTV8X3PU8OL&cv_ct_cx=2200mAh+3S&keywords=2200mAh+3S&pd_rd_i=B08CZF373Y&pd_rd_r=80fea7bd-c90c-4ae2-aa3d-0ade595dbf5d&pd_rd_w=Dx12d&pd_rd_wg=y4t5C&pf_rd_p=1bfb7020-bc2b-4494-b17e-0160f1a71ab1&pf_rd_r=P9RJQQ44EKH1SFDGA0WQ&qid=1734055115&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=2200mah+3s%2Caps%2C149&sr=1-1-7efdef4d-9875-47e1-927f-8c2c1c47ed49-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9zZWFyY2hfdGhlbWF0aWM&psc=1

## 11/29/24: Continued working on Drone Pipeline Optimization

Today, Adi and I realized, we do not actually need to store the base64 image in the storage section of Firebase. Since the base64 encoding resembled a smalled image, we were able to store a smaller base64 encoding on the firestore sensor document itself. This would mean the SIM7600 would only interact with Firebase twice in a single cycle allowing for data transmission speed increase and recieving command speed increase. 

Adi and I rewrote the entire codebase on the ESP side from scratch due to older code being randomly present in our current code. We started a completely new project and ported over a lot of the correct code from our previous codebase. This took us approximately the entirety of the day.

## 12/01/24: Soldered New PCB

While we attemped to flash new code, the USB-B completely ripped off with the solder pads. This is simply worst case scenario because this would mean we need to redo our PCB completely. Previously, we did have a solderpad from the USB-B completely come off, but the main upside was that it was not an important solder pin for flashing since it was completely disconnected. Now, the D+ and D- solder pads came off completely preventing us from flashing code. We then started porting every single component from our previous PCB to our new PCB using a heat gun and soldering iron. This took us about 4-5ish hours until we realized that we completely melted the insides of our spare USB-B connected. We had to approach another group for a new spare USB-B connector which we are luckily receiving the next day. 

## 12/02/24: Motor, ESC, and Battery full tested for installation and 3D CAD Model

We were able to solder the USB-B connected to our new PCB and get all of the sensors working with it. We then continued by testing the brushless motor, esc, and battery and eventually got it working. Now, in order to connect it with the rest of our design, essentially, we would connect the data line from the esc to the PCB and the 5V output to the 5V pin of the PCB. Note that we would need to disconnect the laptop using USB-B which prevents debugging. Therefore, if we needed to debug, we would essentially connect the laptop to the PCB and run the Serial Terminal while the battery is disconnected. I then continued on working on creating the 3D CAD model for the motor mount which required a bit of effort due to irregular dimensioning. We also had minor issues with Camera using the same pins as our I2C pins for our 2 sensors so we had to choose 2 new Camera pins for our VSYNC and D7 pin on our camera from our PCB.

![image](https://github.com/user-attachments/assets/1e12f168-a982-40b3-af5d-837697fad8ea)

## 12/03/24: Completed Production of Drone

Today, our team combined all of the various components together to create a finished product. This meant installing the hardware within the drone shell and flashing the software. However, we ran into a small issue with the OV7670 not being able to provide us with frames while running the servo and sensor code in parrallel. Essentially what would happen is that our system would boot loop. We realized that our code introduced memory leaks so we decided to leave that out of our finalized software.

We then 3d printed the rest of the mounts which includes both a servo mount for the v-tail and a motor mount. Below are some images of the motor mount, servo mount, and our finalized ESP32 PCB/SIM7600/Gimbal Camera Mount. 

![image](https://github.com/user-attachments/assets/bee4f15a-993f-4c0a-82e3-577371d6e116)
![image](https://github.com/user-attachments/assets/a82aa048-7704-4a58-b149-8aeb6ef4cc11)
![image](https://github.com/user-attachments/assets/337be0a8-33c9-42b2-9005-7b68f416e9b1)

It is also important to note that we were not able to finish attaching everything completely. We were not able to strap the battery, GPS antenna, Cellular antenna, as well as not able to attach the pushrods to the servo for complete aileron/v-tail control. 





