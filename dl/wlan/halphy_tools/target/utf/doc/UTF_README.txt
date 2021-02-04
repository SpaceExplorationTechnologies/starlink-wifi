The Objective ("Mandate")
=========================
1. Achieve the identical RF performance between the WLAN sw and System's testing tools.
2. "Unify" various testing firmware pieces: MDK/ART/NART firmware (device.bin), TCMD firmware (athtcmd.bin) 
and OTA solution firmware. 

The Architecture ("Preaching")
==============================

UTF's basic operation is based on a command and respponse model.

UTF serves a number of "clients": ART/NART, MDK, TCMD, and Testscript.

The clients are host applications.

A host can be a desktop of Windows or Linux, or an application processor (for example, an ARM based processor 
in a smart phone running Android).

All clients should be well known with the exception of Testscript. A testscript is basically a collection 
of commands to be executed in a serial order, and is typically a "long" sequence of commands. The Testscript 
client downloads a testscript on target RAM and commands the target to execute it upon power on. OTA 
("Over The Air") testing solution is based on the Testscript client. Typical OTA applications are production 
tools and DVT infrastructure.


                         OTA
                          |
    ART/NART TCMD MDK Testscript
          \   |   /   /
           \  |  /   /
              UTF
                   

The UTF blocks (Every great architect draws)
--------------------------------------------

UTF has several pieces. 
For bottom up on the target, HAL, chip specific modules, generic testing logic, host interfaces.
On the host, test command preprocessor.
Also on the host, the command and response build environment.

The test command preprocessor basically takes various commands and pre-process them into the "uniform" 
binary test commands and "push" them down to the target through a host interface.

The host interface layer currently consists WMI, raw HTC and the Testscript (i.e. direct downloading
to target RAM).

The generic testing logic is basically the old tcmd code excluding any chip specific stuff.

The chip specific modules are functions specific to chips, e.g. AR6003, AR6004, Peregrine, Hera. 


    ART/NART TCMD MDK Testscript
          \   |   /   /
           \  |  /   /
       command preprocessor
              |
         test commands
              |                     (host)
 -------------------------------------------
              |                     (target)
       Host Interface
      WMI    Testscript    rawHTC(debating if needed)
              |

        test commands parser

              |
        Generic Testing logic
 
              |
        Chip specific modules
    AR6003   AR6004  Peregrine  Hera   (future chips ....)


The command and response build environment is based on template and automatically generates command and
response header files used by both host command preprocessor to compose the commands, and UTF to parse
the commands.
          

Chip setup vs test configuration
---------------------------------
Chip setup refers to the register settings different from the ones applied during Reset.

Reset applies the register settings different from hardware defaults, or in the case where hardware has no defaults.

Chip setup can be thought of as equivalent to the good old ART eep file.

Test configuration is the command parameters, such as tx99, tx chain 0.

The distinction between the two can be confusing. But an architectural separation is beneficial, and the practical
partition can be achieved by adhering to the folllowing rule.
Chip setup is a register file containing all registers with different values from the ones applied during Reset.
The chip setup register file is always present and applied after the Reset, even when it's empty.

The test configuration is the result of the command pre-processor, basically its parameters.

The test configuration is based on fixed template with default values, so a particular test configuration does not
need to provide all parameters. All absent parameters will be filled with defaults.


Command preprocessor
--------------------
The input to command preprocessor is the test command and its list of parameters.

The output is a binary testscript, sent down to target through a host interface, typically WMI.


The binary testscript normally is one test command and within the 256 bytes in length.               
This is different from the TestScript client's testscript, which is normally long and consists of multiple
test commands for production or DVT use.



The commands ("Boring Details")
-------------------------------
UTF supports many commands, too many that some constraint needs to be exercised. Ideally the following
commands are probably sufficient.

- Memory access
- Register access
- Tx 
- Rx
- Calibration
- EEPROM/OTP accesss (if any)

For details, refer to the individual modules and the comments in the code.










