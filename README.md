Traffic Signal Simulation System with Priority Vehicle Handling

This project is a C-based simulation of a modern urban traffic management system. It utilizes the Queue Data Structure to manage vehicle flow and incorporates a priority-based mechanism to ensure emergency vehicles (ambulances, fire trucks, etc.) are processed without delay.

Overview
In real-world traffic, a simple First-In-First-Out (FIFO) system can lead to critical delays for emergency services. This simulation addresses that by maintaining two distinct queues:
Priority Queue: For emergency vehicles (Ambulance, Fire Truck, Police).
Normal Queue: For regular vehicles (Cars, Bikes, Trucks).
When the signal turns green, the system automatically checks the Priority Queue first, ensuring life-saving vehicles pass before regular traffic resumes.

Features
Dual-Queue Management: Uses separate queues to categorize vehicle urgency.
Priority Override: Emergency vehicles always bypass the standard traffic flow.
FIFO Logic: Ensures fair treatment of regular vehicles within their own queue.
Directional Simulation: Mimics a 4-way intersection (North, East, South, West).
Real-time Delays: Uses sleep() functions to simulate actual traffic light durations.

Project Structure
Introduction: Modeling urban infrastructure challenges.
Algorithm: Detailed step-by-step logic for enqueue/dequeue operations.
Workflow: Visualized logic flow for vehicle arrival and clearance.
Implementation: Dynamic switching between "Normal Mode" and "Emergency Mode" using flag variables.

Tech Stack
Language: C Programming
Data Structure: Linear Queue (FIFO)
Concepts: Loops, Functions, Conditional Logic, and Control Variables.

How it Works
Arrival: A vehicle is entered into the system.
Categorization: If it’s an emergency vehicle, it goes to the Priority Queue; otherwise, it joins the Normal Queue.
Signal Green:
System checks: Is the Priority Queue empty?
No: Dequeue and pass the priority vehicle immediately.
Yes: Dequeue and pass the vehicle from the Normal Queue.
Display: The console shows the current state of both waiting queues.

Advantages & Limitations
Advantages
Efficient Simulation: Simple yet effective representation of real-world logic.
Lightweight: Low resource consumption, console-based execution.
Scalable: The logic can be easily extended to include sensors or AI optimization.
Limitations
Static Timing: Signal durations are fixed and do not adapt to traffic density.
Manual Input: Emergency vehicles are simulated via manual input rather than automated sensors.
CLI Only: Currently lacks a Graphical User Interface (GUI).

Contributors
Vedashree Patil (AP24110011507)
Spoorthi Sri (AP24110011479)
Bhima Tarini (AP24110011469)
Akshara Putchakayala (AP24110011599)
Prepared for Course CSE 206 – Coding Skills II at SRM University, AP.
