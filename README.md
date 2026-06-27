# Marua: Taking Pictures and Videos

> Wheelchair-mounted smartphone stabilizer with Bluetooth remote for hands-free photography and video recording.

**Team:** Seagirls 
**Members:** Natálie Martincová 🇨🇿 · Alina Paschedag 🇩🇪 · Markéta Růžičková 🇨🇿  
**License — Code:** [MIT License](LICENSE)  
**License — Documentation:** [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)  
**Estimated Total Cost:** ~€90

[Prototype](docs/photos/prototype.jpg) 

---

## Problem

### User Request

Marua is a 30-year-old wheelchair user diagnosed with **myoclonic epilepsy**. A core symptom of her condition is involuntary tremors and twitching of the hands. She wanted to take photos and record videos — including while moving in her wheelchair — without the results being blurry or shaky.

She needed a solution that would:
- Stabilize her smartphone independently of her hand movements
- Be easily attached to and removed from her wheelchair
- Allow her to switch between photo and video mode remotely
- Allow her to trigger the shutter remotely, without touching the phone
- Be usable while the wheelchair is in motion

### Impairment and Remaining Functions

| Aspect | Details |
|--------|---------|
| Diagnosis | Myoclonic Epilepsy |
| Primary Limitation | Uncontrollable tremors and twitching of the hands |
| Remaining Functions | Can press large buttons with fingers even with limited fine motor control |
| Controller Requirement | Simple push-button controller with large buttons, no fine motor control needed |
| Cognitive Ability | Fully capable; communicates without difficulty |

---

## Solution

The Seagirls team designed and built a **two-part assistive technology solution**:

1. A flexible, wheelchair-mounted **smartphone stabilizer** based on the Loc-Line modular hose system with a magnetic phone adapter, fixed to the wheelchair frame using a screw-tightening clamp
2. A custom **3D-printed Bluetooth remote controller** with two large tactile buttons, powered by an Adafruit Feather V4 microcontroller

### What Can Be Done with the Solution?
- Mount a smartphone securely to the wheelchair at any angle
- Adjust the position and angle of the phone using the flexible Loc-Line arm
- Switch between photo mode and video mode with one button press
- Take a photo or start/stop video recording with the shutter button
- Use the device while stationary or while the wheelchair is moving

### Design Principles

| Design Principle | Implementation |
|-----------------|----------------|
| Adaptable to any wheelchair | Screw-tightening clamp fits most standard wheelchair frames |
| Compatible with any smartphone | Magnetic adapter works with any phone regardless of brand or size |
| Openable enclosure | 3D-printed remote can be opened to replace or upgrade components |
| Lightweight | Minimal weight to avoid adding strain to the wheelchair setup |
| Stable | Loc-Line arm holds the phone firmly even while moving |
| Good button resistance | Push buttons provide clear tactile feedback, easy to press with tremors |

<!-- ![Solution overview](docs/photos/solution-overview-remote.jpg) -->
<!-- ![Solution overview](docs/photos/solution-overview-holder.jpg) -->

---

## User Documentation

### Components

