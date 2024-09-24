# ECE445 Notebook - Lohit Muralidharan

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 08/31/24: Created Baseline Boost ASIO C++ Backend and TypeScript Frontend](#08/26/24---08/31/24:-Created-Baseline-Boost-ASIO-C++-Backend-and-TypeScript-Frontend)
* [09/01/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#08/26/24---09/15/24:-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#09/16/24:-Working-on-Project-Proposal)
* [09/17/24: Completed Project Proposal](#09/17/24:-Completed-Project-Proposal)
* [09/18/24: Completed Team Contract](#09/18/24:-Completed-Team-Contract)

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


