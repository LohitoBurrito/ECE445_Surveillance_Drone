# ECE445 Notebook - Kevin Gerard

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#082624---091524-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#091624-working-on-project-proposal)
* [09/17/24: Completed Project Proposal](#091724-completed-project-proposal)
* [09/18/24: Completed Team Contract](#091824-completed-team-contract)
* [09/24/24: Researched MPU6050 IMU Circuit Schematic](#092424-researched-mpu6050-imu-circuit-schematic)
* [09/29/24: Worked on Design Document](#092924-worked-on-design-document)

## 08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook

Coming into the semester, we had already narrowed down the general project idea we wanted to pursue as a team and began some initial research and development. We knew that, in some capacity, we wanted to build a drone that had a camera and a sophisticated software suite. Through our findings, we determined the basic hardware requirments for the drone, such as the array of sensors, microcontroller, motor controls, and internet connectivity. Originally, we wanted the drone to be a device that our local UIUC police force could use on campus for surveillance, and as such as we planned to communicate with the drone via (IllinoisNet) WiFi. This was the major reason why we chose to go with an ESP32 microcontroller in our design, as even through STM32 chips are more powerful, they lack WiFi capabilities. However, it through the RFA process, it became apparent that our intended usecase was not good enough and that we needed to broaden our scope. We decided to pivot our a idea slightly, still serving first responders but this time acting as an early response drone. This, however, meant that we could no longer rely on WiFi as a means for communication. We debated using long-range radio, but powerful receiver/transmitters are too expensive for this project. So, we chose to use a cellular module (SIM7600) and implement cellular connectivity. Theoretically, then, the range of our drone will purely be limited by it's battery life. As the first few weeks of the semester progressed and we completed various tasks such as the CAD and Soldering assignments for ECE 445, we also produced a first draft of the circuit schematic. Additionally, Lohit was able to write most of the baseline code for the frontend UI and backend, but there are still some networking issues being worked out. 

## 09/16/24: Working on Project Proposal

Today, I spent most of my time working on the Project Proposal. Specifically, I finished writing most of the Introduction, which was comprised of explaining the problem, explaining our solution, and writing some high-level requirments we want our drone to meet. Most of the Introduction was not too time consuming, as I could borrow a lot of information I wrote in the RFA. However, the I found it pretty difficult to come up with a list of high-level requirments. Since there are currently a lot of unknowns with our drone, it's pretty hard to provide quantifiable expectations about the drone itself. This, along with the Tolerance Analysis section that we don't really know how to answer, are two questions we definitely want to ask our TA tomorrow during our first meeting. As of this point, most of the report is completed, excluding those two areas of concern and the Ethics and Safety section.

## 09/17/24: Completed Project Proposal

After meeting with our TA and receiving some feedback on our Project Proposal, we were able to complete it and submit within a few more hours of work. I ended up keeping the high-level requirments with what I had originally written, as I felt they were the best quantifiable measures for our project that were not related to the drone itself. With clarification from our TA, we completed the Tolerance Analysis section by analyzing data transmission rates with the SIM7600. After Adi finished writing the Ethics and Safety section, we reviewed our work and submitted the document.

## 09/18/24: Completed Team Contract

Today, our group met at and completed the Team Contract. We had some discussion with regards to how we planned to handle conflict, make decisions, and keep ourselves accountable during the completion of this project, but other than that we completed the document with relative ease. I worked primarily on the group expectations, conflict resolution, and project planning sections.

## 09/24/24: Researched MPU6050 IMU Circuit Schematic

I spent some time today before our meeting with our TA to review the current circuit schematic we have designed. I reviewed the array of sensors we needed and found some online examples of schematics for the MPU6050, which is the IMU we have decided to go with since it is very popular in embedded applications, low cost, and widely availiable. Another added plus of the MPU6050 is that I have some experience interfacing with the software drivers for it through RSO experience.

![1457053860374](https://github.com/user-attachments/assets/5ab0187a-c3c9-471c-9dee-b950a7fed238)

I sent this schematic to Lohit, who latered added it into our design.

Our meeting with the TA was very productive and helpful. Since neither I nor my groupmates have much experience with PCB design, we are quite concerned with if we going about it the right way and if our schematic is any good. We plan to send our schematic to the TA later this week so that she can review it and give us feedback. We also will get confirmation on whether breakout boards (and ESCs) are allowed in our design, as the SIM7600 is an extremely complex module to design around.

## 09/29/24: Worked on Design Document

I spent much of my time today working on our project's design document. I began by reviewing the provided documentation and examples on the assignment from the course website, taking note of key elements we would need to include. Then, I created the document and made the basic outline. I ported over much of the information from the proposal that could be re-used, such as information for the Introduction and Ethics and Safety. However, I re-read the feedback Professor Fliflet provided us on our initial Project Proposal and realized we would need to discuss, as a team, to make some serious adjustments to our project. It seems that the professor is concerned about the scope of our project and implied that the building a drone AND creating the sophisticated software suite may be too much for this class. I am now exploring the option of adjusting our project to be focused on creating the software suite and the drone electronics, rather than a flying drone itself. I am not sure if this is enough to be a project for this class, though, so I have contacted our TA for feedback.
