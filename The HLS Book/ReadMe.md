# Parellel Programming for FPGAs - The HLS book
[Original Source](https://kastner.ucsd.edu/hlsbook/#:~:text=Parallel%20Programming%20for%20FPGAs%20is,to%20effectively%20use%20HLS%20tools.)
## Chapter 1
### Higl-Level-Synthesis
* HLS is an abstraction that enables a designer to focus on larger architectural questions rather than individual registers and cycle-to-cycle operations. It,
    * analyzes and exploits the concurrency in an algorithm.  
    * inserts registers as necessary to limit critical paths and achieve a desired clock frequency.  
    * generates control logic that directs the data path.  
    * implements interfaces to connect to the rest of the system.   
    * maps data onto storage elements to balance resource usage and bandwidth.  
    * maps computation onto logic elements performing user specified and automatic optimizations to achieve the most efficient implementation.
### FPGA Architecture
