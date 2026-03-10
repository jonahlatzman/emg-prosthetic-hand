# EMG Prosthetic Hand - Engineering Journal
**Jonah Latzman | Mamaroneck High School | Class of 2027 | Started February 22, 2026**

This is a daily record of my work on the EMG-controlled prosthetic hand project.

---

## Week 1: Feb 22 - Mar 1

---

### Feb 22, 2026
- Came up with the project idea: an EMG-controlled 3D-printed prosthetic hand with haptic feedback
- Wrote the README and set up the GitHub repository
- Spent time researching and selecting all the parts needed

**Next Steps:**
- Order all the parts from Amazon and Sparkfun
- Watch MyoWare 2.0 tutorial, FSR tutorial, and e-NABLE assembly video on YouTube
- Read the Sparkfun MyoWare 2.0 hookup guide

---

### Feb 23, 2026
- Ordered all the parts from Amazon and Sparkfun
- Watched three tutorials: MyoWare 2.0 Arduino setup, force sensitive resistor basics, and the e-NABLE Phoenix hand assembly. Seeing the Phoenix hand come together made the mechanical side feel a lot more real, and gave me ideas about using that design as a base and modifying it with all the electrical components

**Next Steps:**
- Read the Sparkfun MyoWare 2.0 hookup guide
- Parts arrive Feb 28, get ready to start Phase 1 wiring

---

### Feb 24, 2026
- Watched more YouTube videos about 3D-printed prosthetics to get a better sense of how others have built and wired similar designs
- Built a mock Arduino setup to start getting familiar with the code before the real parts arrive. Used an LDR to simulate the pressure sensor since covering it simulates contact, and a potentiometer to mimic the EMG signal. Got the basic logic working.

**Next Steps:**
- Parts arrive Feb 28
- Keep refining the mock setup until then

---

### Feb 25, 2026
- Looked more into the parts that are arriving and what to expect from each one
- Practiced some simple circuits on the breadboard to start getting familiar with the components before everything arrives

**Next Steps:**
- Continue practicing circuits
- Look into the e-NABLE Phoenix Hand model

---

### Feb 26, 2026
- Spent time in Fusion 360 practicing and getting more comfortable with the tools I will need for modifying the Phoenix Hand design
- Started looking into the e-NABLE Phoenix Hand model to understand how it is built and how I will modify it to fit my circuitry

**Next Steps:**
- Parts arrive Feb 28
- Keep reviewing Phoenix Hand design

---

### Feb 27, 2026
- Continued reviewing the e-NABLE Phoenix Hand model and started thinking through where the FSR sensors and wire channels will need to go in the fingertips
- Did more Fusion 360 practice with the kinds of modifications I will need to make

**Next Steps:**
- Parts begin to arrive tomorrow Feb 28
- Begin Phase 1 wiring as soon as everything is unboxed

---

### Feb 28, 2026
- Amazon parts arrived, unboxed everything and organized by phase
- Tested what I could without the MyoWare sensor using basic sketches
- Still waiting on the Sparkfun order (MyoWare 2.0, Cable Shield, Reference Cables) so no EMG work yet

**Next Steps:**
- Sparkfun parts expected around March 3
- Continue working with the parts I have right now

---

### Mar 1, 2026
- Got the servo, FSR, LED, and vibration motor all working together in one circuit
- FSR values came out clean: no touch is 0, light press is around 90, hard press maxes at 940. Used those as the mapping range for everything else
- The servo, vibration motor, and LED all respond proportionally to FSR pressure at the same time. Pressing harder rotates the servo further, brightens the LED, and increases the buzz intensity
- Had to power components from both the Arduino and the 4xAA battery pack to get everything running stably. The servo needs more current than the Arduino 5V pin can supply on its own, so the battery pack handles the heavier components while the Arduino handles the signal pins
- Taped the vibration motor to my arm during testing and could clearly feel the buzz intensity change with pressure. This is essentially the haptic feedback system in its simplest form
- Recorded a documentation video showing all four components working simultaneously with a walkthrough of what each one does

**Next Steps:**
- Sparkfun parts expected around March 3
- Write the combined FSR and servo control code with EMG threshold logic ready to go for when the sensor arrives

