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
* [10/08/24: Design Review Feedback](#100824-design-review-feedback)
* [10/11/24: PCB Review and Drone Wing Construction](#101124-pcb-review-and-drone-wing-construction)
* [10/12/24: Imported PCB to KiCAD and Explored ESCs](#101224-imported-pcb-to-kicad-and-explored-escs)
* [10/14/24: DRC Warnings and Obtained ESP32 Devkit](#101424-drc-warnings-and-obtained-esp32-devkit)
* [10/15/24: Attempted PCB Order and Began Programming ESP32 Devkit](#101524-attempted-PCB-order-and-began-programming-esp32-devkit)
* [10/16/24: Ordered SIM7600 and Servos](#101624-ordered-sim7600-and-servos)
* [10/21/24: Revised PCB and Ordered Image Sensor](#102124-revised-pcb-and-ordered-image-sensor)
* [10/23/24: Tested Servos and Reviewed Parts List](#102324-tested-servos-and-reviewed-parts-list)
* [10/28/24: Updated PCB Parts List and Submitted Orders](#102824-updated-pcb-parts-list-and-submitted-orders)
* [10/31/24: Tested Servo Control Using Cellular Network](#103124-tested-servo-control-using-cellular-network)
* [11/02/24: Began Soldering PCB and Coded Camera](#110224-began-soldering-pcb-and-coded-camera)
* [11/03/24: Worked On Camera Software Integration](#110324-worked-on-camera-software-integration)
* [11/05/24: Continue Camera Software Development](#110524-continued-camera-software-development)
* [11/08/24: Revised Design Document and Retrieved Working Camera Frame](#110824-revised-design-document-and-retrieved-working-camera-frame)
* [11/12/24: Cleaned Up Software and Completed Most of Soldering](#111224-cleaned-up-software-and-completed-most-of-soldering)
* [11/13/24: Completed Soldering and Attempted to Flash Board](#111324-completed-soldering-and-attempted-to-flash-board)

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

Today my group and I wrapped up the Design Document, which required several more hours of work. I first constructed a diagram for the embedded controls software state machine and wrote descriptions for each state. I then wrote our schedule for the remainder of the semester and assigned tasks to each member. I wrapped up by writing some ideas on how we plan to perform in-flight tests and demos, and also spent a lot of time formatting the document. All in all, the Design Document was 42 pages long. During Adi's development of the power subsystem hardware breakdown, we realized that the OV7670 image sensor required a 3V Vcc. Unfortunately, the rest of our schematic uses either 12V, 5V, or 3.3V, so we may need to find a different camera if this one proves unsuitable. After completing the Design Document, I spent a little time porting over the changes to the Project Proposal and submitted both.

## 10/08/24: Design Review Feedback

During our TA meeting this week, we spent the majority of the time disucssing the feedback we received during our group's Design Review yesterday. It is still very clear the Professor Fliflet is concerned with what problem we are actually trying to solve, the scope of our project, and our high-level requirments list. Our TA, Manvi, suggested we stick with the original plan to have the software suite integrated with the electronics as a demoable Phase 1 of the project, then have the flying drone as a Phase 2. This way, we limit the scope of our project while also giving us an opportunity to get some potential bonus points. Additionally, we reviewed some concerns I had with regards to the SIM7600 and ESCs. Since these are both quite complex modules and their reliable operation is crucial to the safe operation of the drone, I really think we should buy off-the-shelf versions of these components instead of trying to integrate them into our PCB. For now, we will plan to add them to our PCB, but will buy them if it doesn't work out. Pictured below is the pinout for the SIM7600, for example.

![pinout](https://github.com/user-attachments/assets/ea4415ec-5362-4be4-8fad-ee926dee6889)

## 10/11/24: PCB Review and Drone Wing Construction

Today Lohit and I attended the PCB Review session to receive feedback on our current design. After sitting down with a TA, he informed us that there were a set of specific DRC criteria we would need to meet before being able to submit a PCB order. While we had previously been verifying our PCB with EasyEDA's DRC, it's parameters were not the same as the KiCAD parameters the TA provided us. So, we realized we would need to spend time porting our design over into KiCAD so that we could ensure it passes the specific DRC requirments. Additionally, the TA mentioned that, due to the scope of our project, it might be a good idea to look into pre-made drone shells that we could then install our electronics into. I spent some time looking into this, but found that most off-the-shelf options were for quadcopter drones. This would turn out to be too expensive, as even though the drone frame would only be about $20-30 to purchase, it would then require four motors and four ESCs, which are expensive. I did, however, see that we could laser cut a drone frame from an online design if our own design fails to be operational. Since our board is quite complex, we were also suggested to add a crystal oscillator to ensure a smooth and reliable clock signal. However, it seems that this is moreso necessary for designs using an STM32 microcontroller, since the ESP32 S3 WROOM already has a built-in 40MHz crystal oscillator.

Our group then spent a couple of hours at the Siebel Center for Design constructing the second drone wing. The first had already been made the day before out of foam board purchased at Dollar General, so creating the second was simply a matter of replicating the dimensions of the first. The wing is roughly 7 inches in width towards the center, and tapers off to about 6 inches at the end. We also cut slits in the wings for the ailerons, and taped over the edges for improved aerodynamics.

## 10/12/24: Imported PCB to KiCAD and Explored ESCs

After researching online about what the easiest way to move an EasyEDA project into KiCAD would be, [this Reddit post](https://www.reddit.com/r/KiCad/comments/1bxg5ph/importing_easyeda_projects/#) provided information on KiCAD 8.0's built-in feature to import an EasyEDA project backup as a KiCAD project. This meant that we would not need to spend hours recreating our design. After following the instructions and runnings the DRC, there were a few errors related to the board's dimensions that were easily resolvable. However, we had about 350 warnings that showed up. About 250 of them were related to KiCAD not finding the proper footprints for parts we used, which we expected since that was the main reason why we originally used EasyEDA over KiCAD. There were a significant amount of warnings about "negative solder paste margin is larger than pad; no solder paste mask will be generated" that we could not find much information online about. For now, I think we will be able to ignore these warnings and see if they cause an issue while ordering the PCB.

I spent some time researching a possible ESC we would like to buy for our brushless motor. The main requirments is that it should be compatible with up to a 6S battery, output a 5V supply, and be relatively inexpensive. The 5V supply is crucial, as it allows us to not need a second voltage regulator (we already have one for converting 5V to 3.3V). [This ESC](https://shop.tmotor.com/products/fixed-wing-esc-at55a-2-6s), by Tmotor, should be a good choice.

I also explored the idea of adding the SIM7600 to our PCB, however it does not seem like this will be possible. Due to the sheer complexity of the module, there are not many online schematics for breakout boards for it. I did manage to find one example for a schematic, as seen below:

<img width="1150" alt="Screenshot 2024-10-16 at 7 57 00 PM" src="https://github.com/user-attachments/assets/026b96aa-701c-4c6c-a7b7-37424838db89">

While not all of the submodules in this schematic are necessary for our purposes, implementing the ones we need would still prove to be too complex and exceed the size limitations of our PCB. We are limited to a 10cm by 10cm board, so adding the SIM7600 would not fit.

Additionally, Adi and Lohit completed the contruction of the drone's fuselage and attached the wings we had made earlier.

<img width="830" alt="Screenshot 2024-10-16 at 12 00 39 PM" src="https://github.com/user-attachments/assets/f9477451-1033-4991-a60c-f26b1cdf703e">

## 10/14/24: DRC Warnings and Obtained ESP32 S3 Devkit

I met with our TA during her scheduled office hours to discuss my concerns with the DRC warnings. She was also not sure about how to resolve them, so we decided to go ahead and try to order the PCB tomorrow. If it causes and issue, we will resolve them and re-order the PCB during the following week's PCB order. During the PCB Review last Friday, I also learned that the class offers ESP32 S3 Devkits for us to checkout, so I reqested one from our TA. Since the PCB may not come in for another 1-2 weeks, I can at least begin coding the initial control loop and basic interfaces with sensors and servos with this Devkit.

## 10/15/24: Attempted PCB Order and Began Programming ESP32 Devkit

Today we had another meeting with our TA to review our PCB and order it. Our current PCB design uses four layers: a TopLayer, Inner1 (3.3V layer), Inner2 (GND layer), and BottomLayer. This made tracing our board much easier and allowed us to use a much more compact design. While we had previously heard that designs with greater than two layers were generally not recommended, we figured the complexity of our design justified it, and by our cost estimates with JLCPCB, the price increase would not be too significant. However, after we sent our PCB files to our TA, it turns out that making a four layer board with PCBWAY dramatically increases the price (over $50 for 10 boards) and would thus not be possible. We concluded that we would need to spend time simplifying our design down to two layers and order the PCB the following week. 

After our meeting, I spent some time running basic sketches on the ESP32 Devkit to ensure its operation. I first began by simply blinking its onboard RGB LED, which is accessed through IO48. Then, I went to the 445 lab room and obtained a servo and some LEDs. Using code I referenced online from [this website](https://dronebotworkshop.com/esp32-servo/), I wrote code to sweep a servo from 0 to 180 degrees, then 180 back to 0 degrees. I verfied the code by connected the servo to a 5V supply pin, GND pin, and GPIO pin on the Devkit and successfully ran the code. Then, I wanted to explore the idea of multithreading with RTOS. Since our drone will need to be sending and receiving data from the Firebase cloud storage with minimal latency, I decided that running these two tasks on two threads would be optimal. The Arduino IDE provides an example sketch for accomplishing this with FreeRTOS, and using code from [this website](https://randomnerdtutorials.com/esp32-dual-core-arduino-ide/) as a reference, I wrote code to run two tasks on two seperate cores on the microcontroller. The first blinked an LED  every 500ms, and the second blinked an LED every 100ms. After connecting two LEDs to GPIO pins on the Devkit, I verified this worked.

## 10/16/24: Ordered SIM7600 and Servos

I spent time working with my group today to order some of the basic parts necessary for our drone that I can begin testing on the Devkit. First, we looked at the SIM7600, which proved to have some challenges. The module is sold in different variants, with the one we need being the SIM7600A-H since we are in North America. Unfortunately, there are a limited amount of widely sold breakout boards for this variant, and even fewer sold on websites that the ECE department can purchase from. Only Amazon sold a [viable option](https://www.amazon.com/waveshare-Raspberry-SIM7600A-H-Supports-Telephone/dp/B07Q48WNCF/ref=sr_1_4?crid=KHHXSOBI4PZI&dib=eyJ2IjoiMSJ9.fUs1eMGSX8x5TMUiK2GvwS4l_uzZ0KGObNtxo9jk360-T5rwyMDC8fdyi5CxiJUoyhRh_95h0Xb7WWohbHVpBbbF99vLJEqLzXEObQvhv2tno73wM5H_YA74Litgb-nlNF6tcJ3s4nM7zU_GVTHZllq0BPf-FsNyVqJCZCvU462Lwyh93Mn9uz5Tz7t9GHxDn8umfxF0rmk9rOGeABO1SKpd14yvPwXgjeMVYRhp2R4.JTjdTmrEGmhOkV94ypwdhxKr4qR-3agWQRJ7N3l1qMQ&dib_tag=se&keywords=SIM7600A-H&qid=1729121064&sprefix=sim7600a-h%2Caps%2C80&sr=8-4), but it was extremely expensive and nearly half of our entire budget. For a cheaper alternative, we looked at the SIM7000A, however this module only supported up to 2G and could only transfer data at a rate of 375kbps (whereas the SIM7600 can transfer at around 10Mbps). Unfortunately, our only option was to go with the Amazon offering. Lohit had also previously found some good, small servos off Amazon as well that we decided to purchase, linked [here](https://www.amazon.com/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=mp_s_a_1_3?crid=BS5S38CTNWFJ&dib=eyJ2IjoiMSJ9.lRrzFkSvx8GhZXXbAhDTVjP2EBkmoPc78-c-JdjWfKTZ6G91lio_kdzjsWDqFwzZbVMuHW53QXTXvd5kfqbGZxT01VcxdXrQXmVcz2irdLU8r-hZiCjRjDyBukToNBy4xd74BJK_PQM3IyMXwPWK8UFQcaVyQ6iBeXTjT_QOXfQ8Dsqh7YOIkUniuTDJHiwcsXS4pFbd0KSDWaLCZ7v8UQ.yJ2ZDPWrq5zxWtyR6YiXr8_OJHXUBhh5KqmaoInMx0o&dib_tag=se&keywords=servos&qid=1729118694&sprefix=servos%2Caps%2C117&sr=8-3). With about $60 left in our budget, most of this will have to go towards our motor, batteries, and ESC. To stay within budget, we will likely need to purchase cheaper parts that work, but are not powerful enough to actually get the drone to fly.

## 10/21/24: Revised PCB and Ordered Image Sensor

Today I worked with Lohit to convert our existing four layer PCB design to a two layer PCB so that we could order it tomorrow. We decided to once again make the changes on EasyEDA, then port the design over to KiCAD and resolve any DRC errors. Previously, we had a TopLayer, BottomLayer, 3.3V layer, and GND layer, so we needed to eliminate the 3.3V and GND layers. To do so, we decided to make the BottomLayer and GND layer, and the TopLayer a 3.3V layer. After doing so, making the DRC pass was simply a matter of connected filled 3.3V zones and removing some preexisting vias. We are now ready to order the board tomorrow.

<img width="420" alt="Screenshot 2024-10-22 at 10 57 54 AM" src="https://github.com/user-attachments/assets/79faacf9-fb06-4798-a1cd-5cd26a78d9ee">

I also submitted the order for the OV7670 image sensors we will be using as cameras on our drone. We had selected a 2 pack of these sensors off Amazon while writing our Design Document, and this seemed to be a suitable option. We will need to spend more time this week ordering the batteries, ESC, motor, and all of the PCB components that are not availiable through the ECE department.


## 10/23/24: Tested Servos and Reviewed Parts List

Since we recently received the servos and SIM7600 that we ordered, I quickly validated the operation of the servos we got using with the ESP32 Devkit and the code I had written to test a servo earlier. As I expected, the code worked and the servos responded as properly. Below is quick image of the setup I created for the test:

![img2](https://github.com/user-attachments/assets/966920d6-e94d-4023-b064-32b06fd7d764)

During Tuesday's meeting with our TA, I discovered that the BMP280, the barometetric sensor we planed to use, was obsolete and no longer sold. As a last minute change before the PCB order, we swapped our design to use the BME280, which is very similar to the BMP280 except for the fact that it has the ability to also measure humidity. Incorporating the chip into our schematic and PCB was fairly plug and play, as it was also an I2C device and used the same connections. I also found that many of the parts that we planned to use on our PCB were not availiable through the ECE department, whether that be through the Electronics Shop or ECE Supply Center. As a result, I spent time today making a Google sheet that lists all of the parts and whether we will need to make an online order to get them. I believe most of the resistors and capacitors can be gotten through the Electronics Shop, but I will need to check their size/package to ensure this.

## 10/28/24: Updated PCB Parts List and Submitted Orders

I spent most of my time today going through the Google sheet I had made last week for our parts list and confirming where each part would need to be ordered from. Most of the capacitors, some of the resistors, and most of the ICs we would need to use for our PCB would not be directly obtainable from the ECE department, and originally I had thought that we would need to buy them on our own. However, I worked with Lohit and together we were able to find suitable replacements for the aforementioned parts. This process was quite time consuming, as it involved checking various datasheets and confirming that size/dimensions would not be an issue. After much effort, we had compiled a list of parts that could entirely be obtained either from the Electronics Shop, or ordering through the ECE department from an accepted vendor.

I also briefly helped Adi with the initial programming of the SIM7600 with our ESP32 DevKit. We are able to directly connect the breakout board for the SIM7600 with TX/RX, power, and GND pins on the Devkit. Using the sim card from Adi's phone and use starter code from an online website as a reference, we also began to attempt writing code that would simply ping a website. It is a work in progress.

## 10/31/24: Tested Servo Control Using Cellular Network

Over the past few days Lohit was able to expand on the SIM7600 code and connect it to the Firebase cloud storage we are using as an intermediary between the drone and the backend software. Using various networking protocols, the embedded code running on the ESP32 can now talk to and receive commands from the user via the frontend UI. We wanted to test whether we could get some basic drone commands to be received and processed.

![3E2DEC0A-7B20-4023-91B1-904AE681A93F](https://github.com/user-attachments/assets/1839896c-988a-4087-a76b-187fcafb5a9d)

We integrated the cellular code Lohit and Adi had written with the servo and multithreading code I had written. Furthermore, I wrote basic code that writes to specific servos (we had six connected to the ESP32) depending on which input command from the user had been received (roll, pitch, yaw). After troubleshooting some network/communication issues, we were able to successfully have an input command be received by the drone, and have the drone accordingly write to certain servos.

One thing that we noticed during our testing was that the latency between the command being inputted and the drone writting to the servos varied quite drastically depending on how strong the cellular connection was. At its best, the latency was about 2 seconds, but it was as bad as 12 seconds at its worst. This might pose a challenge when we attempt to transmit video frames, since they will be much greater data packets.

## 11/02/24: Began Soldering PCB and Coded Camera

Today we received the parts we had ordered from DigiKey and SparkFun and began soldering some of the components onto our board. Since we are still awaiting some parts from the Electronics Shop (namely the ESP32 itself), we would be unable to test the board today. I spent most of my time working with Adi to solder on all of the capacitors. One thing we will want to change for a future PCB order is increasing the size of certain SMD components, as some as so small they become very tedious to solder on.

I also briefly helped Lohit with the initial code for the OV7670 image sensor. This module is very complex and requires a lot more effort to interface with than we had originally thought. We are in the process of using online references, such as [this](https://github.com/espressif/esp32-camera/tree/master) from Espressif, to get the camera working.

## 11/03/24: Worked on Camera Software Integration

I spent many hours today working on the software integration of the OV7670 image sensor into our embedded code. Most of the code followed a similar structure to the examples we found from the Espressif library above, which proved very useful as much of the hardware interaction is luckily abstracted away in provided functions. From a high level, the overall software needed for the camera is as follows: initialize camera configuration -> declare image buffer -> read data from image -> convert buffer to JPEG -> transmit JPEG buffer to Firebase.

The first three steps in the process were fairly straightforward, except for some configuration parameters we needed to play around with (image resolution, data encoding). The challenge we are facing now is with transmitting the data to Firebase. We are currently trying to capture a 160x120 image in an RGB565 format. With these settings, we would require (19200 pixels)(2 bytes per pixel) = 38400 bytes of data per frame. Unfortunately, the ESP32 does not have enough onboard memory to support this large of a data structure, and moreover Firebase is not able to make much sense out of a frame buffer. Instead, we want to convert the image to a JPEG for data compression and Firebase compatibility. While there were a couple of availiable JPEG encoders online, they are all quite difficult to use. However, I currently think we have the encoder working and need to focus on getting this JPEG buffer transmitted.

## 11/05/24: Continued Camera Software Development

Today I spent more time working on the code required to interface with and obtain image frames from the OV7670 image sensor. From when I last worked on the code, Adi was able to transmit the JPEG buffer output from the JPEG encoder to Firebase and view the image. Unfortunately, the image we are receiving is very noisy and garbage. After spending numerous hours trying different variations of code and configuration settings, we noticed that the Espressif library we were using for configuring and encoding the camera data mention that they only work FIFO-capable variants of cameras. Unfortunately, the OV7670 we had purchased did not have the necessary FIFO chip to enable this. We determined that this was likely the cause of our issues, since the code should be right given that we are using functions provided by Espressif themselves. So, we decided to order another OV7670 off of Amazon, but this one having the FIFO chip, and put our camera debugging on hold for now. 

I then spent the rest of my time completing the Individual Progress Report. 

## 11/08/24: Revised Design Document and Retrieved Working Camera Frame

Today I worked with Adi to revise our Design Document for the regrade. We had received feedback from our TA that we should update our high-level requirments list to have more requirments for the hardware of our drone. Initially, we had three requirments, where two of them had to do with the software subsystems of the drone and only one was related to the hardware. So, I worked to add a high level requirment for the drone's power subsystem, and another related to the drone's ability to quickly repond to user inputted commands. In total, we now have three hardware-related requirments, and two software-related requirments. Another piece of feedback we received was to add more figures to the subsystem breakdown sections of the report, so we did so.

Following the arrival of the new OV7670 with the FIFO chip, Adi and Lohit were able to successfully run the drivers for a FIFO OV7670 and retrieve a correct image. While there is some discoloration that needs some more fine-tuning, this is certainly a step in the right direction. We are now working to re-implement the JPEG encoder so that we can send a much higher quality image to Firebase.

## 11/12/24: Cleaned Up Software and Completed Most of Soldering

Over the past couple of days, Adi and Lohit have worked to iron out most of the issues with the OV7670. We are now able to quite reliably capture and upload images to Firebase. While the quality is a bit lower than we would like, we can look into improving it later on after we have most of the other software components completed. We have found that, occasionally, the system bugs out and stops transmitting frames after 8-10 image uploads. We are not sure if this is an issue with the OV7670, the SIM7600, or the ESP32 itself, but we have found that a temporary fix it just re-initializing the camera whenever this error is encountered.

I spent a significant amount of time working on completing the soldering of other components with Adi. We have decided to use the oven to perform most of the tedious soldering tasks, so we mostly just needed to apply solder to the solder pads, then solder down one pin of each component onto the pad. This would keep it in place and allow the other pins to solder onto their respective pads in the oven.

![IMG_1563](https://github.com/user-attachments/assets/9b623518-7526-4311-a7f6-c73f33e1b7b9)

After all of our hand soldering was completed, Lohit completed the remaining soldering by putting it in the oven at 220 degrees celsius for about 20 minutes.

![75311329759__EF377142-1707-40EF-AA3C-D20F680E3B47](https://github.com/user-attachments/assets/4b5088be-a1fc-4254-a9b2-e31b4fbe103f)

As you can see above, the pins on components such as U4 are so small that we would not have been able to get them soldered down without the use of the oven. Additionally, we have not yet placed the C15 and U1 components onto the board. This is because, for the C15 capacitor, we had requested a .01uF capacitor fromt the E-shop but received a .1uF instead, so we are waiting to get our corrected replacement. For the U1, which is an addressable RGB LED, it appears the sizing of the chip we got is incorrect and may need modifications.

## 11/13/24: Completed Soldering and Attempted to Flash Board

Although we were missing two components to go on our board, the .01uF capacitor and addressable RGB LED, I decided to see if this could be worked around. After looking through the bins of availiable spare parts in the 445 room, I found a few .01uF capacitors, however they were either 402 or 805 packages and we needed 601. Nevertheless, we found that the 805 package capacitor would still be able to fit on the PCB's designated solder pads, so we went ahead and soldered it onto our board. Futhermore, since the RGB LED's circuit only connected to the ESP32 via an IO port (that we could disable), we decided to forego the LED for now.

We encountered several issues upon trying to connect and flash to the board, however. For one, the USB connector had not soldered on properly in the oven, so it fell off when we connected a cable to it. Unfortunately, it also pulled off a solder pad for one of the pins, however this pin was unused and should not pose an issue. We had to re-solder the connecter using a heat gun, since the pads and pins were too small for a regular solder iron to melt solder onto. After we fixed this issue, we tried to connect to the board once again. However, we are unable to detect the board through the Arduino IDE, and some basic probing with a multimeter shows that we are not getting the right voltages where they need to be. We will need to spend significant time debugging the board.
