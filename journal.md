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
