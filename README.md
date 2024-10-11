# ECE445 Notebook - Kevin Gerard

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#082624---091524-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#091624-working-on-project-proposal)
* [09/17/24: Completed Project Proposal](#091724-completed-project-proposal)
* [09/18/24: Completed Team Contract](#091824-completed-team-contract)
* [09/24/24: Researched MPU6050 IMU Circuit Schematic](#092424-researched-mpu6050-imu-circuit-schematic)
* [09/29/24: Worked on Design Document](#092924-worked-on-design-document)
* [09/30/24: Worked on Design Document](#093024-worked-on-design-document)
* [10/01/24: Shifted Project Focus](#100124-shifted-project-focus)
* [10/02/24: Worked on Design Document](#100224-worked-on-design-document)
* [10/03/24: Completed Design Document and Proposal Revisions](#100324-completed-design-document-and-proposal-revisions)

## 08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook

Coming into the semester, we had already narrowed down the general project idea we wanted to pursue as a team and began some initial research and development. We knew that, in some capacity, we wanted to build a drone that had a camera and a sophisticated software suite. Through our findings, we determined the basic hardware requirments for the drone, such as the array of sensors, microcontroller, motor controls, and internet connectivity. Originally, we wanted the drone to be a device that our local UIUC police force could use on campus for surveillance, and as such as we planned to communicate with the drone via (IllinoisNet) WiFi. This was the major reason why we chose to go with an ESP32 microcontroller in our design, as even through STM32 chips are more powerful, they lack WiFi capabilities. However, it through the RFA process, it became apparent that our intended usecase was not good enough and that we needed to broaden our scope. We decided to pivot our a idea slightly, still serving first responders but this time acting as an early response drone. This, however, meant that we could no longer rely on WiFi as a means for communication. We debated using long-range radio, but powerful receiver/transmitters are too expensive for this project. So, we chose to use a cellular module (SIM7600) and implement cellular connectivity. Theoretically, then, the range of our drone will purely be limited by it's battery life. As the first few weeks of the semester progressed and we completed various tasks such as the CAD and Soldering assignments for ECE 445, we also produced a first draft of the circuit schematic. Additionally, Lohit was able to write most of the baseline code for the frontend UI and backend, but there are still some networking issues being worked out. 

## 09/16/24: Working on Project Proposal

Today, I spent most of my time working on the Project Proposal. Specifically, I finished writing most of the Introduction, which was comprised of explaining the problem, explaining our solution, and writing some high-level requirments we want our drone to meet. Most of the Introduction was not too time consuming, as I could borrow a lot of information I wrote in the RFA. However, the I found it pretty difficult to come up with a list of high-level requirments. Since there are currently a lot of unknowns with our drone, it's pretty hard to provide quantifiable expectations about the drone itself. This, along with the Tolerance Analysis section that we don't really know how to answer, are two questions we definitely want to ask our TA tomorrow during our first meeting. As of this point, most of the report is completed, excluding those two areas of concern and the Ethics and Safety section.

## 09/17/24: Completed Project Proposal

After meeting with our TA and receiving some feedback on our Project Proposal, we were able to complete it and submit within a few more hours of work. I ended up keeping the high-level requirments with what I had originally written, as I felt they were the best quantifiable measures for our project that were not related to the drone itself. With clarification from our TA, we completed the Tolerance Analysis section by analyzing data transmission rates with the SIM7600. After Adi finished writing the Ethics and Safety section, we reviewed our work and submitted the document.

<img width="1230" alt="Screenshot 2024-10-02 at 12 19 34 AM" src="https://github.com/user-attachments/assets/38aad503-229a-4ffb-b165-183d9358f492">

Here is a quick visual diagram I made of the main components of our drone system. The crucial part here, and what makes our drone stand out, is the cellular connectivity that is used as a medium for communication between the drone and the local software running on a laptop. This will be the most challenging feature to implement.

## 09/18/24: Completed Team Contract

Today, our group met at and completed the Team Contract. We had some discussion with regards to how we planned to handle conflict, make decisions, and keep ourselves accountable during the completion of this project, but other than that we completed the document with relative ease. I worked primarily on the group expectations, conflict resolution, and project planning sections.

## 09/24/24: Researched MPU6050 IMU Circuit Schematic

I spent some time today before our meeting with our TA to review the current circuit schematic we have designed. I reviewed the array of sensors we needed and found some online examples of schematics for the MPU6050, which is the IMU we have decided to go with since it is very popular in embedded applications, low cost, and widely availiable. Another added plus of the MPU6050 is that I have some experience interfacing with the software drivers for it through RSO experience.

![1457053860374](https://github.com/user-attachments/assets/5ab0187a-c3c9-471c-9dee-b950a7fed238)

I sent this schematic to Lohit, who latered added it into our design.

Our meeting with the TA was very productive and helpful. Since neither I nor my groupmates have much experience with PCB design, we are quite concerned with if we going about it the right way and if our schematic is any good. We plan to send our schematic to the TA later this week so that she can review it and give us feedback. We also will get confirmation on whether breakout boards (and ESCs) are allowed in our design, as the SIM7600 is an extremely complex module to design around.

## 09/29/24: Worked on Design Document

I spent much of my time today working on our project's Design Document. I began by reviewing the provided documentation and examples on the assignment from the course website, taking note of key elements we would need to include. Then, I created the document and made the basic outline. I ported over much of the information from the proposal that could be re-used, such as information for the Introduction and Ethics and Safety. However, I re-read the feedback Professor Fliflet provided us on our initial Project Proposal and realized we would need to discuss, as a team, to make some serious adjustments to our project. It seems that the professor is concerned about the scope of our project and implied that the building a drone AND creating the sophisticated software suite may be too much for this class. I am now exploring the option of adjusting our project to be focused on creating the software suite and the drone electronics, rather than a flying drone itself. I am not sure if this is enough to be a project for this class, though, so I have contacted our TA for feedback.

## 09/30/24: Worked on Design Document

We decided to set up some time to meet with our TA today in order to review some of the feedback we had gotten on the Project Proposal to make sure we were heading in the right direction. I was primarily concerned with the scope of our project and asked questions about how we could reduce it. We got good tips and decided that we would move some of the features we wanted to implement into a "Phase 2" of the drone, so that at least with Phase 1 we would have the core components ready to showcase. We then spent some time working as a group on the Design Document. I reviewed the examples of good Design Documents and took note of key features and well written sections. The document seems to be a lot more technical than I had initially expected. I then began to implement some of the feedback we had gotten on the Proposal into the Introduction portion of our paper, which is relatively the same across the Design Document and Proposal. One piece of feedback that we had gotten was that one of the high-level requirments we had written, which was related to system uptime, was not very good and could be too ambitious. After much discussion, we decided to rewrite this requirment and instead have it be related to a preemptive warning system on the drone to alert the operator to unsafe conditions, which additionally improves the safety of all nearby individuals. We then reviewed the structure of the Design Document as a group and made a plan going forward. Additionally, I was concerned with the safety risks posed by the drone, since it's reliability (with cellular connectivity) is quesitonable. We thought of an idea where we could implement a failsafe in which if a connection between the drone and the software running on a local computer is broken, then the drone could cut the motors and deploy a spring-loaded parachute to safely land.

<img width="675" alt="Screenshot 2024-10-02 at 12 43 19 AM" src="https://github.com/user-attachments/assets/2d58b98e-4dc1-4f46-9778-69e3b0b3958d">

<img width="425" alt="Screenshot 2024-10-02 at 12 44 48 AM" src="https://github.com/user-attachments/assets/1cfd05a5-c71c-4306-91bf-ebe24034d9ab">

I also began reviewing our first draft of the schematic and PCB mockup that Lohit completed.

## 10/01/24: Shifted Project Focus

Unexpectedly, we got more feedback from Profesor Fliflet on our Project Proposal. It seems clear that he wants us to give more details on the specifics of our drone itself, which is not something we focused on. During our weekly meeting with our TA later this day, we discussed this. We decided that, since the main selling point of our project is the core software and electronics (the "guts"), not the flying drone, we would instead shift the focus of the project to be centered around the software/electronics working inside of a drone instead of a drone that flys. This would help to reduce the scope of our project to make it more manageable. If we happen to have extra time, we could then experiment with trying to get the drone flying well enough for a demo.

## 10/02/24: Worked on Design Document

Our group had a lot of discussions today on whether or not we want to actually build a physical drone for the final demo of the project. Ultimately, we came to a consensus that, although we will not include any drone-specific requirments in the High-Level Requirments list, since it is very hard to estimate how well our drone's in-flight performance will be right now, we will still plan to test and demo our drone in the air. This once again puts a flying drone as the end goal of our project. After this, we spent many hours working on the Design Document. I worked primarily on the software analyses for the MPU-6050 IMU, BMP280 barometer, and OV7670 image sensor, which meant that I described how the embedded software would interact with these devices. I then wrote an R-V table for these sensing modules. By the end of the day, we had about 2/3 of the document completed.

## 10/03/24: Completed Design Document and Proposal Revisions

Today my group and I wrapped up the Design Document, which required several more hours of work. I first constructed a diagram for the embedded controls software state machine and wrote descriptions for each state. I then constructed our schedule for the remainder of the semester and assigned tasks to each member. I wrapped up by writing some ideas on how we plan to perform in-flight tests and demos, and also spent a lot of time formatting the document. All in all, the Design Document was 42 pages long. During Adi's development of the power subsystem hardware breakdown, we realized that the OV7670 image sensor required a 3V Vcc. Unfortunately, the rest of our schematic uses either 12V, 5V, or 3.3V, so we may need to find a different camera if this one proves unsuitable. After completing the Design Document, I spent a little time porting over the changes to the Project Proposal and submitted both.

## 10/08/24: 

TODO

## 10/11/24:

TODO
