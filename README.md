# ECE445 Notebook - Aditya Patel

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#08/26/24---09/15/24:-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#09/16/24:-Working-on-Project-Proposal)
* [09/17/24: Completed Project Proposal](#09/17/24:-Completed-Project-Proposal)
* [09/18/24: Completed Team Contract](#09/18/24:-Completed-Team-Contract)

## 08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook

We had already begun basic research and development at the start of the semester, and we had decided on the general project concept that we wanted to work on as a team. We were aware that we planned to build a drone with a camera and powerful software in some form. Our study helped us to establish the drone's basic hardware requirements, such as sensors, microprocessors, motor controllers, and internet connectivity. 

## 09/16/24: Working on Project Proposal

I spent a good chunk of the time today writing the Project Proposal. To be specific, I did all the tolerance analysis by looking up the specific specs and design choices of the sensors and the SIM7600 transmission details. I calculated the precise data rate (bandwidth) required to be able to transmit frames at a reasonable fps. I also worked on researching the ethics behind the drone and how we can take preventive measures necessary to avoid violations. I also read through a lot of the IEEE/ACM code of ethics. The last thing was to update our design and list all the different things we can do to get past these regulations, which turned out to be not too many things wrong. We added to the design rather than changing it in terms of sensor for proper tracking and collision detection methodologies. At first, we intended to utilize the drone to interact with the IllinoisNet WiFi network in order to enable our local UIUC police department to use it for surveillance purposes on campus. This was a crucial factor in our decision to choose an ESP32 microcontroller in our design because, despite STM32 chips' greater power, they do not support WiFi. But as the RFA process went on, it became clear that we needed to expand our scope since our initial usecase was insufficient. We made the decision to somewhat change our original plan in order to continue helping first responders, but this time as an early response drone. Nevertheless, this meant that we could no longer rely on WiFi to communicate. Although long-range radio was discussed, the cost of strong receiver/transmitters made the concept unfeasible. Therefore, we decided to integrate cellular communication using a cellular module (SIM7600). Thus, in theory, our drone's range will only be constrained by the amount of battery life left in it. Furthermore, although there are still some networking challenges to be resolved, Lohit was able to develop the most of the basic code for both the frontend user interface and backend. We created a preliminary version of the circuit design throughout the first few weeks of the semester as we finished homework for ECE 445, including the CAD and soldering activities.

## 09/17/24: Completed Project Proposal

The meeting with the TA led us to make some discoveries with the tolerance analysis, so we went through it again and refined some details. I finished up the ethics section, and we were good to submit. We gave it one last check by reading it over and submitted.

## 09/18/24: Completed Team Contract

Today, our group gathered and signed the Team Contract. We had some discussions about how we planned to handle disagreement, make choices, and hold ourselves responsible throughout the course of this project, but other than that, we produced our work very easily. I worked on the Project Description, Ground Rules, and End-of-term Agreement sections. 
