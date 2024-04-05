# Robo_Soccer

Robo Soccer bot created by students of RoboTech Club at National Institute of Science Education and Research in an attempt for participating in competitions. The purpose of the project is to learn the use of transmitter and receiver and for wireless interactions. And the bot was made for participating the competitions organized in techfests.

# Time Line

- Start of Project - 4 March 2024
- Participation in NIRMAN 3rd Edition in Silicon Institute of Technology, Bhubaneswar - 14 March 2024

# Problem Statment

- Round 1 - There will be balls placed in the arena and the bot has to shoot the balls inside the Goal
- Round 2 - There will be elimination round between bots where bot fight amoung each other and have to score goal by putting the ball inside the opponent's goal.

# Concept/Theory

The concept used for building the bot is that the receiver receives some values from the transmitter given by the user and the user has the control of the transmitter by using the joysticks and the buttons in the transmitter. The user gives input according to the action he wants the bot to perform. The receiver gives the input given by user to microprocessor and then the bot performs the task accordingly.

# Equipments Used

- Arduino UNO
- Breadboard, Jumper Wires, Switch(SPST)
- Li-ion battery 3S: ~12V
- LN 298N Motor Driver
- Acylic Used to make Chassis
- Johnson Motors ×4
- Motor Wheels ×4
- Zipties
- Nut and Blots for attaching Wheels
- Flysky FS-CT6B Transmitter
- Receiver
- Nuts & Blots, Glue gun, Soldering iron, Double Tapes and Tapes
- Heat gun

# System Architecture

At the very starting we have put the 2 front motors bottom of the bot. Arduino is setup in the front for ease in uploading of code. Nearly at the centre the battery is placed. After battery the breadboard is placed and it interacts with every component of the system for ground and for 5 V power supply. After breadboard the receiver and the Motor Driver are placed sideways. At the end we put 2 back motors at the bottom of the bot.

# Mechanical Design

The 2D design is created in Onshape and then we used Laser cutter to get precise design in the Acrylic. We made the bot in shape of cuboid. The dimension of the cuboid was 170mm × 150mm × 80mm. We used heat gun to bend a straight acrylic which will form the front part of the bot which is U shaped and that will hold the ball and for better controlling. Use zipties to tie the motors and apply glue gun to make it stable. And all the electrical compononets must be stick to the base of the Acrylic steadily by double side tape. 

# Electrical Connections

| Battery and Motor Driver               | Motor Driver and Arduino      | Receiver and Arduino | Motor Driver and Motors     | Breadboard to rest of circuit                 |
| -------------------------------------- | ----------------------------- | -------------------- | --------------------------- | --------------------------------------------- |
|12V Positive of battery connected to 12V|5V common connected to Arduino | Channel 2 in Pin 3   | Left Motor Positive in OUT1 | 5V Positive of Motor Driver to Common Positive|
|                                        | ENA to Pin 5                  | Channel 3 in Pin 2   | Left Motor Negative in OUT2 | Ground of Battery to Common Ground            |
|                                        | IN1 to Pin 4                  |                      | Right Motor Negative in OUT3| Positive of Arduino to Common Positive        |
|                                        | IN2 to Pin 6                  |                      | Right Motor Positive in OUT4| Positive of Receiver to Common Positive       |
|                                        | ENB to Pin 9                  |                      |                             | Negative of Arduino to Common Negative        |
|                                        | IN3 to Pin 8                  |                      |                             | Negative of Receiver to Common Negative       |
|                                        | IN4 to Pin 10                 |                      |                             | Negative of Motor Driver to Common Negative   |

# Transmitter and Receiver Setup

In this project we are using Flysky FS-CT6B Transmitter. It is device used by Driver to control the Bot wirelessly. Transmitter takes input from user about what task to perform accordin to what the user has set up and the receiver recives the input given by user by Radiowaves sent by the transmitter. Then receiver decodes the waves and send the input values to the microprocessor then it takes decision of what output must be given according to te way it has been programmed. Every channels of receiver has a specific botton or joystick which it is connected to and every bottons and joystic independently send their signals. So  every channel receives different input. And with different inputs we can do multitasking and make the bot work.

In our case we will use only 2 channels. One channels will help in controling the forward left and forward right wheel and other channel will help in controlling the forward right and backward wheel.

By experimentation we received the data that the input values of the transmitter varies between 1800 at maximum and 1200 at minimum.

- Left wheels (both backward and forward) control ---> channel 2
- Right wheels (both backward and forward) control ---> channel 3

