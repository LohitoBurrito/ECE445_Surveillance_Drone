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

## 10/01/24: TA Meeting and Project focus

We had our TA meeting today, where we discussed a lot of the feedback we recieced via email from Prof. Fliflet. Expanding upon what we discussed earlier, we finally stepped on the pedal to focus on the software suite as our main project. We determined that, because the key selling point of our project is the core software and electronics, not the flying drone, we would move the project's focus to the software/electronics functioning within a drone rather than a drone that flies. This would help to narrow the scope of our project, making it more doable. If we have additional time, and everything else goes as planned, we will experiment with the flying capabilities of this drone near the end of the class.

## 10/02/24: Feedback + Design Document

We recieved a lot of feedback upon how we wrote our project proposal. The main issue was the fact that we did not include a lot of details regarding the drone itself. In other words, we only focused on writing about the softweare suite of the drone and the PCB with little to no information on what the drone will actually look like or how it fly. We took this advice and made sure to write down everything we discussed so far alongside some visuals to better show what the overall drone will look like, and how we are planning on actually flying it inclusing some of the aerodynamics. We also spent a couple of hours today going through what we had written so far in the design document, and wrote more regaridng the R/V tables and high level requirements. I was able to get through a lot of the description for the SIM7600 inclusing the specific requirements for the module to work, and some of the logistics regarding the power subsystem.

