# ECE445 Notebook - Lohit Muralidharan

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 08/31/24: Created Baseline Boost ASIO C++ Backend and TypeScript Frontend](#082624---083124-created-baseline-boost-asio-c-backend-and-typescript-frontend)
* [09/01/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#090124---091524-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#091624-working-on-project-proposal)
* [09/17/24: Completed Project Proposal](#091724-completed-project-proposal)
* [09/18/24: Completed Team Contract](#091824-completed-team-contract)
* [09/30/24: Worked on Design Document](#093024-worked-on-design-document)
* [10/03/24: Design Document](#100324-design-document)
* [10/08/24: TA Meeting and Design Review Feedback](#100824-ta-meeting-and-design-review-feedback)
* [10/09/24: Started Building Drone](#100924-started-building-drone)
* [10/11/24: PCB Review and Wing Completion](#101124-pcb-review-and-wing-completion)
* [10/12/24: Drone Body Completion](#101224-drone-body-completion)
* [10/14/24: DRC Warnings and Obtained ESP32 Devboard](#101424-drc-warnings-and-obtained-esp32-devboard)
* [10/15/24: Attempted PCB Order and ESP32 Test](#101524-attempted-pcb-order-and-esp32-test)
* [10/16/24: Ordered SIM7600 and Servos](#101624-ordered-sim7600-and-servos)
* [10/21/24: Revised PCB and Ordered OV7670](#102124-revised-pcb-and-ordered-ov7670)
* [10/23/24: Researched Libcurl with C++ Backend](#102324-researched-libcurl-with-c-backend)
* [10/31/24: Tested Servo Control with SIM7600](#103124-tested-servo-control-with-sim7600)
* [11/02/24: Began Soldering PCB and Coded Camera](#110224-began-soldering-pcb-and-coded-camera)
* [11/03/24: Worked on Camera Software Integration](#110324-worked-on-camera-software-integration)
* [11/05/24: Camera Software Development Continued](#110524-camera-software-development-continued)
* [11/08/24: Got the Camera to Work](#110824-got-the-camera-to-work)
* [11/13/24: Completed Soldering and Attempted to Flash Board (Didn't Work)](#111324-completed-soldering-and-attempted-to-flash-board-didnt-work)
* [11/14/24: Debugged Board in the morning](#111424-debugged-board-in-the-morning)
* [11/15/24: Created 3D CAD Models for Gimbal Servo Mount and Board Mounts](#111524-created-3d-cad-models-for-gimbal-servo-mount-and-board-mounts)
* [11/19/24: Completed Production of Functional PCB](#111924-completed-production-of-functional-pcb)
* [11/28/24: Ordered Motor, Battery, ESC](#112824-ordered-motor-battery-esc)
* [11/29/24: Continued working on Drone Pipeline Optimization](#112924-continued-working-on-drone-pipeline-optimization)
* [12/01/24: Soldered New PCB](#120124-soldered-new-pcb)
[12/02/24: Motor, ESC, and Battery full tested for installation and 3D CAD Model](#120224-motor-esc-and-battery-full-tested-for-installation-and-3d-cad-model)
* [12/03/24: Completed Production of Drone](#120324-completed-production-of-drone)


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

## 9/30/24: Wrote a 4-layer PCB Design in Easy EDA

This past week I got really busy in another class, but I decided to pick up the pace today. Today, I attached the breakout boards to the overall PCB schematic using our sourced online breakout board examples. I then generated a PCB file on EasyEDA and wrote out all of the traces. I set the trace widths to 10 mils and I had a seperate GND and 3.3V layer. For the 5V layer, I used the polygon tool to combine all of the 5V pads together allowed for more free flow current through the entire polygon.

![image](https://github.com/user-attachments/assets/b426136a-f0a5-4c41-98dd-17e7748ed3d7)
![image](https://github.com/user-attachments/assets/03fda017-41f7-4b4f-89c8-753786b184ec)


## 10/3/24: Design document

Our team went to BIF to finish the design Document. I mainly worked on writing out how the entire design actually works as well as the flowcharts while my teammembers worked on the other parts such as R/V tables, cost analysis, and technical design analysis. I also wrote out the flow charts using Miro Board to show how our entire design comes together as one fully functional drone. We also wrote up on our pcb design and the various components that comprises of it such as the CP2102, ESP32 S3 Wroom 1, MPU6050, and BMP280. We also found out some issues with our power subsystem so we modified our PCB design to accomodate for our modifications.

## 10/8/24: TA Meeting and Design Review feedback

We had our team meeting today mainly to have an overall design review. However, some of my teammates and the professor was extremely concerned with the scope of our project. Therefore, we talked to our TA, and we came up with a solution. Our solution was simply to split our design in 2 seperate phases where the first phase is simply to get all of our electronics working and mounted to our drone. The second phase would be there for extra credit. I personally wanted this drone to fly but the professor did have concerns as our team also did meet with him in person to discuss. He seemed pretty afraid of getting it to fly for 2 main reasons which he pointed out. The first reason was safety, and the second reason was legal reasons. I found solutions to these problems, but my teammates were concerned due having flight as a factor for our grades.

## 10/9/24: Started constructing drone

Today, Adi and I went to Seibel Center of Design to do research on how people construct fixed wing planes with foamboard. We found this one channel called FlightTest that does a lot of crazy builds. After watching a lot of their videos, we analyzed their techniques they used and how they design their drones. From this, we decided to come up with our own design for the drone. We lightly drew out with a pencil and large ruler the design of our PCB including the fuselage and wing. We then double checked the dimensions of everything and started performing cuts using an exacto knife. We also ensured that various components would be able to fit within our design without any trouble. 

Adi and I also gained access to the entire lab facility by going through Canvas training and other necessary processes. This allowed us to get access to various tools and a special card called the GRAIC card. 

## 10/11/24: PCB Review and Wing Design

Kevin and I went to the PCB review session to recieve feedback on our design. However, the one main issue we ran into was that our PCB needed to pass a DRC check. Since we utilized EasyEDA as our PCB design tool, we had slightly different DRC rule checks. This posed to be an issue so we converted our schematic from EasyEDA to Kicad and ran a DRC check from there. We did recieve some feedback in terms of our design, but there were issues that came with implementing the feedback. One of the feedbacks we recieved was to use a 40 Mhz crystal oscillator, but the ESP32 S3 Wroom 1 already has this in-built. We were also asked why we could not just buy a drone shell. The main issue is that quadcopter shells tend to be a lot cheaper than fixed wing drones. A quadcopter also tends to require more motors and escs to be fully functions and utilize more battery.

Our entire group then went to Siebel Center of Design to construct the second drone wing. To do this, we simply had to replicate our first drone wing using our dollar tree foamboard. 

## 10/12/24: Drone Fuselage Completion

Today, Adi and I went to Seibel center of design to finish the drone fuselage and connect our wing to it. We used an exacto knife to cuz out the pieces from our excess foam board and hot glued them together. We also removed excess hot glue to ensure proper connetion and removal of unnecesary weight. We also almost created the V-tail, but we realized we messed up the orientation of the base of V-tail so we completely dismantled the v-tail. We also ensured that the fueselage would be able to be capable of fitting our PCB and external boards such as the SIM7600.   

![image](https://github.com/user-attachments/assets/732af849-1ba0-4753-9978-cd62094e46c0)

## 10/14/24: Obtained ESP32 Devboard and Kicad DRC Check

We met with our TA during the scheduled weekly meeting to talk about the DRC check. When we ran our DRC check on our Kicad schematic, we were able to remove all of the bugs, but there was approximately over 300 warnings. We also realized we could get a devkit for our ESP32 so we checked one out since the PCB wasn't going to come in for a while.

## 10/15/24: Attempted PCB Order and ESP32 Test

We attemped to order our PCB today, but this proved to be a massive challenge as our PCB costed around $50. The reason behind this is due to the fact that our board utilized 4 layers rather than 2 layers. Therefore, we decided that we would not order today and rather attempt to reduce our board to 2 layers. We believed this would not change the trajectory of our class because the first 2 orders come exactly at the same time. 

Also, we attempted to program our ESP32 S3 Wroom 1 Devboard today. We attemped to use Servos and Leds that were randomly in the room to see if we can operate on these devices. The code we wrote moved the servos from 0 to 180 degrees and back to 0 degrees on repeat. We also created a blinking LED sketch with our arduino IDE. Lastly, we learned how to use FreeRTOS with our devkit as we may or may not need to have parrallelism with our application in the future to reduce latency. 

## 10/16/24: Ordered SIM7600 and Servos

Today, we decided to order our first big parts. This included a SIM7600 and a Servo combo pack. The servos would be used for drone control and the SIM7600 would be used as our main source of communication. I do want to point out that the SIM7600 costed $70 off of amazon and we had to look for a specific encoding (A-H) which represents the fact that this module would work in North America. We did find a cheaper alternative which was SIM7600A, but this module only supported 2G which isn't used in the United States anymore. We also found out that we could buy this module for much cheaper from external websites, but the ECE department only supports a variety of vendors which made it much harder for our team. The links to our buy orders are shown below.

Link: https://www.amazon.com/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=mp_s_a_1_3?crid=BS5S38CTNWFJ&dib=eyJ2IjoiMSJ9.lRrzFkSvx8GhZXXbAhDTVjP2EBkmoPc78-c-JdjWfKTZ6G91lio_kdzjsWDqFwzZbVMuHW53QXTXvd5kfqbGZxT01VcxdXrQXmVcz2irdLU8r-hZiCjRjDyBukToNBy4xd74BJK_PQM3IyMXwPWK8UFQcaVyQ6iBeXTjT_QOXfQ8Dsqh7YOIkUniuTDJHiwcsXS4pFbd0KSDWaLCZ7v8UQ.yJ2ZDPWrq5zxWtyR6YiXr8_OJHXUBhh5KqmaoInMx0o&dib_tag=se&keywords=servos&qid=1729118694&sprefix=servos%2Caps%2C117&sr=8-3&th=1

Link: https://www.amazon.com/waveshare-Raspberry-SIM7600A-H-Supports-Telephone/dp/B07Q48WNCF/ref=sr_1_4?crid=KHHXSOBI4PZI&dib=eyJ2IjoiMSJ9.fUs1eMGSX8x5TMUiK2GvwS4l_uzZ0KGObNtxo9jk360-T5rwyMDC8fdyi5CxiJUoyhRh_95h0Xb7WWohbHVpBbbF99vLJEqLzXEObQvhv2tno73wM5H_YA74Litgb-nlNF6tcJ3s4nM7zU_GVTHZllq0BPf-FsNyVqJCZCvU462Lwyh93Mn9uz5Tz7t9GHxDn8umfxF0rmk9rOGeABO1SKpd14yvPwXgjeMVYRhp2R4.JTjdTmrEGmhOkV94ypwdhxKr4qR-3agWQRJ7N3l1qMQ&dib_tag=se&keywords=SIM7600A-H&qid=1729121064&sprefix=sim7600a-h%2Caps%2C80&sr=8-4

## 10/21/24: Revised PCB and Ordered OV7670

Today, we revised our PCB to utilize 2 layers rather than 4 layers. This proved to be a massive challenge, but we decided that we would make the top layer a 3.3V layer and the bottom layer as GND as this is what most of our components connected to. We kept the 5V polygon from our original design as there would be a gap between non 3.3V traces and the 3.3V layer. We also ensured that the DRC checks would pass and that there would be no error. We completely ignored the 300 warnings that were generated again after making this massive change.

![image](https://github.com/user-attachments/assets/0e20085f-3254-449b-be7e-1db737b58f7b)

We also ended up ordering the OV7670 camera which acts as the main camera for our drone. We bought a 2 pack just in case one of the cameras failed. 

## 10/23/24: Researched Libcurl with C++ Backend

Today, I decided to work on configuring libcurl with the rest of C++ backend. The main reason for libcurl is its easy support for using HTTP requests to modify a database. Any curl command that one can run on a terminal can be done through the C++ libcurl library. Boost also has an HTTP library, but it would be much more difficult to configure. Therefore, I first figured out how to run a curl command for performing GET and POST requests. After running these commands on the terminal to recieve dummy sensor data and posting dummy command values, I was able to call these curl commands using the libcurl library. This ended up working out and I was able to peform full communication from the frontend to the firebase cloud storage. 

## 10/31/24: Tested Servo with SIM7600

We tested the servo in conjunction with the SIM7600. Our theory ended up working, and we were able to send commands from our frontend to move the servo. Our next steps would be to expand this to accomodate for more than 1 servo. We also found out that the BMP280 was not sold anymore so we switched to using a BME280. The good thing is that I did not have to change the board at all because both sensors are the same dimensions and have the same exact pads. We also gain temperature readings on top of the altitude readings we originally got from our BMP280 sensor design. 

![image](https://github.com/user-attachments/assets/2b529b0f-cee0-4570-9e8c-b37e207a7972)

## 11/02/24: Researched Camera

Today, Adi and I were researching on how to connect the camera to the ESP board. There are exactly 20 camera pins on the OV7670 and required us to use the entire left side of the ESP32 S3 Wroom 1. We also did research on every pin to figure out what exactly it means and read through some technical documentation. We also did some light research on online libraries and implementation for the camera drivers just in case we needed to create our own camera drivers from scratch. We found a youtube channel called Bitluni that did an entire tutorial on how his drivers worked. 

Link: https://www.youtube.com/watch?v=S2yTQHM82jc

## 11/03/24: Worked on Camera Software

Today, we continued working on writing the code for the OV7670. Adi and I went to Grainger Library and decided to try to retrieve camera frames. We found a lot of online libraries of people who already implemented all of the camera registers and such. We also found an espressif library that works with the OV7670. However, after connected all of the wires from our camera to our ESP32 S3 Wroom 1 devkit, we found out that in some of the libraries, the pin configurations are named differently than what we see on the camera. Regardless, we attempted to create a one-to-one mapping between each camera pin and the library. However, after tested multitudes of libraries, we realized that the camera output we were generating was garbage output.

![image](https://github.com/user-attachments/assets/6452f072-73be-4e7c-9977-7d3d739113fa)
![image](https://github.com/user-attachments/assets/f6ac7b2b-49a8-40fd-b524-d6052d2301dd)

## 11/05/24: Camera Software Development testing update

Today, we continued trying to debug our OV7670. We attempted to try to use multiple different techniques such as JPEG encoding and buffering. We also attempted to take our broken JPEG image and convert it to base64 to see if our image was in fact fine all of this while, and none of this ended up working out. The interesting observation however we received was that our image actually looked different in terms of the noise output that we generated received for the past 2 days.

![image](https://github.com/user-attachments/assets/f4eb6058-e9a3-4e2a-b5d3-d402b1fef66f)

After doing a lot more careful research, we found out that the OV7670 was missing a special chip called a FIFO buffer chip. This chip is mainly used to retrieve a couple frames lines from the OV7670 and store it in this buffer. Since this was missing, all of our OV7670 camera libraries did not end up working out. Therefore, Adi ended up buying a new OV7670 with a fifo buffer chip attached to it. 

## 11/08/24: Camera Worked

Today, I mainly worked on getting the camera to work. Essentially, we found a library by bitluni that allowed us to retrieve Camera Frames from our OV7670 with FIFO chip. We also went through OV7670 technical documentation and modified some of the registers to remove some of the discoloration and pixel noise. Next steps will be to simply find a JPEG encoder library or a method to convert our image to base64 for storing on firebase.  

Library: https://bitluni.net/ov7670-with-fifo

![image](https://github.com/user-attachments/assets/4a913068-d7b3-4db2-b647-f204637beca6)
![image](https://github.com/user-attachments/assets/cba158de-d32b-4c33-b8a9-8bf693e9a8b3)

## 11/13/24: Completed Soldering and attemped to flash board (didnt work)

We spent the entirety of today finishing soldering the board. One thing we noticed is that we were not able to get the multicolor LED on the board due to it being completely different sizes. We ended up deciding that we would omit the multicolor LED from the board overall. This has its own drawback as we could not utilize the gpio pin that the multicolor LED was connected to. We also did not have a 601 package for 0.01 uF capacitor. To go around this, we found an 805 package for this capacitor which we managed to solder on the board. 

Once the rest of the components were on the board, we flashed a simple Serial print code, but when we connected the USB-B connector, the board was not even being powered on. We attempted to probe the board using a multimeter, but this ended up being inneffective and decided to give up after a long night. 

## 11/14/24: Debugged Board in the morning

I randomly decided to get up early on the morning as I was completely confused why we could not even get 5V from our USB-B connector. I then decided to go to the lab room and stick a spare USB-B connector through the cable and probe the 5V line. This ended up showing 5V on the voltmeter. This made me curious as I was confused why 5V would not be outputted from the USB-B connected on the PCB board. I then looked under a microscope and realized that the pad was not completely soldered. Once I soldered the pad, I was able to get 5V from the USB-B connector. However, the rest of the board was still not powering on, and the LED did not glow. I then realized the LED was completely flipped, so after fixing this issue, I was able to get the led to turn red. Now even after resolving these issues, I still was not able to flash. I went through the Kicad schematic and found our that the D+ and D- pins of the USB-B connector ends up connecting to a D+ and D- on the CP2102 USB-to-UART chip.

![image](https://github.com/user-attachments/assets/05e8fe04-1e95-40a8-aa11-3aaca03ed97c)

After looking under a microscope, I found out that the TX pin and the D+ pin were both not soldered correctly. I simply applied flux and solder to make sure all the pads recieved an even amount of solder. This still did not end up resolving the issue as I was not able to boot. The last issue which I found under the microscope was that GPIO0 was not soldered correctly on the board. After soldering the pin, I was able to get a Serial print from our serial print tester file.

## 11/15/24: Created 3D CAD Models for Gimbal Servo Mount and Board Mounts

Today, I utilized Onshape to create 3 3d CAD models. 2 of the 3d CAD Models were for the mounting the servos that control the camera as well as the OV7670, and the last CAD model was used to mount the gimbal camera structure, SIM7600, and PCB board in a single design. Below shows the 3 designs of our CAD models. 

![image](https://github.com/user-attachments/assets/ff4164a0-73cb-456d-86b3-a04841918257)
![image](https://github.com/user-attachments/assets/a7319afb-b09d-4fa3-8273-f9985b1fe0ca)
![image](https://github.com/user-attachments/assets/674ce50c-1ff6-44e5-a6b7-de3fb60fc2c9)

I also was able to learn how to use the Bambu printed in the lab by installing the Bambu software on my machine, importing an STL file, configuring the 3D printing setup and adding braces, exporting the gcode file to the sdcard, and printing the gcode file from the sdcard. I also found out that the Bambu printer was broken so I ended up looking through technical documentation to figure out how to fix it. Aparently, I first had to clean the tip of the 3d printer nozzel and readjust the sensor. After doing this, I was able to print all of my parts.  

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