![image](https://github.com/DibboBhai/Robo_Racer_Robot/assets/148962484/7474b158-252c-4d5a-ac55-f2d05743f883) <img src="https://github.com/DibboBhai/Robo_Racer_Robot/assets/148962484/799f5dda-c8e9-4137-bd46-c04fa60250c4" height = 300 width = 300>  <img src ="https://github.com/DibboBhai/Robo_Racer_Robot/assets/148962484/75919350-2e63-4e4d-bec7-76d75963875f" height=300 width=300> 


# Motor Driver Controlling

Whenever the driver wants to make a motion he can change the direction of wheels by changing the voltage supply of IN pins and can change the speed by varying the voltage supply to EN pins.

| FORWARD DIRECTION | BACKWARD DIRECTION | LEFT DIRECTION                            | RIGHT DIRECTION    |
| ----------------- | ------------------ | ---------------------------------------   | ------------------ |
| IN1 voltage HIGH  | IN1 voltage LOW    | IN1 voltage HIGH OR LOW (SAME AS IN2)     | IN1 voltage HIGH  |
| IN2 voltage LOW   | IN2 voltage HIGH   | IN2 voltage HIGH OR LOW (SAME AS IN1)     | IN2 voltage LOW   |
| IN3 voltage LOW   | IN3 voltage HIGH   | IN3 voltage LOW                           | IN3 voltage HIGH OR LOW (SAME AS IN4) |
| IN4 voltage HIGH  | IN4 voltage LOW    | IN4 voltage HIGH                          | IN4 voltage HIGH OR LOW (SAME AS IN3) |

Apart for controling we observe the magnitude of how much the joystick by mapping is given the arduino instruct the motor driver to how much power is to be give. Or in simple terms it controls the speed of the bot.

# Programming

**<ins>Initializing of Variables and Naming Pins</ins>**

- At the starting we define different variables for pins and for dyanamic input values.
- ch2 and ch3 are for channel 2 and channel 3 repsectively.
- enA (5 pin) and enB(9 pin) are connected to ENA and ENB pins of motor driver repectively.
- a,b,c, and d are for IN1, IN2, IN3 and IN4 pins respectively.
- But while initilizing we do it separate for the left motor and separate for the right motor.
- The we set variable for the maximum and the minimum value of the input given by the transmitter by ch2_high and ch3_high and ch2_low and ch3_low respectively.
- After that we assign polynomail value of output variable by ch2_poly and ch3_poly.
- At the end we assign values for the original value of input given by trasmitter by original_ch2 and original_ch3

**<ins>Setup</ins>**
 - In the setup we start with telling which pins will give input and which will give input according to left and right motor.
 - Pin 2 and 3 are taking inputs and pin 2 is connected to channel 3 and pin 3 is connected to channel 2.
 - enA and enB are giving outputs to the ENA and ENB respectively for the magnitude of the voltage to be supplied.
 - a,b,c and d are respectively giving OUTPUT to IN1,IN2,IN3 and IN4.

**<ins>polynomial()</ins>**

We define a function such that the output given by the microprocessor to the en pins will be a polynomial function such that initially it increase slowly but later it increase rapidly. This function will help for better control because at intial there will be slow movement in bot but after certain magnitude when the bot will move fast.

-It takes input of the original value from two different channels of the input given by the transmitter
- Initialy we linerly map the input values of channel 3 and channel 2 to 0 to 255 so that we have a analog output
- After that we assign values to ch2_poly and ch3_poly by putting the ch2 and ch3 value in polynomial function
>Polynomial Output of Analog Value = (1/255) × (Linear Mapped Output the input given by Transmitter)<sup>2</sup>

**<ins>Loop</ins>**
- Inside the loop first we map the input given by transmitter which is 1800 to 1200 to -254 to 254 so that we can give analog output.
- We used negative for negative pull of the joystick and positive for positive pull of joystick so that we can control the direction of the bot and can control at ease.
- Then we define original_ch2 and original_ch3 as the original value given by the Transmitter to the receiver which will be used as input for polynomial(original_ch2,original_ch3) function
- After that boundary conditions are defined because in experimental observation we observed that the input values varies due to technical and mechanical errors constantly varyind due to dynamic environment.
- So to counter the above problem we defined set of boundary condition such that if the value is above 254 then the value of channel's input is 254 only and if it is less than -254 then the input in channel is -254 only.
- After this we setup the conditions for motions of directions like FORWARD,BACKWARD,RIGHT,LEFT and STABLE(Beacuse at experimentation we observed that the bot was not stable at that so we specified the condition at else statment).
- At the end we use polynomail function

# Testing and Calibration

After testing the bot will be able to do all the motions easily. But one has to calibrate according to the Transmitter they are using because every transmitter has different input values and they vary very frequently so the transmitter and mapping must be calibrated accordingly.

# Performance Evaluation

- The bot works good in plane surface and is very easy to control and very responsive to user's command
- After some time the Motor Driver Overheats too much


# Future Improvements

There are many inprovements to be done in the bot
- Using good equipments for building bot.
- Reduction of weight
- Writing a exponential function of mapping so that we have more control on the bot and can switch back to linear or polynomial according to need
- More power from battery for more speed

 # Conclusion

The project was mostly successful. In this project we learn how the receiver and transmitter works and how wireless transmission of Radiowaves occur. And we learnt about functions like mapping and pulseIn and how to define a function. This bot has the special function such that on low inpur by user it moves slow but after certain point the speed increse very rapidly. This function allows better result and better control. This project overall teaches us of basic wireless transmission of signals and this ignites our mind to do more projects on transmitter and receiver.

# Members

- Dr. Subhankar Mishra (Faculty incharge of RoboTech Club) - Guidance for the Project
- Sanat Kumar Behera (Captain) - Mechanical work of the project
- Rikan Mahakur - Circuiting work of the project
- Dadhichi Das - Coding work for project

  # Joy Maa Kali
