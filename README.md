# Interconnect

Interconnect daemon for OpenSmarts.  This is an implementation of the logical hub for OpenSmarts devices.

Its responsabilities are (in *hub mode*):
- Maintain an internal graph of the network (uuids, keys, and *endpoints*)
- Keep and run all the *automation scripts* as required
- Manage/push new state information to smart home devices as required by users or scripts
- Store/forward state information from smart home devices as requested by users or scripts
- Pair new devices when requested by users

Its responsabilities are (in *endpoint mode*):
- Present all onboard logical endpoints as iot devices
- Pair and maintain keys with other smart home software
- Forward commands from the paired hub to underlying onboard devices
- Forward new data from underlying onboard devices to other smart home software

This daemon is meant to run as the underlying logical smart home hub for a given network.
Current focus is on the basic features of device management, automation, and extensability, but
future work will be done on different setup modes to run a "hub device" as a bridge or endpoint
so that it can be managed (and expose its connected devices) to/from other smart home software
such as HomeAssistant or AppleHomeKit.
