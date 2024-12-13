# ECE445 Notebook - Aditya Patel

Notebook for daily records, logs, design plans, decisions, and outcomes in ECE 445 - Senior Design Laboratory

## Table of Contents

* [08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook](#08/26/24---09/15/24:-logging-work-completed-before-starting-notebook)
* [09/16/24: Working on Project Proposal](#09/16/24:-Working-on-Project-Proposal)
* [09/17/24: Completed Project Proposal](#09/17/24:-Completed-Project-Proposal)
* [09/18/24: Completed Team Contract](#09/18/24:-Completed-Team-Contract)

## 08/26/24 - 09/15/24: Logging Work Completed Before Starting Notebook

We had already begun basic research and development at the start of the semester, and we had decided on the general project concept that we wanted to work on as a team. We were aware that we planned to build a drone with a camera and powerful software in some form. Our study helped us to establish the drone's basic hardware requirements, such as sensors, microprocessors, motor controllers, and internet connectivity. At first, we intended to utilize the drone to interact with the IllinoisNet WiFi network in order to enable our local UIUC police department to use it for surveillance purposes on campus. This was a crucial factor in our decision to choose an ESP32 microcontroller in our design because, despite STM32 chips' greater power, they do not support WiFi. But as the RFA process went on, it became clear that we needed to expand our scope since our initial use case was insufficient. We made the decision to somewhat change our original plan in order to continue helping first responders, but this time as an early response drone. Nevertheless, this meant that we could no longer rely on WiFi to communicate. Although long-range radio was discussed, the cost of strong receiver/transmitters made the concept unfeasible. Therefore, we decided to integrate cellular communication using a cellular module (SIM7600). Thus, in theory, our drone's range will only be constrained by the amount of battery life left in it. Furthermore, although there are still some networking challenges to be resolved, Lohit was able to develop the most of the basic code for both the frontend user interface and backend. We created a preliminary version of the circuit design throughout the first few weeks of the semester as we finished homework for ECE 445, including the CAD and soldering activities.

## 09/16/24: Working on Project Proposal

I spent a good chunk of the time today writing the Project Proposal. To be specific, I did all the tolerance analysis by looking up the specific specs and design choices of the sensors and the SIM7600 transmission details. I calculated the precise data rate (bandwidth) required to be able to transmit frames at a reasonable fps. I also worked on researching the ethics behind the drone and how we can take preventive measures necessary to avoid violations. I also read through a lot of the IEEE/ACM code of ethics. The last thing was to update our design and list all the different things we can do to get past these regulations, which turned out to be not too many things wrong. We added to the design rather than changing it in terms of sensor for proper tracking and collision detection methodologies. 

## 09/17/24: Completed Project Proposal

The meeting with the TA led us to make some discoveries with the tolerance analysis, so we went through it again and refined some details. Specifically the data transfer rate we could afford to send and receive was a bit off. I researched the different types of JPEG compression techniques, and got set on one that allowed us to retain most of the image quality while allowing for a little bit of headroom for anything we did not account for just yet. I finished up the ethics section, and we were good to submit. We gave it one last check by reading it over and submitting.

## 09/18/24: Completed Team Contract

Today, our group gathered and signed the Team Contract. We had some discussions about how we planned to handle disagreement, make choices, and hold ourselves responsible throughout the course of this project, but other than that, we produced our work very easily. I worked on the Project Description, Ground Rules, and End-of-term Agreement sections. 

## 09/24/24: Started Researching into the SIM7600 Module

We had a great meeting with the TA today, where we discussed the current scope of the project, and came up at a reasonable middle ground. We were also able to discuss the logistics of the PCB order and design since none of us are particularly proficient in that regard. We also had a discussion regarding the SIM7600 and the scope of actually soldering one ourself. Upon further investigation of the module, we concluded that with our current set of knowledge and expertise, it would be nearly impossible to be able to design one from the ground up. We requested to have that part ordered for us separately, so hopefully that is okay. After the meeting, I really started researching how to code the SIM7600 and how capable it will be in terms of realistically being able to send and receive most of the data we wished to gather. I had a really good intuition that we would be able to get HTML based connection working on the SIM7600 and go to a lower abstraction from there if truly needed.

## 09/29/24: Started writing the Design Document

Kevin started the document for us by copying over some of the things we already wrote for the project proposal. I spent a lot of my time today going over the stuff we already wrote and making sure to read all the feedback we got from Prof. Fliflet. He made a fair point of wanting a lot more details from us regarding what the final product will be. Now, it is clear that the drone will be a very hard project to achieve considering the fact that we need to have it flying and have the complex software suite working. Me and Kevin talked a bit regarding this and we are exploring the option to switch the focus of our project to only have the software suite as our main point of focus.

## 09/30/24: More work on the Design Document

We were having a lot of issues truly deducing the scope of our project, so we decided to have a meeting with our TA to discuss it thoroughly. She was able to give us some great feedback on how to narrow down our focus. We came up with the compromise that the drone needs to have two phases, where the first phase will be to finish the software suite fully, and the second focusing on actually getting the drone to fly. After the meeting we switched focus to the design document to incorporate this new advice and refactor some of the older advice we had gotten. We reviewed some of the older design documents to get a good sense of what was expected from us. We discussed one of the requirements we wrote for the drone which dealt with the drone uptime, and it seemed to be a bit unrealistic upon some back and forth with out TA and Prof. Fliflet's advice. The main concern for me was the revision of some of the solutions for solving ethical problems, and the main one here was the absence of an absolute fail safe system. This helped us formulate a new plan of action that signified changing the uptime requirement to something that is more trivial to the safety of our drone. We decided to incorporate an additional servo to our drone that would act as a holster for the parachute to deploy under certain circumstances like network loss, restricted properties, and collision avoidance. This would allow the drone to safely land both through user input in the case where that's feasible and autonomously when bad network connection is observed. 

<img width="674" alt="Screenshot 2024-12-08 at 2 57 48 PM" src="https://github.com/user-attachments/assets/39a3d405-6d33-4304-8a2a-baebcb3de087">

I hadn't worked with the schematic much at this point because my main focus had been to figure out the Arduino software and the SIM7600 interfacing. I reviewed our first draft to realize a wrong pin set high on the pressure sensor, which ended up getting fixed. 

## 10/01/24: TA Meeting and Project focus

We had our TA meeting today, where we discussed a lot of the feedback we received via email from Prof. Fliflet. Expanding upon what we discussed earlier, we finally stepped on the pedal to focus on the software suite as our main project. We determined that, because the key selling point of our project is the core software and electronics, not the flying drone, we would move the project's focus to the software/electronics functioning within a drone rather than a drone that flies. This would help to narrow the scope of our project, making it more doable. If we have additional time, and everything else goes as planned, we will experiment with the flying capabilities of this drone near the end of the class.

## 10/02/24: Feedback + Design Document

We received a lot of feedback upon how we wrote our project proposal. The main issue was the fact that we did not include a lot of details regarding the drone itself. In other words, we only focused on writing about the software suite of the drone and the PCB with little to no information on what the drone will actually look like or how it will fly. We took this advice and made sure to write down everything we discussed so far alongside some visuals to better show what the overall drone will look like, and how we are planning on actually flying it including some of the aerodynamics. We also spent a couple of hours today going through what we had written so far in the design document, and wrote more regarding the R/V tables and high level requirements. I was able to get through a lot of the description for the SIM7600 including the specific requirements for the module to work, and some of the logistics regarding the power subsystem.

![image](https://github.com/user-attachments/assets/590777e8-254c-462e-855b-e25064d6f37c)

We made considerable progress today, but were unable to finish the whole report, so we plan on meeting up tomorrow to finalize the rest of it and give it one last overview before submission.

## 10/03/24: Finishing up Design Document

Although we had made a significant amount of progress on this report, we weren't able to fully finish it and refine it yesterday. We put in several more hours to finish the report up including all the formatting issues and then content. I wrapped up all the information needed for the network stack including R/V tables, conclusion and the ethics, and helped out with some of the sensor requirements. We were also able to point out some of the last minute issues with the overall power subsystem and swap some of the parts around to incorporate our design and PCB better. The report ended up being 42 pages long, which seemed like quite the feat because of how much effort we put into making it descriptive and accurate.

## 10/08/24: TA Meeting and Design Review feedback

We got a bit of feedback from the design review from the professor today, and it seems like the professor seems very concerned with the scope of our project. We also had a TA meeting today, where this was the main point of discussion. We doubled down on the fact that we would stick to our initial plan of having the electronics and software as a phase one and that would be what we demo at the end of it. We would still keep flying the drone as a phase 2 to ensure that we are within a realistic scope for completion at the end of the semester. We had another long conversation about the attainability of building our own SIM7600 and ESC. The SIM7600 schematic and power board itself are incredibly complex, and we are simply not skilled enough to be able to design much less solder everything on. We also did a bit of research on the pricing of the module itself on the approved vendors and the pricing of buying the individual components. I spent a lot of time today with Lohit going over a bunch of different drone designs and bought styrofoam. We referenced a specific image for the design of our drone and make our own modifications based off of our pcb design. 

![image](https://github.com/user-attachments/assets/f945cf3b-be19-45c5-90e6-a6258869324c)

## 10/09/24: Started Building the Drone

I started today off by reviewing the design and made some measurements to start on the drone. I first started off by going to the ECEB to work on it, but noticed the lack of tools and space to do a lot of the cutting since we decided on the wingspan of 100 inches, which excludes the fuselage. The fuselage dimensions were designed based off of the PCB dimensions from KiCad, but we didn't have the physical PCB, so we made do with a cutout of styrofoam. Me and Lohit decided to go to Seibel Center of Design after discovering the design lab that was open to all students. They had a wide array of equipment including power tools and 3D printers, which we were able to utilize. We watched a lot of tutorials on the specific criteria of the drone itself, and successfully made the first wing after some small errors. We had the idea set for the fuselage and the back wings of the plane at this point, but due to a lot of time spent today in researching, we didn't have enough time to finish the whole thing due to the lab hours. After spending this time building the drone, I also realized the scope of this design and whether we would benefit from ordering an already made shell that we would put our hardware into. I discussed with the rest of the team members a bit and we all decided to research this on our own end and give it a couple of days to fully understand the pros and cons to this idea. It would make our project much simpler to attain if we were to do this, but it would fully remove the creative element of all the effort we already put into coming up with the design and building it partially. Overall, it was a very productive day and we made some amazing progress towards our end product, but it also gave us something to think about.

## 10/11/24: PCB Review + Wing Completion

Today was a very important day as we were finally able to get our PCB reviewed for the first time since building it. We decided to split the task of building the drone and reviewing the PCB i.e. Kevin and Lohit went to the PCB review while I stayed at SCD to start on the second wing of our drone. I made some solid progress on trying to replicate the wing that we had made a bit earlier, and the team got together after the review to finish it fully. We did end up getting a lot out of the PCB review as we figured out that the nature of DRC requirements was different for different softwares i.e. EasyEDA's DRCs were completely different from KiCad's. The discussion about buying a prebuilt frame for the drone was also put to an end today because of a bit of research on all of our ends and Kevin's final verdict of budget issues. This was a relief as we had a bit more budget to work with now for the more expensive components like the SIM7600 and future unprecedented costs. Additionally, I was also able to get done with the map element of our front end, which shows the current location of the plane, which I sent to Lohit for him to integrate it with the rest of the app. 

## 10/12/24: General Drone Body Completion

We spent a lot of time today figuring out how to hold the wings of our drone properly with the body, and were able to come up with a solid plan of execution. We spent 5 hours finishing up this design and being extremely careful so as not to make minor calculation errors as this could result in actual issues with the aerodynamics of the drone. At the end of today, we had most of it except the back flaps, and it came out exactly how we wanted it to without any issues at all. After this, I spent a lot of time looking over the various options of the SIM7600 module we had to work with. There were way too many options regarding the functionalities and capabilities of the numerous chips I was researching. I was able to find a lot of details regarding the naming convention of these chips and how certain ones only worked in certain regions. I used this [datasheet](https://download.mikroe.com/documents/datasheets/SIM7600_datasheet.pdf) for a lot of the distinctions and figuring out what we needed out of all of them. The final choice I got set on was the SIM7600A-H, which is the fastest module I could find for sale that had all the antennas we needed to be able to use my specific cellular provider. Next was the question of what housing we would go for i.e. since we were buying a prebuilt breakout board for it, it would make the most sense to have an antenna and a sim card holder attached rather than having to manually solder that. Meanwhile, Kevin spent some time looking into how we could port over the EasyEDA design over to KiCad, and he was successful to a great extent, which meant that we had a lot of the preliminary tasks handled.

![image](https://github.com/user-attachments/assets/366d4a0a-4d2e-4c3f-9f6d-93fa8f2e2209)

## 10/15/24: TA Meeting + PCB Order

The TA meeting today took a rather unexpected turn due to the nature of our PCB design. We initially started off by using 4 layers, which made tracing a lot easier and the overall complexity of the board more manageable considering the size of our pcb was very small. We were unaware of the drastic change in price in correspondence to the number of layers i.e. our 4 layer board came out to be around 55 dollars for 10 boards, which was well over the general assigned budget for ordering PCBs. We decided to split the work here, where Lohit would work on redesigning the board and changing it to 2 layers while keeping the overall size of the board the same because we had already built the fuselage. 

Kevin was able to get a devkit for the ESP32s3, which was amazing because it would help us do all the pre-testing before we put everything on our actual PCB once that comes in. This was the first time I would be writing Arduino code, so I did a little bit of research on the general idea of the language and helped Kevin do the basic testing with the onboard LED on the module. After this, I decided to look more into the exact board to order for the SIM7600 to finalize the board. Meanwhile, Kevin got a lot of the Servo and multitasking code written and loaded onto the ESP, which worked great. This would prove helpful as we had a couple of ideas in mind to have all our systems running concurrently to increase the speed of functions. 

## 10/16/24: Ordered SIM7600A-H and Servos

Today we wrapped up on all the research I had initially done with the SIM7600 module in order to finally put the order in. I did have some research done on exactly what to buy and where to but it from, but Kevin and Lohit helped look for cheaper options as the module I found would cost us half of our budget. We were unfortunately a bit unsuccessful because we couldnt find anything cheaper, and going with an inferior module would be way too slow in transferring data. We decided to buy it from [Amazon](https://www.amazon.com/waveshare-Raspberry-SIM7600A-H-Supports-Telephone/dp/B07Q48WNCF?crid=KHHXSOBI4PZI&dib=eyJ2IjoiMSJ9.fUs1eMGSX8x5TMUiK2GvwS4l_uzZ0KGObNtxo9jk360-T5rwyMDC8fdyi5CxiJUoyhRh_95h0Xb7WWohbHVpBbbF99vLJEqLzXEObQvhv2tno73wM5H_YA74Litgb-nlNF6tcJ3s4nM7zU_GVTHZllq0BPf-FsNyVqJCZCvU462Lwyh93Mn9uz5Tz7t9GHxDn8umfxF0rmk9rOGeABO1SKpd14yvPwXgjeMVYRhp2R4.JTjdTmrEGmhOkV94ypwdhxKr4qR-3agWQRJ7N3l1qMQ&dib_tag=se&keywords=SIM7600A-H&qid=1729121064&sprefix=sim7600a-h%2Caps%2C80&sr=8-4) as it was our only option that ticked all the checks for us, but it was quite expensive coming in at 72 dollars. This was a huge relief for me as I would now be able to start testing the module wih the devkit as soon as it arrives. As for the servos, Lohit had a specific brand in mind already, and he ended up finalizing that with me and Kevin, which concluded our order for this session. We were also able to put the finishing touches to the drone today alongside fixing some minor issues that went unnoticed last time, which finally finished that part of our project.

## 10/18/24: Basic SIM7600 Code + Carrier Verification

Today I spent a lot of time researching the base testing code for the SIM7600 module for initializing a connection and setting up the module to connect to the T-Mobile APN. This process initially started by digging deeper into how the module actually connects to the internet, where I discovered that anything that wants to connect to the internet would need an IMEI number, and there are only certain kind of devices my carrier could connect to. I was initially surprised to see that the SIM7600 module was not one of the listed devices, but upon calling the service a couple of times and spending hours trying to research how I could get this thing to work, I came upon the conclusion that the SIM7600 module was a partially connectable module i.e. all it meant is that I would not see data speeds over 150 MBps, which was totally fine in our case because the module only supported data rate upto 150 MBps. I was finally able to access the website, which would allow me to input the IMEI number for the SIM7600 and allow the module to connect to the internet through my service plan. The second thing I did today was to write a lot of the initial testing code, which included the exact GPIO pins I would connect it to, and 30 commands that I wanted to try out before I even deal with the cloud storage. I was also able to get this code verified using an LLM, so all this leaves me trying it out on the real thing, which is meant to come in 4-5 days. 

## 10/23/24: TA Meeting + SIM7600 Arrival

We had our TA meeting today, and we realized that the BMP280 sensor is not sold anymore, which resulted in us having to switch to a BME280 sensor, which had more capabilities. The SIM7600 module also came in today, which was great as I could start testing it and put on whatever code I had written for it already, but this did not end up being the case. I spent a little bit of time today trying to connect it to the ESP32, and try to flash some code on it, but this resulted in a lot of errors, which didn't make sense to me. I went through the [manual](https://www.waveshare.com/w/upload/a/af/SIM7500_SIM7600_Series_AT_Command_Manual_V3.00.pdf) that came with the module very thoroughly before resuming testing. What I did decide to use was another software that came with the module itself meant for testing, but upon trying it out on Lohit's laptop and my personal computer, we realized that the drivers that came with the module were only meant for Windows 10, and none of us were using this version of Windows, so I borrowed a friend's computer to be able to actually start debugging. The software itself was very complicated to interface with, and upon installing various UART and SIM7600 drivers onto the computer, we were able to establish a solid connection with the module. 

![image (1)](https://github.com/user-attachments/assets/ae5c7c8b-5673-4282-86a2-ef4a4ec608e0)

We started testing this in the senior design room on the second floor, where the internet connection was really bad and the SIM7600 wasn't able to make a connection with the internet, and the only way we were able to test that was not even with the software, but the on-board LED, which had certain indication modes. We moved to a Grainger Library, where we first saw the indication of the LED working i.e. internet was successfully connected. We then started sending commands to the SIM7600, which gave us valid responses, and this meant that we were ready to send HTTP commands to the database to retrieve and send data. That's because we tried pinging a bunch of websites and the database itself, where we received valid responses.

## 10/25/24: HTTP Send and Receive Testing

After a lot of issues with authentication and database querying, I was finally able to get to the firebase with an AT command and retrieve some data that was stored inside. This gave me a good idea of the order of commands to send to be able to retrieve data - We first need to set the SIM7600 to GET mode, followed by giving it the Firebase URL, and finally getting the data in a JSON format. I also did a lot of testing trying to send data, and I was successfully able to send data to a different database as well, which meant that we would be able to replicate these commands on the Arduino end and hopefully see the same behaviour.

## 10/28/24: Part List Tracking + SIM7600 Dev Board Attachment

I edited all the code from the past that didn't work with the devboard to a working version that would allow us to connect the module with the ESP32. We started off by using GPIOs 37 and 38 for TX and RX to the SIM7600, which was able to connect with the internet perfectly now. After I spent some time debugging the code and setting the UART connection correctly, I was able to run all of my code and read the output of the SIM7600 just fine, which was another milestone hit for the project. Now, Kevin and Lohit went through the part list to find replacements for all the parts that were not readily available to us, and they were able to come up with replacements for pretty much all of the parts. By the end of today, I was successfully able to reach the database and retrieve data as well as send some set data to another database after playing around a lot with the delays i.e. understand what command takes how long and putting custom delays after each command.

## 10/30/24: Servo Integration

I have spent a lot of time the past 2 days trying to integrate the servos with the rest of the code I wrote and the front end, which is in charge of sending commands. Me and Lohit worked a lot trying to figure out the best way to send commands and the frequency with which he should be sending it. I dished out a lot of delay issues, and integrated the threading and servo code that Kevin had written in the past, which turned out to be very simply as all I had to do was simply supply a command. At this point, we were able to command the servo based off of the front end with quite a lot of delay, which spiked up to 10-12s in bad network conditions. I tried a lot fo things to try fixing this, but it was not something I could physically fix as the module itself was not going past the limit it was set to, and we noticed a lot of packet loss even if the network was great sometimes. We decided to look at this issue later on as we had to integrate the sending code with this later on as well. 

## 11/02/24: Soldering + Camera Testing

We started soldering all the components we had already received today, and some of the resistors and capacitors turned out to be a real challenge because of how small they were. Me and Kevin spent 2 hours soldering just 7-8 components, but we were able to check these out under the microscope to validate contact as well. We also did a bit of research into the OV7670 camera module to capture a frame, but this turned out to be a lot more complicated than any of us expected, but we were able to find a Github repository with a bunch of drivers for our specific camera. The issue after that was the fact that none of those drivers worked with our board because they were written for a regular ESP32 not an ESP32 s3. We decided to take a look at this drivers tomorrow and see if there was anything that can be done. 

## 11/03/24: Camera

We spent a lot of time today trying to capture a frame with our new camera while Kevin wrote a bit of the surrounding code for encoding and decoding. Me and Lohit spent a couple of hours simply trying to find a good library to use for this, and we tried out a lot of random ones that people made themselves and one made by [expressif](https://github.com/espressif/esp32-camera/tree/master), but none of them seemed to work with our camera/board. We would either see errors or get a meaningless frame like shown in the image below. We then decided to see if we could manually change the expressif drivers to work with our module, which was a doubting task in itself because of how complicated the code was to begin with, and we were looking through some things we barely had a grasp of to begin with. This was quite the nightmarish task, but we made some changes there and decided that this was very futile, and maybe we should start looking into a different board to try/ different camera to buy. We felt a bit defeated at this point, but we decided to give this one last shot with a regular ESP32 board the following day to see how that would turn out.

![image](https://github.com/user-attachments/assets/d320d146-eeb1-4493-a6fe-9c0dc8aad2af)

## 11/04/24: Camera Again

We got to ECEB today to find that there was in fact an ESP32 left to borrow, which is exactly what we did to try the code out on that instead. The drivers stopped throwing errors once we correctly connected all the pins, but the image we captured was pretty similar in the regard that it didn't quite mean anything. 

![image](https://github.com/user-attachments/assets/cf77cf30-8b19-4eee-8f9d-9a0b922c5fd0)

We were now set on ordering the camera we knew would work the following day. In the meantime, I perfected my code to send over the frame we just received to Firebase, which worked great and we now had a way to send image frames (although not correct) to the database. 

## 11/05/24: Last Look at Camera  

We spent some today discussing everything that we noticed the past couple of days while debugging the camera. We decided to put our foot down and finally order the OV7670 with the FIFO chip because debugging this camera was very obsolete. I spent a lot of today working on the individual progress report, and made some really good progress on it, but I soon came to realize how long it will be for me as I had to explain the entirety of SIM7600 module. 

## 11/08/24: Design Document + Camera Updates

Me and Lohit spent some time yesterday trying to figure out the new camera, which initially seemed very easy ass we were able to capture a frame quite simply without needed any modifications to a [driver code](https://bitluni.net/ov7670-with-fifo) we found onlineThe issue, however seemed to be the fact that the image was very saturated and seemed to be wrong in a lot of aspects including the chopiness and blurriness. I helped Lohit a little bit trying to fix that, and we were finally able to figure out how to get a perfect frame today. We integrated the code Kevin wrote earlier, which seemed to work with the new images we were able to retrieve, but it seemed to mess up the format a little bit such that the firebase wasn't able to exactly see the image very well, so we will be working on that in a bit. I collaborated with Kevin to update our Design Document for the regrade. We had gotten input from our TA that we should revise our high-level requirements list to include more hardware requirements for our drone. Initially, we had three requirements, two of which were with the drone's software and one with the hardware. So we worked on adding a high-level need for the drone's power subsystem for the most part. In sum, we now have three hardware requirements and two software requirements.

## 11/11/24: ESP32 Code Update

Me and Lohit dished out a lot of the camera and SIM7600 at this point, and we are close to actually having the code robust because it still seems to bootloop once in a while after a couple of frame captures. Now, I am not sure why this is happening and we are still trying to debug it, but adding delays and making the code purposely run slower fixes a lot of our current problems. This, however, is not quite ideal as we would like for the code to run fast because of our application. I experimented with a lot of ways to go about this i.e. re ordering the code many times to figure out how I would best be able to meet all of the requirements we have with the code, and sending images separately from the sensor data introduces a lot of complexity and delay, which in turn causes for the system to boot loop sometimes. The best way I have it set up in my loop as retrieve commands, send sensor data then send image, but we will work more in the next couple of days to path this out because soldering is very important at this stage. 

## 11/12/24: Soldering

We spent a lot of time today trying to solder on all the components because we did have most of them at this point, and we had to test this PCB before tomorrow to get a feel of what needs ot changed in the design (tomorrow is the last day to order new PCB). I was able to help solder a lot of the components, after which I helped Lohit with the oven to put in the more complicated components. We did a but of research first on the acceptable temperatures for all the components, after which we were able to oven them and then we attached buttons. We were missing two components at this point, so we decided to put those in tomorrow to test out the PCB because we can only get them tomorrow. This was because we received the wrong capacitor compared to what we had ordered, and the LED was simply faulty.

## 11/13/24: Testing out The PCB


We spent a lot of time today trying to verify our board and resolder whatever it was that we were missing. We ended up taking some pins off of the PCB while trying to connect to it, but we luckily did not use any of the pins that came off. Kevin also found some spare parts in the lab of the part that we were missing and we ended up using that on our board as it fit perfectly. The PCB did not work the first try i.e. power was not supplied to the board, which got us a bit discouraged.

Lohit led the Soldering from this point on and inspired us to not lose hope in our PCB, and after spending all day debugging, we ended up seeing power that was originally blocked off due to a flipped LED. It was all uphill from there and we tried seeing all the components under the microscope to notice a lot of issues that we didn't initially notice. We got our hope back and pushed through it to be able to finally flash code on the board.

![9y2jcelj](https://github.com/user-attachments/assets/e3c282ce-32d7-4874-9c35-85b37dccc0c9)

## 11/14/24: Testing out The PCB 2.0

We stayed up very late last night to try to figure the PCB out such that we didn;t actually try out any of the sensors. Upon trying them this morning, we discovered that the BME280 had been destroyed either due to applying too much heat in the oven or a short in the board. This was one of the two things we noticed. The ESP32 chip we had on the board did not contain psram, which was an issue because we heavily relied on that to be able to capture frames and store them temporarily until they are either printed out or sent to the database. 

We decided to order the two components that we needed right away without wasting time in order ot begin final assembly of the drone.

## 11/19/24: Testing out The PCB 2.0

The ESP32 chip with psram and the BME280 sensor came in today, which we were able to solder successfully without any issues or harm to the other components using a heat gun. We also had out TA meeting today, and she was just as happy with the progress we were able to make with the PCB as we were. Going from it fully not working to fully functional was incredible because upon testing both of our sensors worked great.

## 11/21/24: Combining Code

While Kevin worked on the camera verification and Lohit worked on the 3D module he wanted to design for the drone, I went back to the code to figure out the issue with that's causing these boot loops. After a couple hours of debugging I came to the conclusion that although the SIM7600 advertised to have the upload and download speed of upto 150 MBps, it wasn't nearly as close to that as I would've hoped, which left me in a dilemma as we could have the code run fast, but it would cause a lot of boot loops and errors, or we run it slow where it will be very robust and slow, which violates a bit of the purpose we are designing this drone for. Now, upon finishing up testing, we started fully using the new board where I attached whatever I had attached to the devkit to the new PCB temporarily, and everything worked great, which further solidified that our PCB was perfect. 

## 11/22/24: Sensor Verification

Me and Kevin finished the entirety of sensor verification today according to our R-V table. The two sensors we tested were the MPU-6050 IMU and BME280 barometer. The BME280 took the longest to verify because of the various ways we decided to go about it. The first way was to test it it indoors and do a relative measurement i.e. have a starting point and raise the drone up in measured increments and see how much the sensor picked up to validate. We ended up seeing these results where the error was under the margin on 15 percent.

![image](https://github.com/user-attachments/assets/3baeb024-0021-492c-9388-f216b021717a)

The second test was going to an outdoor location and testing it that way. We first tested ground level near ECEB, and then went to the HERE terrace for the second extreme case. Upon testing both, we noticed around a 12 percent error which was amazing. 

The second sensor we tested was the IMU, which was tested under 3 conditions - room temp, fridge, and outside, which gave us results as shown in the image where the error was sub 15 percent.

![image](https://github.com/user-attachments/assets/ade267d2-6021-46e9-92ae-7f559f7a3034)

## 11/28/24: Ordering the Last Few Components

We finally finished up ordering some of the components from Amazon - ESC, motor, battery, and the battery charger. We did delay this a bit because our schedules were a bit different during break. Now, we had all the components we needed for the drone, so all that is left is to put it together.

## 12/01/24: Resoldering

While me and Lohit were testing the old PCB, the USB connector full came off, and we were not able to solder it back on, which is why we decided to fully resolder the board. This was a very last minute decision, but we didn't have any other choice if we wanted the PCB to work. We spent all night trying to remove components from the old board and putting them onto the new one, which after a couple of stressful hours, worked perfectly fine. This was a huge relief, and we are truly thankful to the team who donated the USB connector to us as we had run out of them.

## 12/02/24: Battery, ESC, Motor Testing

We were now able to test the components that we ordered earlier, but the ESC and Motor had a very weird protocol attached to them such that we had to follow some specific instructions for it to work, and after an hour or two, me and Kevin were able to crack it. We had to use the start function on Arduino to define the max and min rotary limits before we started running our control loop. Once I was able to get this done, I switched to assisting Lohit and Kevin with the drone itself and the servo attachment / making necessary cuts to the already existing wing and frame. We made really good progress with the frame itself but we were far from done because we hadn't fully tested the servos we installed.

## 12/03/24: Final Testing + Demo 

We tried our best to finish everything today, which included putting the final code in and making sure that everything works before the demo. We spent all day today finishing whatever was left, but we ran into some issues with the code such that the memory allocation seemed to be messing up a lot with the camera frames, and we weren't fully able to upload the image properly. This led us to make some reasonable cuts with the code, and focus on what was there already and perfect that instead. Lohit and Kevin ended up putting everything into the drone while I worked on the code to perfect it, and I got it working very well with everything but the camera, which was unfortunate given all the effort we had already put into this. 








