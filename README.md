# ECE445 Notebook - Aditya Patel

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#08/26/24---09/15/24:-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#09/16/24:-Working-on-Project-Proposal)
* [09/17/24: Completed Project Proposal](#09/17/24:-Completed-Project-Proposal)
* [09/18/24: Completed Team Contract](#09/18/24:-Completed-Team-Contract)

## 08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook

We had already begun basic research and development at the start of the semester, and we had decided on the general project concept that we wanted to work on as a team. We were aware that we planned to build a drone with a camera and powerful software in some form. Our study helped us to establish the drone's basic hardware requirements, such as sensors, microprocessors, motor controllers, and internet connectivity. At first, we intended to utilize the drone to interact with the IllinoisNet WiFi network in order to enable our local UIUC police department to use it for surveillance purposes on campus. This was a crucial factor in our decision to choose an ESP32 microcontroller in our design because, despite STM32 chips' greater power, they do not support WiFi. But as the RFA process went on, it became clear that we needed to expand our scope since our initial usecase was insufficient. We made the decision to somewhat change our original plan in order to continue helping first responders, but this time as an early response drone. Nevertheless, this meant that we could no longer rely on WiFi to communicate. Although long-range radio was discussed, the cost of strong receiver/transmitters made the concept unfeasible. Therefore, we decided to integrate cellular communication using a cellular module (SIM7600). Thus, in theory, our drone's range will only be constrained by the amount of battery life left in it. Furthermore, although there are still some networking challenges to be resolved, Lohit was able to develop the most of the basic code for both the frontend user interface and backend. We created a preliminary version of the circuit design throughout the first few weeks of the semester as we finished homework for ECE 445, including the CAD and soldering activities.

## 09/16/24: Working on Project Proposal

I spent a good chunk of the time today writing the Project Proposal. To be specific, I did all the tolerance analysis by looking up the specific specs and design choices of the sensors and the SIM7600 transmission details. I calculated the precise data rate (bandwidth) required to be able to transmit frames at a reasonable fps. I also worked on researching the ethics behind the drone and how we can take preventive measures necessary to avoid violations. I also read through a lot of the IEEE/ACM code of ethics. The last thing was to update our design and list all the different things we can do to get past these regulations, which turned out to be not too many things wrong. We added to the design rather than changing it in terms of sensor for proper tracking and collision detection methodologies. 

## 09/17/24: Completed Project Proposal

The meeting with the TA led us to make some discoveries with the tolerance analysis, so we went through it again and refined some details. Specifically the data transfer rate we could afford ot send and recieve was a bit off. I researched the different types of JPEG compression tecniques, and got set on one that allowed us to retain most of the image quality while allowing for a little bit of headroom for anything we did not account for just yet. I finished up the ethics section, and we were good to submit. We gave it one last check by reading it over and submitted.

## 09/18/24: Completed Team Contract

Today, our group gathered and signed the Team Contract. We had some discussions about how we planned to handle disagreement, make choices, and hold ourselves responsible throughout the course of this project, but other than that, we produced our work very easily. I worked on the Project Description, Ground Rules, and End-of-term Agreement sections. 

## 09/24/24: Started Researching into the SIM7600 Module

We had a great meeting with the TA today, where we discussed the current scope of the project, and came up at a reasonable middle ground. We were also able to discuss the logistics of the PCB order and design since none of us are particularly proficient in that regard. We also had a discussion regarding the SIM7600 and the scope of actually soldering one ourself. Upon further investigation of the module, we concluded that with our current set of knowledge and expertise, it would be nearly impossible to be able to design one from the ground up. We requested to have that part ordered for us separately, so hopefully that is okay. After the meeting, I really started researching how to code the SIM7600 and how capable it will be in terms of realistically being able to send and receive most of the data we wished to gather. I had a really good intuition that we would be able to get HTML based connection working on the SIM7600 and go to a lower abstraction from there if truly needed.

## 09/29/24: Started writing the Design Document

Kevin started the document for us by copying over some of the things we already wrote for the project proposal. I spent a lot of my time today going over the stuff we already wrote and making sure to read all the feedback we got from Prof. Fliflet. He made a fair point of wanting a lot more details from us regarding what the final product will be. Now, it is clear that the drone will be a very hard project to achieve sonsidering the fact that we need to have it flying and have the complex software suite working. Me and Kevin talked a bit regaarding this and we are exploring the option to switch the focus of our project to only have the software suite as our main point of focus.

## 09/30/24: More work on the Design Document

We were having a lot of issues truly deducing the scope of our project, so we decided to have a meeting with our TA to discuss it thoroughly. She was able to give us some great feedback on how to narrow down our focus. We came up with the compromise that the drone needs to have two phases, where the first phase will be to finish the software suite fully, and the second focusing on actually getting the drone to fly. After the meeting we switched focus to the design document to incorporate this new advice and reafactor some of the older advice we had gotten. We reviewed some of the older design documents to get a good sense of what was expected from us. We discussed one of the requirements we wrote for the drone which dealt with the drone uptime, and it seemed to be abit unrealistic upon some back and forth with out TA and Prof. Fliflet's advice. The main concern for me was the revision of some of the solutions for solving ethical problems, and the main one here was the absence of an absolute fail safe system. This helped us formulate a new plan of action that signified changing the uptime requirement to something that is more trivial to the safety of our drone. We decided to incorporate an additional servo to our drone that would act as a holster for the parachute to deploy under certain circumstances like network loss, restricted properties, and collision avoidance. This would allow the drone to safely land both through user input in the case where that's feasible and autonomously when bad network conection is observed. 

<img width="674" alt="Screenshot 2024-12-08 at 2 57 48 PM" src="https://github.com/user-attachments/assets/39a3d405-6d33-4304-8a2a-baebcb3de087">

I hadn't worked with the schematic much at this point because my main focus had been to figure out the Arduino software and the SIM7600 interfacing. I reviewed our first draft to realize a wrong pin set high on the pressure sensor, which is ended up getting fixed. 



