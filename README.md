# ReSoel - Wonderful Terminal Technology #

*Work in progress, non-functional.*

A project to build an easy-to-use API around the Windows console subsystem 
to make creation of ConsoleHost replacements like ConEmu easy and straight-forward
and to decouple a specific replacement from the underlying hooking technology.

ReSoel will also hopefully evolve to have a default implementation of a ConsoleHost
replacement. 

Right now I'm building basic hooking infrastructure and getting a feel for what sort
of state I'll need to track to properly piece back together the full state of the
console window. 