| Component | Description |
|-----------|-------------|
| Loc-Line arm (3/4") | Flexible modular hose, adjustable to any angle |
| Magnetic phone adapter | Quick-attach/detach, compatible with any smartphone |
| Wheelchair clamp | Screw-tightening clamp, fits any standard wheelchair frame |
| Bluetooth remote | 3D-printed openable enclosure, 2 tactile push buttons |
| LiPo battery | 3.7V 800mAh, rechargeable via USB-C |

### Setting Up

1. Attach the Loc-Line arm to the wheelchair frame using the screw-tightening clamp
2. Attach the magnetic adapter to the end of the Loc-Line arm
3. Attach a magnetic sticker to your phone case (or insert it between the phone and case)
4. Attach the smartphone to the magnetic adapter
5. Adjust the arm to the desired position and angle
6. Turn on the Bluetooth remote
7. Pair the remote with the smartphone via Bluetooth
8. Open the camera app on the smartphone

### Controls

| Button | Action | Notes |
|--------|--------|-------|
| Button 1 — Shutter | Take photo / Start–Stop video recording | Main trigger button |
| Button 2 — Mode | Switch between photo and video mode | Toggle function |

[Control layout](docs/photos/controls.jpg) 

---

## Technical Documentation

### Materials, Components and Costs

| Item | Details / Source | Est. Cost |
|------|-----------------|-----------|
| Loc-Line modular hose (3/4") | Amazon — 5-foot coil | ~€50 |
| Magnetic phone holder adapter + stickers | Amazon DE — LIUCOLI | ~€10 |
| Adafruit Feather V4 | BLE + LiPo charging circuit built-in | ~€20 |
| LiPo Battery 3.7V 800mAh | JST connector, fits Adafruit Feather V4 | ~€7 |
| 3D printed enclosure | Prusa MK4S, PLA filament | ~€2 |
| Push buttons (×2) | Tactile momentary push buttons | ~€1 |
| **TOTAL** | | **~€90** |

### Tools Needed
- 3D printer (Prusa MK4S or similar FDM printer)
- PrusaSlicer (free — [prusaslicer.org](https://www.prusaslicer.org/))
- Visual Studio Code
- Soldering iron and solder
- USB-C cable for programming and charging

### 3D Printing — Remote Enclosure

| Parameter | Value |
|-----------|-------|
| Printer | Prusa MK4S |
| Slicer | PrusaSlicer |
| Material | PLA filament |
| Estimated print time | ~3 hours 30 minutes |
| CAD tool | Onshape |

CAD files are available on Onshape:
- [Remote enclosure](https://cad.onshape.com/documents/0b6fb212b79f42c29ad16602/)
- [Button caps](https://cad.onshape.com/documents/94e022fe4d6fa302c492216f/w/ed2f0a4f99ac6465352d92ab/e/22765c5e61bea228afda956b)

STL files for printing are also included in the [`design/`](design/) folder of this repository.

### Microcontroller and Electronics

The remote controller is based on the **Adafruit Feather V4**, which includes:
- Built-in Bluetooth Low Energy (BLE) module
- Built-in LiPo battery charging circuit
- USB-C port for charging and programming

Two tactile push buttons are wired to GPIO pins of the microcontroller. The LiPo battery (3.7V, 800mAh) connects directly to the JST connector on the Feather V4. All electronics are housed inside the openable 3D-printed enclosure.

<!-- TODO: Insert simplified wiring diagram here -->
<!-- ![Wiring diagram](docs/wiring-diagram.png) -->

### Firmware

| Parameter | Value |
|-----------|-------|
| Development Environment | Visual Studio Code |
| Language | C++ |
| Protocol | Bluetooth HID (Human Interface Device) |
| Button 1 — Shutter | Triggers photo capture or starts/stops video recording |
| Button 2 — Mode | Toggles between photo and video mode |

Firmware source code is located in the [`firmware/`](firmware/) folder.

### Assembly Steps

1. 3D print the remote enclosure using the provided CAD/STL files
2. Solder the two push buttons to the GPIO pins of the Adafruit Feather V4
3. Connect the LiPo battery to the JST connector on the Feather V4
4. Flash the firmware using Visual Studio Code via USB-C
5. Place the electronics into the 3D-printed enclosure
6. Secure the buttons with hot glue
7. Assemble the Loc-Line arm to the desired length
8. Attach the magnetic phone adapter to the end of the Loc-Line arm
9. Mount the Loc-Line arm to the wheelchair frame using the screw-tightening clamp
10. Pair the remote with the smartphone via Bluetooth and test all functions

---

## Team

| Name | Role | Skills |
|------|------|--------|
| Natálie Martincová 🇨🇿 | Prototyper, Documentation | Python, Mechanics, Anatomy |
| Markéta Růžičková 🇨🇿 | Time Manager, User Researcher, 3D design | Anatomy, SQL, C# |
| Alina Paschedag 🇩🇪 | Communicator, Connectivity | Java, Matlab, Electrotechnics, SQL |

---

## License

| Scope | License |
|-------|---------|
| Code and design files | [MIT License](LICENSE) |
| Documentation | [Creative Commons Attribution 4.0 International (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/) |