---

## Week 2: Mar 2 - Mar 8

---

### Mar 2, 2026
- Got the MyoWare 2.0 EMG sensor working for the first time. Signal responds clearly when flexing
- Troubleshot a flatline reading that turned out to be a loose ground solder joint on the MyoWare board. Resoldered it and the signal came in clean
- Electrode placement confirmed working: two pads on the forearm muscle belly with the reference cable on the elbow bone
- Phase 1 EMG work officially started
- Ordered Sparkfun CAB-12970 sensor cable, which has a 3.5mm plug on one end and three snap connectors on the other. This will work with the Cable Shield to keep the board off the skin and make electrode placement much cleaner

**Next Steps:**
- Headers and sensor cable arrive around March 4
- Once they arrive, resolder MyoWare with header pins and set up the Cable Shield properly
- Find threshold value that cleanly separates flex from rest
- Start combining EMG signal with the servo and haptic motor code

---

### Mar 3, 2026
- Researched 3D printed hand designs to get a better sense of what base model to work from
- Downloaded the Flexy-Hand 2 by Gyrobot from Thingiverse as an alternative to the e-NABLE Phoenix Hand. Key features that stood out were the discrete internal tendon channels already built in and adjustable tensioners
- Still deciding whether to modify the Phoenix Hand or Flexy-Hand 2 as the base for Phase 3

**Next Steps:**
- Header pins arrive tomorrow
- Solder the header pins onto EMG sensor
- Compare Phoenix Hand and Flexy-Hand 2 designs in Fusion 360

---

### Mar 4, 2026
- 40 pin header strip arrived
- Soldered header pins onto the MyoWare board
- Hooked up the MyoWare with all three electrodes. Initially got a stuck reading around 740 that turned out to be because only the reference electrode was connected with no signal electrodes. Added all three and signal came in properly
- EMG signal range: resting around 80, hard flex around 300
- Integrated EMG into the full circuit alongside servo, FSR, LED, and vibration motor. Flex closes the servo, relax opens it. FSR still drives haptic motor intensity independently
- Added a 10 sample moving average filter to smooth out noise. Threshold set at 60, which gives a clean gap above the resting signal
- Got Python visualizer running and plotting EMG and FSR signals live side by side

**Next Steps:**
- Run flex and rest trials to nail down a proper threshold value
- Take a screen recording of the visualizer for documentation
- Compare Phoenix Hand and Flexy-Hand 2 in Fusion 360 to decide which base model to use

---

### Mar 5, 2026
- Signal was still inconsistent session to session due to floating pin noise on the breadboard
- Increased moving average filter from 10 to 30 samples, brought resting signal down to around 30 and hard flex consistently to around 400
- Added spike rejection to ignore any reading that jumps more than 50 units from the previous sample, eliminated nearly all false triggers

**Next Steps:**
- Implement auto-calibration using startup seed readings
- Test calibration consistency across multiple sessions with electrode removal and replacement

---

### Mar 6, 2026
- Implemented auto-calibration seeded from 100 startup readings to set autoMin and autoMax, values track continuously during use
- Tested by removing and reattaching electrodes between runs, calibration adapted each time without manual adjustment

**Next Steps:**
- Add variance-based intent detection
- Add rate limiting to smooth servo movement

---

### Mar 7, 2026
- Added variance-based intent detection, servo locks position when EMG variance across the 30-sample window drops below 6
- Added hysteresis with separate engage threshold at 35% of calibrated range and release at 20%, prevents stuttering at the boundary of a flex

**Next Steps:**
- Decouple serial printing from the control loop

---

### Mar 8, 2026
- Added rate limiting, max 8 degrees per loop while moving and 4 while settling, grip open and close feels controlled instead of snapping
- Added return-to-zero so the hand fully opens when intent lock disengages
- Decoupled serial printing from control loop, loop runs at fixed 20ms and serial prints every 500ms only
- Added ASCII bar graphs to serial monitor for EMG, grip angle, and force so readings are readable at a glance

**Next Steps:**
- Run extended stress test to confirm full algorithm stability
- Finalize hand model decision