![image](https://github.com/user-attachments/assets/590777e8-254c-462e-855b-e25064d6f37c)

We made considerable progress today, but were unable to finish the whole report, so we plan on meeting up tomorrow to finalize the rest of it and give it one last overview before submission.

## 10/03/24: Finishing up Design Document

Although we had made a significant amount of progress on this report, we weren't able to fully finish it and refine it yesterday. We put in several more hours to finish the report up inclusing all the formatting issues and then content. I wrapped up all the information needed for the network stack inclusing R/V tables, conclusion and the ethics, and helped out with some of the sensor requirements. We were also able to point out some of the last minute issues with the overall power subsystem and swap some of the parts around to incorporate our design and PCB better. The report ended up being 42 pages long, which seemed like quite the feat because of how much effort we put into making it descriptive and accurate.

## 10/08/24: TA Meeting and Design Review feedback

We got a bit of feedback from the design review from the professor today, and it seems like the professor seems very concerned with the scope of our project. We also had a TA meeting today, where this was the main point of discussion. We doubled down on the fact that we would stick to our initial plan of having the electronics and software as a phase one and that would be what we demo at the end of it. We would still keep flying the drone as a phase 2 to ensure that we are within a realistic scope for completion at the end of the semester. We had another long conversation about the attainability of building our own SIM7600 and ESC. The SIM7600 schematic and power board itself are incredibly complex, and we are simply not skilled enough to be able to design much less sauder everything on. We also did a bit of resaearch on the pricing of the module itself on the approved vendors and the pricing of buying the individual components. I spent a lot of time today with Lohit going over a bunch of different drone designs and bought styrofoam. We referenced a specific image for the design of our drone and make our own modifications based off of our pcb design. 

![image](https://github.com/user-attachments/assets/f945cf3b-be19-45c5-90e6-a6258869324c)

## 10/09/24: Started Building the Drone

I started today off by reviewing the design and made some measurements to start on the drone. I first started off by going to the ECEB to work on it, but noticed the lack of tools and space to do a lot of the cutting since we decided on the wingspan of 100 inches, which excludes the fuselage. The fuselage dimentions were designed based off of the PCB dimenstions from KiCad, but we didnt have the physical PCB, so we made do with a cutout of styrofoam. Me and Lohit descided to go to Seibel Center of Design after discovering about the design lab that was open to all students. They had a wide array of equipment including power tools and 3D printers, which we were able to utilize. We watched a lot of tutorials on the specific criteria of the drone itsself, and successfully made the first wing after some small errors. We had the idea set for the fuselage and the back wings of the plane at this point, but due to a lot of time spent today in researching, we didn't have enough time to finish the whole thing due to the lab hours. After spending this time building the drone, I also realized the scope of this design and whether we would benifit from ordering an already made shell that we would put our hardware into. I discussed with the rest of the team members a bit and we all decided to reseach this on our own end and give it a couple of days to fully understand the pros and cons to this idea. It would make our project much simpler to attain if we were to do this, but it would fully remove the creative element of all the effort we already put into coming up with the design and building it partially. Overall, it was a very productive day and we made some amazing progress towards our end product, but it also gave us something to think about.

## 10/11/24: PCB Review + Wing Completion

Today was a very important day as we were finally able to get our PCB reviewed for the first time since building it. We decided to split the task of building the drone and reviewing the PCB i.e. Kevin and Lohit went to the PCB review while I stayed at SCD to start on the second wing of our drone. I made some solid progress on trying to replicate the wing that we had made a bit earlier, and the team got together after the review to finish it fully. We did end up getting a lot out of the PCB review as we figured out that the nature of DRC requirements was different for different softwares i.e. EasyEDA's DRCs were completely different than KiCad's. The discussion about buying a prebuilt frame for the drone was also put to an end today because of a bit of research on all of our ends and Kevin's final verdict of budget issues. This was a relief as we had a bit more budget to work with now for the more expensive components like the SIM7600 and future unpresedented costs.

// Include a pic of the wing ?

## 10/12/24: General Drone Body Completion

We spent a lot of time today figuring out how to hold the wings of our drone properly with the body, and were able to come up with a solid plan of execution. We spent 5 hours finishing up this design and being extremely carefuly so as not to make minor calculation errors as this could result in actual issues with the aerodynamics of the drone. At the end of today, we had most of it except the back flaps, and it came out exactly how we wnated it to without any issues at all. After this, I spent a lot of time looking over the various options of SIM7600 module we had to work with. There were way too many options regarding the functionalities and capabilities of the numerous chips I was researching. I was able to find a lot fo details regarding the naming convention of these chips and how certain ones only worked in certain regions. I used this [datasheet](https://download.mikroe.com/documents/datasheets/SIM7600_datasheet.pdf) for a lot of the distinctions and figuring out what we needed out of all of them. The final choice I got set on was the SIM7600A-H, which is the fastest module I could find for sale that had all the antennas we needed to be able to use my specific cellular provider. Next was the question of what housing we would go for i.e. since we were buying a prebuilt breakout board for it, it would make the most sense to have an antenna and a sim card holder attached rather thn having to manually solder that. Meanwhile, Kevin spent some time looking into how we could port over the EasyEDA design over to KiCad, and he was successful to great extent, which meant that we had a lot of the preliminary tasks handled.

![image](https://github.com/user-attachments/assets/366d4a0a-4d2e-4c3f-9f6d-93fa8f2e2209)

## 10/15/24: TA Meeting + PCB Order

The TA meeting today took a rather unexpected turn due to the nature of our PCB design. We initially started off by using 4 layers, which made tracing a lot easier and the overall complexity of the board more managable considering the size of our pcb was very small. We were unaware of the drastic change in price in corresponence to the number of layer i.e. our 4 layer board came out to be around 55 dollars for 10 board, which was well over the general assigned budget for ordering PCBs. We decided to split the work here, where Lohit would work on redeisgning the board and changing it to 2 layers while keeping the overall size of the board the same because we had already built the fuselage. 

Kevin was able to get a devkit for the ESP32s3, which wa amazing because it would help us do all the pre testing before we put everything on our actual PCB once that comes in. This was the first time I would be writing Arduino code, so I did a little bit of research on the general idea of the language and helped Kevin do the basic testing with the onboard LED on the module. After this, I decided to look more into the exact board to order for the SIM7600 to finalize the board. Meanwhile, Kevin got a lot of the Servo and multitasking code written and loaded onto the ESP, which worked great. This would prove helpful as we had 






